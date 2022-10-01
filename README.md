# Modifed QMK for the NIBBLE keyboard
This project is a full build of the NIBBLE keyboard kit with the additional OLED screen.

For information about the QMK software and a tutorial for flashing your own keyboard check out QMK's website here: https://docs.qmk.fm/#/
# OLED Animations
**Bongocat:**

Bongocat is the premade OLED keymap animation available in the NIBBLE keyboards keymaps but the keymap and configurations have been changed to fit my preferences and keyboard layout.

The animation displays a WPM counter and a Bongocat that will tap along to key inputs. The faster you type the faster he will tap the table in front of him.

**Ejected Among Us:**

This animation of my own design displays a spinning among us character floating through space. As you type he will begin to accelerate, spinning faster along with your inputs.

The animation itself is 30 fps for the first 30 wpm but after 30 wpm the animation drops to 15 fps to allow for even faster spinning. Lowering the minimum frame duration causes the animation to tear, and increasing the wpm before switching to lower fps will make the transition less smooth; however feel free to adjust these numbers to your desire.
This project makes use of squeeze-o to compress the individual frames and save enough space to make it possible to have all 30 frames. The repo is here: https://github.com/nullbitsco/squeez-o

There are two available animations for the spinning among us; clockwise and counter clockwise. This comes down to preference and there is no difference other than which direction he spins.

**Clockwise:**

![Clockwise](https://github.com/swimwater/bennibble/blob/master/Among%20Us%20Animation/clockwise.gif)

**Counter Clockwise:**

![Counter Clockwise](https://github.com/swimwater/bennibble/blob/master/Among%20Us%20Animation/counter_clockwise.gif)
