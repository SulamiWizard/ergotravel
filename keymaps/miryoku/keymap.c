#include QMK_KEYBOARD_H

enum layer_names {
    _MIRYOKU,
    _NAV,
    _SYM,
    _NUM,
    _FUN,
    _MEDIA,
};

#define TMUX_PRE C(KC_A)

// Home row mods - left hand
#define HM_A  MT(MOD_LGUI, KC_A)
#define HM_R  MT(MOD_LALT, KC_R)
#define HM_S  MT(MOD_LCTL, KC_S)
#define HM_T  MT(MOD_LSFT, KC_T)

// Home row mods - right hand
#define HM_N  MT(MOD_LSFT, KC_N)
#define HM_E  MT(MOD_LCTL, KC_E)
#define HM_I  MT(MOD_LALT, KC_I)
#define HM_O  MT(MOD_LGUI, KC_O)

// Thumb keys
#define TH_ESC  LT(_MEDIA, KC_ESC)
#define TH_SPC  LT(_NAV,   KC_SPC)
// #define TH_TAB  LT(_MOUSE, KC_TAB)
#define TH_TAB  KC_TAB
#define TH_ENT  LT(_SYM,   KC_ENT)
#define TH_BSP  LT(_NUM,   KC_BSPC)
#define TH_DEL  LT(_FUN,   KC_DEL)

enum custom_keycodes {
    KC_AROW = SAFE_RANGE,  // ->
    KC_EQAR,               // =>
};

// misc
#define KC_REDO C(KC_Y)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MIRYOKU] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_LPRN,          KC_RPRN, KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_ESC,  HM_A,    HM_R,    HM_S,    HM_T,    KC_G,    KC_LBRC,          KC_RBRC, KC_M,    HM_N,    HM_E,    HM_I,    HM_O,    KC_SCLN,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_MINS, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    TH_TAB,           TH_ENT,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+---------+--------|
     KC_UNDS, KC_LSFT, KC_RPRN, TH_ESC,           TH_SPC,  TH_TAB,           TH_ENT,  TH_BSP,            TH_DEL, KC_LSFT, KC_GRV,  TMUX_PRE
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_NAV] = LAYOUT(
     _______, _______,  _______, _______, _______, _______, _______,         _______,  KC_REDO, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, _______,
     _______, KC_LGUI,  KC_LALT, KC_LCTL, KC_LSFT, _______, _______,         _______,  KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,
     _______, _______,  _______, _______, _______, _______, _______,         _______,  KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______,
     _______, _______,  _______, _______,          _______, _______,         _______,  _______,          _______, _______, _______, _______

  ),

  [_SYM] = LAYOUT(
     _______, KC_LCBR,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______,         _______,  _______, _______, _______, _______, _______, _______,
     _______, KC_COLN,  KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, _______,         _______,  _______, KC_LABK, KC_RABK, KC_QUES, KC_BSLS, KC_BSPC,
     _______, KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_TAB,          _______,  _______, KC_AROW, KC_EQAR, _______, _______, _______,
     _______, _______, _______, _______,           KC_ESC,  KC_UNDS,         _______,  _______,          _______, _______, _______, _______

  ),

  [_NUM] = LAYOUT(
     _______, KC_LBRC,  KC_7,    KC_8,    KC_9, KC_RBRC, _______,            _______,  _______, _______, _______, _______, _______, _______,
     _______, KC_SCLN,  KC_4,    KC_5,    KC_6, KC_EQL,  _______,            _______,  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC,
     _______, KC_GRV,   KC_1,    KC_2,    KC_3, KC_BSLS, _______,            _______,  _______, _______, _______, _______, _______, _______,
     _______, _______, _______,  KC_COMM,        KC_0,    KC_DOT,            _______,  _______,          _______, _______, _______, _______

  ),

  [_FUN] = LAYOUT(
     _______, KC_F12,  KC_F7,   KC_F8,   KC_F9, KC_PSCR, _______,            _______,  _______, _______, _______, _______, _______, _______,
     _______, KC_F11,  KC_F4,   KC_F5,   KC_F6, KC_SCRL, _______,            _______,  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
     _______, KC_F10,  KC_F1,   KC_F2,   KC_F3, KC_PAUS, _______,            _______,  _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______,        _______, _______,            _______,  _______,          _______, _______, _______, _______

  ),

  [_MEDIA] = LAYOUT(
     _______,  _______,  _______, _______, _______, _______,_______,         KC_F14,   _______, _______, _______, _______, _______, _______,
     _______,  KC_LGUI,  KC_LALT, KC_LCTL, KC_LSFT, _______,_______,         KC_F13,   _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
     _______,  _______,  _______, _______, _______, _______,_______,         KC_MPLY,  _______, _______, _______, _______, _______, _______,
     _______,  _______,  _______, _______,          _______,_______,         KC_MPLY,  KC_MUTE,          _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_AROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
        case KC_EQAR:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            return false;
    }
    return true;
}
