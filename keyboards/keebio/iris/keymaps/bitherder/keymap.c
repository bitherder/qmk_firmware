#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_layers {
  _QWERTY,
  _ARENSITO,
  _ARE_SHIFT,
  _ARE_RAISE,
  _ARE_LOWER,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MOUSE
};

// pseudo key codes
#define KC_____  _______
#define KC_XXXX  XXXXXXX
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
#define KC_E_MO  LT(_MOUSE, KC_E)
#define KC_S_F1 S(KC_F1)
#define KC_S_F2 S(KC_F2)
#define KC_S_F3 S(KC_F3)
#define KC_S_F4 S(KC_F4)
#define KC_S_F5 S(KC_F5)
#define KC_S_F6 S(KC_F6)
#define KC_S_F7 S(KC_F7)
#define KC_S_F8 S(KC_F8)
#define KC_S_F9 S(KC_F9)
#define KC_S_F10 S(KC_F10)
#define KC_S_F11 S(KC_F11)
#define KC_S_F12 S(KC_F12)
#define KC_BTAB S(KC_TAB)
#define KC_SENT S(KC_ENT)
#define KC_S_Q S(KC_Q)
#define KC_S_L S(KC_L)
#define KC_S_P S(KC_P)
#define KC_S_F S(KC_F)
#define KC_S_U S(KC_U)
#define KC_S_D S(KC_D)
#define KC_S_K S(KC_K)
#define KC_S_A S(KC_A)
#define KC_S_R S(KC_R)
#define KC_S_E S(KC_E)
#define KC_S_N S(KC_N)
#define KC_S_B S(KC_B)
#define KC_S_G S(KC_G)
#define KC_S_S S(KC_S)
#define KC_S_I S(KC_I)
#define KC_S_T S(KC_T)
#define KC_S_O S(KC_O)
#define KC_S_Z S(KC_Z)
#define KC_S_X S(KC_X)
#define KC_S_W S(KC_W)
#define KC_S_H S(KC_H)
#define KC_S_J S(KC_J)
#define KC_S_V S(KC_V)
#define KC_S_C S(KC_C)
#define KC_S_Y S(KC_Y)
#define KC_S_M S(KC_M)
#define KC_S_X S(KC_X)

#define KC_ARE_S MO(_ARE_SHIFT)
#define KC_AREHI MO(_ARE_RAISE)
#define KC_ARELO MO(_ARE_LOWER)
#define KC_A_S_E LT(_ARE_SHIFT, KC_ENT)
#define KC_ADJ   MO(_ADJUST)

enum custom_keycodes {
  KC_CMQS = SAFE_RANGE,
  KC_ATHS,
  KC_PIAP,
  KC_DQTD,
  KC_QTGV,
  KC_DTEX,
  KC_QWERTY,
  KC_ARENSITO,
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
     LSFT, Z,    X,    C,    V,    B,    ESC,           RALT, N,    M,    COMM, DOT,  SLSH, S_ENT,
  //└─────┴─────┴─────┼─────┴┬────┴─┬───┴──┬──┘        └──┬──┴───┬─┴────┬┴─────┼─────┴─────┴────────┘
                       LGUI,  LOWER,  CESC,                SPC,   RAISE, LALT
                   // └──────┴──────┴──────┘              └──────┴──────┴──────┘
  ),

  /* [_ARENSITO] = LAYOUT_kc( */
  /* //┌─────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬────────┐ */
  /*    F1,   F2,   F3,   F4,   F5,   F6,                        F7,   F8,   F9,   F10,  F11,  F12, */
  /* //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤ */
  /*    TAB,  Q,    L,    COMM, P,    AT,                        PIPE, F,    U,    D,    K,    BSPC, */
  /* //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤ */
  /*    QUOT, A,    R,    E_MO, N,    B,                         G,    S,    I,    T,    O,    DQT, */
  /* //├─────┼─────┼─────┼─────┼─────┼─────┼─────┐        ┌─────┼─────┼─────┼─────┼─────┼─────┼────────┤ */
  /*    ARE_S,Z,    W,    DOT,  H,    J,    ESC,           RALT, V,    C,    Y,    M,    X,    A_S_E, */
  /* //└─────┴─────┴─────┼─────┴┬────┴─┬───┴──┬──┘        └──┬──┴───┬─┴────┬┴─────┼─────┴─────┴────────┘ */
  /*                      LGUI,  ARELO, CESC,                 SPC,   AREHI, LALT */
  /*                  // └──────┴──────┴──────┘              └──────┴──────┴──────┘ */
  /* ), */
  [_ARENSITO] = LAYOUT_kc(
  //┌─────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬────────┐
     F1,   F2,   F3,   F4,   F5,   F6,                        F7,   F8,   F9,   F10,  F11,  F12,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     TAB,  Q,    L,    CMQS, P,    ATHS,                      PIAP, F,    U,    D,    K,    BSPC,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     QTGV, A,    R,    E_MO, N,    B,                         G,    S,    I,    T,    O,    DQTD,
  //├─────┼─────┼─────┼─────┼─────┼─────┼─────┐        ┌─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     LSFT, Z,    W,    DTEX, H,    J,    ESC,           RALT, V,    C,    Y,    M,    X,    S_ENT,
  //└─────┴─────┴─────┼─────┴┬────┴─┬───┴──┬──┘        └──┬──┴───┬─┴────┬┴─────┼─────┴─────┴────────┘
                       LGUI,  ARELO, CESC,                 SPC,   AREHI, LALT
                   // └──────┴──────┴──────┘              └──────┴──────┴──────┘
  ),

  /* [_ARE_SHIFT] = LAYOUT_kc( */
  /* //┌─────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬────────┐ */
  /*    S_F1, S_F2, S_F3, S_F4, S_F5, S_F6,                      S_F7, S_F8, S_F9, S_F10,S_F11,S_F12, */
  /* //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤ */
  /*    BTAB, S_Q,  S_L,  QUES, S_P,  HASH,                      AMPR, S_F,  S_U,  S_D,  S_K,  ____, */
  /* //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤ */
  /*    GRV,  S_A,  S_R,  S_E,  S_N,  S_B,                       S_G,  S_S,  S_I,  S_T,  S_O,  TILD, */
  /* //├─────┼─────┼─────┼─────┼─────┼─────┼─────┐        ┌─────┼─────┼─────┼─────┼─────┼─────┼────────┤ */
  /*    ____, S_Z,  S_W,  EXLM, S_H,  S_J,  ____,          ____, S_V,  S_C,  S_Y,  S_M,  S_X,  SENT, */
  /* //└─────┴─────┴─────┼─────┴┬────┴─┬───┴──┬──┘        └──┬──┴───┬─┴────┬┴─────┼─────┴─────┴────────┘ */
  /*                      ____,  ____,  ____,                 ____,   ____,  ____ */
  /*                  // └──────┴──────┴──────┘              └──────┴──────┴──────┘ */
  /* ), */

[_ARE_RAISE] = LAYOUT_kc(
  //┌─────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬────────┐
     XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,                      XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, 
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     XXXX, LCBR, RCBR, LBRC, RBRC, XXXX,                      XXXX, UNDS, LT,   GT,   DLR,  BSPC,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     PERC, SCLN, SLSH, MINS, 0,    COLN,                      BSLS, 1,    LPRN, RPRN, EQL,  CIRC,
  //├─────┼─────┼─────┼─────┼─────┼─────┼─────┐        ┌─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     EUR,  6,    7,    8,    9,    PLUS, ____,          ____, ASTR, 2,    3,    4,    5,    XXXX,
  //└─────┴─────┴─────┼─────┴┬────┴─┬───┴──┬──┘        └──┬──┴───┬─┴────┬┴─────┼─────┴─────┴────────┘
                       ____,  ADJ,   ____,                 ____,  ____,  ____
                   // └──────┴──────┴──────┘              └──────┴──────┴──────┘
),

[_ARE_LOWER] = LAYOUT_kc(
  //┌─────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬────────┐
     XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,                      XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, 
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     F1,   F2,   F3,   F4,   F5,   F6,                        F7,   F8,   F9,   F10,  F11,  F12,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     ____, ____, MNXT, VOLD, VOLU, MPLY,                      LEFT, DOWN, UP,   RGHT, ____, ____,
  //├─────┼─────┼─────┼─────┼─────┼─────┼─────┐        ┌─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     ____, ____, ____, ____, ____, ____, ____,          ____, HOME, PGDN, PGUP, END,  ____, ____,
  //└─────┴─────┴─────┼─────┴┬────┴─┬───┴──┬──┘        └──┬──┴───┬─┴────┬┴─────┼─────┴─────┴────────┘
                       ____,  ____,  ____,                 ____,  ADJ,   ____
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
     DEL,  F1,   F2,   F3,   F4,   F5,                        F6,   MINS, EQL,  LBRC, RBRC, BSLS,
  //├─────┼─────┼─────┼─────┼─────┼─────┼─────┐        ┌─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     ____, F7,   F8,   F9,   F10,  F11,  ____,          ____, F12,  NUHS, NUBS, PGUP, PGDN, ____,
  //└─────┴─────┴─────┼─────┴┬────┴─┬───┴──┬──┘        └──┬──┴───┬─┴────┬┴─────┼─────┴─────┴────────┘
                       ____,  ____,  ____,                 ____,  ____,  ____
                   // └──────┴──────┴──────┘              └──────┴──────┴──────┘
  ),

  [_MOUSE] = LAYOUT_kc(
  //┌─────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬────────┐
     ____, ____, ____, ____, ____, ____,                      ____, ____, ____, ____, ____, ____,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     ____, ____, ____, ____, BTN3, ____,                      LEFT, UP,   DOWN, RGHT, ____, ____,
  //├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼────────┤
     ____, ____, ____, ____, BTN1, ____,                      MS_L, MS_D, MS_U, MS_R, ____, ____,
  //├─────┼─────┼─────┼─────┼─────┼─────┼─────┐        ┌─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     LSFT, ____, ____, ____, BTN2, ____, ____,          ____, WH_L, WH_U, WH_D, WH_R, ____, RSFT,
  //└─────┴─────┴─────┼─────┴┬────┴─┬───┴──┬──┘        └──┬──┴───┬─┴────┬┴─────┼─────┴─────┴────────┘
                       ____,  ____,  ____,                 ____,  ____,  ____
                   // └──────┴──────┴──────┘              └──────┴──────┴──────┘
  ),
  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, RESET,   DEBUG,   _______, _______, _______,                            _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM,                            AG_SWAP, KC_QWERTY,KC_ARENSITO,_______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,                              MI_OFF,  RGB_M_B, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, RGB_M_P, RGB_M_R, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t kc;
  switch (keycode) {
    case KC_CMQS:
      if (record->event.pressed) {
	if ( get_mods() & MOD_MASK_SHIFT) {
            kc = KC_SLSH;
        } else {
            kc = KC_COMM;
        }
        register_code16(kc);
      } else {
	unregister_code16(kc);
      }
      return false;
      break;
    case KC_QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case KC_ARENSITO:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_ARENSITO);
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
