#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "vector.h"

#include <SDL2/SDL.h>

struct Entity
{
    Vector position;
    SDL_Rect screen;

    Entity ();
    ~Entity ();
};

#endif
