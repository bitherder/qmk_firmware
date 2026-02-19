// Copyright 2026 bitherder
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include QMK_KEYBOARD_H
#include "arensito.h"

// Main header for bitherder's user space
// Include this in your keymap.c files

// ============================================================================
// SHARED KEYCODES
// ============================================================================
// These keycodes are shared across all bitherder keymaps

// Currency and shifted keys
#define KC_EUR A(S(KC_2))   // Euro sign: Alt+Shift+2
#define KC_SNUHS S(KC_NUHS) // Shifted NUHS (non-US hash)
#define KC_SNUBS S(KC_NUBS) // Shifted NUBS (non-US backslash)

// Mod-tap keys
#define KC_CESC MT(MOD_LCTL, KC_ESC)  // Control when held, Escape when tapped
#define KC_S_ENT MT(MOD_RSFT, KC_ENT) // Right Shift when held, Enter when tapped

// Mouse layer access (when MOUSEKEY_ENABLE is set)
#define KC_D_MO LT(_MOUSE, KC_D) // Mouse layer on D key
#define KC_E_MO LT(_MOUSE, KC_E) // Mouse layer on E key
#define KC_MO MO(_MOUSE)         // Mouse layer momentary
