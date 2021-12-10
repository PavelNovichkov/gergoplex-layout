EXTRAKEY_ENABLE = yes # Audio control and System control
MOUSEKEY_ENABLE = yes # Mouse keys

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
