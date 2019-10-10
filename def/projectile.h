#ifndef PROJECTILE
#define PROJECTILE

#include "entities.h"
#include "automated_movement.h"

#include "bullet.h"

struct Projectiles : public List < Bullet >, Timer
{
    Platform * source;
    bool active;

    Projectiles ( Platform * source );
    ~Projectiles ();

    void set ( float x , float y , int w , int h ) , update ();
};

#endif
