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

// #ifdef CONSOLE_ENABLE
// #include "print.h"
// #endif
//
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     #ifdef CONSOLE_ENABLE
//         const bool is_combo = record->event.type == COMBO_EVENT;
//         uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
//              keycode,
//              is_combo ? 254 : record->event.key.row,
//              is_combo ? 254 : record->event.key.col,
//              get_highest_layer(layer_state),
//              record->event.pressed,
//              get_mods(),
//              get_oneshot_mods(),
//              record->tap.count
//              );
//     #endif
//     switch (keycode) {
//     //...
//     }
//     return true;
// }

enum layers {
  _BASELAYER,
  _CTL,
  _ALT,
  _CTL_ALT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASELAYER] = LAYOUT(
KC_NO, KC_ESC, KC_GRAVE, KC_1,	  KC_2,    KC_3,    KC_4,    KC_5,       KC_6,       KC_7,    KC_8,     KC_9,    KC_0,    KC_MINUS, KC_EQUAL, QK_BOOT,
KC_NO, KC_F3,  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,       KC_U,    KC_I,     KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,
KC_NO, KC_NO,  KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,       KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,  KC_NO,    KC_PSCR,
KC_NO, KC_NO,  MO(_CTL), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,       KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_NO,  KC_NO,  KC_NO,
KC_NO, KC_NO,  KC_NO,    KC_LGUI, KC_LSFT, MO(_ALT), KC_SPC,  QK_BOOT,    KC_ENTER,  KC_SPC, KC_LSFT, KC_PGUP, KC_PGDN, KC_NO,  KC_NO,    KC_NO,
KC_NO, KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_END,     KC_BSPC,    KC_DEL, KC_NO,    KC_NO,   KC_NO,   KC_NO, KC_NO,    KC_NO
    ),
    [_CTL] = LAYOUT(
KC_NO, KC_NO, KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO,  KC_NO,        KC_NO,       KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,
KC_NO, KC_NO, C(KC_TAB), C(KC_Q), C(KC_W), C(KC_E), C(KC_R), C(KC_T),         C(KC_Y), C(KC_U),    C(KC_I),     C(KC_O),  C(KC_P), KC_NO, KC_NO, KC_NO,
KC_NO, KC_NO, KC_NO,     C(KC_A), C(KC_S), C(KC_D), C(KC_F), C(KC_G),         C(KC_H), C(KC_J), C(KC_K),    C(KC_L),    C(KC_SCLN),   KC_NO, KC_NO, KC_NO,
KC_NO, KC_NO, _______,     C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_B),         C(KC_SLSH), C(KC_LEFT), C(KC_UP), C(KC_DOWN), C(KC_RIGHT),   KC_NO, KC_NO, KC_NO,
KC_NO, KC_NO, KC_NO, C(KC_LGUI), C(KC_LSFT), _______, C(KC_SPC), KC_NO,  C(KC_ENTER), C(KC_SPC), KC_LSFT, C(KC_PGUP),    C(KC_PGDN),   KC_NO, KC_NO, KC_NO,
KC_NO, KC_NO, KC_NO,     KC_NO,   KC_NO,   KC_NO,  C(KC_HOME), C(KC_END),     KC_BSPC, KC_DEL,     KC_NO,       KC_NO,    KC_NO,   KC_NO, KC_NO, KC_NO
    ),
    [_ALT] = LAYOUT(
    KC_NO, KC_NO, KC_NO,        KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, A(KC_TAB),    A(KC_Q), KC_7,   KC_8, KC_9, A(KC_T),         KC_LBRC,  KC_MINUS,     KC_BSLS,     S(KC_EQUAL),    KC_RBRC, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO,        A(KC_A), KC_4,  KC_5, KC_6, A(KC_G),         S(KC_9),  S(KC_MINUS),      KC_QUOT,     KC_EQUAL,    S(KC_0), KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, _______, A(KC_Z), KC_1,	KC_2, KC_3, A(KC_B), A(KC_LEFT),   KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT,KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_0,  A(KC_LSFT), _______, A(KC_SPC), KC_NO,                A(KC_ENTER), A(KC_SPC), A(KC_LSFT), S(KC_9), S(KC_0), KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, A(KC_HOME), A(KC_END),  KC_BSPC, KC_DEL, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [_CTL_ALT] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO,         KC_NO,         KC_NO,           KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, C(A(KC_T)),     KC_NO, KC_NO,         KC_NO,         KC_NO,           KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO,         KC_NO,         KC_NO,           KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, C(A(KC_LEFT)), C(A(KC_UP)), C(A(KC_DOWN)), C(A(KC_RIGHT)), KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, _______, KC_NO, KC_NO,   KC_NO, KC_NO,         KC_LSFT,         KC_NO,           KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO,       KC_NO,         KC_NO,           KC_NO, KC_NO, KC_NO, KC_NO
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _CTL, _ALT, _CTL_ALT);
}
