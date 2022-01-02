#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0
#define RUS 1 // TODO
#define NUM 2
#define FN 3
#define NAV 4


// Key definitions

#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)
#define HOME_D LGUI_T(KC_D)
#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_H RGUI_T(KC_H)


// Key overrides

// shift + comma -> semicolon
const key_override_t comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
// shift + dot -> colon
const key_override_t dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);

const key_override_t **key_overrides = (const key_override_t *[]){
    &comma_override,
    &dot_override,
    NULL
};


// Tapping force hold per key
// (enable only for home block mods)
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case HOME_R:
  case HOME_S:
  case HOME_T:
  case HOME_D:
  case HOME_N:
  case HOME_E:
  case HOME_I:
  case HOME_H:
    return true;
  default:
    return false;
  }
}


// Layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_split_3x5_3(
    KC_Q, KC_W,   KC_F,   KC_P,   KC_B,    KC_J, KC_L,   KC_U,    KC_Y,   KC_QUOT,
    KC_A, HOME_R, HOME_S, HOME_T, KC_G,    KC_M, HOME_N, HOME_E,  HOME_I, KC_O,
    KC_Z, KC_X,   KC_C,   HOME_D, KC_V,    KC_K, HOME_H, KC_COMM, KC_DOT, KC_SLSH,

    KC_NO,  LT(NAV, KC_SPC), OSL(FN),
    KC_APP, OSL(NUM),        KC_NO
    ),

[NUM] = LAYOUT_split_3x5_3(
    KC_6,    KC_4,  KC_2,    KC_0,    KC_8,       KC_9,    KC_1,    KC_3,    KC_5,    KC_7,
    KC_BSLS, KC_LT, KC_LBRC, KC_LPRN, KC_LCBR,    KC_CIRC, KC_MINS, KC_EQL,  KC_EXLM, KC_ASTR,
    KC_AT,   KC_GT, KC_RBRC, KC_RPRN, KC_RCBR,    KC_TILD, KC_PLUS, KC_COMM, KC_DOT,  KC_SLSH,

    KC_NO,  KC_ESC,  KC_TRNS,
    KC_SPC, KC_TRNS, KC_NO
    ),

[FN] = LAYOUT_split_3x5_3(
    KC_F6, KC_F4,   KC_F2,   KC_F10, KC_8,     KC_9,  KC_1,    KC_3,    KC_5,    KC_7,
    KC_NO, KC_AMPR, KC_HASH, KC_GRV, KC_NO,    KC_NO, KC_UNDS, KC_PERC, KC_DLR,  KC_PIPE,
    KC_NO, KC_NO,   KC_NO,   KC_INS, KC_NO,    KC_NO, KC_PSCR, KC_SLCK, KC_PAUS, KC_NO,

    KC_NO,   KC_NO,   KC_TRNS,
    KC_CAPS, KC_TRNS, KC_NO
    ),

[NAV] = LAYOUT_split_3x5_3(
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_HOME, KC_END,  KC_NO,   KC_NO,
    KC_NO, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_PGDN, KC_PGUP, KC_NO,   KC_NO,

    KC_NO,  KC_NO,   KC_NO,
    KC_NO,  KC_DEL,  KC_NO
    )
};
