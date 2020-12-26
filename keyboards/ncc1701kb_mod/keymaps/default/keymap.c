#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-----------------------.
 * |   <<  |  MUTE |  >>   |  ENCODER - PRESS (MUTE) / KNOB (VOLUME CONTROL)
 * |-------+-------+-------|
 * |  STOP |  PLAY | MEDIA | 
 * |-------+-------+-------|
 * | CALC  | MAIL  | PC/FN | 
 * `-----------------------'
 */
[0] = LAYOUT(
  KC_MPRV,       KC_MUTE,      KC_MNXT,
  KC_MSTP,       KC_MPLY,      KC_MSEL,
  KC_CALC,       KC_MAIL,      LT(1, KC_MYCM)
),

/* LAYER 1
 * ,--------------------------.
 * |RGB TOG |RGB_MOD |  VA +  |
 * |--------+--------+--------|
 * |  HU +  |  SA +  |  VA -  |
 * |--------+--------+--------|
 * |  HU -  |  SA -  |  TRNS  |
 * `--------------------------'
 */
[1] = LAYOUT(
  RGB_TOG, RGB_MOD, RGB_VAI,
  RGB_HUI, RGB_SAI, RGB_VAD,
  RGB_HUD, RGB_SAD, KC_TRNS
)

};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
	if (IS_LAYER_ON(1)) {
      if (clockwise) {
		rgblight_increase_hue_noeeprom();
      } else {
        rgblight_decrease_hue_noeeprom();
      }
    } else {
      tap_code((clockwise == true) ? KC_VOLU : KC_VOLD);
    }
  }
}