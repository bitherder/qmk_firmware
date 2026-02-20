# TODO List for QMK Firmware Fork

**NOTE: This TODO list should be removed once all items have been checked off.**

## Branch: extract-arensito-to-userspace-2026-02

### Remaining Tasks

- [ ] **Add clang-format directives to Levinson keymap**
  - Add formatting guide comment before keymaps array
  - Add `// clang-format off` before keymaps array
  - Add `// clang-format on` after keymaps array closing `};`
  - Similar to what was done for Iris keymap in keyboards/keebio/iris/keymaps/bitherder/keymap.c

- [ ] **Vertically align keycodes in Levinson layouts**
  - Each keycode should be padded to 9 characters total (keycode + comma + space padding)
  - Example: `KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    ...`
  - All 12 keycodes per row on a single line
  - IMPORTANT: Each keycode line MUST end with a comma (even the last keycode)
  - Align keycodes to match the box-drawing grid in comments above them
  - The grid uses `┌───────┬` pattern where each box represents one key column
  - Apply to all 7 layouts: QWERTY, ARENSITO, ARE_RAISE, ARE_LOWER, LOWER, RAISE, ADJUST, MOUSE
  
- [ ] **Test Levinson after formatting changes**
  - Run clean compile: `qmk compile -c -kb keebio/levinson/rev2 -km bitherder`
  - Verify firmware still builds successfully
  - Check that alignment is preserved after compile (clang-format directives working)

- [ ] **Flash and smoke test Levinson**
  - Flash updated firmware to Levinson keyboard
  - Test Arensito layout functionality
  - Verify custom shift keys work correctly (e.g., , → ? when shifted)
  - Test layer switching between QWERTY and Arensito

- [ ] **Merge branch to master**
  - Once all formatting is complete and tested
  - Merge extract-arensito-to-userspace-2026-02 into master
  - Update AGENTS.md if needed with any new learnings

### Completed Tasks

- [x] Extract Arensito custom shift keys to userspace as macro
- [x] Update Iris to use ARENSITO_CUSTOM_SHIFT_KEYS macro
- [x] Update Levinson to use ARENSITO_CUSTOM_SHIFT_KEYS macro
- [x] Remove manual shift handling code from Levinson
- [x] Add clang-format directives to Iris keymap
- [x] Vertically align Iris keymap layouts
- [x] Clean up commented code in arensito.h
- [x] Add EXTRAINCDIRS to userspace rules.mk
- [x] Verify both keyboards compile with clean builds

## Future Improvements

### Explore Better Solutions for Custom Shift Keys Module Integration

The current implementation uses a compromise solution where:
- Key mappings are defined once in userspace as a macro (ARENSITO_CUSTOM_SHIFT_KEYS)
- Each keyboard must still create its own custom_shift_keys[] array using that macro
- This is required due to the module's introspection system using ARRAY_SIZE()

Potential alternatives to explore:
1. Contribute patch to QMK to support extern arrays in module introspection
2. Create custom introspection functions that work with userspace arrays
3. Use preprocessor techniques to share the actual array definition
4. Fork/modify the custom_shift_keys module to support userspace integration

### Extract More Arensito Elements to Userspace

Consider extracting additional Arensito-specific elements:
- Layer switching logic (currently in each keyboard's process_record_user)
- Common layer definitions or macros
- Shared macros for layer switching keycodes

### Documentation

- Update users/bitherder/README.md with details about the Arensito userspace integration
- Document the custom_shift_keys compromise solution more thoroughly
- Add examples of how to use the userspace in new keyboards
