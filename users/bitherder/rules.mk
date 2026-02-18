# Bitherder's QMK User Space

# Enable custom shift keys module for Arensito layout
CUSTOM_SHIFT_KEYS_ENABLE = yes

# Add the custom_shift_keys module to include path so userspace headers can access it
EXTRAINCDIRS += $(TOP_DIR)/modules/getreuer/custom_shift_keys
