#ifndef BULLET_INTERFACE
#define BULLET_INTERFACE

#include "kinematic.h"
#include "timer.h"

struct Bullet : public Kinematic
{
    Bullet ();
    ~Bullet ();

    void move () , top () , bot () , left () , right ();
};

#endif
