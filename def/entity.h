#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "camera.h"
#include "constants.h"
#include "game.h"
#include "vector.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

struct Entity
{
    Vector position , velocity;
    SDL_Rect screen , locator;
    Uint8 config , sensor;

    SDL_Texture *texture;

    Entity ( std::string filePath = "none.png" , SDL_Texture *texture = nullptr );
    ~Entity ();

    void adjust () , deleteLocator () , setLocator (),
        render () , move ();

    static SDL_Texture * loadTexture ( std::string );
};

namespace entities
{
    extern std::vector < std::vector < std::vector < Entity* > > > entities;

    void init () , render () , move ();
}

#endif
