#ifndef PROJECTILE
#define PROJECTILE

#include "constants.h"
#include "entity.h"
#include "texture.h"
#include "automated_movement.h"

#include <memory>

struct Projectile : public Entities < Entity > , Timer
{
    Entity * entity;
    bool isActive;

    Projectile ( Uint8 speed , Entity * entity );
    ~Projectile ();

    void add ( float , float ) ,  update ();
};

#endif
