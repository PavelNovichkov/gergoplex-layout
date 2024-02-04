#include "rus_layout.h"
#include "../definitions.h"

bool rus_on = false;

bool is_rus_on(void) {
  return rus_on;
}

void toggle_rus_layout(void) {
  rus_on = !rus_on;
}

bool process_rus_layout(uint16_t keycode, keyrecord_t* record) {
  // When RUS "layer" is on, base layer English letters and
  // punctuation keys are modified with RALT, e.g. RALT(q) is sent
  // instead of q, so that the OS can interpret them as Russian
  // letters using a custom layout. However, we do not send RALT if
  // any modifiers other than SHIFT are active so that shortcuts still
  // work, e.g. CTRL(q) is sent as is.
  if (!is_rus_on()) {
    return true;
  }
  if ((get_mods() | get_oneshot_mods()) & (MOD_MASK_CG | MOD_BIT(KC_LALT))) {
    del_oneshot_mods(MOD_BIT(KC_RALT));
    return true;
  }
  if ((get_highest_layer(layer_state) == BASE) && record->event.pressed) {
    switch (keycode) {
    // Russian letters
    case KC_A ... KC_Z:
    case MY_COMM:
    case MY_DOT:
    case KC_SLSH:
    case KC_QUOT:
    case HOME_R:
    case HOME_S:
    case HOME_T:
    case HOME_D:
    case HOME_N:
    case HOME_E:
    case HOME_I:
    case HOME_H:
      add_oneshot_mods(MOD_BIT(KC_RALT));
    }
  }

  // To reduce the number of Russian letter keys, make some of them
  // send a different key when held.
  static uint16_t ru_yeyo_timer;
  static uint16_t ru_zee_timer;
  if (is_rus_on()) {
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

  return true;
}
