#ifndef TEXTURE
#define TEXTURE

#include "game.h"

#if __ANDROID__
#include <SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

#include <iostream>

struct Texture
{
    SDL_Texture *texture;

    Texture ( std::string filePath = GENERIC_PLATFORM_FILE_PATH );
    Texture ( SDL_Texture * );
    ~Texture ();
};

#endif
