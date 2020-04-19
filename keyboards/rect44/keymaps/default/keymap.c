/* Copyright 2020 koshinoya
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
    _FN2
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    RGBRST = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC,          KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,    KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    KC_MINS, KC_BSPC,
        LCTL_T(KC_TAB),  KC_A,    KC_S,    KC_D,  KC_F,  KC_G,    KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN, KC_NO,   KC_ENT,
        KC_LSFT, KC_NO,  LT(_FN2,KC_Z),    KC_X,  KC_C,  KC_V,    KC_B,  KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_NO,   RSFT_T(KC_SLSH),
        LCTL_T(KC_DEL),  KC_LGUI, KC_LALT, KC_NO, LT(_FN,KC_SPC), KC_NO, KC_NO, RALT_T(KC_LEFT),  KC_UP,   KC_DOWN, KC_RGHT
    ),
    [_FN] = LAYOUT(
        KC_GRV,         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,  KC_F12,
        KC_TRNS,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_NO,   KC_EQL,
        KC_TRNS, KC_NO, KC_APP,  KC_BSLS, KC_COLN, KC_MINS, KC_LBRC, KC_RBRC, KC_QUOT, KC_TRNS, KC_TRNS, KC_NO,  KC_TRNS,
        KC_INS,         KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_HOME, KC_PGUP, KC_PGDN, KC_END
    ),
    [_FN2] = LAYOUT(
        KC_NO,    KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_NO,
        KC_CAPS,  KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_TRNS,  KC_NO,   KC_TRNS, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_LCTL,  KC_TRNS, KC_TRNS, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGBRST:
          #ifdef RGBLIGHT_ENABLE
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
            }
          #endif
        break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
