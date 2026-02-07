/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define NO_MUSIC_MODE
#define AUDIO_PIN C6

// #define USE_I2C
// #define EE_HANDS

// Underlighting
// #undef RGBLED_NUM
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

// Mousekey configuration
/* #define MOUSEKEY_INTERVAL 16 */
/* #define MOUSEKEY_DELAY 0 */
/* #define MOUSEKEY_TIME_TO_MAX 60 */
/* #define MOUSEKEY_MAX_SPEED 7 */
/* #define MOUSEKEY_WHEEL_DELAY 0 */

// Taipo related
#undef NO_ACTION_ONESHOT

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 1000

#define COMBO_TERM 75
#define COMBO_MUST_HOLD_MODS
#define COMBO_SHOULD_TRIGGER
#define EXTRA_SHORT_COMBOS

#define TAP_CODE_DELAY 25
#define TAPPING_FORCE_HOLD

// Memory reduction
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
