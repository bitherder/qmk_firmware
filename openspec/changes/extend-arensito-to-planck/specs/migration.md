# Planck Arensito Migration

This spec documents the migration of the Planck keyboard's Arensito layout implementation to use the userspace-based approach (matching Iris and Levinson).

## Summary

This is a **migration task** with no new or modified capabilities. The Arensito layout functional behavior remains identical; only the implementation approach changes.

### What Stays the Same

- Arensito base layer key positions
- Shifted character behavior (`, → ?`, `' → `` `, etc.)
- Layer structure (`_ARENSITO`, `_ARE_LO`, `_ARE_HI`, `_ARE_SHIFT`)
- Default layer switching behavior

### What Changes

- Implementation uses `custom_shift_keys` module instead of manual `S()` wrapping
- Configuration centralized in `users/bitherder/arensito.h` macro
- Keymap.json added with required module configuration

## Implementation Notes

This document serves as a marker that this change does not modify the existing Arensito capability specification. The implementation follows the same pattern as the Iris and Levinson keyboards.
