# Bitherder's QMK Firmware Fork

This document contains important context about this QMK firmware fork for future reference and AI assistant sessions.

## Repository Setup

- **Fork Owner**: bitherder
- **Upstream Remote**: `qmk` (https://github.com/qmk/qmk_firmware.git)
- **Origin Remote**: `origin` (git@github.com:bitherder/qmk_firmware.git)

## Update Workflow

To update this fork with the latest QMK firmware:

1. Fetch from upstream: `git fetch qmk`
2. Switch to local master: `git checkout master`
3. Merge upstream: `git merge qmk/master`

## Keyboards and Revisions

### Active Keyboards

1. **Keebio Iris Rev3** - Daily driver keyboard at main location
   - Keymap location: `keyboards/keebio/iris/keymaps/bitherder/`
   - Compile: `qmk compile -kb keebio/iris/rev3 -km bitherder`
   - Flash: `qmk flash -kb keebio/iris/rev3 -km bitherder`
   - Firmware size: ~98% capacity (28250/28672 bytes)

2. **Keebio Levinson Rev2** - Travel keyboard
   - Keymap location: `keyboards/keebio/levinson/keymaps/bitherder/`
   - Compile: `qmk compile -kb keebio/levinson/rev2 -km bitherder`
   - Flash: `qmk flash -kb keebio/levinson/rev2 -km bitherder`
   - Firmware size: ~83% capacity (23798/28672 bytes)

### Other Keymaps

- **Planck**: `keyboards/planck/keymaps/bitherder/`
- **Preonic**: `keyboards/preonic/keymaps/bitherder/`

## Commit Message Format

All commits follow this format:
```
bitherder:<keyboard>: <intent-based message>
```

Examples:
- `bitherder:levinson: fix mouse keycode MS_RIGHT to MS_RGHT for QMK compatibility`
- `bitherder:iris: update mouse keycode MS_RIGHT to MS_RGHT for QMK compatibility`

## Branch Naming Conventions

- Feature/update branches: `<Keyboard>-<purpose>-YYYY-MM`
  - Example: `Levinson-update-2026-02`
- Bug fix branches: `fix-<keyboard>-<issue>-YYYY-MM`
  - Example: `fix-levinson-mouse-keycodes-2026-02`

## Known Issues and Fixes

### QMK Firmware Updates (Feb 2026)

When updating to the latest QMK firmware (as of Feb 2026), the following breaking change was encountered:

- **Mouse keycode rename**: `MS_RIGHT` → `MS_RGHT`
  - Affected: Levinson keymap line 225
  - Fixed in: `fix-levinson-mouse-keycodes-2026-02` branch

## Build Notes

- Both keyboards successfully compile with QMK firmware as of Feb 2026
- Iris Rev3 is near capacity (98% full) - be mindful when adding features
- Levinson Rev2 has more headroom (83% full)

## Untracked Files

The following files may be present but are not yet committed:
- `keyboards/keebio/iris/keymaps/bitherder/songs.c`
- `keyboards/keebio/iris/keymaps/bitherder/songs.h`

## Testing After Updates

After pulling upstream changes, always verify both active keyboards compile:
```bash
qmk compile -kb keebio/iris/rev3 -km bitherder
qmk compile -kb keebio/levinson/rev2 -km bitherder
```
