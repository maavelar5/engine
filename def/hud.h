#ifndef HUD
#define HUD

#include "constants.h"
#include "font.h"
#include "game.h"

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

namespace hud
{
    void draw ( std::string , SDL_Rect position = T , SDL_Color color = white );
}

#endif
