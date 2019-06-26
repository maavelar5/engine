#ifndef ENEMY
#define ENEMY

#include "automated_movement.h"
#include "constants.h"
#include "entity.h"
#include "projectile.h"
#include "vector.h"

#include <vector>

struct Enemy : public Entity , AutomatedMovement
{
    Projectile projectiles;

    Enemy ( float , float , float , float );
    ~Enemy ();

    void search ( Vector ) , update ( Vector , uint16 );
};

struct Enemies : public Entities < Enemy >
{
    Entity *entity;
    uint8 minDistance;

    Enemies ( Entity * entity = nullptr );
    ~Enemies ();

    void update () , render () override;
};

#endif
