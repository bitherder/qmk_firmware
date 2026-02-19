# AGENTS.md

This is bitherder's fork of QMK Firmware with custom keymaps for Keebio keyboards.

## Repository Setup

- **Fork Owner**: bitherder
- **Upstream Remote**: `qmk` (https://github.com/qmk/qmk_firmware.git)
- **Origin Remote**: `origin` (git@github.com:bitherder/qmk_firmware.git)

## Update Workflow

To update this fork with the latest QMK firmware:

```bash
git fetch qmk
git checkout master
git merge qmk/master
```

## Active Keyboards

### Keebio Iris Rev3 - Daily driver keyboard
- **Keymap location**: `keyboards/keebio/iris/keymaps/bitherder/`
- **Compile**: `qmk compile -kb keebio/iris/rev3 -km bitherder`
- **Clean compile**: `qmk compile -c -kb keebio/iris/rev3 -km bitherder`
- **Flash**: `qmk flash -kb keebio/iris/rev3 -km bitherder`
- **Firmware size**: ~98% capacity (28250/28672 bytes) - near maximum
- **Features**: RGB lighting, Audio, Combos, Leader key, Custom shift keys

### Keebio Levinson Rev2 - Travel keyboard
- **Keymap location**: `keyboards/keebio/levinson/keymaps/bitherder/`
- **Compile**: `qmk compile -kb keebio/levinson/rev2 -km bitherder`
- **Clean compile**: `qmk compile -c -kb keebio/levinson/rev2 -km bitherder`
- **Flash**: `qmk flash -kb keebio/levinson/rev2 -km bitherder`
- **Firmware size**: ~80% capacity (23190/28672 bytes)
- **Features**: Mouse keys, Custom shift keys
- **CRITICAL**: Levinson rules.mk MUST include `BOOTLOADER = atmel-dfu` for flashing to work. Do not remove this setting.

## Userspace Structure

Shared code is located in `users/bitherder/`:

- **README.md** - Documentation about this fork (for humans)
- **arensito.h** - Arensito layout definitions (custom shift keys macro)
- **bitherder.h** - Main userspace header (includes arensito.h)
- **rules.mk** - Userspace build configuration

### Arensito Layout

The Arensito alternative keyboard layout is shared across keyboards via userspace:

- Custom shift key mappings are defined in the `ARENSITO_CUSTOM_SHIFT_KEYS` macro in `users/bitherder/arensito.h`
- Each keyboard populates its `custom_shift_keys[]` array using this macro
- Requires `CUSTOM_SHIFT_KEYS_ENABLE = yes` in keyboard's rules.mk
- Uses the getreuer/custom_shift_keys community module

## Commit Message Format

All commits follow this format:
```
bitherder:<keyboard>: <intent-based message>
```

Examples:
- `bitherder:levinson: fix mouse keycode MS_RIGHT to MS_RGHT for QMK compatibility`
- `bitherder:iris: add clang-format directives to preserve layout visual alignment`
- `bitherder:userspace: extract Arensito custom shift keys to shared userspace`

For userspace changes, use `bitherder:userspace:` as the prefix.

## Branch Naming Conventions

- **Feature/update branches**: `<Keyboard>-<purpose>-YYYY-MM`
  - Example: `Levinson-update-2026-02`
- **Bug fix branches**: `fix-<keyboard>-<issue>-YYYY-MM`
  - Example: `fix-levinson-mouse-keycodes-2026-02`
- **Cross-keyboard branches**: `<purpose>-<scope>-YYYY-MM`
  - Example: `extract-arensito-to-userspace-2026-02`

## Build and Test Instructions

### Always Use Clean Compiles

When verifying changes, always use the `-c` flag for clean builds:
```bash
qmk compile -c -kb keebio/iris/rev3 -km bitherder
qmk compile -c -kb keebio/levinson/rev2 -km bitherder
```

This ensures:
- Community modules are properly regenerated
- Include paths are correctly configured
- No stale build artifacts cause issues

### Efficient Compile Output Analysis

When analyzing compile output, save the result to a file and interrogate it with multiple commands rather than re-running the compile:

```bash
# Run compile once and save output
qmk compile -c -kb keebio/levinson/rev2 -km bitherder 2>&1 > /tmp/compile_output.txt

# Then interrogate the saved output multiple times
grep "error:" /tmp/compile_output.txt
grep "Linking" /tmp/compile_output.txt
grep "firmware size" /tmp/compile_output.txt
grep "custom_shift" /tmp/compile_output.txt
```

This is much faster and more reliable than running the full compile multiple times with different filters.

### After Updating from Upstream

Always verify both active keyboards compile after pulling upstream changes:
```bash
qmk compile -c -kb keebio/iris/rev3 -km bitherder
qmk compile -c -kb keebio/levinson/rev2 -km bitherder
```

## Code Style and Formatting

### Layout Visual Alignment

LAYOUT macro calls use carefully aligned formatting to visually match the physical keyboard layout:

- Each keycode is padded to 8 characters (keycode + comma + space)
- Comment lines start with two spaces followed by `//`
- Box-drawing characters in comments align with keycodes
- Large visual gap between left and right keyboard halves (split keyboard)
- Thumb cluster row has 20 spaces before first keycode (for Iris)

**IMPORTANT**: This alignment is protected by `// clang-format off` and `// clang-format on` directives. Do NOT remove these directives or the auto-formatter will break the visual alignment.

Example from Iris:
```c
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] =  LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  ...
  )
};
// clang-format on
```

### Userspace Macro Formatting

The `ARENSITO_CUSTOM_SHIFT_KEYS` macro in `users/bitherder/arensito.h` also uses protected formatting:

```c
// clang-format off
#define ARENSITO_CUSTOM_SHIFT_KEYS                      \
    {KC_COMM, KC_QUES},  /* , becomes ? when shifted */ \
    {KC_AT,   KC_HASH},  /* @ becomes # when shifted */ \
    ...
    {KC_DOT,  KC_EXLM}   /* . becomes ! when shifted */ \
    /* END */
// clang-format on
```

The `/* END */` sentinel marker guides future additions - add new entries before it, maintaining the backslash continuation pattern.

## Known Issues and Fixes

### QMK Firmware Updates (Feb 2026)

When updating to the latest QMK firmware (as of Feb 2026):

- **Mouse keycode rename**: `MS_RIGHT` → `MS_RGHT`
  - Affected: Levinson keymap
  - Fixed in: `fix-levinson-mouse-keycodes-2026-02` branch

### Custom Shift Keys Module Integration

The custom_shift_keys community module has introspection limitations:

- **Issue**: Module's `ARRAY_SIZE()` macro requires direct array definition, not extern references
- **Compromise**: Define `ARENSITO_CUSTOM_SHIFT_KEYS` macro in userspace, but each keyboard must create its own `custom_shift_keys[]` array using that macro
- **Benefit**: Key mappings are still centralized in one place despite duplication of array definition
- **Details**: See comments in `users/bitherder/arensito.h`

## Security Considerations

- Never commit files that likely contain secrets (.env, credentials.json, etc.)
- Review all changes before committing
- Do not push to remote unless explicitly requested

## Additional Notes

- **Iris capacity warning**: The Iris Rev3 firmware is at 98% capacity - be very careful when adding features
- **Untracked files**: songs.c and songs.h for Iris may be present but uncommitted - handle with care
- **Module dependencies**: Custom shift keys require `CUSTOM_SHIFT_KEYS_ENABLE = yes` in both userspace and keyboard rules.mk
