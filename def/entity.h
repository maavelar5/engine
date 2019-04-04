#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "camera.h"
#include "game.h"
#include "texture.h"
#include "vector.h"

#if __ANDROID__
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include <algorithm>
#include <memory>
#include <vector>

struct Entity
{
    Vector position , velocity;
    SDL_Rect screen , locator;
    Uint8 config , sensor;

    Entity ();
    ~Entity ();

    void add (), adjust() , move () , render ( SDL_Texture * ),
        setLocator (), deleteLocator ();
};

struct Entities : public Texture
{
    std::vector < std::shared_ptr < Entity > > entities;

    Entities ( std::string filePath = GENERIC_PLATFORM_FILE_PATH );
    ~Entities ();

    void render ();
};

namespace entities
{
    extern std::vector
    < std::vector < std::vector
                    < Entity * > > > entities;

    extern std::vector < Entity * > toCollide;

    void init ();
}

#endif
