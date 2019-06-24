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

    void search ( Vector ) , update ( Vector , Uint8 );
};

struct Enemies : public Entities
{
    std::vector < std::shared_ptr < Enemy > > entities;

    Enemies ();
    ~Enemies ();

    void update ( Vector ) , render () override,
        add ( float , float , int , int ) override;

};

#endif
