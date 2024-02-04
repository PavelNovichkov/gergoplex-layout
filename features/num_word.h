#pragma once
#include QMK_KEYBOARD_H

bool process_num_word(uint16_t keycode, keyrecord_t* record,
                      uint16_t toggle_keycode);

void num_word_task(void);
