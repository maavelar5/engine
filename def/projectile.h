#ifndef PROJECTILE
#define PROJECTILE

#include "constants.h"
#include "entity.h"
#include "texture.h"
#include "automated_movement.h"

#include <memory>

struct Projectile : public Entities , Timer
{
    Entity *entity;

    Projectile ( Uint8 , Entity * );
    ~Projectile ();

    void add ( float , float ) , update ();

    bool isActive;
};

#endif
