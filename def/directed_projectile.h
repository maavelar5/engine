#ifndef DIRECTED_PROJECTILE
#define DIRECTED_PROJECTILE

#include "constants.h"
#include "entity.h"
#include "projectile.h"

struct DirectedProjectiles : public Entities < Projectile > , Timer
{
    Entity * entity;
    bool isActive;

    DirectedProjectiles ( uint16 speed , Entity * entity );
    ~DirectedProjectiles ();

    void add ( float , float ) ,  update ();
};

#endif
