#ifndef PLAYER
#define PLAYER

#include "debug.h"
#include "info.h"
#include "projectile.h"

struct Player : public Kinematic
{
    bool doubleJump;
    Projectiles projectiles;

    Player ();
    ~Player ();

    void event ( SDL_Event ) , update () , render () , top () , bot (),
        left () , right ();

    bool clear ();
};

#endif
