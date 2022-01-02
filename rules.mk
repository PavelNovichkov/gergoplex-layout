EXTRAKEY_ENABLE = yes # Audio control and System control
KEY_OVERRIDE_ENABLE = yes # Override shift + key

# Debug options
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE = no
DEBUG_MATRIX = no
CONSOLE_ENABLE = no

# Combos
# VPATH+=keyboards/gboards/

# Copied from default layout
ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
