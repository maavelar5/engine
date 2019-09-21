#ifndef DIRECTED_PROJECTILE
#define DIRECTED_PROJECTILE

#include "entity.h"
#include "projectile.h"

struct DirectedProjectiles : public Projectiles
{
    DirectedProjectiles ( uint16 speed , Entity * entity );
    ~DirectedProjectiles ();

    void update () , move ( Vector );
};

#endif
