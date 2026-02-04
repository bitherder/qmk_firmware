#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_layers {
  _QWERTY,
  _ARENSITO,
  _TAIPO,
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
#define QWERTY   PDF(_QWERTY)
#define ARENSITO PDF(_ARENSITO)
#define TAIPO    PDF(_TAIPO)

enum custom_keycodes {
  CMQS = SAFE_RANGE,
  ATHS,
  PIAP,
  DQTD,
  QTGV,
  DTEX,
  MY_LGUI,
  MY_LALT,
  MY_LCTL,
  MY_LSFT,
  LOWER,
  RAISE,
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
     QTGV,    KC_A,    KC_R,    KC_E,    KC_N,    KC_B,                               KC_G,    KC_S,    KC_I,    KC_T,    KC_O,    DQTD,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_W,    DTEX,    KC_H,    KC_J,    KC_ESC,           KC_RALT, KC_V,    KC_C,    KC_Y,    KC_M,    KC_X,    KC_S_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, MO_ARELO, KC_CESC,                 KC_SPC,   MO_AREHI, KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_TAIPO] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_R,    KC_S,    KC_N,    KC_I,    XXXXXXX,                            XXXXXXX, KC_I,    KC_N,    KC_S,    KC_R,    XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_A,    KC_O,    KC_T,    KC_E,    XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, KC_E,    KC_T,    KC_O,    KC_A,    XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LOWER,   KC_SPC,  KC_BSPC,                   KC_BSPC, KC_SPC,  RAISE
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
                                    _______,  _______, _______,                  _______,   _______,  _______
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
                                    _______,  _______, _______,                  _______,  _______,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  /*
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
                                    _______,  _______, _______,                  _______,  _______,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  */
  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, QK_BOOT, DB_TOGG,  _______, _______, _______,                            _______, _______, _______,_______, _______, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, MU_NEXT,  AU_ON,   AU_OFF,  AG_NORM,                            AG_SWAP, QWERTY, ARENSITO, TAIPO,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______,  MU_ON,   MU_OFF,  MI_ON,                              MI_OFF,  RGB_M_B, UG_TOGG, UG_HUEU, UG_SATU, UG_VALU,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, RGB_M_P, RGB_M_R, UG_NEXT, UG_HUED, UG_SATD, UG_VALD,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

const uint16_t PROGMEM cm_s_e[] = {KC_E, KC_SPC, COMBO_END};
const uint16_t PROGMEM cm_s_t[] = {KC_T,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_o[] = {KC_O,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_a[] = {KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_lprn[] = {KC_E,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_lbrc[] = {KC_T,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_lcbr[] = {KC_O,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_lt[] = {KC_A,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_s_i[] = {KC_I,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_n[] = {KC_N,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_s[] = {KC_S,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_r[] = {KC_R,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_rprn[] = {KC_I,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_rbrc[] = {KC_N,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_rcbr[] = {KC_S,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_gt[] = {KC_R,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_h[] = {KC_E,KC_T,COMBO_END};
const uint16_t PROGMEM cm_l[] = {KC_O,KC_A,COMBO_END};
const uint16_t PROGMEM cm_y[] = {KC_I,KC_N,COMBO_END};
const uint16_t PROGMEM cm_b[] = {KC_S,KC_R,COMBO_END};
const uint16_t PROGMEM cm_s_h[] = {KC_E,KC_T,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_l[] = {KC_O,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_y[] = {KC_I,KC_N,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_b[] = {KC_S,KC_R,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_0[] = {KC_E,KC_T,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_4[] = {KC_O,KC_A,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_5[] = {KC_I,KC_N,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_9[] = {KC_S,KC_R,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_g[] = {KC_I,KC_R,COMBO_END};
const uint16_t PROGMEM cm_u[] = {KC_T,KC_O,COMBO_END};
const uint16_t PROGMEM cm_d[] = {KC_E,KC_A,COMBO_END};
const uint16_t PROGMEM cm_p[] = {KC_N,KC_S,COMBO_END};
const uint16_t PROGMEM cm_s_g[] = {KC_I,KC_R,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_u[] = {KC_T,KC_O,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_d[] = {KC_E,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_p[] = {KC_N,KC_S,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_hash[] = {KC_I,KC_R,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_2[] = {KC_T,KC_O,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_at[] = {KC_E,KC_A,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_7[] = {KC_N,KC_S,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_c[] = {KC_E,KC_O,COMBO_END};
const uint16_t PROGMEM cm_q[] = {KC_T,KC_A,COMBO_END};
const uint16_t PROGMEM cm_f[] = {KC_I,KC_S,COMBO_END};
const uint16_t PROGMEM cm_z[] = {KC_N,KC_R,COMBO_END};
const uint16_t PROGMEM cm_s_c[] = {KC_E,KC_O,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_q[] = {KC_T,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_f[] = {KC_I,KC_S,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_z[] = {KC_N,KC_R,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_1[] = {KC_E,KC_O,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_3[] = {KC_T,KC_A,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_6[] = {KC_I,KC_S,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_8[] = {KC_N,KC_R,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_v[] = {KC_S,KC_E,COMBO_END};
const uint16_t PROGMEM cm_x[] = {KC_R,KC_T,COMBO_END};
const uint16_t PROGMEM cm_k[] = {KC_I,KC_O,COMBO_END};
const uint16_t PROGMEM cm_j[] = {KC_N,KC_A,COMBO_END};
const uint16_t PROGMEM cm_s_v[] = {KC_S,KC_E,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_x[] = {KC_R,KC_T,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_k[] = {KC_I,KC_O,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_j[] = {KC_N,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_astr[] = {KC_S,KC_E,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_circ[] = {KC_R,KC_T,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_plus[] = {KC_I,KC_O,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_eql[] = {KC_N,KC_A,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_mins[] = {KC_N,KC_O,COMBO_END};
const uint16_t PROGMEM cm_w[] = {KC_I,KC_A,COMBO_END};
const uint16_t PROGMEM cm_m[] = {KC_R,KC_E,COMBO_END};
const uint16_t PROGMEM cm_slsh[] = {KC_S,KC_T,COMBO_END};
const uint16_t PROGMEM cm_unds[] = {KC_N,KC_O,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_w[] = {KC_I,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_s_m[] = {KC_R,KC_E,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_bsls[] = {KC_S,KC_T,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_perc[] = {KC_N,KC_O,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_ampr[] = {KC_I,KC_A,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_dlr[] = {KC_R,KC_E,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_pipe[] = {KC_S,KC_T,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_quot[] = {KC_S,KC_A,COMBO_END};
const uint16_t PROGMEM cm_scln[] = {KC_R,KC_O,COMBO_END};
const uint16_t PROGMEM cm_ques[] = {KC_I,KC_T,COMBO_END};
const uint16_t PROGMEM cm_comma[] = {KC_N,KC_E,COMBO_END};
const uint16_t PROGMEM cm_dqt[] = {KC_S,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_coln[] = {KC_R,KC_O,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_exlm[] = {KC_I,KC_T,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_dot[] = {KC_N,KC_E,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_grave[] = {KC_S,KC_A,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_tilde[] = {KC_N,KC_E,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_enter[] = {KC_E,KC_T,KC_O,COMBO_END};
const uint16_t PROGMEM cm_tab[] = {KC_I,KC_N,KC_S,COMBO_END};
const uint16_t PROGMEM cm_esc[] = {KC_E,KC_T,KC_O,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_del[] = {KC_I,KC_N,KC_S,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_algr[] = {KC_E,KC_T,KC_O,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_lead[] = {KC_I,KC_N,KC_S,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_lgui[] = {KC_A,KC_R,COMBO_END};
const uint16_t PROGMEM cm_lalt[] = {KC_O,KC_S,COMBO_END};
const uint16_t PROGMEM cm_lctl[] = {KC_T,KC_N,COMBO_END};
const uint16_t PROGMEM cm_lsft[] = {KC_E,KC_I,COMBO_END};
const uint16_t PROGMEM cm_right[] = {KC_A,KC_R,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_up[] = {KC_O,KC_S,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_down[] = {KC_T,KC_N,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_left[] = {KC_E,KC_I,KC_SPC,COMBO_END};
const uint16_t PROGMEM cm_end[] = {KC_A,KC_R,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_pgup[] = {KC_O,KC_S,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_pgdn[] = {KC_T,KC_N,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_home[] = {KC_E,KC_I,KC_BSPC,COMBO_END};
const uint16_t PROGMEM cm_adjust[] = {RAISE,LOWER,COMBO_END};

enum combos {
  CM_S_E,
  CM_S_T,
  CM_S_O,
  CM_S_A,
  CM_LPRN,
  CM_LBRC,
  CM_LCBR,
  CM_LT,
  CM_S_I,
  CM_S_N,
  CM_S_S,
  CM_S_R,
  CM_RPRN,
  CM_RBRC,
  CM_RCBR,
  CM_GT,
  CM_H,
  CM_L,
  CM_Y,
  CM_B,
  CM_S_H,
  CM_S_L,
  CM_S_Y,
  CM_S_B,
  CM_0,
  CM_4,
  CM_5,
  CM_9,
  CM_G,
  CM_U,
  CM_D,
  CM_P,
  CM_S_G,
  CM_S_U,
  CM_S_D,
  CM_S_P,
  CM_HASH,
  CM_2,
  CM_AT,
  CM_7,
  CM_C,
  CM_Q,
  CM_F,
  CM_Z,
  CM_S_C,
  CM_S_Q,
  CM_S_F,
  CM_S_Z,
  CM_1,
  CM_3,
  CM_6,
  CM_8,
  CM_V,
  CM_X,
  CM_K,
  CM_J,
  CM_S_V,
  CM_S_X,
  CM_S_K,
  CM_S_J,
  CM_ASTR,
  CM_CIRC,
  CM_PLUS,
  CM_EQL,
  CM_MINS,
  CM_W,
  CM_M,
  CM_SLSH,
  CM_UNDS,
  CM_S_W,
  CM_S_M,
  CM_BSLS,
  CM_PERC,
  CM_AMPR,
  CM_DLR,
  CM_PIPE,
  CM_QUOT,
  CM_SCLN,
  CM_QUES,
  CM_COMMA,
  CM_DQT,
  CM_COLN,
  CM_EXLM,
  CM_DOT,
  CM_GRAVE,
  CM_TILDE,
  CM_ENTER,
  CM_TAB,
  CM_ESC,
  CM_DEL,
  CM_ALGR,
  CM_LEAD,
  CM_LGUI,
  CM_LALT,
  CM_LCTL,
  CM_LSFT,
  CM_RIGHT,
  CM_UP,
  CM_DOWN,
  CM_LEFT,
  CM_PGUP,
  CM_HOME,
  CM_END,
  CM_PGDN,
  CM_ADJUST
};

combo_t key_combos[] = {
  [CM_S_E] = COMBO(cm_s_e,S(KC_E)),
  [CM_S_T] = COMBO(cm_s_t,S(KC_T)),
  [CM_S_O] = COMBO(cm_s_o,S(KC_O)),
  [CM_S_A] = COMBO(cm_s_a,S(KC_A)),
  [CM_LPRN] = COMBO(cm_lprn,KC_LPRN),
  [CM_LBRC] = COMBO(cm_lbrc,KC_LBRC),
  [CM_LCBR] = COMBO(cm_lcbr,KC_LCBR),
  [CM_LT] = COMBO(cm_lt,KC_LT),
  [CM_S_I] = COMBO(cm_s_i,S(KC_I)),
  [CM_S_N] = COMBO(cm_s_n,S(KC_N)),
  [CM_S_S] = COMBO(cm_s_s,S(KC_S)),
  [CM_S_R] = COMBO(cm_s_r,S(KC_R)),
  [CM_RPRN] = COMBO(cm_rprn,KC_RPRN),
  [CM_RBRC] = COMBO(cm_rbrc,KC_RBRC),
  [CM_RCBR] = COMBO(cm_rcbr,KC_RCBR),
  [CM_GT] = COMBO(cm_gt,KC_GT),
  [CM_H] = COMBO(cm_h,KC_H),
  [CM_L] = COMBO(cm_l,KC_L),
  [CM_Y] = COMBO(cm_y,KC_Y),
  [CM_B] = COMBO(cm_b,KC_B),
  [CM_S_H] = COMBO(cm_s_h,S(KC_H)),
  [CM_S_L] = COMBO(cm_s_l,S(KC_L)),
  [CM_S_Y] = COMBO(cm_s_y,S(KC_Y)),
  [CM_S_B] = COMBO(cm_s_b,S(KC_B)),
  [CM_0] = COMBO(cm_0,KC_0),
  [CM_4] = COMBO(cm_4,KC_4),
  [CM_5] = COMBO(cm_5,KC_5),
  [CM_9] = COMBO(cm_9,KC_9),
  [CM_G] = COMBO(cm_g,KC_G),
  [CM_U] = COMBO(cm_u,KC_U),
  [CM_D] = COMBO(cm_d,KC_D),
  [CM_P] = COMBO(cm_p,KC_P),
  [CM_S_G] = COMBO(cm_s_g,S(KC_G)),
  [CM_S_U] = COMBO(cm_s_u,S(KC_U)),
  [CM_S_D] = COMBO(cm_s_d,S(KC_D)),
  [CM_S_P] = COMBO(cm_s_p,S(KC_P)),
  [CM_HASH] = COMBO(cm_hash,KC_HASH),
  [CM_2] = COMBO(cm_2,KC_2),
  [CM_AT] = COMBO(cm_at,KC_AT),
  [CM_7] = COMBO(cm_7,KC_7),
  [CM_C] = COMBO(cm_c,KC_C),
  [CM_Q] = COMBO(cm_q,KC_Q),
  [CM_F] = COMBO(cm_f,KC_F),
  [CM_Z] = COMBO(cm_z,KC_Z),
  [CM_S_C] = COMBO(cm_s_c,S(KC_C)),
  [CM_S_Q] = COMBO(cm_s_q,S(KC_Q)),
  [CM_S_F] = COMBO(cm_s_f,S(KC_F)),
  [CM_S_Z] = COMBO(cm_s_z,S(KC_Z)),
  [CM_1] = COMBO(cm_1,KC_1),
  [CM_3] = COMBO(cm_3,KC_3),
  [CM_6] = COMBO(cm_6,KC_6),
  [CM_8] = COMBO(cm_8,KC_8),
  [CM_V] = COMBO(cm_v,KC_V),
  [CM_X] = COMBO(cm_x,KC_X),
  [CM_K] = COMBO(cm_k,KC_K),
  [CM_J] = COMBO(cm_j,KC_J),
  [CM_S_V] = COMBO(cm_s_v,S(KC_V)),
  [CM_S_X] = COMBO(cm_s_x,S(KC_X)),
  [CM_S_K] = COMBO(cm_s_k,S(KC_K)),
  [CM_S_J] = COMBO(cm_s_j,S(KC_J)),
  [CM_ASTR] = COMBO(cm_astr,KC_ASTR),
  [CM_CIRC] = COMBO(cm_circ,KC_CIRC),
  [CM_PLUS] = COMBO(cm_plus,KC_PLUS),
  [CM_EQL] = COMBO(cm_eql,KC_EQL),
  [CM_MINS] = COMBO(cm_mins,KC_MINS),
  [CM_W] = COMBO(cm_w,KC_W),
  [CM_M] = COMBO(cm_m,KC_M),
  [CM_SLSH] = COMBO(cm_slsh,KC_SLSH),
  [CM_UNDS] = COMBO(cm_unds,KC_UNDS),
  [CM_S_W] = COMBO(cm_s_w,S(KC_W)),
  [CM_S_M] = COMBO(cm_s_m,S(KC_M)),
  [CM_BSLS] = COMBO(cm_bsls,KC_BSLS),
  [CM_PERC] = COMBO(cm_perc,KC_PERC),
  [CM_AMPR] = COMBO(cm_ampr,KC_AMPR),
  [CM_DLR] = COMBO(cm_dlr,KC_DLR),
  [CM_PIPE] = COMBO(cm_pipe,KC_PIPE),
  [CM_QUOT] = COMBO(cm_quot,KC_QUOT),
  [CM_SCLN] = COMBO(cm_scln,KC_SCLN),
  [CM_QUES] = COMBO(cm_ques,KC_QUES),
  [CM_COMMA] = COMBO(cm_comma,KC_COMMA),
  [CM_DQT] = COMBO(cm_dqt,KC_DQT),
  [CM_COLN] = COMBO(cm_coln,KC_COLN),
  [CM_EXLM] = COMBO(cm_exlm,KC_EXLM),
  [CM_DOT] = COMBO(cm_dot,KC_DOT),
  [CM_GRAVE] = COMBO(cm_grave,KC_GRAVE),
  [CM_TILDE] = COMBO(cm_tilde,KC_TILDE),
  [CM_ENTER] = COMBO(cm_enter,KC_ENTER),
  [CM_TAB] = COMBO(cm_tab,KC_TAB),
  [CM_ESC] = COMBO(cm_esc,KC_ESC),
  [CM_DEL] = COMBO(cm_del,KC_DEL),
  [CM_ALGR] = COMBO(cm_algr,KC_ALGR),
  [CM_LEAD] = COMBO(cm_lead,QK_LEADER),
  [CM_LGUI] = COMBO(cm_lgui,MY_LGUI),
  [CM_LALT] = COMBO(cm_lalt,MY_LALT),
  [CM_LCTL] = COMBO(cm_lctl,MY_LCTL),
  [CM_LSFT] = COMBO(cm_lsft,MY_LSFT),
  [CM_RIGHT] = COMBO(cm_right,KC_RIGHT),
  [CM_UP] = COMBO(cm_up,KC_UP),
  [CM_DOWN] = COMBO(cm_down,KC_DOWN),
  [CM_LEFT] = COMBO(cm_left,KC_LEFT),
  [CM_PGUP] = COMBO(cm_pgup,KC_PGUP),
  [CM_HOME] = COMBO(cm_home,KC_HOME),
  [CM_END] = COMBO(cm_end,KC_END),
  [CM_PGDN] = COMBO(cm_pgdn,KC_PGDN),
  [CM_ADJUST] = COMBO(cm_adjust,MO_ADJ),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  if (combo_index == CM_ADJUST) {
    return true;
  } else {
    return IS_LAYER_ON_STATE(default_layer_state, _TAIPO);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t saved_keycode;
  static uint8_t saved_mods = 0;

  switch (keycode) {
    case MY_LGUI:
      if(record->event.pressed) {
	add_oneshot_mods(MOD_BIT(KC_LGUI));
        add_mods(MOD_BIT(KC_LGUI));
      } else {
	clear_mods();
      }
      break;
    case MY_LALT:
      if(record->event.pressed) {
	add_oneshot_mods(MOD_BIT(KC_LALT));
        add_mods(MOD_BIT(KC_LALT));
      } else {
	clear_mods();
      }
      break;
    case MY_LCTL:
      if(record->event.pressed) {
	add_oneshot_mods(MOD_BIT(KC_LCTL));
        add_mods(MOD_BIT(KC_LCTL));
      } else {
	clear_mods();
      }
      break;
    case MY_LSFT:
      if(record->event.pressed) {
	add_oneshot_mods(MOD_BIT(KC_LSFT));
        add_mods(MOD_BIT(KC_LSFT));
      } else {
	clear_mods();
      }
      break;
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
  }
  return true;
}

// Quite leader early if it's done
bool leader_add_user(uint16_t keycode) {
  if (keycode >= KC_1 && keycode <= KC_9) return true;
  if (leader_sequence_two_keys(KC_0, KC_0)) return true;
  return false;
}

// function key leader sequence for Taipo layout
void leader_end_user(void) {
  if (leader_sequence_one_key(KC_1)) tap_code16(KC_F1);
  if (leader_sequence_one_key(KC_2)) tap_code16(KC_F2);
  if (leader_sequence_one_key(KC_3)) tap_code16(KC_F3);
  if (leader_sequence_one_key(KC_4)) tap_code16(KC_F4);
  if (leader_sequence_one_key(KC_5)) tap_code16(KC_F5);
  if (leader_sequence_one_key(KC_6)) tap_code16(KC_F6);
  if (leader_sequence_one_key(KC_7)) tap_code16(KC_F7);
  if (leader_sequence_one_key(KC_8)) tap_code16(KC_F8);
  if (leader_sequence_one_key(KC_9)) tap_code16(KC_F9);

  if (leader_sequence_two_keys(KC_0, KC_0)) tap_code16(KC_F10);
  if (leader_sequence_two_keys(KC_0, KC_1)) tap_code16(KC_F11);
  if (leader_sequence_two_keys(KC_0, KC_2)) tap_code16(KC_F12);
  if (leader_sequence_two_keys(KC_0, KC_3)) tap_code16(KC_F13);
  if (leader_sequence_two_keys(KC_0, KC_4)) tap_code16(KC_F14);
  if (leader_sequence_two_keys(KC_0, KC_5)) tap_code16(KC_F15);
  if (leader_sequence_two_keys(KC_0, KC_6)) tap_code16(KC_F16);
  if (leader_sequence_two_keys(KC_0, KC_7)) tap_code16(KC_F17);
  if (leader_sequence_two_keys(KC_0, KC_8)) tap_code16(KC_F18);
  if (leader_sequence_two_keys(KC_0, KC_9)) tap_code16(KC_F19);
}
