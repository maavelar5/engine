#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "vector.h"

#include <SDL2/SDL.h>

struct Entity
{
    Vector position , velocity;
    SDL_Rect screen;
    SDL_bool top , bot , right , left;

    Entity ();
    ~Entity ();
};

#endif
