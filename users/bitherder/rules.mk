# Bitherder's QMK User Space

# Add the custom_shift_keys module to include path so userspace headers can access it
# The module itself is enabled via keymap.json in each keyboard's keymap directory
EXTRAINCDIRS += $(TOP_DIR)/modules/getreuer/custom_shift_keys
