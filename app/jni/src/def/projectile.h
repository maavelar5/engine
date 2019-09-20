#ifndef PROJECTILE
#define PROJECTILE

#include "constants.h"
#include "entity.h"
#include "entities.h"
#include "texture.h"
#include "automated_movement.h"

#include <memory>

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
