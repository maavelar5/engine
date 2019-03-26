#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "constants.h"
#include "entity.h"

struct Projectile : public Entities
{
    int speed;

    Projectile ();
    ~Projectile ();

    Uint32 add ( float , float );
};

#endif
