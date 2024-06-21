#include "SDL_music.h"

Uint8 *audio_buf;
Uint32 audio_len;
Uint32 audio_pos = 0;
SDL_AudioDeviceID device_id;

void callback(void *userdata, Uint8 *stream, int len)   //和播音樂相關的函式
{
    int remain = (int)audio_len - (int)audio_pos;
    if(remain > len)
    {
        SDL_memcpy(stream, audio_buf + audio_pos, len);
        audio_pos += len;
    }
    else
    {
        SDL_memcpy(stream, audio_buf + audio_pos, remain);
        audio_pos = 0;
    }
}

void play_music(const char *music_name) //播音樂
{
    SDL_AudioSpec desired_spec;
    SDL_AudioSpec obtained_spec;

    // 導入wav文件
    if (SDL_LoadWAV(music_name, &desired_spec, &audio_buf, &audio_len) == NULL)
    {
        SDL_Log("SDL_LoadWAV failed: %s", SDL_GetError());
        return;
    }

    // 設置回調函數
    desired_spec.callback = callback;

    // 開啟音訊設備
    device_id = SDL_OpenAudioDevice(NULL, 0, &desired_spec, &obtained_spec, 0);
    if (device_id == 0)
    {
        SDL_Log("SDL_OpenAudioDevice failed: %s", SDL_GetError());
        SDL_FreeWAV(audio_buf); // 釋放音訊資源
        return;
    }

    // 開始撥放音樂
    SDL_PauseAudioDevice(device_id, 0);
}

void deinit_music()   //銷毀音樂
{
    //銷毀音樂資源
    SDL_FreeWAV(audio_buf);
    SDL_CloseAudioDevice(device_id);
}