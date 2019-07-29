#ifndef FONT
#define FONT

#include "constants.h"
#include "game.h"

#include <iostream>
#include <SDL2/SDL_ttf.h>

namespace font
{
    extern TTF_Font *Sans;

    void init ( std::string fileName = SANS_FONT_FILE_PATH , Uint8 size = 128 );

    SDL_Texture * createTexture ( std::string message,
                                  SDL_Color color = white,
                                  SDL_Renderer *renderer = game::renderer );
}

#endif
