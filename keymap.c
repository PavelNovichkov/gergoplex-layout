#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0
#define NUM 1
#define SYMB 2
#define NAV 3
#define FN 4
#define MOUSE 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_split_3x5_3(
    KC_Q, KC_W,         KC_E,         KC_R,         KC_T,            KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,
    KC_A, LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), LGUI_T(KC_G),    RGUI_T(KC_H), RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), KC_SCLN,
    KC_Z, KC_X,         KC_C,         KC_V,         KC_B,            KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,

    KC_TAB,           LT(NAV, KC_SPC),  LT(MOUSE, KC_ESC),
    LT(SYMB, KC_ENT), LT(NUM, KC_BSPC), LT(FN, KC_APP)
    ),

[NUM] = LAYOUT_split_3x5_3(
    KC_DOT,  KC_7, KC_8, KC_9, KC_0,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_EQL,  KC_4, KC_5, KC_6, KC_LBRC,    KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT, KC_NO,
    KC_BSLS, KC_1, KC_2, KC_3, KC_RBRC,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

    KC_GRV, KC_MINS, KC_QUOT,
    KC_NO,  KC_NO,   KC_NO
    ),

[SYMB] = LAYOUT_split_3x5_3(
    KC_GT,   KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,
    KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_LCBR,    KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT, KC_NO,
    KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_RCBR,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

    KC_TILD, KC_UNDS, KC_DQUO,
    KC_NO,   KC_NO,   KC_NO
    ),

[NAV] = LAYOUT_split_3x5_3(
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_HOME, KC_END,  KC_NO,   KC_NO,
    KC_NO, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_PGDN, KC_PGUP, KC_NO,   KC_NO,

    KC_NO,  KC_NO,   KC_NO,
    KC_NO,  KC_DEL,  KC_NO
    ),

[FN] = LAYOUT_split_3x5_3(
    KC_F12, KC_F7, KC_F8, KC_F9, KC_SLCK,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_F11, KC_F4, KC_F5, KC_F6, KC_PSCR,    KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT, KC_NO,
    KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

    KC_CAPS, KC_APP, KC_INS,
    KC_NO,   KC_NO,  KC_NO
    ),

[MOUSE] = LAYOUT_split_3x5_3(
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO, KC_WH_L, KC_MS_U, KC_WH_R, KC_NO,
    KC_NO, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI,    KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO, KC_WH_D, KC_WH_U, KC_NO,   KC_NO,

    KC_NO,   KC_NO,   KC_NO,
    KC_BTN1, KC_BTN3, KC_BTN2
    )
};
