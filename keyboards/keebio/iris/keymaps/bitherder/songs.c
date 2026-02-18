#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
  float guitar_song[][2] = SONG(GUITAR_SOUND);
  float caps_lock_on_song[][2] = SONG(CAPS_LOCK_ON_SOUND);
  float caps_lock_off_song[][2] = SONG(CAPS_LOCK_OFF_SOUND);
  float ctr_lock_on_song[][2] = SONG(Q__NOTE(_A5), Q__NOTE(_B5));
  float ctr_lock_off_song[][2] = SONG(Q__NOTE(_B5), Q__NOTE(_A5));
  float alt_lock_on_song[][2] = SONG(Q__NOTE(_B5), Q__NOTE(_CS6));
  float alt_lock_off_song[][2] = SONG(Q__NOTE(_CS6), Q__NOTE(_B5));
  float gui_lock_on_song[][2] = SONG(Q__NOTE(_CS6), Q__NOTE(_D6));
  float gui_lock_off_song[][2] = SONG(Q__NOTE(_D6), Q__NOTE(_CS6));
#endif
