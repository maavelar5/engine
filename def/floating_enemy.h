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

    FloatingEnemy ( float , float , int , int );
    ~FloatingEnemy ();

    void search ( Vector ) , update ( Vector , uint16 );
};

struct FloatingEnemies : public Entities
{
    std::vector < std::shared_ptr < FloatingEnemy > > entities;

    Entity *entity;
    uint8 minDistance;
    int speed;

    FloatingEnemies ( Entity * entity = nullptr );
    ~FloatingEnemies ();

    void update () , render () , move (),
        add ( float , float , int , int );
};

#endif
