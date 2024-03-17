#include "quantum.h"
#include "keymap.h"

bool is_accent_layer(void) {
  return IS_LAYER_ON(_ACCENTS);
}

// bool is_accent_layer(void) {
//   return IS_LAYER_ON(_ACCENTS);
// }

bool is_shift_layer(void) {
  return IS_LAYER_ON(_SFT_COLEMAK_FR);
}

bool is_colemak_layer(void) {
  return IS_LAYER_ON(_COLEMAK_FR);
}