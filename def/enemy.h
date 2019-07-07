#ifndef ENEMY
#define ENEMY

#include "automated_movement.h"
#include "constants.h"
#include "entity.h"
#include "directed_projectile.h"
#include "vector.h"

struct Enemy : public Entity , AutomatedMovement
{
    Enemy ( float , float , float , float );
    ~Enemy ();

    void update () , leftSensorCallback ( Entity & ),
        rightSensorCallback ( Entity & );
};

struct Enemies : public Entities < Enemy >
{
    Enemies ();
    ~Enemies ();

    void update ();
};

#endif
