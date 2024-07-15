# mes rules custom
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
SEND_STRING_ENABLE = yes
# RGB_MATRIX_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMMAND_ENABLE = no
LTO_ENABLE = yes
TAP_DANCE_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = is31fl3731
# VIA_ENABLE = YES
OLED_ENABLE = yes
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
SPLIT_KEYBOARD = yes

BOOTLOADER = rp2040
CONVERT_TO = rp2040_ce

SRC += custom_files/french_symbols/french_symbols.c # include into the compilation
SRC += custom_files/*.c