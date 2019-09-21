#ifndef PROJECTILE
#define PROJECTILE

#include "entities.h"
#include "automated_movement.h"

struct Projectile : public Entity
{
    Projectile ( float , float , int , int );
    ~Projectile ();

    void positionLimits ();
};

struct Projectiles : public Entities , Timer
{
    Entity * entity;
    bool isActive;
    int speed;

    std::vector < std::shared_ptr < Projectile > > entities;

    Projectiles ( int speed , Entity * entity );
    ~Projectiles ();

    virtual void update () ,  move () , render (),
        add ( float , float , int w = 4 , int h = 4 );
};

#endif
