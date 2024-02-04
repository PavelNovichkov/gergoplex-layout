CAPS_WORD_ENABLE = yes # Smart Caps Lock
EXTRAKEY_ENABLE = yes # Audio control and System control
REPEAT_KEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
LTO_ENABLE = yes # reduce firmware size

SRC += features/custom_keys.c
SRC += features/rus_layout.c

# Debug options
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE = no
DEBUG_MATRIX = no
CONSOLE_ENABLE = yes # for the heatmap
SRC += features/heatmap.c

# Combos
COMBO_ENABLE = yes

# Copied from default layout
ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
