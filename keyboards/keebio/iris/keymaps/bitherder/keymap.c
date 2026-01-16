#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_layers {
  _QWERTY,
  _ARENSITO,
  _ARE_RAISE,
  _ARE_LOWER,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MOUSE
};

// pseudo key codes
#define KC_EUR   A(S(KC_2))
#define KC_CESC  MT(MOD_LCTL, KC_ESC)
#define KC_SCESC S(MT(MOD_LCTL, KC_ESC))
#define KC_SNUHS S(KC_NUHS)
#define KC_SNUBS S(KC_NUBS)
#define KC_S_ENT MT(MOD_RSFT, KC_ENT)
#define KC_D_MO  LT(_MOUSE, KC_D)
#define KC_E_MO  LT(_MOUSE, KC_E)
#define MO_AREHI MO(_ARE_RAISE)
#define MO_ARELO MO(_ARE_LOWER)
#define MO_ADJ   MO(_ADJUST)

enum custom_keycodes {
  CMQS = SAFE_RANGE,
  ATHS,
  PIAP,
  DQTD,
  QTGV,
  DTEX,
  QWERTY,
  ARENSITO,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] =  LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_A,    KC_S,    KC_D_MO, KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,           KC_RALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_S_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LOWER,   KC_CESC,                   KC_SPC,  RAISE,   KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ARENSITO] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_L,    CMQS,    KC_P,    ATHS,                               PIAP,    KC_F,    KC_U,    KC_D,    KC_K,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     QTGV,    KC_A,    KC_R,    KC_E_MO, KC_N,    KC_B,                               KC_G,    KC_S,    KC_I,    KC_T,    KC_O,    DQTD,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_W,    DTEX, KC_H,    KC_J,    KC_ESC,           KC_RALT, KC_V,    KC_C,    KC_Y,    KC_M,    KC_X,    KC_S_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI,  MO_ARELO, KC_CESC,                 KC_SPC,   MO_AREHI, KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

[_ARE_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, XXXXXXX,                            XXXXXXX, KC_UNDS, KC_LT,   KC_GT,   KC_DLR,  KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_PERC, KC_SCLN, KC_SLSH, KC_MINS, KC_0,    KC_COLN,                            KC_BSLS, KC_1,    KC_LPRN, KC_RPRN, KC_EQL,  KC_CIRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_EUR,  KC_6,    KC_7,    KC_8,    KC_9,    KC_PLUS, _______,          _______, KC_ASTR, KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, MO_ADJ,  _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),

[_ARE_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, MO_ADJ,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,                             KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,          _______, KC_F12,  KC_SNUHS,KC_SNUBS,KC_HOME, KC_END,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______,  _______,  _______,                 _______,   _______,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,          _______, KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______,  _______,  _______,                 _______,  _______,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, MS_BTN3, _______,                            KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, MS_BTN1, _______,                            MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, _______, _______, _______, MS_BTN2, _______, _______,          _______, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, _______, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______,  _______,  _______,                 _______,  _______,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, QK_BOOT, DB_TOGG,  _______, _______, _______,                            _______, _______, _______,_______, _______, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, MU_NEXT,  AU_ON,   AU_OFF,  AG_NORM,                            AG_SWAP, QWERTY, ARENSITO, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______,  MU_ON,   MU_OFF,  MI_ON,                              MI_OFF,  RGB_M_B, UG_TOGG, UG_HUEU, UG_SATU, UG_VALU,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, RGB_M_P, RGB_M_R, UG_NEXT, UG_HUED, UG_SATD, UG_VALD,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t saved_keycode;
  static uint8_t saved_mods = 0;
  
  switch (keycode) {
    case CMQS:
      if (record->event.pressed) {
	if ( get_mods() & MOD_MASK_SHIFT) {
            saved_keycode = KC_SLSH;
        } else {
            saved_keycode = KC_COMM;
        }
        register_code16(saved_keycode);
      } else {
	unregister_code16(saved_keycode);
      }
      return false;
      break;
    case ATHS:
      if (record->event.pressed) {
	if ( get_mods() & MOD_MASK_SHIFT) {
            saved_keycode = KC_3;
	    register_code16(saved_keycode);
        } else {
	    add_mods(MOD_LSFT);
	    saved_keycode = KC_2;
	    register_code16(saved_keycode);
	    del_mods(MOD_LSFT);
        }
      } else {
	unregister_code16(saved_keycode);
      }
      return false;
      break;
    case PIAP:
      if (record->event.pressed) {
	if ( get_mods() & MOD_MASK_SHIFT) {
            saved_keycode = KC_7;
	    register_code16(saved_keycode);
        } else {
	    add_mods(MOD_LSFT);
	    saved_keycode = KC_BSLS;
	    register_code16(saved_keycode);
	    del_mods(MOD_LSFT);
        }
      } else {
	unregister_code16(saved_keycode);
      }
      return false;
      break;
    case QTGV:
      if (record->event.pressed) {
	if ( get_mods() & MOD_MASK_SHIFT) {
  	    saved_mods = get_mods() & MOD_MASK_SHIFT; // Mask off anything that isn't Shift
	    del_mods(saved_mods); // Remove any Shifts present
            saved_keycode = KC_GRV;
	    register_code16(saved_keycode);
	    add_mods(saved_mods);
        } else {
	    saved_keycode = KC_QUOT;
	    register_code16(saved_keycode);
        }
      } else {
	unregister_code16(saved_keycode);
      }
      return false;
      break;
    case DQTD:
      if (record->event.pressed) {
	if ( get_mods() & MOD_MASK_SHIFT) {
            saved_keycode = KC_GRV;
	    register_code16(saved_keycode);
        } else {
	    add_mods(MOD_LSFT);
	    saved_keycode = KC_QUOT;
	    register_code16(saved_keycode);
	    del_mods(MOD_LSFT);
        }
      } else {
	unregister_code16(saved_keycode);
      }
      return false;
      break;
    case DTEX:
      if (record->event.pressed) {
	if ( get_mods() & MOD_MASK_SHIFT) {
            saved_keycode = KC_1;
        } else {
            saved_keycode = KC_DOT;
        }
        register_code16(saved_keycode);
      } else {
	unregister_code16(saved_keycode);
      }
      return false;
      break;
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

bool encoder_updeate_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
