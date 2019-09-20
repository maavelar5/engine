#ifndef CONTROLLER
#define CONTROLLER

#if __ANDROID__
#include <SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

namespace controller
{
    extern SDL_GameController * controller;

    void init ();
}

#endif
