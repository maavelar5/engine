#ifndef HUD
#define HUD

#include "constants.h"
#include "game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace hud
{
    extern TTF_Font *Sans;
    extern SDL_Texture *texture;

    void init () , draw ( std::string );
}

#endif
