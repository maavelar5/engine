#ifndef INFO
#define INFO

#include "config.h"
#include "constants.h"
#include "font.h"
#include "game.h"
#include "texture.h"

#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace info
{
    extern uint8 y;
    extern SDL_Window * window;
    extern SDL_Renderer * renderer;
    extern bool show;

    void init () , draw ( std::string , SDL_Color color = white ),
        event ( SDL_Event );
}

#endif
