#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MUSIC_MASK (keycode != KC_NO)

#endif
