#pragma once
#include QMK_KEYBOARD_H

bool process_window_switcher(uint16_t keycode, keyrecord_t* record,
                             uint16_t switch_keycode);

void window_switcher_task(void);
