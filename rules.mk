CAPS_WORD_ENABLE = yes # Smart Caps Lock
EXTRAKEY_ENABLE = yes # Audio control and System control
KEY_OVERRIDE_ENABLE = yes # Override shift + key
REPEAT_KEY_ENABLE = yes
SRC += features/rus_layout.c

# Debug options
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE = no
DEBUG_MATRIX = no
CONSOLE_ENABLE = no

# Combos
COMBO_ENABLE = yes

# Copied from default layout
ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
