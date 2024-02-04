// Based on https://docs.qmk.fm/#/feature_macros?id=super-alt%e2%86%aftab.

#include "window_switcher.h"

bool is_window_switcher_active = false;
uint16_t window_switcher_timer = 0;

bool process_window_switcher(uint16_t keycode, keyrecord_t* record,
                             uint16_t switch_keycode) {
  if (keycode != switch_keycode) {
    return true;
  }

  if (record->event.pressed) {
    if (!is_window_switcher_active) {
      is_window_switcher_active = true;
      register_code(KC_LWIN);
    }
    window_switcher_timer = timer_read();
    register_code(KC_COMM);
  } else {
    unregister_code(KC_COMM);
  }

  return false;
}

void window_switcher_task(void) {
  if (is_window_switcher_active) {
    if (timer_elapsed(window_switcher_timer) > 500) {
      unregister_code(KC_LWIN);
      is_window_switcher_active = false;
    }
  }
}
