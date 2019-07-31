#ifndef FONT
#define FONT

#include "constants.h"
#include "game.h"

#include <iostream>
#include <map>
#include <SDL2/SDL_ttf.h>

namespace font
{
    extern std::map < uint8 , TTF_Font * > fonts;

    void init ( std::string path = SANS_FONT_FILE_PATH,
                std::vector < uint8 > sizes = { 8 , 12 , 16 , 24 , 32 } );

    SDL_Texture * createTexture ( std::string message , uint8 size = 12,
                                  SDL_Color color = white,
                                  SDL_Renderer *renderer = game::renderer );
}

#endif
