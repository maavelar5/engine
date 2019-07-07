#ifndef FLOATING_ENEMY
#define FLOATING_ENEMY

#include "automated_movement.h"
#include "constants.h"
#include "entity.h"
#include "directed_projectile.h"
#include "vector.h"

struct FloatingEnemy : public Entity , AutomatedMovement
{
    DirectedProjectiles projectiles;

    FloatingEnemy ( float , float , float , float );
    ~FloatingEnemy ();

    void search ( Vector ) , update ( Vector , uint16 );
};

struct FloatingEnemies : public Entities < FloatingEnemy >
{
    Entity *entity;
    uint8 minDistance;

    FloatingEnemies ( Entity * entity = nullptr );
    ~FloatingEnemies ();

    void update () , render () override;
};

#endif
