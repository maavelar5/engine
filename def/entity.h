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
    Vector position , velocity, previousPosition,
        previousVelocity , renderPosition;

    SDL_Rect screen , locator;

    Uint8 config , sensor , status;

    std::map < std::string , std::vector < Entity * > > * collection;

    Entity ( float , float , int , int , Uint8 config = STATIC | ACTIVE );
    ~Entity ();

    void adjust () , render ( SDL_Texture * ) , setLocator (),
        deleteLocator (), updateLocator () , positionLimits ();

    virtual void move () , update (),
        move ( Vector , Uint8 speed , Uint8 minDistance = 0 );
        

    static std::string getPositionHash ( int , int );
};

struct Entities : public Texture
{
    std::vector < std::shared_ptr < Entity > > entities;
    Uint8 speed , config;

    Entities ( Uint8 config = ACTIVE | STATIC,
               std::string filePath = GENERIC_PLATFORM_FILE_PATH );
    ~Entities ();

    virtual void render () , move () , move ( Vector ),
        add ( float , float , int , int ) , update ();
};

namespace entities
{
    extern std::map < std::string ,
                      std::vector < Entity * > > kinematics , statics;
    extern std::vector < Entity * > queue;

    void addHashIfNotExists ( std::string,
                              std::map < std::string , std::vector
                              < Entity * > > * collection );
}

#endif
