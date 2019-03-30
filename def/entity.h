#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "camera.h"
#include "game.h"
#include "vector.h"

#include <SDL2/SDL.h>
#include <vector>

struct Entities
{
    std::vector < Vector > position , velocity;
    std::vector < SDL_Rect > screen , locator;
    std::vector < Uint8 > config , sensor;

    SDL_Texture *texture;

    Entities ( std::string filePath = GENERIC_PLATFORM_FILE_PATH );
    ~Entities ();

    virtual void add (), adjust( Uint32 ) , move () , render ();
};

#endif
