/* Copyright 2024 Matt Flax (@flatmax)
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

#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
        const bool is_combo = record->event.type == COMBO_EVENT;
        uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
             keycode,
             is_combo ? 254 : record->event.key.row,
             is_combo ? 254 : record->event.key.col,
             get_highest_layer(layer_state),
             record->event.pressed,
             get_mods(),
             get_oneshot_mods(),
             record->tap.count
             );
    #endif
    switch (keycode) {
    //...
    }
    return true;
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
// #endif
//   return true;
// }

enum layers {
  _BASELAYER,
  // _CTL,
  _LAYER1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASELAYER] = LAYOUT(
KC_GRAVE, KC_Q,     KC_W,    KC_E,    KC_R,        KC_T,                KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,    KC_ESC,
KC_TAB,   KC_A,     KC_S,    KC_D,    KC_F,        KC_G,                KC_H,       KC_J,    KC_K,    KC_L,    KC_SCLN, KC_PSCR,
KC_LCTL,  KC_Z,     KC_X,    KC_C,    KC_V,        KC_B,                KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_F3,
KC_NO,    KC_LALT,  KC_LGUI, KC_LSFT, MO(_LAYER1), KC_BSPC,             KC_ENTER,   KC_SPC,  KC_PGUP, KC_PGDN, KC_LSFT, KC_NO
    ),
    [_LAYER1] = LAYOUT(
QK_BOOT, _______, KC_7,    KC_8,  KC_9,     _______,        S(KC_LBRC),  KC_MINUS,    KC_BSLS, S(KC_EQUAL), S(KC_RBRC), QK_BOOT,
_______, _______, KC_4,    KC_5,  KC_6,     KC_HOME,        KC_LBRC,     S(KC_MINUS), KC_QUOT, KC_EQUAL,    KC_RBRC,    KC_NO,
_______, _______, KC_1,	   KC_2,  KC_3,     KC_END,         _______,     KC_LEFT,     KC_UP,   KC_DOWN,     KC_RIGHT,   KC_F2,
KC_NO,   _______, _______, KC_0,  _______,  KC_DEL,         _______,     _______,     S(KC_9), S(KC_0),     _______,    KC_NO
    )
};
