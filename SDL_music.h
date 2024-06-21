#ifndef SDL_MUSIC_H
#define SDL_MUSIC_H

#include <SDL2/SDL.h>

extern Uint8 *audio_buf;
extern Uint32 audio_len;
extern Uint32 audio_pos;
extern SDL_AudioDeviceID device_id;

extern void callback(void *userdata, Uint8 *stream, int len);
extern void play_music(const char *music_name);
extern void deinit_music();

#endif
