#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "constants.h"
#include "timer.h"

#if __APPLE__ || __ANDROID__
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

namespace game
{
    extern SDL_bool quit;

    extern SDL_Window* window;
    extern SDL_Renderer* renderer;

    SDL_bool init ();
    void event ( SDL_Event event );
};

#endif // GAME_H_INCLUDED
