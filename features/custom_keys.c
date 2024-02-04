// Copyright 2021-2023 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Custom keys implementation that correctly handles shifted keys and
// plays well with QMK repeat key. This code is based on
// <https://getreuer.info/posts/keyboards/custom-shift-keys>,
// modified by @PavelNovichkov.
//
// An alternative to this implementation is QMK key overrides with
// KEY_OVERRIDE_INCLUDE_WEAK_MODS setting enabled (without this
// setting, repeat key does not respect the override).

#include "custom_keys.h"

void process_custom_key(keyrecord_t* record, uint16_t kc, uint16_t kc_shifted) {
  static uint16_t kc_registered = KC_NO;

  // Unregister previously registered custom key.
  if (kc_registered != KC_NO) {
    unregister_code16(kc_registered);
    kc_registered = KC_NO;
  }

  if (record->event.pressed) {
    const uint8_t mods = get_mods();
    if ((mods | get_weak_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
      // shifted
      kc_registered = kc_shifted;
      if ((QK_MODS_GET_MODS(kc_registered) & MOD_MASK_SHIFT) != 0) {
        register_code16(kc_registered);
      } else {
        // Cancel shift mods, press the key, and restore mods.
        del_weak_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);
        unregister_mods(MOD_MASK_SHIFT);
        register_code16(kc_registered);
        set_mods(mods);
      }
    } else {
      // not shifted
      kc_registered = kc;
      register_code16(kc_registered);
    }
  }
}
