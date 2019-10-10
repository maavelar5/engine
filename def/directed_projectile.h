#ifndef DIRECTED_PROJECTILE
#define DIRECTED_PROJECTILE

#include "directed_bullet.h"
#include "automated_movement.h"

struct DirectedProjectiles : public List < DirectedBullet > , Timer
{
    Platform * source;
    bool active;

    DirectedProjectiles ( Platform * source );
    ~DirectedProjectiles ();

    void update () , set ( float , float , int , int );
};

#endif
