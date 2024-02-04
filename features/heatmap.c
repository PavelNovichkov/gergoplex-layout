// Based on <https://precondition.github.io/qmk-heatmap>.

#include "heatmap.h"
#include "print.h"

void heatmap_log(uint16_t keycode, keyrecord_t *record) {
  const bool is_combo = record->event.type == COMBO_EVENT;
  uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
          keycode,
          is_combo ? 254 : record->event.key.row,
          is_combo ? 254 : record->event.key.col,
          get_highest_layer(layer_state),
          record->event.pressed,
          get_mods(),
          get_oneshot_mods(),
          record->tap.count
          );
}
