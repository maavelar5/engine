#ifndef HUD
#define HUD

#include "constants.h"
#include "game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

extern const SDL_Color white , black;

extern const SDL_Rect LT , T , RT;

namespace hud
{
    extern TTF_Font *Sans;
    extern SDL_Texture *texture;

    void init () , draw ( std::string , SDL_Rect position = T , SDL_Color color = white );
}

#endif
