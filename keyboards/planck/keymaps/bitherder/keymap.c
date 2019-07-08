/* Copyright 2015-2017 Jack Humbert
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
extern keymap_config_t keymap_config;

#define CUR_EUR A(S(KC_2))

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _ARENSITO,
  _ARE_SHIFT,
  _ARE_LO,
  _ARE_HI,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MOUSE
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  ARENSITO,
  ARE_SHIFT,
  ARE_LO,
  ARE_HI,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV,
  MOUSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-------------------------------------------------------------------------------------.
 * |  Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp  |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |Esc/Ctl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   /   |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * | Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Ent/Sht|
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * | Mouse | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  | Right |
 * `-------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid( \
  KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_ENT), \
  MO(_MOUSE),    KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Colemak
 * ,-------------------------------------------------------------------------------------.
 * |  Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp  |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |Esc/Ctl|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |   /   |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * | Shift |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Ent/Sht|
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * | Mouse | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  | Right |
 * `-------------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid( \
  KC_TAB,  KC_Q, KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  CTL_T(KC_ESC), KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_ENT), \
  MO(_MOUSE),    KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Arensito Base
 * ,-------------------------------------------------------------------------------------.
 * |  Tab  |   q  |   l  |   ,  |   p  |   '  |   "  |   f  |   u  |   d  |   k  | Bksp  |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |Esc/Ctl|   a  |   r  |   e  |   n  |   b  |   g  |   s  |   i  |   t  |   o  |Esc/Ctl|
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * | Shift |   z  |   w  |   .  |   h  |   j  |   v  |   c  |   y  |   m  |   x  |Ent/Sht|
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * | Mouse | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Alt  | GUI  | Ctrl | Right |
 * `-------------------------------------------------------------------------------------'
 */

[_ARENSITO] = LAYOUT_planck_grid( \
  KC_TAB,         KC_Q,    KC_L,    KC_COMM, KC_P,        S(KC_QUOTE), KC_QUOT, KC_F,         KC_U,    KC_D,    KC_K,    KC_BSPC, \
  CTL_T(KC_ESC),  KC_A,    KC_R,    KC_E,    KC_N,        KC_B,        KC_G,    KC_S,         KC_I,    KC_T,    KC_O,    CTL_T(KC_ESC), \
  MO(_ARE_SHIFT), KC_Z,    KC_W,    KC_DOT,  KC_H,        KC_J,        KC_V,    KC_C,         KC_Y,    KC_M,    KC_X,    LT(_ARE_SHIFT,KC_ENT), \
  MO(_MOUSE),     KC_LCTL, KC_LALT, KC_LGUI, MO(_ARE_LO), KC_SPC,      KC_SPC,  MO(_ARE_HI),  KC_RALT, KC_RGUI, KC_RCTL, MO(_MOUSE) \
),

/* Arensito Shift
 * ,-------------------------------------------------------------------------------------.
 * |  BTab |   Q  |   L  |   ?  |   P  |   `  |   ~  |   F  |   U  |   D  |   K  |  Del  |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |       |   A  |   T  |   E  |   N  |   B  |   G  |   S  |   I  |   T  |   O  |       |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * |       |   Z  |   W  |   !  |   H  |   J  |   V  |   C  |   Y  |   M  |   X  |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |    Space    |      |      |      |      |       |
 * `-------------------------------------------------------------------------------------'
 */

[_ARE_SHIFT] = LAYOUT_planck_grid( \
  S(KC_TAB), S(KC_Q), S(KC_L), KC_QUES, S(KC_P), KC_GRV,    KC_TILD, S(KC_F), S(KC_U), S(KC_D),  S(KC_K), KC_DEL,  \
  _______,   S(KC_A), S(KC_R), S(KC_E), S(KC_N), S(KC_B),   S(KC_G), S(KC_S), S(KC_I), S(KC_T), S(KC_O), _______, \
  _______,   S(KC_Z), S(KC_W), KC_EXLM, S(KC_H), S(KC_J),   S(KC_V), S(KC_C), S(KC_Y), S(KC_M), S(KC_X), _______, \
  _______,   _______, _______, _______, _______,   KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______  \
),

/* Arensito Raise
 * ,-------------------------------------------------------------------------------------.
 * |   ^   |   {  |   }  |   [  |   ]  |   #  |   &  |   _  |   <  |   >  |   $  |  Bsp  |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |   %   |   ;  |   /  |   -  |   0  |   :  |   \  |   1  |   (  |   )  |   =  |   |   |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * |   €   |   6  |   7  |   8  |   9  |   +  |   *  |   2  |   3  |   4  |   5  |   @   |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      | Adj  |    Space    |      |      |      |      |       |
 * `-------------------------------------------------------------------------------------'
 */

[_ARE_HI] = LAYOUT_planck_grid( \
  KC_CIRC, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_HASH,  KC_AMPR, KC_UNDS, KC_LT,   KC_GT,   KC_DLR,  KC_BSPC, \
  KC_PERC, KC_SCLN, KC_SLSH, KC_MINS, KC_0,    KC_COLN,  KC_BSLS, KC_1,    KC_LPRN, KC_RPRN, KC_EQL,  KC_PIPE, \
  CUR_EUR, KC_6,    KC_7,    KC_8,    KC_9,    KC_PLUS,  KC_ASTR, KC_2,    KC_3,    KC_4,    KC_5,    KC_AT, \
  _______, _______, _______, _______, MO(_ADJUST), KC_SPC,   KC_SPC,  _______, _______, _______, _______, _______  \
),

/* Arensito lower
 * ,-------------------------------------------------------------------------------------.
 * |   F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12  |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |       |      |      |      |      |      | Left | Down |  Up  |Right |      |       |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * |       |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |             | Adj  |      |      |      |       |
 * `-------------------------------------------------------------------------------------'
 */
[_ARE_LO] = LAYOUT_planck_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, _______, _______, _______, _______, _______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______,  KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______, _______, \
  _______, _______, _______, _______, _______, KC_SPC,   KC_SPC,  MO(_ADJUST), _______, _______, _______, _______  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid( \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, ARENSITO,  _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Btn3 | Btn2 | Btn1 |      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | LScr | UScr | DScr | RScr |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid( \
  _______, _______, _______,    _______,    _______,    _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN1, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______, _______, _______,    _______,    _______,    _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______, _______, \
  _______, _______, _______,    _______,    _______,    _______, _______, _______, _______, _______, _______, _______  \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case ARENSITO:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_ARENSITO);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
