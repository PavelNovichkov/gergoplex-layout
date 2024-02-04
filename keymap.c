#include QMK_KEYBOARD_H
#include "definitions.h"
#include "features/rus_layout.h"
#include "features/custom_keys.h"

// Combos

enum combo_events {
  CMB_BSPC,
  CMB_CW,
  CMB_DEL,
  CMB_ENT,
  CMB_ESC,
  CMB_RUS,
  CMB_TAB
};

// Left hand
const uint16_t PROGMEM cmb_esc[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_rus[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM cmb_del[] = {KC_C, HOME_D, COMBO_END};
const uint16_t PROGMEM cmb_ent[] = {KC_X, KC_C, COMBO_END};

// Right hand
const uint16_t PROGMEM cmb_cw[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM cmb_bspc[] = {HOME_H, MY_COMM, COMBO_END};
const uint16_t PROGMEM cmb_tab[] = {MY_COMM, MY_DOT, COMBO_END};

combo_t key_combos[] = {
  [CMB_BSPC] = COMBO(cmb_bspc, KC_BSPC),
  [CMB_CW] = COMBO(cmb_cw, CW_TOGG),
  [CMB_DEL] = COMBO(cmb_del, KC_DEL),
  [CMB_ENT] = COMBO(cmb_ent, KC_ENT),
  [CMB_ESC] = COMBO(cmb_esc, ESCAPE),
  [CMB_RUS] = COMBO(cmb_rus, TG_RUS),
  [CMB_TAB] = COMBO(cmb_tab, KC_TAB),
};


// Layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_split_3x5_3(
    KC_Q, KC_W,   KC_F,   KC_P,   KC_B,    KC_J, KC_L,   KC_U,    KC_Y,   KC_QUOT,
    KC_A, HOME_R, HOME_S, HOME_T, KC_G,    KC_M, HOME_N, HOME_E,  HOME_I, KC_O,
    KC_Z, KC_X,   KC_C,   HOME_D, KC_V,    KC_K, HOME_H, MY_COMM, MY_DOT, KC_SLSH,

    KC_NO,  LT(NAV, KC_SPC), KC_APP,
    QK_REP, OSL(SYM),        KC_NO
    ),

[SYM] = LAYOUT_split_3x5_3(
    KC_AT,   KC_LBRC, KC_RBRC,         KC_DLR,          KC_NO,      KC_NO,   KC_AMPR,        KC_LT,   KC_GT,   KC_GRV,
    KC_PERC, KC_LPRN, LSFT_T(KC_RPRN), LCTL_T(KC_UNDS), KC_HASH,    KC_CIRC, RCTL_T(KC_EQL), KC_MINS, KC_PLUS, KC_ASTR,
    KC_PIPE, KC_LCBR, KC_RCBR,         KC_BSLS,         KC_NO,      KC_TILD, KC_EXLM,        KC_COMM, KC_DOT,  KC_SLSH,

    KC_NO,   OSL(NUM), OSL(FN),
    KC_TRNS, KC_TRNS,  KC_NO
    ),

[NUM] = LAYOUT_split_3x5_3(
    KC_NO, MY_LGQT, MY_RGQT, KC_NO,        KC_NO,     KC_NO,   MY_EM_D,      MY_EN_D, MY_ELPS, KC_NO,
    KC_6,  KC_4,    KC_2,    LCTL_T(KC_0), MY_EUR,    MY_NBSP, RCTL_T(KC_1), KC_3,    KC_5,    KC_7,
    KC_NO, MY_LDQT, MY_RDQT, KC_8,         KC_NO,     KC_NO,   KC_9,         MY_LSQT, MY_RSQT, KC_NO,

    KC_NO,   KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_NO
    ),

[NAV] = LAYOUT_split_3x5_3(
    // QK_BOOT, KC_BRID,       KC_BRIU,       TO(MOUSE),     KC_MUTE,    KC_NO,   KC_PGUP, KC_UP,   KC_PGDN, KC_NO,
    QK_BOOT, KC_BRID,       KC_BRIU,       KC_NO,         KC_MUTE,    KC_NO,   KC_PGUP, KC_UP,   KC_PGDN, KC_NO,
    CW_TOGG, OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_VOLD,    KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
    TG_RUS,  KC_ESC,        KC_ENT,        OSM(MOD_LGUI), KC_VOLU,    KC_NO,   KC_BSPC, KC_TAB,  KC_DEL,  KC_NO,

    KC_NO,   KC_TRNS,  KC_TRNS,
    KC_TRNS, OSL(NUM), KC_NO
    ),

[FN] = LAYOUT_split_3x5_3(
    KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,     KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_NO,
    KC_F6, KC_F4, KC_F2, KC_F10, KC_F12,    KC_F11, KC_F1, KC_F3,   KC_F5,   KC_F7,
    KC_NO, KC_NO, KC_NO, KC_F8,  KC_NO,     KC_NO,  KC_F9, KC_PSCR, KC_WAKE, KC_NO,

    KC_NO,   KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_NO
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_rus_layout(keycode, record)) { return false; }

  switch (keycode) {
  case MY_COMM:
    process_custom_key(record, KC_COMM, KC_SCLN);
    return false;
  case MY_DOT:
    process_custom_key(record, KC_DOT, KC_COLN);
    return false;
  case TG_RUS:
    if (record->event.pressed) {
      toggle_rus_layout();
    }
    break;
  case ESCAPE:
    if (record->event.pressed) {
      if (get_highest_layer(layer_state) != BASE) {
        layer_clear();
      } else {
        tap_code(KC_ESC);
      }
    }
    break;
    // Mod-tap cannot tap shifted keys, so we have to intercept it as
    // described in the QMK documentation.
  case LCTL_T(KC_UNDS):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_UNDS);
      return false;
    }
    break;
  case LSFT_T(KC_RPRN):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_RPRN);
      return false;
    }
    break;
  }

  return true;
}
