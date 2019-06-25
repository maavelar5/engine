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

    Uint8 config , sensor;

    std::map < std::string , std::vector < Entity * > > * collection;

    Entity ( float , float , int , int , Uint8 config = STATIC | ACTIVE );
    ~Entity ();

    void adjust () , render ( SDL_Texture * ) , setLocator (),
        deleteLocator (), updateLocator () , positionLimits ();

    virtual void move () , update (),
        move ( Vector , Uint8 speed , Uint8 minDistance = 0 );
        

    static std::string getPositionHash ( int , int );
};

template < class T >
struct Entities : public Texture
{
    std::vector < std::shared_ptr < T > > entities;
    Uint8 speed , config;
    
    Entities ( Uint8 config , std::string filePath ) :
        Texture ( filePath )
    {
        this->config = config;
    }

    ~Entities () { }

    virtual void render ()
    {
        for ( auto entity = entities.begin();
              entity != entities.end();
              entity++ )
        {
            if ( (*entity)->config & ACTIVE )
            {
                (*entity)->render ( texture );                
            }
            else
            {
                entities.erase ( entity-- );                
            }
        }
    }

    virtual void move ()
    {
        for ( auto &entity : entities )
        {
            entity->move();
        }
    }

    virtual void move ( Vector &vector )
    {
        for ( auto &entity : entities )
        {
            entity->move( vector , speed );
        }
    }

    virtual add ( float x , float y , int w , int h )
    {
        entities.push_back ( std::shared_ptr < T > ( new T ( x , y , w , h ) ) );
    }
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
