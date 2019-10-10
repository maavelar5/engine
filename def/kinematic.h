#ifndef KINEMATIC_INTERFACE
#define KINEMATIC_INTERFACE

#include "platform.h"

struct Kinematic : public Platform
{
    Vector velocity, previousPosition, previousVelocity;
    uint8 status , sensor , config;
    int speed;
    SDL_RendererFlip flip;

    Kinematic ();
    ~Kinematic ();

    void adjust () , move () , pushToGrid (),
        collide ( std::shared_ptr < Base > , AABB );

    bool positionLimits () , clear ();

    std::string getPositionHash ( int x , int y );

    uint8 collisionType ();

    virtual void top () , bot () , left () , right ();
};

#endif
