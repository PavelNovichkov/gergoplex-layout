#pragma once
#include QMK_KEYBOARD_H

bool is_rus_on(void);

void toggle_rus_layout(void);

bool process_rus_layout(uint16_t keycode, keyrecord_t* record);
