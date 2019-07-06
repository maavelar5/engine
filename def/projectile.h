#ifndef PROJECTILE
#define PROJECTILE

#include "constants.h"
#include "entity.h"
#include "texture.h"
#include "automated_movement.h"

#include <memory>

struct Projectile : public Entity
{
    Projectile ( float , float , float , float );
    ~Projectile ();

    void positionLimits ();
};

struct Projectiles : public Entities < Projectile > , Timer
{
    Entity * entity;
    bool isActive;

    Projectiles ( uint16 speed , Entity * entity );
    ~Projectiles ();

    void add ( float , float ) ,  update ();
};

#endif
