#ifndef INFO
#define INFO

#include "constants.h"
#include "font.h"
#include "game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace info
{
    extern Uint8 x , y;

    void init () , draw ( std::string , std::string , SDL_Color color = white );
}

#endif
