#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

#include "entity.h"
#include "utils.h"

#include <vector>

struct Platform
{
    SDL_Texture* texture;
    std::vector < Entity > platforms;

    void render ();

    Platform ();
    ~Platform ();
};

#endif
