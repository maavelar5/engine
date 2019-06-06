#ifndef GAME
#define GAME

#include "constants.h"
#include "timer.h"

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <Box2D/Box2D.h>

namespace game
{
    extern bool quit;
    extern SDL_Window *window;
    extern SDL_Renderer *renderer;

    bool init ();
    void event ( SDL_Event event );
}

namespace physics
{
    extern b2Vec2 gravity;
    extern b2World world;

    bool init ();
}

#endif // GAME_H_INCLUDED
