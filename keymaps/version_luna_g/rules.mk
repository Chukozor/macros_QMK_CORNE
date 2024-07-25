# mes rules custom
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
SEND_STRING_ENABLE = yes
# RGB_MATRIX_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMMAND_ENABLE = no
OLED_ENABLE = yes
LTO_ENABLE = yes
TAP_DANCE_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
SPLIT_KEYBOARD = yes
RGBLIGHT_ENABLE = yes
# VIA_ENABLE = YES

SRC += custom_files/french_symbols/french_symbols.c # include into the compilation
SRC += custom_files/helpers.c