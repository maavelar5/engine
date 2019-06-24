#ifndef ENEMY
#define ENEMY

#include "automated_movement.h"
#include "entity.h"
#include "vector.h"

#include <vector>

struct Enemy : public Entity , AutomatedMovement
{
    Enemy ( float , float , float , float );
    ~Enemy ();

    void search ( Vector ) , move ( Vector );
};

struct Enemies : public Entities
{
    std::vector < std::shared_ptr < Enemy > > entities;

    Enemies ();
    ~Enemies ();
};

#endif
