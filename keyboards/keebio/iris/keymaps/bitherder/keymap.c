#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MOUSE
};

// pseudo key codes
#define KC_____  _______
#define KC_BLSTP BL_STEP
#define KC_BLTOG RGB_TOG
#define KC_BLMOD RGB_MOD
#define KC_BLHUI RGB_HUI
#define KC_BLSAI RGB_SAI
#define KC_BLVAI RGB_VAI
#define KC_BLHUD RGB_HUD
#define KC_BLSAD RGB_SAD
#define KC_BLVAD RGB_VAD
#define KC_EUR   A(S(KC_2))
#define KC_CESC  MT(MOD_LCTL, KC_ESC)
#define KC_SCESC S(MT(MOD_LCTL, KC_ESC))
#define KC_SNUHS S(KC_NUHS)
#define KC_SNUBS S(KC_NUBS)
#define KC_S_ENT MT(MOD_RSFT, KC_ENT)
#define KC_D_MO  LT(_MOUSE, KC_D)

enum custom_keycodes {
  KC_QWERTY = SAFE_RANGE,
  KC_LOWER,
  KC_RAISE,
  KC_ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //┌─────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬────────┐
     F1,   F2,   F3,   F4,   F5,   F6,                        F7,   F8,   F9,   F10,  F11,  F12,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     TAB,  Q,    W,    E,    R,    T,                         Y,    U,    I,    O,    P,    BSPC,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     ESC,  A,    S,    D_MO, F,    G,                         H,    J,    K,    L,    SCLN, QUOT,
  //├─────┼─────┼─────┼─────┼─────┼─────┼─────┐        ┌─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     LSFT, Z,    X,    C,    V,    B,    LOWER,         RAISE,N,    M,    COMM, DOT,  SLSH, S_ENT,
  //└─────┴─────┴─────┼─────┴┬────┴─┬───┴──┬──┘        └──┬──┴───┬─┴────┬┴─────┼─────┴─────┴────────┘
                       LSFT,  LGUI,  CESC,                 SPC,   LALT,  BSPC
                   // └──────┴──────┴──────┘              └──────┴──────┴──────┘
  ),

  [_LOWER] = LAYOUT_kc(
  //┌─────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬────────┐
     F13,  F14,  F15,  F16,  F17,  F18,                       F19,  F20,  F21,  F22,  F23,  F24,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     TILD, EXLM, AT,   HASH, DLR,  PERC,                      CIRC, AMPR, ASTR, LPRN, RPRN, BSPC,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     DEL,  F1,   F2,   F3,   F4,   F5,                        F6,   UNDS, PLUS, LCBR, RCBR, PIPE,
  //├─────┼─────┼─────┼─────┼─────┼─────┼─────┐        ┌─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     ____, F7,   F8,   F9,   F10,  F11,  ____,          ____, F12,  SNUHS,SNUBS,HOME, END,  ____,
  //└─────┴─────┴─────┼─────┴┬────┴─┬───┴──┬──┘        └──┬──┴───┬─┴────┬┴─────┼─────┴─────┴────────┘
                       ____,  ____,  ____,                 ____,   ____,  ____
                   // └──────┴──────┴──────┘              └──────┴──────┴──────┘
  ),

  [_RAISE] = LAYOUT_kc(
  //┌─────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬────────┐
     F12,  F1,   F2,   F3,   F4,   F5,                        F6,   F7,   F8,   F9,   F10,  F11,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     GRV,  1,    2,    3,    4,    5,                         6,    7,    8,    9,    0,    BSPC,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     DEL,  F1,   F2,   F3,   F4,   F5,                        LEFT, DOWN, UP,   RGHT ,PGUP, PGDN,
  //├─────┼─────┼─────┼─────┼─────┼─────┼─────┐        ┌─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     ____, ____, ____, ____, ____, ____, ____,          ____, ____, ____, MNXT, VOLD, VOLU, MPLY,
  //└─────┴─────┴─────┼─────┴┬────┴─┬───┴──┬──┘        └──┬──┴───┬─┴────┬┴─────┼─────┴─────┴────────┘
                       ____,  ____,  ____,                 ____,  ____,  ____
                   // └──────┴──────┴──────┘              └──────┴──────┴──────┘
  ),

  [_MOUSE] = LAYOUT_kc(
  //┌─────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬────────┐
     ____, ____, ____, ____, ____, ____,                      ____, ____, ____, ____, ____, ____,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     ____, ____, ____, ____, BTN3, ____,                      ____, ____, ____, ____, ____, ____,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     ____, ____, ____, ____, BTN1, ____,                      MS_L, MS_D, MS_U, MS_R, ____, ____,
  //├─────┼─────┼─────┼─────┼─────┼─────┼─────┐        ┌─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     ____, ____, ____, ____, BTN2, ____, ____,          ____, WH_L, WH_U, WH_D, WH_R, ____, ____,
  //└─────┴─────┴─────┼─────┴┬────┴─┬───┴──┬──┘        └──┬──┴───┬─┴────┬┴─────┼─────┴─────┴────────┘
                       ____,  ____,  ____,                 ____,  ____,  ____
                   // └──────┴──────┴──────┘              └──────┴──────┴──────┘
  ),
  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, RESET,   DEBUG,   _______, _______, _______,                            _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM,                            AG_SWAP, KC_QWERTY,BL_STEP,_______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,                              MI_OFF,  _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case KC_LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case KC_RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case KC_ADJUST:
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

void encoder_update_user(uint8_t index, bool clockwise) {
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
}
