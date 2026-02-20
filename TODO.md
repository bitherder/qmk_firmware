# TODO List for QMK Firmware Fork

**NOTE: This TODO list should be removed once all items have been checked off.**

## Branch: extract-arensito-to-userspace-2026-02

### Remaining Tasks

- [ ] **Flash and smoke test Levinson**
  - Flash updated firmware to Levinson keyboard
  - Test Arensito layout functionality
  - Verify custom shift keys work correctly (e.g., , → ? when shifted)
  - Test layer switching between QWERTY and Arensito

- [ ] **Merge branch to master and update AGENTS.md**
  - Once testing is complete
  - Merge extract-arensito-to-userspace-2026-02 into master
  - Update AGENTS.md if needed with any new learnings
  - Note: master was previously merged at an earlier point; re-merge needed to pick up Levinson formatting commits

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
- [x] Remove redundant ASCII art layout comments from Levinson keymap
- [x] Add clang-format directives to Levinson keymap
- [x] Vertically align keycodes in all 8 Levinson layouts (8-char padding, matching Iris style)
- [x] Add visual split gap between left/right halves in Levinson box-drawing grid
- [x] Remove duplicate layout formatting guide comment from Iris keymap
- [x] Clean compile Levinson after all formatting changes (24544/28672 bytes, 85%)

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
