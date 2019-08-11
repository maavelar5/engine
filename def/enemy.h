#ifndef ENEMY
#define ENEMY

#include "automated_movement.h"
#include "constants.h"
#include "info.h"
#include "entity.h"
#include "directed_projectile.h"
#include "vector.h"

struct Enemy : public Entity , AutomatedMovement
{
    Enemy ( float , float , int , int );
    ~Enemy ();

    void update () , leftSensorCallback ( Entity & ),
        rightSensorCallback ( Entity & );
};

struct Enemies : public Entities
{
    int speed;

    std::vector < std::shared_ptr < Enemy > > entities;

    Enemies ();
    ~Enemies ();

    void move () , update () , render () , clear (),
        add ( float , float , int , int );
};

#endif
