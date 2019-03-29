#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "camera.h"
#include "constants.h"
#include "game.h"
#include "vector.h"

#include <algorithm>
#include <memory>

#if __APPLE__ || __ANDROID__
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

#if __APPLE__ || __ANDROID__
    #include <SDL_image.h>
#else
    #include <SDL2/SDL_image.h>
#endif

#include <vector>

struct Entity
{
    Uint32 index;
    Vector position , velocity;
    SDL_Rect screen , locator;
    Uint8 config , sensor;

    SDL_Texture *texture;

    Entity ( std::string filePath = "none", SDL_Texture *texture = nullptr );
    ~Entity ();

    void adjust () , deleteLocator () , setLocator (),
        render () , move ();

    static SDL_Texture * loadTexture ( std::string );
};

struct Entities
{
    Uint8 config;
    SDL_Rect screen;
    SDL_Texture *texture;

    std::vector < Uint32 > indices;

    Entities ( std::string );
    ~Entities ();

    virtual Uint32 add ( float , float );
};

namespace entities
{
    extern Uint32 currentIndex;
    extern std::vector < std::vector < std::vector < std::shared_ptr < Entity > > > > entities;
    extern std::map < Uint32 , std::shared_ptr < Entity > > linear;

    void init () , render () , move () , remove ();
    Uint32 add ( std::string filePath , SDL_Texture *texture = nullptr );
}

#endif
