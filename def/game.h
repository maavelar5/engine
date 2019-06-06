#ifndef GAME
#define GAME

#include "constants.h"
#include "timer.h"

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <SDL2/SDL_ttf.h>

namespace game
{
    extern bool quit;
    extern SDL_Window *window , *debugWindow;
    extern SDL_Renderer *renderer , *debugRenderer;

    bool init () , initDebugObjects ();
    void event ( SDL_Event event );
}

#endif // GAME_H_INCLUDED
