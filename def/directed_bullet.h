#ifndef DIRECTED_BULLET
#define DIRECTED_BULLET

#include "bullet.h"
#include "game.h"

struct DirectedBullet : public Bullet
{
    DirectedBullet ();
    ~DirectedBullet ();

    void move ();
};

#endif
