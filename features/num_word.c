#include "num_word.h"
#include "../definitions.h"

bool is_num_word_active = false;
uint16_t num_word_timer = 0;

void enable_num_word(void) {
  layer_on(NUM);
  is_num_word_active = true;
  num_word_timer = timer_read();
} 

void disable_num_word(void) {
  layer_off(NUM);
  is_num_word_active = false;
} 

void toggle_num_word(void) {
  if (is_num_word_active) {
    disable_num_word();
  } else {
    enable_num_word();
  }
}

bool process_num_word(uint16_t keycode, keyrecord_t* record,
                      uint16_t toggle_keycode) {
  if (keycode == toggle_keycode) {
    if (record->event.pressed) {
      toggle_num_word();
    }
    return false;
  }

  if (!is_num_word_active) { return true; }

  switch (keycode) {
  case KC_2 ... KC_9:
  case LCTL_T(KC_0):
  case RCTL_T(KC_1):
  case KC_COMM:
  case KC_DOT:
  case MY_EN_D:
  case MY_EUR:
  case KC_BSPC:
    num_word_timer = timer_read();
    break;
  default:
    disable_num_word();
  }

  return true;
}

void num_word_task(void) {
  if (is_num_word_active) {
    if (timer_elapsed(num_word_timer) > 5000) {
      disable_num_word();
    }
  }
}
