#ifndef GAME
#define GAME

#include "constants.h"
#include "timer.h"

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

namespace game
{
    extern bool quit;
    extern SDL_Window *window;
    extern SDL_Renderer *renderer;

    bool init ();
    void event ( SDL_Event event );
}

#endif // GAME_H_INCLUDED
