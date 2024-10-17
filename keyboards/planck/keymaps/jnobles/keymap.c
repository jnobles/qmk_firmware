/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _PLOVER,
  _ADJUST
};

enum _keycodes {
    PLOVER = SAFE_RANGE,
    EXT_PLV
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn   | Ctrl | GUI  | Alt  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,         KC_T,    KC_Y,    KC_U,         KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,        KC_A,    KC_S,    KC_D,    KC_F,         KC_G,    KC_H,    KC_J,         KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,         KC_B,    KC_N,    KC_M,         KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    MO(_FUNCTION), KC_LCTL, KC_LGUI, KC_LALT, MO(_LOWER),   KC_SPC,  KC_SPC,  TT(_RAISE),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |   =  |   +  |   [  |   ]  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | XXXX | XXXX | XXXX | XXXX | XXXX |   _  |   -  |   |  |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX |      |      |      |      |      |      |      | XXXX | XXXX | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_MINS, KC_PIPE, KC_LCBR, KC_RCBR, _______,
    XXXXXXX, _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  | XXXX | XXXX | XXXX | XXXX | XXXX |   *  |   4  |   5  |   6  |   -  | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | XXXX | XXXX | XXXX | XXXX | XXXX |   /  |   1  |   2  |   3  |   +  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX |      |      |      |      |      |      |      |   0  |   .  |   =  | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_MINS, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, KC_1,    KC_2,    KC_3,    KC_PLUS, KC_ENT,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_EQL,  XXXXXXX
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |PrtScr| F9   | F10  | F11  | F12  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | F5   | F6   | F7   | F8   | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | F1   | F2   | F3   | F4   | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | XXXX |      |      | XXXX | End |Pg Dn |Pg Up | Home  |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_planck_grid(
    KC_PSCR, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, XXXXXXX, _______,  _______, XXXXXXX, KC_END,  KC_PGDN, KC_PGUP, KC_HOME
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | XXXX |Clicky|Tone +|Tone -|Tone 0| XXXX | XXXX | XXXX | XXXX | XXXX |Reboot|Plover|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX |Rec 1 |Rec 2 |EndRec| XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |Loader| XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX |Play 1|Play 2| XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX |      | XXXX | XXXX |      | XXXX | XXXX | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    XXXXXXX, CK_TOGG, CK_UP,   CK_DOWN, CK_RST,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, QK_RBT,  PLOVER,
    XXXXXXX, DM_REC1, DM_REC2, DM_RSTP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, QK_BOOT, XXXXXXX,
    XXXXXXX, DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit | XXXX | XXXX |   A  |   O  | XXXX | XXXX |   E  |   U  | XXXX | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
)

};

// Plover Code
#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
        layer_off(_RAISE); // for some reason leaving plover triggers TT(_RAISE)?
      }
      return false;
      break;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
