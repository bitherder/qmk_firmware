#include QMK_KEYBOARD_H
// #include "muse.h"
#include "quantum.h"

extern keymap_config_t keymap_config;

#define CUR_EUR A(S(KC_2))
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_SESC S(MT(MOD_LCTL, KC_ESC))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers {
  _QWERTY,
  _ARENSITO,
  _ARE_SHIFT,
  _ARE_LO,
  _ARE_HI,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MOUSE
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
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
 * ,------------------------------------------..------------------------------------------.
 * |  Tab  |   Q  |   W  |   E  |   R  |   T  ||   Y  |   U  |   I  |   O  |   P  | Bksp  |
 * |-------+------+------+------+------+------||------+------+------+------+------+-------|
 * |Esc/Ctl|   A  |   S  |   D  |   F  |   G  ||   H  |   J  |   K  |   L  |   ;  |   '   |
 * |-------+------+------+------+------+------||------+------+------+------+------+-------|
 * | Shift |   Z  |   X  |   C  |   V  |   B  ||   N  |   M  |   ,  |   .  |   /  |Ent/Sht|
 * |-------+------+------+------+------+------||------+------+------+------+------+-------|
 * | Mouse | Ctrl | Alt  | GUI  |Lower | Spc  || Spc  |Raise | Left | Down |  Up  | Right |
 * `------------------------------------------''------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,     KC_A,    KC_S,   LT(_MOUSE, KC_D),    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_ENT), \
  MO(_MOUSE), KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_LCTL, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Arensito Base
 * ,-------------------------------------------..------------------------------------------.
 * |  Tab  |   q  |   l  |   ,  |   p  |   @   ||   |  |   f  |   u  |   d  |   k  | Bksp  |
 * |-------+------+------+------+------+-------||------+------+------+------+------+-------|
 * |   '   |   a  |   r  |   e  |   n  |   b   ||   g  |   s  |   i  |   t  |   o  |  "    |
 * |-------+------+------+------+------+-------||------+------+------+------+------+-------|
 * | Shift |   z  |   w  |   .  |   h  |   j   ||   v  |   c  |   y  |   m  |   x  |Ent/Sht|
 * |-------+------+------+------+------+-------||------+------+------+------+------+-------|
 * | Mouse | Ctrl | Alt  | GUI  |Lower |ESC/Ctl|| Spc  |Raise | Alt  | GUI  | Ctrl | Mouse |
 * `-------------------------------------------''------------------------------------------'
 */

[_ARENSITO] = LAYOUT_ortho_4x12( \
  KC_TAB,         KC_Q,    KC_L,    KC_COMM, KC_P,        KC_AT,   KC_PIPE, KC_F,         KC_U,    KC_D,    KC_K,    KC_BSPC,               \
  KC_QUOTE,       KC_A,    KC_R,    LT(_MOUSE, KC_E),    KC_N,        KC_B,    KC_G,    KC_S,         KC_I,    KC_T,    KC_O,    S(KC_QUOTE), \
  MO(_ARE_SHIFT), KC_Z,    KC_W,    KC_DOT,  KC_H,        KC_J,    KC_V,    KC_C,         KC_Y,    KC_M,    KC_X,    LT(_ARE_SHIFT,KC_ENT), \
  MO(_MOUSE),     KC_LCTL, KC_LALT, KC_LGUI, MO(_ARE_LO), CTL_ESC, KC_SPC,  MO(_ARE_HI),  KC_RALT, KC_RGUI, KC_RCTL, MO(_MOUSE)             \
),

/* Arensito Shift
 * ,------------------------------------------..------------------------------------------.
 * |  BTab |   Q  |   L  |   ?  |   P  |   #  ||   &  |   F  |   U  |   D  |   K  |  Del  |
 * |-------+------+------+------+------+------||------+------+------+------+------+-------|
 * |   `   |   A  |   R  |   E  |   N  |   B  ||   G  |   S  |   I  |   T  |   O  |   ~   |
 * |-------+------+------+------+------+------||------+------+------+------+------+-------|
 * |       |   Z  |   W  |   !  |   H  |   J  ||   V  |   C  |   Y  |   M  |   X  |       |
 * |-------+------+------+------+------+------||------+------+------+------+------+-------|
 * |       |      |      |      |      |      ||      |      |      |      |      |       |
 * `------------------------------------------''------------------------------------------'
 */

[_ARE_SHIFT] = LAYOUT_ortho_4x12( \
  S(KC_TAB), S(KC_Q), S(KC_L), KC_QUES, S(KC_P), KC_HASH,  KC_AMPR, S(KC_F), S(KC_U), S(KC_D), S(KC_K), KC_DEL,  \
  KC_GRV,    S(KC_A), S(KC_R), S(KC_E), S(KC_N), S(KC_B),  S(KC_G), S(KC_S), S(KC_I), S(KC_T), S(KC_O), KC_TILD, \
  _______,   S(KC_Z), S(KC_W), KC_EXLM, S(KC_H), S(KC_J),  S(KC_V), S(KC_C), S(KC_Y), S(KC_M), S(KC_X), _______, \
  _______,   _______, _______, _______, _______, CTL_SESC, _______, _______, _______, _______, _______, _______  \
),

/* Arensito Raise
 * ,------------------------------------------..------------------------------------------.
 * |       |   {  |   }  |   [  |   ]  |      ||      |   _  |   <  |   >  |   $  |  Bsp  |
 * |-------+------+------+------+------+------||------+------+------+------+------+-------|
 * |   %   |   ;  |   /  |   -  |   0  |   :  ||   \  |   1  |   (  |   )  |   =  |   ^   |
 * |-------+------+------+------+------+------||------+------+------+------+------+-------|
 * |   €   |   6  |   7  |   8  |   9  |   +  ||   *  |   2  |   3  |   4  |   5  |       |
 * |-------+------+------+------+------+------||------+------+------+------+------+-------|
 * |       |      |      |      | Adj  |      ||      |      |      |      |      |       |
 * `------------------------------------------''------------------------------------------'
 */

[_ARE_HI] = LAYOUT_ortho_4x12( \
  XXXXXXX, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,     XXXXXXX,  XXXXXXX, KC_UNDS, KC_LT,   KC_GT,   KC_DLR,  KC_BSPC, \
  KC_PERC, KC_SCLN, KC_SLSH, KC_MINS, KC_0,        KC_COLN,  KC_BSLS, KC_1,    KC_LPRN, KC_RPRN, KC_EQL,  KC_CIRC, \
  CUR_EUR, KC_6,    KC_7,    KC_8,    KC_9,        KC_PLUS,  KC_ASTR, KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, \
  _______, _______, _______, _______, MO(_ADJUST), _______,  _______, _______, _______, _______, _______, _______  \
),

/* Arensito lower
 * ,------------------------------------------..------------------------------------------.
 * |   F1  |  F2  |  F3  |  F4  |  F5  |  F6  ||  F7  |  F8  |  F9  |  F10 |  F11 |  F12  |
 * |-------+------+------+------+------+------||------+------+------+------+------+-------|
 * |       |      | Next | Vol- | Vol+ | Play || Left | Down |  Up  |Right |      |       |
 * |-------+------+------+------+------+------||------+------+------+------+------+-------|
 * |       |      |      |      |      |      || Home | PgDn | PgUp | End  |      |       |
 * |-------+------+------+------+------+------||------+------+------+------+------+-------|
 * |       |      |      |      |      |      ||      | Adj  |      |      |      |       |
 * `------------------------------------------''------------------------------------------'
 */
[_ARE_LO] = LAYOUT_ortho_4x12( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,       KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,  KC_LEFT, KC_DOWN,     KC_UP,   KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______,  KC_HOME, KC_PGDN,     KC_PGUP, KC_END,  _______, _______, \
  _______, _______, _______, _______, _______, _______,  _______, MO(_ADJUST), _______, _______, _______, _______  \
),

/* Lower
 * ,-----------------------------------------..-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  ||   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  ||  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 ||  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------''-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______, \
  _______, _______, _______, _______, _______, _______,  _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Raise
 * ,-----------------------------------------..-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  ||   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  ||  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 ||  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------''-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, \
  _______, _______, _______, _______, _______, _______,  _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------..-----------------------------------------.
 * |      | Reset|      |      |      |      ||      |      |      |      |      |  Del |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm||AGswap|Qwerty|Arensi|      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon||MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * `-----------------------------------------''-----------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12( \
  _______, QK_BOOT, DB_TOGG, _______, _______, _______,  _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, MU_NEXT,   AU_ON,  AU_OFF, AG_NORM,  AG_SWAP, QWERTY,  ARENSITO, _______, _______, _______, \
  _______, AU_PREV, AU_NEXT,   MU_ON,  MU_OFF,   MI_ON,   MI_OFF,  _______, _______,  _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______, _______, _______  \
),

/* Mouse
 * ,-----------------------------------------..-----------------------------------------.
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      | Btn3 | Btn2 | Btn1 |      || Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      || LScr | UScr | DScr | RScr |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * `-----------------------------------------''-----------------------------------------'
 */
[_MOUSE] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, KC_MS_BTN3, _______,   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_MS_BTN1, _______,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______, _______, _______, _______, KC_MS_BTN2, _______,   KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______, _______, \
  _______, _______, _______, _______,    _______, _______,   _______, _______, _______, _______, _______, _______  \
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
