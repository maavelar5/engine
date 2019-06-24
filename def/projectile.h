#ifndef PROJECTILE
#define PROJECTILE

#include "constants.h"
#include "entity.h"
#include "texture.h"

struct Projectile : public Entities
{
    Projectile ( Uint8 );
    ~Projectile ();

    void add ( float , float );
};

#endif
