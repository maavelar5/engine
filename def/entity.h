#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "constants.h"
#include "vector.h"

#include <SDL2/SDL.h>
#include <vector>

struct Entity
{
    Vector position , velocity;
    SDL_Rect screen , locator;
    Uint8 config , sensor;

    SDL_Texture *texture;

    Entity ( std::string filePath = "none.png" , SDL_Texture *texture = nullptr );
    ~Entity ();

    void adjust () , deleteLocator () , setLocator ();
};

namespace entities
{
    extern std::vector < std::vector < std::vector < Entity* > > > entities;

    void init () , render () , move ();
}

#endif
