#ifndef GAME
#define GAME

#include "config.h"
#include "controller.h"
#include "timer.h"

namespace game
{
    extern bool quit;
    extern SDL_Window *window;
    extern SDL_Renderer *renderer;

    bool init ();
    void event ( SDL_Event event );
}

#endif // GAME_H_INCLUDED
