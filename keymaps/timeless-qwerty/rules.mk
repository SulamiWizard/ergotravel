VIA_ENABLE = yes
SEND_STRING_ENABLE = yes

# No LEDs on this board's build and no mouse keys in this keymap - drop both
# to reclaim flash (rgblight/RGB effects are one of the biggest single users).
RGBLIGHT_ENABLE = no
MOUSEKEY_ENABLE = no

# Free size reduction via link-time optimization.
LTO_ENABLE = yes
