// Copyright 2026 bitherder
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include QMK_KEYBOARD_H

// Include the custom_shift_keys module header
// The module path is added to EXTRAINCDIRS in users/bitherder/rules.mk
#include "custom_shift_keys.h"

// NOTE: Arensito layer indices (_ARENSITO, _ARE_RAISE, _ARE_LOWER) should be
// defined in each keyboard's keymap.c within the custom_layers enum, as layer
// ordering may vary between keyboards.

// ============================================================================
// ARENSITO CUSTOM SHIFT KEYS
// ============================================================================
// Custom shift keys for Arensito layout
// These provide custom shifted behavior for Arensito-specific keys
// See: https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
//
// IMPLEMENTATION NOTE: This is a compromise solution due to QMK module limitations.
// The Arensito key mappings are defined here in userspace as a macro, but each
// keyboard must still define its own custom_shift_keys[] array in keymap.c using
// this macro. This is required because the custom_shift_keys module's introspection
// system uses ARRAY_SIZE() which only works on directly-defined arrays, not extern
// references. While not ideal, this approach at least centralizes the key mapping
// data so changes only need to be made in one place (this file).
//
// Usage in keymap.c:
//   const custom_shift_key_t custom_shift_keys[] = {
//       ARENSITO_CUSTOM_SHIFT_KEYS
//   };
//
#define ARENSITO_CUSTOM_SHIFT_KEYS                          \
    {KC_COMM, KC_QUES},      /* , becomes ? when shifted */ \
        {KC_AT, KC_HASH},    /* @ becomes # when shifted */ \
        {KC_PIPE, KC_AMPR},  /* | becomes & when shifted */ \
        {KC_DQT, KC_TILD},   /* " becomes ~ when shifted */ \
        {KC_QUOT, KC_GRAVE}, /* ' becomes ` when shifted */ \
    {                                                       \
        KC_DOT, KC_EXLM                                     \
    } /* . becomes ! when shifted */
