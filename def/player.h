#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "entity.h"
#include "game.h"
#include "projectile.h"

struct Player : public Entities
{
    float speed;
    Projectile projectile;

    Player ();
    ~Player ();

    void event( SDL_Event );
};

#endif
