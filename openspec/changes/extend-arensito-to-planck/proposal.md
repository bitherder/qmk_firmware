## Why

The Arensito layout is currently configured separately for each keyboard (Iris, Levinson, Planck), leading to duplication and inconsistency. The Iris and Levinson keymaps have been normalized to use a shared userspace approach (`users/bitherder/arensito.h`), but the Planck keymap still uses a different method. Migrating Planck to the userspace approach will eliminate duplication and ensure consistent behavior across all keyboards.

## What Changes

- Update Planck keymap to use the shared `ARENSITO_CUSTOM_SHIFT_KEYS` macro from `users/bitherder/arensito.h`
- Define `custom_shift_keys[]` array in Planck keymap using the shared macro
- Ensure Planck's `keymap.json` includes the `getreuer/custom_shift_keys` module
- Verify Planck rules.mk has required configuration for the custom shift keys module

## Capabilities

### New Capabilities
- (none - this is a migration of existing functionality)

### Modified Capabilities
- (none - the Arensito capability itself is unchanged, only the implementation approach)

## Impact

- **Affected code**:
  - `keyboards/planck/keymaps/bitherder/` (keymap files)
  - `users/bitherder/arensito.h` (may need Planck-specific additions if Iris/Levinson differ)
