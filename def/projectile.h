#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "constants.h"
#include "entity.h"
#include "texture.h"

struct Projectile : public Entities
{
    int speed;

    Projectile ();
    ~Projectile ();

    void add ( float , float );
};

#endif
