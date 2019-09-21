#ifndef INFO
#define INFO

#include "font.h"
#include "game.h"
#include "texture.h"
#include "sdl_inclusion.h"

#include <memory>

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
