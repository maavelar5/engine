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
                std::vector < uint8 > sizes = { 12 , 16 , 18 , 24 , 32 , 48 } );

    SDL_Texture * createTexture ( std::string message,
                                  SDL_Renderer *renderer,
                                  uint8 size = 18,
                                  SDL_Color color = white );
}

#endif
