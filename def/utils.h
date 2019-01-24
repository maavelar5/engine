#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "camera.h"
#include "constants.h"
#include "entity.h"
#include "game.h"
#include "timer.h"
#include "vector.h"

#include <algorithm>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


namespace utils
{
    SDL_Texture* createTexture ( const std::string );
    void adjust ( Entity & );
    void render ( Entity & , SDL_Texture * );
    void render ( std::vector < Entity > & , SDL_Texture * );
    void move ( Entity & );
}

#endif
