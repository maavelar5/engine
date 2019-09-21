#ifndef ENTITY
#define ENTITY

#include "automated_movement.h"
#include "camera.h"
#include "game.h"
#include "texture.h"

#include <algorithm>
#include <memory>

struct Entity
{
    Vector position , velocity, previousPosition,
        previousVelocity , renderPosition , direction;

    SDL_Rect screen , locator;

    uint8 config , status;

    SDL_RendererFlip flip;

    int speed;

    uint8 sensor , previousSensor;
    Timer topTimer , botTimer , rightTimer , leftTimer;

    std::map < std::string , std::vector < Entity * > > * collection;

    Entity ( float , float , int , int , uint8 config = STATIC | ACTIVE );
    ~Entity ();

    void adjust () , render ( SDL_Texture * ) , setLocator (),
        deleteLocator (), updateLocator ();

    virtual void move () , positionLimits (),
        move ( Vector , uint16 speed , uint8 minDistance = 0 ) , update (),
        move ( bool );

    virtual void topSensorCallback ( Entity & ) , botSensorCallback ( Entity & ),
        leftSensorCallback ( Entity & ) , rightSensorCallback ( Entity & );

    virtual void sensorDelay ();
};

namespace entities
{
    extern std::map < std::string ,
                      std::vector < Entity * > > kinematics , statics;
    extern std::vector < Entity * > queue;

    void addHashIfNotExists ( std::string,
                              std::map < std::string , std::vector
                              < Entity * > > * collection );

    std::string getPositionHash ( int , int );
}

#endif
