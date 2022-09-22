/* Copyright 2021 Jay Greco
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
 */
#pragma once
#ifdef OLED_ENABLE

// Enable OLED bitmap compression selectively.
#define USE_OLED_BITMAP_COMPRESSION

#define NUM_IDLE_FRAMES 30
#define NUM_FAST_FRAMES 15
#define NUM_OLED_BYTES 512

#ifdef USE_OLED_BITMAP_COMPRESSION

static const char PROGMEM spin_0_block_map[] = {
  0x1c, 0x80, 0x00, 0x03, 0x00, 0x01, 0x00, 0xf8, 0x1f, 0x00, 0x0c, 0x80, 0x00, 0x00, 0xc0, 0x01,
  0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0x80, 0x00, 0x10, 0x80, 0x00, 0x00, 0x08,
  0x00, 0x00, 0x18, 0x00, 0x40, 0x00, 0x00, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x04, 0x00, 0xc0, 0xc0, 0xe3, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x40
};

static const char PROGMEM spin_1_block_map[] = {
  0xc0, 0x01, 0x08, 0x30, 0x00, 0x10, 0x00, 0xfc, 0x3f, 0x00, 0xc0, 0x00, 0x08, 0x00, 0x00, 0x1c,
  0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x01, 0x08, 0x00, 0x01, 0x08, 0x00, 0x80,
  0x00, 0x00, 0x80, 0x01, 0x00, 0x04, 0x80, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00,
  0x04, 0x80, 0x00, 0x00, 0x40, 0x00, 0x00, 0x8c, 0x0f, 0x02, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM spin_2_block_map[] = {
  0x01, 0x1c, 0x80, 0x00, 0x03, 0x00, 0x01, 0xfe, 0x1f, 0x00, 0x00, 0x0c, 0x80, 0x00, 0x00, 0xc0,
  0x08, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x03, 0x80, 0x00, 0x10, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x18, 0x00, 0x40, 0x80, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01,
  0x40, 0x00, 0x08, 0x00, 0x00, 0x04, 0x00, 0xe0, 0x1e, 0x20, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
};

static const char PROGMEM spin_3_block_map[] = {
  0x1c, 0xc0, 0x01, 0x08, 0x30, 0x00, 0x10, 0xfe, 0x07, 0x01, 0x00, 0xc0, 0x00, 0x08, 0x00, 0x00,
  0x80, 0x00, 0x02, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x03, 0x00, 0x08, 0x00, 0x01, 0x08, 0x00,
  0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x04, 0xff, 0xff, 0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18,
  0x00, 0x04, 0x80, 0x00, 0x00, 0x40, 0x00, 0xe0, 0x7c, 0x00, 0x02, 0x00, 0x20, 0x00, 0x00, 0x00
};

static const char PROGMEM spin_4_block_map[] = {
  0xc0, 0x01, 0x1c, 0x80, 0x00, 0x03, 0x00, 0xef, 0x03, 0x10, 0x00, 0x00, 0x0c, 0x80, 0x00, 0x00,
  0x00, 0x08, 0x20, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0x0f, 0x00, 0x80, 0x00, 0x10, 0x80, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x18, 0x00, 0x40, 0xff, 0xff, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x00, 0x40, 0x00, 0x08, 0x00, 0x00, 0x04, 0x80, 0xc3, 0x00, 0x20, 0x00, 0x00, 0x02, 0x00, 0x00
};

static const char PROGMEM spin_5_block_map[] = {
  0x00, 0x1c, 0xc0, 0x01, 0x08, 0x30, 0x00, 0xfb, 0x00, 0x00, 0x01, 0x00, 0xc0, 0x00, 0x08, 0x00,
  0x00, 0x80, 0x00, 0x02, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x07, 0x00, 0x00, 0x08, 0x00, 0x01, 0x08,
  0x18, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0xff, 0xff, 0x03, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 0x40, 0x00, 0x07, 0x0c, 0x00, 0x02, 0x00, 0x20, 0x00, 0x00
};

static const char PROGMEM spin_6_block_map[] = {
  0x00, 0xc0, 0x01, 0x1c, 0x80, 0x00, 0x03, 0x3c, 0x01, 0x00, 0x10, 0x00, 0x00, 0x0c, 0x80, 0x00,
  0x00, 0x00, 0x08, 0x20, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x07, 0x00, 0x00, 0x80, 0x00, 0x10, 0x80,
  0x80, 0x01, 0x00, 0x00, 0x00, 0x18, 0xe0, 0xff, 0xff, 0x07, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x40, 0x00, 0x08, 0x00, 0x00, 0x04, 0x00, 0xc0, 0x00, 0x20, 0x00, 0x00, 0x02, 0x00
};

static const char PROGMEM spin_7_block_map[] = {
  0x00, 0x00, 0x1c, 0xc0, 0x01, 0x08, 0x30, 0x08, 0x10, 0x00, 0x00, 0x01, 0x00, 0xc0, 0x00, 0x08,
  0x08, 0x00, 0x80, 0x00, 0x02, 0x00, 0xe0, 0xff, 0xff, 0x73, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01,
  0x00, 0x18, 0x00, 0x00, 0x00, 0x80, 0xe1, 0xff, 0xff, 0x07, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 0x40, 0x00, 0x00, 0x0c, 0x00, 0x02, 0x00, 0x20, 0x00
};

static const char PROGMEM spin_8_block_map[] = {
  0x00, 0x00, 0xc0, 0x01, 0x1c, 0x80, 0x00, 0x03, 0xff, 0x01, 0x00, 0x10, 0x00, 0x00, 0x0c, 0x80,
  0x80, 0x00, 0x00, 0x08, 0x20, 0x00, 0xe0, 0xff, 0xff, 0x07, 0x07, 0x00, 0x00, 0x80, 0x00, 0x10,
  0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0xe8, 0xff, 0xff, 0x07, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x40, 0x00, 0x08, 0x00, 0x80, 0x04, 0x00, 0xc0, 0x00, 0x20, 0x00, 0x00, 0x02
};

static const char PROGMEM spin_9_block_map[] = {
  0x10, 0x00, 0x00, 0x38, 0x80, 0x03, 0x10, 0xa0, 0x3f, 0x20, 0x00, 0x00, 0x02, 0x00, 0x80, 0x01,
  0x02, 0x10, 0x00, 0x00, 0x01, 0x04, 0xe0, 0xff, 0xff, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x10, 0x00,
  0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x08, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x00, 0x81, 0x00, 0x00, 0x18, 0x00, 0x04, 0x00, 0x40
};

static const char PROGMEM spin_10_block_map[] = {
  0x00, 0x02, 0x00, 0x00, 0x07, 0x70, 0x00, 0xe2, 0x0f, 0x00, 0x04, 0x00, 0x40, 0x00, 0x00, 0x30,
  0x40, 0x00, 0x02, 0x00, 0x20, 0x80, 0xc0, 0xff, 0xff, 0x03, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x01, 0x20, 0x06, 0x00, 0x10, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00
};

static const char PROGMEM spin_11_block_map[] = {
  0x03, 0x20, 0x00, 0x00, 0x70, 0x00, 0x07, 0xf0, 0xc3, 0x00, 0x40, 0x00, 0x00, 0x04, 0x00, 0x00,
  0x00, 0x04, 0x20, 0x00, 0x00, 0x02, 0xe8, 0xff, 0xff, 0x01, 0x00, 0xc0, 0x01, 0x00, 0x00, 0x20,
  0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x01, 0x10, 0x00, 0x00, 0x00, 0x01, 0x00,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x7e, 0x00, 0x00, 0x01, 0x00, 0x30, 0x00, 0x08, 0x00
};

static const char PROGMEM spin_12_block_map[] = {
  0x30, 0x00, 0x02, 0x00, 0x00, 0x07, 0x70, 0xf8, 0x72, 0x0c, 0x00, 0x04, 0x00, 0x40, 0x00, 0x00,
  0x02, 0x40, 0x00, 0x02, 0x00, 0x20, 0xc0, 0xff, 0xff, 0x01, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0xc0, 0xff, 0xff, 0x01, 0x00, 0x01, 0x00, 0x00, 0x10, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x01, 0x00, 0x10, 0x00, 0x00, 0x03, 0x80, 0x00
};

static const char PROGMEM spin_13_block_map[] = {
  0x00, 0x06, 0x40, 0x00, 0x00, 0xe0, 0x00, 0x3e, 0x7c, 0x80, 0x01, 0x80, 0x00, 0x00, 0x08, 0x00,
  0x40, 0x00, 0x08, 0x40, 0x00, 0x00, 0x04, 0xff, 0xff, 0x01, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0xff, 0xff, 0x0c, 0x00, 0x20, 0x00, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0xff, 0x07, 0x00, 0x00, 0x02, 0x00, 0x60, 0x00, 0x10
};

static const char PROGMEM spin_14_block_map[] = {
  0x00, 0xc0, 0x00, 0x08, 0x00, 0x00, 0x1c, 0xce, 0x0f, 0x08, 0x30, 0x00, 0x10, 0x00, 0x00, 0x01,
  0x00, 0x08, 0x00, 0x01, 0x08, 0x00, 0x00, 0xff, 0xef, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x80, 0xff, 0xef, 0x80, 0x01, 0x00, 0x04, 0x00, 0x00, 0x40,
  0x02, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x87, 0x00, 0x00, 0x40, 0x00, 0x00, 0x0c, 0x00
};

static const char PROGMEM spin_15_block_map[] = {
  0x00, 0x00, 0x0c, 0x80, 0x00, 0x00, 0xc0, 0xc3, 0x1f, 0x80, 0x00, 0x03, 0x00, 0x01, 0x00, 0x10,
  0x00, 0x80, 0x00, 0x10, 0x80, 0x00, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0xff, 0xff, 0x00, 0x18, 0x00, 0x40, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0xf8, 0x1f, 0x08, 0x00, 0x00, 0x04, 0x00, 0xc0, 0x00
};

static const char PROGMEM spin_16_block_map[] = {
  0x01, 0x00, 0xc0, 0x00, 0x08, 0x00, 0x00, 0xfc, 0xc1, 0x01, 0x08, 0x30, 0x00, 0x10, 0x00, 0x00,
  0x00, 0x00, 0x08, 0x00, 0x01, 0x08, 0xc0, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00,
  0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0xff, 0xff, 0x01, 0x80, 0x01, 0x00, 0x04, 0x00, 0x00,
  0x00, 0x02, 0x00, 0x20, 0x00, 0x00, 0x00, 0xfc, 0x3f, 0x80, 0x00, 0x00, 0x40, 0x00, 0x00, 0x0c
};

static const char PROGMEM spin_17_block_map[] = {
  0x20, 0x00, 0x00, 0x18, 0x00, 0x01, 0x00, 0xf8, 0x07, 0x38, 0x00, 0x01, 0x06, 0x00, 0x02, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x20, 0x00, 0xe1, 0xff, 0xff, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e,
  0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0x00, 0x00, 0x30, 0x00, 0x80, 0x00, 0x00,
  0x01, 0x40, 0x00, 0x00, 0x04, 0x00, 0x00, 0xf8, 0xff, 0x00, 0x10, 0x00, 0x00, 0x08, 0x00, 0x80
};

static const char PROGMEM spin_18_block_map[] = {
  0x00, 0x04, 0x00, 0x00, 0x03, 0x20, 0x00, 0x1e, 0x77, 0x00, 0x07, 0x20, 0xc0, 0x00, 0x40, 0x00,
  0x01, 0x00, 0x00, 0x20, 0x00, 0x04, 0xf0, 0xff, 0xff, 0x02, 0x08, 0x00, 0x00, 0x00, 0x00, 0xc0,
  0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0x01, 0x00, 0x00, 0x06, 0x00, 0x10, 0x00,
  0x30, 0x00, 0x08, 0x00, 0x80, 0x00, 0x00, 0xe0, 0x7f, 0x10, 0x00, 0x02, 0x00, 0x00, 0x01, 0x00
};

static const char PROGMEM spin_19_block_map[] = {
  0x00, 0x40, 0x00, 0x00, 0x30, 0x00, 0x02, 0xc0, 0x01, 0x07, 0x70, 0x00, 0x02, 0x0c, 0x00, 0x04,
  0x1c, 0x00, 0x00, 0x00, 0x02, 0x40, 0xe0, 0xff, 0xff, 0x20, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x03, 0x00, 0x00, 0x60, 0x00, 0x00, 0x01,
  0x00, 0x03, 0x80, 0x00, 0x00, 0x08, 0x00, 0xc0, 0xf7, 0x00, 0x01, 0x20, 0x00, 0x00, 0x10, 0x00
};

static const char PROGMEM spin_20_block_map[] = {
  0x00, 0x00, 0x04, 0x00, 0x00, 0x03, 0x20, 0xe0, 0x00, 0x70, 0x00, 0x07, 0x20, 0xc0, 0x00, 0x40,
  0xc0, 0x01, 0x00, 0x00, 0x20, 0x00, 0xc4, 0xff, 0xff, 0x01, 0x02, 0x08, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x06, 0x00, 0x10,
  0x00, 0x30, 0x00, 0x08, 0x00, 0x80, 0x00, 0x00, 0xdf, 0x00, 0x10, 0x00, 0x02, 0x00, 0x00, 0x01
};

static const char PROGMEM spin_21_block_map[] = {
  0x08, 0x00, 0x80, 0x00, 0x00, 0x60, 0x00, 0x04, 0x00, 0x00, 0x0e, 0xe0, 0x00, 0x04, 0x18, 0x00,
  0x00, 0x38, 0x00, 0x00, 0x00, 0x04, 0xe0, 0xff, 0xff, 0x07, 0x40, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x20, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00,
  0x00, 0x00, 0x06, 0x00, 0x01, 0x00, 0x10, 0x00, 0x3c, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x20
};

static const char PROGMEM spin_22_block_map[] = {
  0x00, 0x01, 0x00, 0x10, 0x00, 0x00, 0x0c, 0x80, 0x00, 0x00, 0xc0, 0x01, 0x1c, 0x80, 0x00, 0x03,
  0x00, 0x00, 0x07, 0x00, 0x00, 0x80, 0xe0, 0xff, 0xff, 0x07, 0x00, 0x08, 0x20, 0x00, 0x00, 0x00,
  0x40, 0x00, 0x00, 0x00, 0x04, 0x00, 0xc0, 0xff, 0xff, 0x87, 0x01, 0x00, 0x00, 0x00, 0x18, 0x00,
  0x04, 0x00, 0xc0, 0x00, 0x20, 0x00, 0x00, 0x0a, 0x10, 0x00, 0x00, 0x40, 0x00, 0x08, 0x00, 0x00
};

static const char PROGMEM spin_23_block_map[] = {
  0x00, 0x10, 0x00, 0x00, 0x01, 0x00, 0xc0, 0x00, 0x09, 0x00, 0x00, 0x1c, 0xc0, 0x01, 0x08, 0x30,
  0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0xe8, 0xff, 0xff, 0x0f, 0x00, 0x80, 0x00, 0x02, 0x00, 0x00,
  0x00, 0x04, 0x00, 0x00, 0x40, 0x00, 0xe0, 0xff, 0xff, 0x07, 0x18, 0x00, 0x00, 0x00, 0x80, 0x01,
  0x40, 0x00, 0x00, 0x0c, 0x00, 0x02, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00
};

static const char PROGMEM spin_24_block_map[] = {
  0x03, 0x00, 0x01, 0x00, 0x10, 0x00, 0x00, 0x8c, 0x80, 0x00, 0x00, 0xc0, 0x01, 0x1c, 0x80, 0x00,
  0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0xff, 0xff, 0x87, 0x00, 0x00, 0x08, 0x20, 0x00, 0x00,
  0x00, 0x40, 0x00, 0x00, 0x00, 0x04, 0xe0, 0xff, 0xff, 0x07, 0x80, 0x01, 0x00, 0x00, 0x00, 0x18,
  0x00, 0x04, 0x00, 0xc0, 0x00, 0x20, 0x00, 0xfc, 0x03, 0x00, 0x00, 0x00, 0x40, 0x00, 0x08, 0x00
};

static const char PROGMEM spin_25_block_map[] = {
  0x30, 0x00, 0x10, 0x00, 0x00, 0x01, 0x00, 0xc0, 0x60, 0x08, 0x00, 0x00, 0x1c, 0xc0, 0x01, 0x08,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x80, 0xff, 0xff, 0x07, 0x08, 0x00, 0x80, 0x00, 0x02, 0x00,
  0x01, 0x00, 0x04, 0x00, 0x00, 0x40, 0xc0, 0xff, 0xff, 0x03, 0x00, 0x18, 0x00, 0x00, 0x00, 0x80,
  0x00, 0x40, 0x00, 0x00, 0x0c, 0x00, 0x02, 0xf0, 0x27, 0x00, 0x00, 0x00, 0x00, 0x04, 0x80, 0x00
};

static const char PROGMEM spin_26_block_map[] = {
  0x00, 0x03, 0x00, 0x01, 0x00, 0x10, 0x00, 0x00, 0x7e, 0x80, 0x00, 0x00, 0xc0, 0x01, 0x1c, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x80, 0xff, 0xff, 0x17, 0x80, 0x00, 0x00, 0x08, 0x20, 0x00,
  0x18, 0x00, 0x40, 0x00, 0x00, 0x00, 0x84, 0xff, 0xff, 0x07, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x04, 0x00, 0xc0, 0x00, 0x20, 0xc0, 0x0f, 0x02, 0x00, 0x00, 0x00, 0x40, 0x00, 0x08
};

static const char PROGMEM spin_27_block_map[] = {
  0x08, 0x30, 0x00, 0x10, 0x00, 0x00, 0x01, 0x80, 0xff, 0x00, 0x08, 0x00, 0x00, 0x1c, 0xc0, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x80, 0xff, 0xff, 0x03, 0x01, 0x08, 0x00, 0x80, 0x00, 0x02,
  0x80, 0x01, 0x00, 0x04, 0x00, 0x00, 0x80, 0xff, 0xff, 0x03, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x40, 0x00, 0x00, 0x0c, 0x00, 0x0e, 0x1f, 0x20, 0x00, 0x00, 0x00, 0x00, 0x04, 0x80
};

static const char PROGMEM spin_28_block_map[] = {
  0x80, 0x00, 0x03, 0x00, 0x01, 0x00, 0x10, 0xc0, 0xff, 0x0c, 0x80, 0x00, 0x00, 0xc0, 0x01, 0x1c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0xff, 0xff, 0x03, 0x10, 0x80, 0x00, 0x00, 0x08, 0x20,
  0x00, 0x18, 0x00, 0x40, 0x00, 0x00, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x04, 0x00, 0xc0, 0x00, 0x3c, 0x1c, 0x00, 0x02, 0x00, 0x00, 0x00, 0x40, 0x00
};

static const char PROGMEM spin_29_block_map[] = {
  0x01, 0x08, 0x30, 0x00, 0x10, 0x00, 0x00, 0xe1, 0x7f, 0xc0, 0x00, 0x08, 0x00, 0x00, 0x1c, 0xc0,
  0x02, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0xf7, 0xff, 0x09, 0x00, 0x01, 0x08, 0x00, 0x80, 0x00,
  0x00, 0x80, 0x01, 0x00, 0x04, 0x00, 0x00, 0xf7, 0xff, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00,
  0x80, 0x00, 0x00, 0x40, 0x00, 0x00, 0x0c, 0xf0, 0x72, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x04
};

static const char PROGMEM spin_0_block_list[] = {
  0x04, 0x0e, 0x04, 0x10, 0xc0, 0xc0, 0x04, 0x80, 0xc2, 0xe0, 0xe0, 0xe0, 0xe0, 0x60, 0x60, 0x60,
  0x40, 0x60, 0x60, 0x04, 0x10, 0x38, 0x10, 0x80, 0x02, 0x07, 0x02, 0xe0, 0xf0, 0xc0, 0x3f, 0xff,
  0xff, 0xe3, 0xcc, 0xde, 0x9e, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xc6, 0x80, 0x80, 0x10, 0x10, 0x03,
  0x03, 0x08, 0x07, 0x3f, 0x7f, 0x78, 0x07, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x3f, 0x1f, 0x1f, 0x7f,
  0xff, 0xff, 0xcc, 0xc0, 0xc0, 0x20, 0x20, 0x0c, 0x0c, 0x03, 0x07, 0x07, 0x03, 0x40, 0x01, 0x01,
  0x20, 0x20
};

static const char PROGMEM spin_1_block_list[] = {
  0x04, 0x0e, 0x04, 0x10, 0xc0, 0xc0, 0x04, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0x60, 0x62, 0x60, 0xa0,
  0x80, 0x80, 0x80, 0x60, 0x60, 0x04, 0x10, 0x38, 0x10, 0x80, 0x02, 0x07, 0x02, 0x80, 0xc0, 0xc5,
  0x3f, 0xff, 0xff, 0xe3, 0xee, 0xce, 0xdf, 0xdf, 0xdf, 0xef, 0xef, 0xf7, 0xf3, 0xe0, 0x80, 0x80,
  0x80, 0x10, 0x10, 0x03, 0x03, 0x08, 0x01, 0x07, 0x1f, 0x7f, 0xfc, 0xf3, 0x8f, 0x7f, 0xff, 0xff,
  0xff, 0xff, 0x1f, 0x1f, 0x0f, 0x1f, 0x7f, 0x7f, 0x70, 0xc0, 0xc0, 0x20, 0x20, 0x20, 0x0c, 0x0c,
  0x01, 0x03, 0x07, 0x07, 0x01, 0x40, 0x20
};

static const char PROGMEM spin_2_block_list[] = {
  0x10, 0x04, 0x0e, 0x04, 0x10, 0xc0, 0xc0, 0x04, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0x60, 0x20, 0xa0,
  0xc0, 0xc0, 0xc0, 0x82, 0x60, 0x60, 0x04, 0x10, 0x38, 0x10, 0x80, 0x87, 0x3f, 0x7f, 0xff, 0xe3,
  0xce, 0xdf, 0xdf, 0xdf, 0xcf, 0xef, 0xf7, 0xfb, 0xf8, 0xf8, 0xe0, 0xc0, 0x80, 0x80, 0x80, 0x10,
  0x03, 0x03, 0x08, 0x02, 0x07, 0x1f, 0x3e, 0x7d, 0xf3, 0xe7, 0xdf, 0x3f, 0xff, 0xff, 0xff, 0xff,
  0xcf, 0x07, 0x07, 0x0f, 0x1f, 0x1f, 0x19, 0xc0, 0xc0, 0x20, 0x20, 0x20, 0x01, 0x0d, 0x0c, 0x01,
  0x03, 0x03, 0x03, 0x40, 0x20
};

static const char PROGMEM spin_3_block_list[] = {
  0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x10, 0xc0, 0xc0, 0x04, 0x80, 0xc0, 0xc0, 0xe0, 0x60, 0x80,
  0xc0, 0xc0, 0xc0, 0xc0, 0x02, 0x60, 0x60, 0x04, 0x10, 0x80, 0x0e, 0x7f, 0xff, 0xff, 0xe1, 0xde,
  0xdf, 0xdf, 0xdf, 0xcf, 0xe7, 0xf3, 0xf9, 0xfc, 0xfc, 0xf8, 0xf0, 0xe0, 0x80, 0x80, 0x80, 0x10,
  0x03, 0x03, 0x08, 0x0e, 0x1e, 0x3c, 0x79, 0xf3, 0xf7, 0xef, 0xdf, 0xbf, 0x7f, 0xff, 0xff, 0xff,
  0xe7, 0xc3, 0x01, 0x03, 0x07, 0x07, 0x02, 0x01, 0xc0, 0xc0, 0x20, 0x20, 0x20, 0x01, 0x01, 0x01,
  0x0c, 0x0d, 0x01, 0x01, 0x01, 0x40, 0x20
};

static const char PROGMEM spin_4_block_list[] = {
  0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x10, 0xc0, 0xc0, 0x84, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0,
  0xc0, 0x80, 0x02, 0x60, 0x60, 0x04, 0x10, 0x80, 0x3c, 0xfe, 0xff, 0xff, 0xe3, 0x9c, 0xbf, 0x9f,
  0x9f, 0xdf, 0xe7, 0xf9, 0xfc, 0xfe, 0xfe, 0xfc, 0xf8, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x80, 0x80,
  0x10, 0xc0, 0x03, 0x03, 0x08, 0x08, 0x1d, 0x39, 0x7b, 0x77, 0xf7, 0xef, 0xef, 0xdf, 0xbf, 0x3f,
  0x7f, 0x7f, 0xff, 0xf1, 0xf0, 0x40, 0x01, 0x01, 0x01, 0xc0, 0x20, 0x20, 0x20, 0x01, 0x01, 0x01,
  0x0c, 0x0c, 0x40, 0x20
};

static const char PROGMEM spin_5_block_list[] = {
  0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x10, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0xc4, 0xc0, 0xc0, 0xc0,
  0x02, 0x60, 0x60, 0x04, 0x10, 0x80, 0x60, 0xfc, 0xfe, 0xff, 0xe3, 0xbc, 0x7f, 0x3f, 0xbf, 0x9f,
  0xc7, 0xf8, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0x7c, 0x3c, 0x78, 0x70, 0x70, 0x80, 0x80, 0x10, 0xc0,
  0xc0, 0x03, 0x03, 0x01, 0x03, 0x13, 0x7b, 0x77, 0x77, 0xf7, 0xef, 0xef, 0xef, 0xdf, 0xdf, 0xdf,
  0x3f, 0x3f, 0x3c, 0x7c, 0x38, 0x30, 0x01, 0x20, 0x20, 0x20, 0x01, 0x01, 0x01, 0x0c, 0x0c, 0x40,
  0x20
};

static const char PROGMEM spin_6_block_list[] = {
  0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x10, 0xc0, 0xc0, 0x80, 0xc0, 0x80, 0x80, 0x04, 0x02, 0x60,
  0x60, 0x04, 0x10, 0x80, 0xf8, 0xfc, 0xfe, 0xc7, 0xb8, 0x7f, 0xff, 0x7f, 0x3f, 0x87, 0xf8, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xfe, 0x1e, 0x1c, 0x1c, 0x1d, 0x0c, 0x80, 0x80, 0x10, 0xc0, 0xc0, 0x03,
  0x03, 0x01, 0x03, 0x03, 0x07, 0x07, 0x27, 0x6e, 0xee, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
  0xff, 0x1f, 0x1e, 0x1e, 0x1e, 0x1e, 0x0c, 0x01, 0x20, 0x20, 0x20, 0x0c, 0x0c, 0x40, 0x20
};

static const char PROGMEM spin_7_block_list[] = {
  0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x10, 0xc0, 0xc0, 0x80, 0x84, 0x02, 0x60, 0x60, 0x04, 0x10,
  0x10, 0x80, 0xe0, 0xfc, 0xf0, 0x0e, 0xff, 0xff, 0xff, 0x7f, 0x38, 0x87, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0x87, 0x87, 0x87, 0x80, 0x02, 0x07, 0x02, 0x80, 0x80, 0xc0, 0xc0, 0x03, 0x03,
  0x07, 0x0f, 0x0f, 0x0f, 0x1e, 0x1d, 0x1e, 0xee, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
  0x77, 0x27, 0x07, 0x07, 0x07, 0x03, 0x01, 0x20, 0x20, 0x20, 0x0c, 0x0c, 0x40, 0x20
};

static const char PROGMEM spin_8_block_list[] = {
  0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x10, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x04, 0x02, 0x60, 0x60, 0x04, 0x10, 0x10, 0x80, 0xf0, 0xe0, 0x0c, 0xfe, 0xfe, 0xfe, 0xfe,
  0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xc3, 0xc1, 0xe0, 0xe0, 0xc0, 0x02,
  0x07, 0x02, 0x80, 0x80, 0xc0, 0xc0, 0x03, 0x07, 0x1f, 0x3f, 0x3e, 0x3d, 0x3f, 0x39, 0x1c, 0xde,
  0xdf, 0xef, 0xef, 0xef, 0xf7, 0x77, 0x77, 0x7b, 0x3b, 0x13, 0x01, 0x01, 0x01, 0x01, 0x20, 0x20,
  0x01, 0x20, 0x0c, 0x0c, 0x40, 0x20
};

static const char PROGMEM spin_9_block_list[] = {
  0x04, 0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x10, 0x40, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xc0,
  0x04, 0x02, 0x60, 0x60, 0x80, 0x10, 0x10, 0x80, 0xc0, 0x30, 0x78, 0xfc, 0xfc, 0xfc, 0xf2, 0xce,
  0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xe0, 0xf0, 0xf0, 0xf8, 0x70, 0x30, 0x02, 0x07,
  0x02, 0x80, 0xc0, 0xc0, 0x0f, 0x3f, 0x7e, 0x79, 0x7f, 0x7f, 0x77, 0x79, 0x38, 0x3f, 0xdf, 0xef,
  0xef, 0xf7, 0x77, 0x7b, 0x39, 0x1d, 0x1c, 0x08, 0x01, 0x20, 0x20, 0x01, 0x20, 0x0c, 0x0c, 0x40,
  0x20
};

static const char PROGMEM spin_10_block_list[] = {
  0x04, 0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x10, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xf0, 0x60, 0x04,
  0x02, 0x60, 0x60, 0x80, 0x10, 0x10, 0x80, 0xf0, 0xf0, 0xf0, 0xf0, 0xe4, 0xce, 0xbf, 0x7f, 0xff,
  0xff, 0xff, 0xff, 0xfc, 0xf8, 0xf0, 0xf8, 0xfc, 0x7c, 0x3c, 0x1c, 0x02, 0x07, 0x02, 0x80, 0xc0,
  0xc0, 0x17, 0x3e, 0x79, 0xf3, 0xf7, 0xff, 0xff, 0xf7, 0xf0, 0x7f, 0x3f, 0xdf, 0xef, 0xf7, 0xf3,
  0x79, 0x3c, 0x1e, 0x0f, 0x07, 0x08, 0x01, 0x20, 0x20, 0x20, 0x01, 0x01, 0x20, 0x0c, 0x0c, 0x40
};

static const char PROGMEM spin_11_block_list[] = {
  0x60, 0x60, 0x04, 0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x80, 0x90, 0xc0, 0xe0, 0xf0, 0x60, 0x40,
  0x40, 0x04, 0x02, 0x80, 0x10, 0x10, 0x80, 0x80, 0xc0, 0xe0, 0xe0, 0xd8, 0xdc, 0xbe, 0x7f, 0x7f,
  0xff, 0xff, 0xff, 0xfc, 0xfc, 0xf8, 0xfc, 0x7f, 0x3f, 0xcf, 0x86, 0x02, 0x07, 0x02, 0x80, 0xc0,
  0xc0, 0x08, 0x3b, 0x73, 0xf7, 0xef, 0xdf, 0xff, 0xff, 0xe0, 0xf3, 0x7f, 0x3f, 0x5f, 0xe7, 0xf3,
  0x7d, 0x3e, 0x1f, 0x07, 0x03, 0x08, 0x01, 0x20, 0x20, 0x21, 0x03, 0x03, 0x03, 0x01, 0x01, 0x20,
  0x0c, 0x0c, 0x40
};

static const char PROGMEM spin_12_block_list[] = {
  0x60, 0x60, 0x04, 0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x80, 0x80, 0xf0, 0xf0, 0x60, 0x10, 0x80,
  0x80, 0x80, 0xc0, 0xc0, 0x04, 0x02, 0x80, 0x80, 0x10, 0x10, 0x80, 0x80, 0x80, 0xb8, 0x7e, 0x7f,
  0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0x3f, 0xc7, 0xe0, 0xe0, 0x02, 0x07, 0x02,
  0xc0, 0xc0, 0x27, 0x6f, 0xef, 0xdf, 0xdf, 0xbf, 0xde, 0xdc, 0xc1, 0xff, 0xff, 0x3f, 0x0f, 0x73,
  0x7c, 0x7f, 0x1f, 0x07, 0x01, 0x08, 0x01, 0x20, 0x20, 0x01, 0x01, 0x03, 0x03, 0x03, 0x23, 0x03,
  0x01, 0x01, 0x20, 0x0c, 0x0c, 0x40
};

static const char PROGMEM spin_13_block_list[] = {
  0x60, 0x60, 0x04, 0x10, 0x38, 0x10, 0x04, 0x0e, 0xe4, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x10,
  0xc0, 0xc0, 0x04, 0x02, 0x80, 0x80, 0x10, 0x10, 0x60, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc,
  0xfc, 0xfe, 0xff, 0xff, 0x3f, 0xc1, 0xf8, 0xf8, 0x20, 0x02, 0x07, 0x02, 0xc0, 0xc0, 0x0c, 0x1e,
  0xbf, 0xbe, 0xbe, 0xbe, 0xbe, 0xfc, 0xb1, 0xc7, 0xff, 0xff, 0x7f, 0x07, 0x38, 0x3f, 0x1f, 0x07,
  0x03, 0x03, 0x08, 0x01, 0x20, 0x20, 0x01, 0x01, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x03, 0x01,
  0x20, 0x20, 0x0c, 0x0c, 0x40
};

static const char PROGMEM spin_14_block_list[] = {
  0x60, 0x60, 0x04, 0x10, 0x38, 0x10, 0xc0, 0xc0, 0xc0, 0x04, 0x0e, 0xc4, 0xe0, 0xe0, 0xc0, 0x10,
  0xc0, 0xc0, 0x04, 0x02, 0x80, 0x80, 0x10, 0xfc, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xfc, 0xff,
  0xff, 0xff, 0xff, 0xfc, 0xfc, 0xf8, 0x02, 0x07, 0x02, 0xc0, 0xc0, 0x38, 0x7d, 0x7d, 0x7d, 0x7d,
  0x7d, 0x7d, 0x79, 0xb3, 0xc7, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0x0f, 0x03, 0x03, 0x08, 0x01, 0x40,
  0x20, 0x01, 0x23, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x20, 0x20, 0x0c, 0x0c
};

static const char PROGMEM spin_15_block_list[] = {
  0x60, 0x60, 0x04, 0x10, 0x38, 0x90, 0x80, 0xc0, 0xe0, 0xe0, 0xc0, 0x04, 0x0e, 0x04, 0x10, 0xc0,
  0xc0, 0x04, 0x02, 0x80, 0x80, 0x10, 0x33, 0xff, 0xff, 0xfe, 0xf8, 0xf8, 0xfc, 0xfd, 0xff, 0xff,
  0xff, 0xff, 0xe0, 0x1e, 0xfe, 0xfc, 0xe0, 0x02, 0x07, 0x02, 0x01, 0xc0, 0xc0, 0x63, 0xfb, 0xfb,
  0xfb, 0xfb, 0xfb, 0x79, 0x7b, 0x33, 0xc7, 0xff, 0xff, 0xfc, 0x03, 0x0f, 0x07, 0x03, 0x03, 0x08,
  0x40, 0x20, 0x02, 0x06, 0x06, 0x26, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x20, 0x20, 0x0c, 0x0c
};

static const char PROGMEM spin_16_block_list[] = {
  0x02, 0x60, 0x60, 0x04, 0x10, 0x18, 0x80, 0xe0, 0xe0, 0xc0, 0x80, 0x04, 0x0e, 0x04, 0x10, 0xc0,
  0xc0, 0x04, 0x80, 0x80, 0x10, 0x0e, 0xfe, 0xfe, 0xf8, 0xf0, 0xf8, 0xf8, 0xff, 0xff, 0xff, 0xff,
  0xfe, 0xf1, 0xcf, 0x3f, 0xfe, 0xf8, 0xe0, 0x80, 0x02, 0x07, 0x02, 0x01, 0xc0, 0xc0, 0x01, 0x07,
  0xcf, 0xef, 0xf7, 0xf7, 0xfb, 0xfb, 0xfb, 0x73, 0x77, 0xc7, 0xff, 0xff, 0xfc, 0xa3, 0x03, 0x01,
  0x03, 0x03, 0x08, 0x40, 0x20, 0x01, 0x01, 0x01, 0x05, 0x06, 0x06, 0x06, 0x07, 0x27, 0x03, 0x03,
  0x03, 0x20, 0x20, 0x0c, 0x0c
};

static const char PROGMEM spin_17_block_list[] = {
  0x02, 0x60, 0x60, 0x04, 0xc0, 0xc0, 0xc0, 0x80, 0x10, 0x38, 0x90, 0x80, 0x04, 0x0e, 0x04, 0x10,
  0xc0, 0xc0, 0x04, 0x80, 0x80, 0x10, 0x18, 0xf8, 0xf8, 0xf0, 0xe0, 0xe0, 0xf3, 0xff, 0xff, 0xff,
  0xff, 0xfc, 0xfb, 0xe7, 0xcf, 0xbe, 0x7c, 0xf8, 0xe0, 0x40, 0x80, 0x02, 0x07, 0x02, 0x01, 0x01,
  0x03, 0xc7, 0xdf, 0x1f, 0xdf, 0xef, 0xf7, 0xf3, 0xfb, 0xfb, 0xfb, 0x73, 0xc7, 0xff, 0xfe, 0xfc,
  0xe1, 0x03, 0x03, 0x08, 0x0c, 0x40, 0x20, 0x01, 0x03, 0x03, 0x03, 0x05, 0x04, 0x06, 0x07, 0x07,
  0x03, 0x03, 0x01, 0x20, 0x20, 0x20, 0x0c
};

static const char PROGMEM spin_18_block_list[] = {
  0x02, 0x60, 0x60, 0x04, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x10, 0x38, 0x10, 0x04, 0x0e,
  0x04, 0x10, 0xc0, 0xc0, 0x04, 0x02, 0x80, 0x80, 0x40, 0xf0, 0xe0, 0xc0, 0x80, 0xc3, 0xe7, 0xff,
  0xff, 0xff, 0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xcf, 0x9e, 0x3c, 0x78, 0x70, 0x10, 0x80, 0x02, 0x07,
  0x01, 0x01, 0x07, 0x0f, 0x1f, 0x3f, 0x3f, 0x9f, 0xcf, 0xe7, 0xf3, 0xfb, 0xfb, 0xfb, 0x7b, 0x87,
  0xff, 0xff, 0xfe, 0x70, 0x03, 0x03, 0x08, 0x0c, 0x0c, 0x40, 0x20, 0x03, 0x03, 0x03, 0x03, 0x01,
  0x06, 0x07, 0x03, 0x03, 0x01, 0x20, 0x20, 0x20
};

static const char PROGMEM spin_19_block_list[] = {
  0x02, 0x60, 0x60, 0x04, 0x80, 0x80, 0x80, 0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x10, 0xc0, 0xc0,
  0x04, 0x02, 0x07, 0x02, 0x80, 0x80, 0x80, 0x80, 0x02, 0x0f, 0x8f, 0xff, 0xfe, 0xfe, 0xfc, 0xfd,
  0xfb, 0xf7, 0xf7, 0xef, 0xee, 0xde, 0x9c, 0xb8, 0x10, 0x10, 0x80, 0x01, 0x01, 0x03, 0x07, 0x0f,
  0x1f, 0x1f, 0x3f, 0x7f, 0x7f, 0x3f, 0x9f, 0xe7, 0xfb, 0xf9, 0xf9, 0xfd, 0x39, 0xc7, 0xff, 0xff,
  0x7f, 0x3c, 0x03, 0x03, 0x08, 0x0c, 0x0c, 0x40, 0x20, 0x01, 0x03, 0x07, 0x03, 0x03, 0x03, 0x03,
  0x01, 0x01, 0x20, 0x20, 0x20
};

static const char PROGMEM spin_20_block_list[] = {
  0x02, 0x60, 0x60, 0x04, 0x80, 0x80, 0x80, 0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x10, 0xc0, 0xc0,
  0x04, 0x02, 0x07, 0x02, 0x80, 0x80, 0x0c, 0x1c, 0x3e, 0x3c, 0xfc, 0xfc, 0xfb, 0xfb, 0xfb, 0xf7,
  0xf7, 0xf7, 0xef, 0xee, 0xee, 0xde, 0xc8, 0xc0, 0x80, 0x10, 0x80, 0x01, 0x0e, 0x0e, 0x1e, 0x3c,
  0x3e, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0x1f, 0xe3, 0xf9, 0xfd, 0xfc, 0xfe, 0x3d, 0xc7, 0xff, 0x7f,
  0x3f, 0x06, 0x03, 0x03, 0x08, 0x0c, 0x0c, 0x40, 0x20, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01,
  0x20, 0x20, 0x20
};

static const char PROGMEM spin_21_block_list[] = {
  0x04, 0x02, 0x60, 0x60, 0x04, 0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x10, 0xc0, 0xc0, 0x02, 0x07,
  0x02, 0x80, 0x30, 0x78, 0x78, 0x78, 0x78, 0xf8, 0xff, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7,
  0x77, 0x76, 0xe4, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x10, 0x80, 0x08, 0x01, 0x30, 0x38, 0x38, 0x38,
  0x78, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xe1, 0xfc, 0xfe, 0xff, 0xfe, 0x1d, 0xe3, 0x7f,
  0x3f, 0xdf, 0xc0, 0x03, 0x03, 0x0c, 0x0c, 0x40, 0x20, 0x01, 0x01, 0x03, 0x01, 0x20, 0x20, 0x20
};

static const char PROGMEM spin_22_block_list[] = {
  0x04, 0x02, 0x60, 0x60, 0x04, 0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x10, 0xc0, 0xc0, 0x02, 0x07,
  0x02, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe4, 0xee, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7,
  0x77, 0x78, 0xb8, 0x78, 0xf0, 0xf0, 0xf0, 0xe0, 0x10, 0x80, 0x08, 0x01, 0x01, 0xe1, 0xe1, 0xe1,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe1, 0x1c, 0xfe, 0xff, 0xff, 0xff, 0x70, 0x0f, 0x3f,
  0x07, 0xc0, 0xc0, 0x03, 0x03, 0x20, 0x0c, 0x0c, 0x40, 0x20, 0x01, 0x01, 0x20, 0x20
};

static const char PROGMEM spin_23_block_list[] = {
  0x04, 0x02, 0x60, 0x60, 0x80, 0x04, 0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x10, 0xc0, 0xc0, 0x02,
  0x07, 0x02, 0x80, 0x80, 0x80, 0x80, 0xc8, 0xdc, 0xde, 0xee, 0xee, 0xef, 0xf7, 0xf7, 0xf7, 0xfb,
  0x7b, 0x38, 0x9c, 0xfc, 0xbc, 0x7c, 0xfc, 0xf8, 0xe0, 0x10, 0x10, 0x80, 0x08, 0x01, 0x03, 0x07,
  0x07, 0x83, 0xc3, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0x7f, 0x7f, 0x7f,
  0x7f, 0x30, 0x07, 0x0f, 0xc0, 0xc0, 0x03, 0x03, 0x20, 0x0c, 0x0c, 0x40, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x21, 0x01, 0x01, 0x20, 0x20
};

static const char PROGMEM spin_24_block_list[] = {
  0xc0, 0xc0, 0x04, 0x02, 0x60, 0x60, 0x80, 0x04, 0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x10, 0x02,
  0x07, 0x02, 0x38, 0xb8, 0x9c, 0xde, 0xee, 0xef, 0xf7, 0xf7, 0xfb, 0xfc, 0x1c, 0x9e, 0xee, 0xfe,
  0xfe, 0x9e, 0x7e, 0xfc, 0xf0, 0x10, 0x10, 0x80, 0x08, 0x01, 0x0c, 0x0e, 0x1f, 0x0f, 0x0f, 0x07,
  0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x73, 0x4f, 0x3f, 0x3f, 0x3f, 0x1e, 0x0c, 0x03,
  0xc0, 0xc0, 0x03, 0x03, 0x20, 0x0c, 0x0c, 0x40, 0x03, 0x07, 0x03, 0x03, 0x03, 0x03, 0x01, 0x20,
  0x20, 0x20
};

static const char PROGMEM spin_25_block_list[] = {
  0xc0, 0xc0, 0x04, 0x02, 0x60, 0x60, 0x80, 0x80, 0x04, 0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x10,
  0x02, 0x07, 0x02, 0xe0, 0xf0, 0x78, 0x3c, 0x9e, 0xcf, 0xef, 0xf7, 0xfb, 0xfc, 0xfe, 0x0f, 0xef,
  0xff, 0xff, 0xef, 0xcf, 0x9e, 0x7c, 0xe8, 0x10, 0x10, 0x80, 0x03, 0x08, 0x01, 0x38, 0x3c, 0x3e,
  0x3f, 0x1f, 0x0f, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfd, 0x73, 0x27, 0x0f, 0x0f, 0x0f,
  0x0f, 0xc0, 0xc0, 0x03, 0x20, 0x0c, 0x0c, 0x40, 0x06, 0x0f, 0x07, 0x03, 0x03, 0x01, 0x01, 0x20,
  0x20, 0x20
};

static const char PROGMEM spin_26_block_list[] = {
  0xc0, 0xc0, 0x04, 0x02, 0x80, 0xa0, 0xc0, 0xc0, 0xc0, 0x80, 0x04, 0x10, 0x38, 0x10, 0x04, 0x0e,
  0x04, 0x10, 0x02, 0x07, 0x02, 0xc0, 0xe0, 0xf8, 0x7c, 0xbe, 0xcf, 0xe7, 0xfa, 0xfc, 0xfe, 0xcf,
  0x07, 0xff, 0xff, 0xfb, 0xf7, 0xef, 0xce, 0xdc, 0x10, 0x80, 0x10, 0x10, 0x80, 0x03, 0x03, 0x08,
  0x01, 0x61, 0xf3, 0xfc, 0xfe, 0x3f, 0x1f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0x7d, 0x3b,
  0x1b, 0x07, 0x07, 0x03, 0x01, 0xc0, 0xc0, 0x20, 0x0c, 0x0c, 0x40, 0x06, 0x0f, 0x07, 0x03, 0x01,
  0x01, 0x20, 0x20, 0x20
};

static const char PROGMEM spin_27_block_list[] = {
  0x10, 0xc0, 0xc0, 0x04, 0x02, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xa0, 0xa0, 0x04, 0x10,
  0x38, 0x10, 0x04, 0x0e, 0x04, 0x02, 0x07, 0x02, 0x80, 0xe0, 0xf8, 0xfe, 0x3e, 0xce, 0xf0, 0xfc,
  0xff, 0xff, 0x83, 0x3b, 0x7b, 0xfd, 0xfb, 0xfb, 0xf7, 0xf6, 0xe4, 0x80, 0x10, 0x10, 0x80, 0x03,
  0x03, 0x08, 0x07, 0x07, 0xe3, 0xfc, 0xff, 0xff, 0x3f, 0x3f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xfe,
  0x7e, 0x1d, 0x01, 0x01, 0x01, 0xc0, 0xc0, 0x20, 0x0c, 0x0c, 0x41, 0x01, 0x01, 0x06, 0x0f, 0x0f,
  0x01, 0x01, 0x20, 0x20, 0x20
};

static const char PROGMEM spin_28_block_list[] = {
  0x10, 0xc0, 0xc0, 0x04, 0x02, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x60,
  0x60, 0x04, 0x10, 0x38, 0x10, 0x04, 0x0e, 0x04, 0x02, 0x07, 0x02, 0xe0, 0xf8, 0xfc, 0x1c, 0xe0,
  0xfe, 0xff, 0xff, 0xe3, 0x8d, 0x3f, 0x7d, 0x7d, 0x7d, 0x7d, 0xfd, 0x78, 0x30, 0x80, 0x10, 0x10,
  0x80, 0x03, 0x03, 0x08, 0x04, 0x1f, 0x1f, 0x83, 0xfc, 0xff, 0xff, 0x7f, 0x3f, 0x3f, 0x3f, 0xff,
  0xff, 0xff, 0xff, 0x7f, 0x06, 0xc0, 0xc0, 0x20, 0x20, 0x0c, 0x0c, 0x01, 0x03, 0x03, 0x43, 0x07,
  0x07, 0x07, 0x20, 0x20
};

static const char PROGMEM spin_29_block_list[] = {
  0x04, 0x10, 0xc0, 0xc0, 0x04, 0x02, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80,
  0x60, 0x60, 0x04, 0x10, 0x38, 0x10, 0x04, 0x0e, 0x80, 0x02, 0x07, 0x02, 0xf0, 0xf8, 0xf8, 0xff,
  0xff, 0xff, 0xe3, 0xcd, 0x9e, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0x1c, 0x80, 0x80, 0x10, 0x10,
  0x03, 0x03, 0x08, 0x1f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff,
  0xff, 0x3f, 0xc0, 0xc0, 0x20, 0x20, 0x0c, 0x0c, 0x03, 0x07, 0x07, 0x03, 0x40, 0x03, 0x03, 0x03,
  0x20, 0x20
};

static const char* idle_frames [NUM_IDLE_FRAMES] = {
  spin_29_block_list,
  spin_28_block_list,
  spin_27_block_list,
  spin_26_block_list,
  spin_25_block_list,
  spin_24_block_list,
  spin_23_block_list,
  spin_22_block_list,
  spin_21_block_list,
  spin_20_block_list,
  spin_19_block_list,
  spin_18_block_list,
  spin_17_block_list,
  spin_16_block_list,
  spin_15_block_list,
  spin_14_block_list,
  spin_13_block_list,
  spin_12_block_list,
  spin_11_block_list,
  spin_10_block_list,
  spin_9_block_list,
  spin_8_block_list,
  spin_7_block_list,
  spin_6_block_list,
  spin_5_block_list,
  spin_4_block_list,
  spin_3_block_list,
  spin_2_block_list,
  spin_1_block_list,
  spin_0_block_list,
};

static const char* idle_block_map [NUM_IDLE_FRAMES] = {
  spin_29_block_map,
  spin_28_block_map,
  spin_27_block_map,
  spin_26_block_map,
  spin_25_block_map,
  spin_24_block_map,
  spin_23_block_map,
  spin_22_block_map,
  spin_21_block_map,
  spin_20_block_map,
  spin_19_block_map,
  spin_18_block_map,
  spin_17_block_map,
  spin_16_block_map,
  spin_15_block_map,
  spin_14_block_map,
  spin_13_block_map,
  spin_12_block_map,
  spin_11_block_map,
  spin_10_block_map,
  spin_9_block_map,
  spin_8_block_map,
  spin_7_block_map,
  spin_6_block_map,
  spin_5_block_map,
  spin_4_block_map,
  spin_3_block_map,
  spin_2_block_map,
  spin_1_block_map,
  spin_0_block_map,
};

static const char* faster_frames [NUM_FAST_FRAMES] = {
  spin_28_block_list,
  spin_26_block_list,
  spin_24_block_list,
  spin_22_block_list,
  spin_20_block_list,
  spin_18_block_list,
  spin_16_block_list,
  spin_14_block_list,
  spin_12_block_list,
  spin_10_block_list,
  spin_8_block_list,
  spin_6_block_list,
  spin_4_block_list,
  spin_2_block_list,
  spin_0_block_list,
};

static const char* faster_block_map [NUM_FAST_FRAMES] = {
  spin_28_block_map,
  spin_26_block_map,
  spin_24_block_map,
  spin_22_block_map,
  spin_20_block_map,
  spin_18_block_map,
  spin_16_block_map,
  spin_14_block_map,
  spin_12_block_map,
  spin_10_block_map,
  spin_8_block_map,
  spin_6_block_map,
  spin_4_block_map,
  spin_2_block_map,
  spin_0_block_map,
};
#endif //USE_OLED_BITMAP_COMPRESSION
#endif //OLED_ENABLE