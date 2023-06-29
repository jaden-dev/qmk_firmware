/*
Copyright 2023
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/  

#include QMK_KEYBOARD_H

#include "quantum.h"

enum custom_keycodes {
    SAVE_CLOSE_MACRO = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(OSL(2),     OSL(1),     SAVE_CLOSE_MACRO,
               MEH(KC_0),  KC_MPLY,    KC_MNXT,
               KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN1),

  [1] = LAYOUT(MEH(KC_1), MEH(KC_2), MEH(KC_3),
               MEH(KC_4), MEH(KC_5), MEH(KC_6),
               MEH(KC_7), MEH(KC_8), TO(0)),

  [2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS,
               KC_TRNS, QK_BOOT, KC_TRNS,
               KC_TRNS, KC_TRNS, TO(0)),


  [3] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS,
               KC_TRNS, KC_TRNS, KC_TRNS,
               KC_TRNS, KC_TRNS, TO(0)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SAVE_CLOSE_MACRO:
            // When the keycode SAVE_MACRO is pressed down.
            if (record->event.pressed) {
                // Sends LCtrl+s
                tap_code16(LCTL(KC_S));
                wait_ms(500);
                // Sends Enter twice to overwrite the file if it exists.
                tap_code(KC_ENTER);
                wait_ms(500);
                tap_code(KC_ENTER);
                wait_ms(500);
                // Close tab
                tap_code16(LCTL(KC_W));
            }
            return false; // Skip all further processing of this key
        default:
            return true; // Process all other keycodes normally
    }
}
