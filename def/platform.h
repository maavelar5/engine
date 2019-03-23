#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

#include "entity.h"

#include <vector>

struct Platform
{
    SDL_Texture* texture;
    std::vector < Entity > platforms;

    Platform ();
    ~Platform ();
};

#endif
