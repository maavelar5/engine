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
        previousVelocity , renderPosition , direction;

    SDL_Rect screen , locator;

    uint8 config , status , sensor;

    SDL_RendererFlip flip;

    std::map < std::string , std::vector < Entity * > > * collection;

    Entity ( float , float , int , int , uint8 config = STATIC | ACTIVE );
    ~Entity ();

    void adjust () , render ( SDL_Texture * ) , setLocator (),
        deleteLocator (), updateLocator ();

    virtual void move () , positionLimits () , topSensorCallback ( Entity & ),
        botSensorCallback ( Entity & ) , leftSensorCallback ( Entity & ),
        rightSensorCallback ( Entity & ),
        move ( Vector , uint16 speed , uint8 minDistance = 0 );
        
    static std::string getPositionHash ( int , int );
};

template < class T >
struct Entities : public Texture
{
    std::vector < std::shared_ptr < T > > entities;
    uint8 config;
    uint16 speed;

    Entities ( int config = ACTIVE | STATIC,
               std::string filePath = GENERIC_PLATFORM_FILE_PATH ) :
        Texture ( filePath )
    {
        this->config = config;
    }

    ~Entities () { }

    virtual void render ()
    {
        for ( auto entity = entities.begin(); entity != entities.end(); entity++ )
        {
            if ( (*entity)->config & ACTIVE )
            {
                (*entity)->render ( texture );                
            }
            else
            {
                (*entity)->deleteLocator ();
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

    virtual void add ( float x , float y , int w , int h )
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
