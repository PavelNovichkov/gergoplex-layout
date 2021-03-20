EXTRAKEY_ENABLE = yes # Audio control and System control
MOUSEKEY_ENABLE = yes # Mouse keys

# Debug options
VERBOSE = yes
DEBUG_MATRIX_SCAN_RATE = no
DEBUG_MATRIX = yes
CONSOLE_ENABLE = yes

# Combos
# VPATH+=keyboards/gboards/

# Copied from default layout
SRC += matrix.c i2c_master.c
ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
