/* Copyright 2021 Jonathan Law, Jay Greco
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Original: j-inc's kyria keymap
 */
#include QMK_KEYBOARD_H
#include "animation_frames_counter_clock.h"
//#include "animation_frames_clockwise.h"

enum layer_names {
  _BASE,
  _VIA1,
  _VIA2,
  _VIA3
};

//RGB  turn off when idle variables
static uint16_t key_timer; // timer to track the last keyboard activity
static void refresh_rgb(void); // refreshes the activity timer and RGB, invoke whenever activity happens
static void check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
bool is_rgb_timeout = false; // store if RGB has timed out or not in a boolean

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all(
              KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
    RGB_TOG,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
    KC_GRV,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
    KC_VOLU,  KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
    KC_VOLD,  KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                  MO(_VIA1), KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_VIA1] = LAYOUT_all(
              _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  KC_END,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______,  KC_INS,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, KC_PSCR,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(_VIA2), _______, _______,
    KC_SLEP,  _______, _______, _______,                            _______,                   _______, _______, _______,   _______, _______, _______
  ),

  [_VIA2] = LAYOUT_all(
              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(_VIA3), _______,
    _______,  _______, _______, _______,                            _______,                   _______, _______, _______, _______,   _______, _______
  ),

  [_VIA3] = LAYOUT_all(
              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
  ),

};

bool encoder_update_user(uint8_t index, bool clockwise) {
  switch(biton32(layer_state)){
    case 3:
    //saturation
      if (clockwise) {
          rgblight_increase_sat();
      } else {
          rgblight_decrease_sat();
      }
    case 2:
      //hue
      if (clockwise) {
          rgblight_increase_hue();
      } else {
          rgblight_decrease_hue();
      }
    break;
    //mode
    case 1:
      if (clockwise) {
          rgblight_step();
      } else {
          rgblight_step_reverse();
      }
    break;
    default:
      //brightness
      if (clockwise) {
          rgblight_increase_val();
      } else {
          rgblight_decrease_val();
      }
    break;
  }

  /*Refresh RGB timer*/
  #ifdef RGBLIGHT_TIMEOUT
  refresh_rgb();
  #endif

  return true;
}

#ifdef OLED_ENABLE
#define IDLE_FRAME_DURATION_MAX 100 // Idle animation iteration max rate in ms
#define IDLE_FRAME_DURATION_MIN 40  // Idle animation iteration min rate in ms
#define IDLE_FRAME_DURATION 100 // base value for how long each idle animation will last in ms
uint8_t anim_frame_ratio = 1; // how aggressively animation speeds up with wpm

uint32_t anim_timer         = 0;
uint32_t anim_sleep         = 0;
uint8_t  current_idle_frame = 0;
uint32_t curr_anim_duration = 0; // variable animation duration
uint8_t idx = 0;

// Decompress and write a precompressed bitmap frame to the OLED.
// Documentation and python compression script available at:
// https://github.com/nullbitsco/squeez-o
#ifdef USE_OLED_BITMAP_COMPRESSION
static void oled_write_compressed_P(const char* input_block_map, const char* input_block_list) {
    uint16_t block_index = 0;
    for (uint16_t i=0; i<NUM_OLED_BYTES; i++) {
        uint8_t bit = i%8;
        uint8_t map_index = i/8;
        uint8_t _block_map = (uint8_t)pgm_read_byte_near(input_block_map + map_index);
        uint8_t nonzero_byte = (_block_map & (1 << bit));
        if (nonzero_byte) {
            const char data = (const char)pgm_read_byte_near(input_block_list + block_index++);
            oled_write_raw_byte(data, i);
        } else {
            const char data = (const char)0x00;
            oled_write_raw_byte(data, i);
        }
    }
}
#endif

static void render_anim(void) {
    // Among us animation
    void animation_phase(void) {
        if (get_current_wpm() <= 30) {
          anim_frame_ratio = 2;
          current_idle_frame = (current_idle_frame + 1) % NUM_IDLE_FRAMES; //determines current frame
          idx = abs((NUM_IDLE_FRAMES - 1) - current_idle_frame); //gets index of first frame
          #ifdef USE_OLED_BITMAP_COMPRESSION  //if using bitmap compression
            oled_write_compressed_P(idle_block_map[idx], idle_frames[idx]);  //create frame for Display
          #endif
        }
        if (get_current_wpm() > 30){
          anim_frame_ratio = 1;
          current_idle_frame = (current_idle_frame + 2) % NUM_IDLE_FRAMES;
          idx = abs((NUM_IDLE_FRAMES - 1) - (current_idle_frame));
          #ifdef USE_OLED_BITMAP_COMPRESSION  //if using bitmap compression
            oled_write_compressed_P(faster_block_map[idx/2], faster_frames[idx/2]);  //create frame for Display
          #endif
        }
    }

    curr_anim_duration = MAX(IDLE_FRAME_DURATION_MIN, IDLE_FRAME_DURATION_MAX - anim_frame_ratio * get_current_wpm());

    // Idle behaviour
    if (get_current_wpm() != 000) {  // prevent sleep
        oled_on(); //Turn on oled screen
        if (timer_elapsed32(anim_timer) > curr_anim_duration) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    }
    else {  // Turn off screen when timer threshold elapsed or reset time since last input
        if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        }
        else {
            if (timer_elapsed32(anim_timer) > IDLE_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

bool oled_task_user(void) {
    render_anim();
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /*Refresh RGB timer*/
    #ifdef RGBLIGHT_TIMEOUT
    if (record->event.pressed) refresh_rgb();
    #endif

    return true;
}

/*Runs at end of each scan loop, check if RGB timeout has occured*/
void housekeeping_task_user(void) {
  #ifdef RGBLIGHT_TIMEOUT
  check_rgb_timeout();
  #endif
}

void refresh_rgb() {
  key_timer = timer_read(); // store time of last refresh
  if (is_rgb_timeout) { // only do something if rgb has timed out
    is_rgb_timeout = false;
    rgblight_wakeup();
  }
}

void check_rgb_timeout() {
  if (!is_rgb_timeout && timer_elapsed(key_timer) > RGBLIGHT_TIMEOUT) {
    rgblight_suspend();
    is_rgb_timeout = true;
  }
}
