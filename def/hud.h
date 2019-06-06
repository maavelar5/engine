#ifndef HUD
#define HUD

#include "constants.h"
#include "font.h"
#include "game.h"

#include <SDL2/SDL.h>

namespace hud
{
    void draw ( std::string , SDL_Rect position = T , SDL_Color color = white );
}

#endif
