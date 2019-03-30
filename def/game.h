#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "constants.h"
#include "timer.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

extern bool quit;
extern SDL_Window *window;
extern SDL_Renderer *renderer;

bool gameInit ();
void gameEvent ( SDL_Event event );

#endif // GAME_H_INCLUDED
