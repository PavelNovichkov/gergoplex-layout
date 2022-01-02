#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0
#define RUS 1 // TODO
#define NUM 2
#define FN 3
#define NAV 4

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


// Layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_split_3x5_3(
    KC_Q, KC_W,         KC_F,         KC_P,         KC_B,    KC_J, KC_L,         KC_U,         KC_Y,         KC_QUOT,
    KC_A, LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,    KC_M, RCTL_T(KC_N), RSFT_T(KC_E), LALT_T(KC_I), KC_O,
    KC_Z, KC_X,         KC_C,         LGUI_T(KC_D), KC_V,    KC_K, RGUI_T(KC_H), KC_COMM,      KC_DOT,       KC_SLSH,

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
    KC_F12, KC_F7, KC_F8, KC_F9, KC_SLCK,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_F11, KC_F4, KC_F5, KC_F6, KC_PSCR,    KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT, KC_NO,
    KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

    KC_CAPS, KC_APP, KC_INS,
    KC_NO,   KC_NO,  KC_NO
    ),

[NAV] = LAYOUT_split_3x5_3(
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_HOME, KC_END,  KC_NO,   KC_NO,
    KC_NO, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_PGDN, KC_PGUP, KC_NO,   KC_NO,

    KC_NO,  KC_NO,   KC_NO,
    KC_NO,  KC_DEL,  KC_NO
    )
};
