## 1. Configuration Files

- [x] 1.1 Create `keyboards/planck/keymaps/bitherder/keymap.json` with `getreuer/custom_shift_keys` module
- [x] 1.2 Add `USER_NAME := bitherder` to Planck `rules.mk` (userspace rules.mk handles EXTRAINCDIRS)

## 2. Keymap Updates

- [x] 2.1 Add `#include "custom_shift_keys.h"` to Planck keymap.c
- [x] 2.2 Add `custom_shift_keys[]` array using `ARENSITO_CUSTOM_SHIFT_KEYS` macro
- [x] 2.3 Remove manual `S()` wrapping from Arensito base layer keycodes
- [x] 2.4 Remove `_ARE_SHIFT` layer (custom_shift_keys handles shifted characters)

## 3. Formatting Improvements

- [x] 3.1 Add clang-format directives (`// clang-format off`/`on`) around keymaps array
- [x] 3.2 Remove ASCII art diagrams before each layout
- [x] 3.3 Replace with inline row comments (e.g., `// Row 1`, `// Row 2`, etc.)
- [x] 3.4 Ensure vertically aligned keycode columns

## 4. Testing

- [x] 4.1 Run clean compile for Planck: `qmk compile -c -kb planck/rev6 -km bitherder`
- [x] 4.2 Verify Arensito shifted characters work correctly (`, → ?`, `' → `` `, etc.)
- [x] 4.3 Verify all other layers still work (QWERTY, Lower, Raise, Adjust, Mouse)

## 5. Documentation

- [x] 5.1 Update AGENTS.md to add Planck keyboard to Active Keyboards section
