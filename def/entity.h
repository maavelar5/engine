#ifndef ENTITY
#define ENTITY

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
#include <map>

struct Entity
{
    Vector position , velocity,
        previousPosition , previousVelocity , renderPosition;

    SDL_Rect screen , locator;

    Uint8 config , sensor , status;

    std::map < std::string , std::vector < Entity * > > * collection;

    Entity ( float , float , int , int , Uint8 config = STATIC | ACTIVE );
    ~Entity ();

    void adjust() , move () , render ( SDL_Texture * ), setLocator (),
        deleteLocator () , updateLocator () , positionLimits ();

    static std::string getPositionHash ( int , int );
};

struct Entities : public Texture
{
    std::vector < std::shared_ptr < Entity > > entities;

    Entities ( std::string filePath = GENERIC_PLATFORM_FILE_PATH );
    ~Entities ();

    virtual void render () , move () , add ( float , float , int , int );
};

namespace entities
{
    extern std::map < std::string , std::vector < Entity * > > kinematics , statics;
    extern std::vector < Entity * > queue;

    void addHashIfNotExists ( std::string , std::map < std::string , std::vector < Entity * > > * collection );
}

#endif
