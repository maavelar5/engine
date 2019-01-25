#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "constants.h"
#include "vector.h"

#include <SDL2/SDL.h>
#include <vector>

struct Entity
{
    Vector position , velocity , previousPosition;
    SDL_Rect screen;
    SDL_bool top , bot , right , left , isActive;
    int xId , yId;

    Entity ();
    ~Entity ();
};

namespace entities
{
    extern std::vector < std::vector < std::vector < Entity * > > > entities;

    void init ();
}

#endif
