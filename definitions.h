#pragma once


#define BASE 0
#define SYM 1
#define NUM 2
#define NAV 3
#define FN 4
#define MOUSE 5


// Key definitions

#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)
#define HOME_D LGUI_T(KC_D)
#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_H RGUI_T(KC_H)

#define MY_ELPS RALT(KC_GRV)
#define MY_NBSP RSA(KC_GRV)
#define MY_EUR RALT(KC_4)
#define MY_LSQT RALT(KC_9)
#define MY_RSQT RALT(KC_0)
#define MY_EN_D RALT(KC_MINS)
#define MY_EM_D RSA(KC_MINS)
#define MY_LDQT RALT(KC_LBRC)
#define MY_RDQT RALT(KC_RBRC)
#define MY_LGQT RSA(KC_LBRC)
#define MY_RGQT RSA(KC_RBRC)

#define MY_COPY LCTL(KC_INS)
#define MY_PSTE LSFT(KC_INS)
#define MY_CUT LSFT(KC_DEL)

// Custom keycodes

enum custom_keycodes {
  TG_RUS = SAFE_RANGE,
  TG_NUM,
  MY_COMM,
  MY_DOT,
  MY_GRV,
  MY_AT,
  MY_PIPE,
  MY_LQT,
  MY_RQT,
  SW_WIN,
  ESCAPE
};
