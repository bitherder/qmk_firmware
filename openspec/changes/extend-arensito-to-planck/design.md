## Context

The Planck keyboard currently has an Arensito layout implementation that differs from the Iris and Levinson keyboards. The Planck uses a manual shift layer (`_ARE_SHIFT`) with pre-shifted keycodes (e.g., `S(KC_QUOTE)` for the `' → \`` shift), while Iris and Levinson use the `getreuer/custom_shift_keys` community module with a shared `ARENSITO_CUSTOM_SHIFT_KEYS` macro from `users/bitherder/arensito.h`.

The userspace approach is cleaner because:
- Shift mappings are centralized in one file (`users/bitherder/arensito.h`)
- The `custom_shift_keys` module provides automatic shifted output without needing a separate layer
- Changes to Arensito shift behavior only need to be made in one place

## Goals / Non-Goals

**Goals:**
- Migrate Planck Arensito to use the `custom_shift_keys` module approach
- Reuse the shared `ARENSITO_CUSTOM_SHIFT_KEYS` macro from `users/bitherder/arensito.h`
- Remove the `_ARE_SHIFT` layer (custom_shift_keys module handles shifted characters)
- Improve keymap readability: remove ASCII art diagrams, use inline row comments, add clang-format directives

**Non-Goals:**
- Change the Arensito layout finger positions (the layout itself stays the same)
- Modify Iris or Levinson keymaps (they already use the correct approach)
- Add layers to Planck

## Decisions

1. **Use custom_shift_keys module**: Adopt the same approach as Iris/Levinson using `getreuer/custom_shift_keys` module. This provides cleaner shifted character handling without manual S() wrapping.

2. **Reuse existing macro**: Use the existing `ARENSITO_CUSTOM_SHIFT_KEYS` macro from `users/bitherder/arensito.h`. The macro already defines the correct shift mappings:
   - `,` → `?`
   - `@` → `#`
   - `|` → `&`
   - `"` → `~`
   - `'` → `` ` ``
   - `.` → `!`

3. **Define custom_shift_keys[] in Planck keymap**: Due to QMK module limitations (ARRAY_SIZE() requires direct definition), each keyboard must define its own `custom_shift_keys[]` array, but it uses the shared macro.

4. **Add keymap.json with module**: Create `keymaps/bitherder/keymap.json` to enable the `getreuer/custom_shift_keys` module (required for the module to work).

5. **Update rules.mk if needed**: Verify Planck's rules.mk includes necessary configuration for custom shift keys (may need `EXTRAINCDIRS` like other keyboards).

## Risks / Trade-offs

- **Risk**: Planck's current Arensito layout may differ slightly from Iris/Levinson layout positions
  - **Mitigation**: Review the keymap to ensure layout consistency before migrating

- **Risk**: Build capacity may increase with the additional module
  - **Mitigation**: Run clean compile after changes to verify firmware size

- **Trade-off**: Still need to define `custom_shift_keys[]` array in Planck keymap (not just reference from userspace) due to QMK module limitations. This is the same limitation Iris/Levinson have.
