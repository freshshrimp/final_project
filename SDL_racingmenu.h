#ifndef SDL_RACING_H
#define SDL_RACING_H

#include <SDL2/SDL.h>
#include "SDL_basic.h"
#include <time.h>
#include <stdio.h>

extern void reset_racing_virable();
extern int racing_event_loop(struct horse_data ** horse_data_array);

#endif