#include QMK_KEYBOARD_H

#define BASE 0
#define NUM 1
#define FN 2
#define NAV 3


// Key definitions

#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)
#define HOME_D LGUI_T(KC_D)
#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_H RGUI_T(KC_H)


// Custom keycodes

enum custom_keycodes {
  TG_RUS = SAFE_RANGE,
  ESCAPE
};


// Combos

enum combo_events {
  CMB_RUS,
  CMB_ESC,
  CMB_NAV,
  CMB_NUM,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM cmb_rus[] = {HOME_R, HOME_S, HOME_T, COMBO_END};
const uint16_t PROGMEM cmb_esc[] = {HOME_N, HOME_E, HOME_I, COMBO_END};
const uint16_t PROGMEM cmb_nav[] = {KC_X, KC_C, HOME_D, COMBO_END};
const uint16_t PROGMEM cmb_num[] = {HOME_H, KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
  [CMB_RUS] = COMBO(cmb_rus, TG_RUS),
  [CMB_ESC] = COMBO(cmb_esc, ESCAPE),
  [CMB_NAV] = COMBO(cmb_nav, TO(NAV)),
  [CMB_NUM] = COMBO(cmb_num, TO(NUM)),
};


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
// (enable for home block mods and space)
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
  case LT(NAV, KC_SPC):
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

    KC_NO,   LT(NAV, KC_SPC), KC_APP,
    OSL(FN), OSL(NUM),        KC_NO
    ),

[NUM] = LAYOUT_split_3x5_3(
    KC_6,    KC_4,  KC_2,    KC_0,    KC_8,       KC_9,    KC_1,    KC_3,    KC_5,    KC_7,
    KC_PERC, KC_LT, KC_LBRC, KC_LPRN, KC_LCBR,    KC_CIRC, KC_MINS, KC_EQL,  KC_PLUS, KC_ASTR,
    KC_NO,   KC_GT, KC_RBRC, KC_RPRN, KC_RCBR,    KC_TILD, KC_EXLM, KC_COMM, KC_DOT,  KC_SLSH,

    KC_NO,   KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_NO
    ),

[FN] = LAYOUT_split_3x5_3(
    KC_F6,   KC_F4, KC_F2,   KC_F10, KC_F8,    KC_F9, KC_F1,   KC_F3,   KC_F5,   KC_F7,
    KC_PIPE, KC_AT, KC_HASH, KC_DLR, KC_NO,    KC_NO, KC_UNDS, KC_AMPR, KC_BSLS, KC_GRV,
    KC_NO,   KC_NO, KC_NO,   KC_NO,  KC_NO,    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_DQUO,

    KC_NO,   KC_NO,   CW_TOGG,
    KC_TRNS, KC_TRNS, KC_NO
    ),

[NAV] = LAYOUT_split_3x5_3(
    QK_BOOT, KC_NO,         KC_NO,         KC_NO,         KC_NO,    KC_NO,   KC_PGUP, KC_UP,   KC_PGDN, KC_NO,
    KC_NO,   OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_NO,    KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
    KC_NO,   KC_NO,         KC_NO,         OSM(MOD_LGUI), KC_NO,    KC_NO,   KC_BSPC, KC_TAB,  KC_DEL,  KC_NO,

    KC_NO, KC_TRNS, KC_NO,
    KC_NO, KC_ENT,  KC_NO
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // When RUS "layer" is on, base layer English letters and
  // punctuation keys are modified with RALT, e.g. RALT(q) is sent
  // instead of q, so that the OS can interpret them as Russian
  // letters using a custom layout. However, we do not send RALT if
  // any modifiers other than SHIFT are active so that shortcuts still
  // work, e.g. CTRL(q) is sent as is.
  static bool is_rus_on = false;
  if (is_rus_on &&
      (get_highest_layer(layer_state) == BASE) &&
      record->event.pressed) {
    if (get_mods() & (MOD_MASK_CG | MOD_BIT(KC_LALT))) {
      del_oneshot_mods(MOD_BIT(KC_RALT));
    } else {
      switch (keycode) {
      // thumb keys and combos:
      case TG_RUS:
      case ESCAPE:
      case LT(NAV, KC_SPC):
      case OSL(FN):
      case KC_APP:
      case OSL(NUM):
        del_oneshot_mods(MOD_BIT(KC_RALT));
        break;
      // Russian letters
      default:
        add_oneshot_mods(MOD_BIT(KC_RALT));
      }
    }
  }

  // To reduce the number of Russian letter keys, make some of them
  // send a different key when held.
  static uint16_t ru_yeyo_timer;
  static uint16_t ru_zee_timer;
  if (is_rus_on) {
    switch (keycode) {
    case KC_B: // RU_IE on tap, RU_YO on hold
      if (record->event.pressed) {
        ru_yeyo_timer = timer_read();
      } else {
        if (timer_elapsed(ru_yeyo_timer) < TAPPING_TERM) {
          tap_code(KC_B);
        } else {
          tap_code(KC_1);
        }
      }
      return false;
    case KC_QUOT: // RU_ZE on tap, RU_E on hold
      if (record->event.pressed) {
        ru_zee_timer = timer_read();
      } else {
        if (timer_elapsed(ru_zee_timer) < TAPPING_TERM) {
          tap_code(KC_QUOT);
        } else {
          tap_code(KC_2);
        }
      }
      return false;
    }
  }

  switch (keycode) {
  case TG_RUS:
    if (record->event.pressed) {
      is_rus_on = !is_rus_on;
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
  }

  return true;
}
