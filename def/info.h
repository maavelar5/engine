#ifndef INFO
#define INFO

#include "constants.h"
#include "font.h"
#include "game.h"
#include "texture.h"

#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace info
{
    extern uint8 y;
    extern SDL_Window * window;
    extern SDL_Renderer * renderer;

    void init () , draw ( std::string , SDL_Color color = white );
}

#endif
