#ifndef FLOATING_ENEMY
#define FLOATING_ENEMY

#include "automated_movement.h"
#include "directed_projectile.h"

#include "player.h"

struct FloatingEnemy : public Kinematic , AutomatedMovement
{
    uint8 distance;
    Platform * destination;
    DirectedProjectiles projectiles;

    FloatingEnemy ();
    ~FloatingEnemy ();

    void search () , update () , move ();
};

struct FloatingEnemies : public List < FloatingEnemy >
{
    Platform * destination;

    FloatingEnemies ( Platform * destination );
    ~FloatingEnemies ();

    void set ( float , float , int , int );
};

#endif
