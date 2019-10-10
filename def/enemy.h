#ifndef ENEMY
#define ENEMY

#include "automated_movement.h"
#include "info.h"
#include "kinematic.h"

struct Enemy : public Kinematic , AutomatedMovement
{
    Enemy ();
    ~Enemy ();

    void update () , left () , right ();
};

#endif
