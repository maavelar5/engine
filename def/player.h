#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "entity.h"
#include "game.h"
#include "projectile.h"

struct Player
{
    float speed;
    Projectile projectile;
    std::shared_ptr < Entity > entity;
    
    Player ();
    ~Player ();

    void event( SDL_Event );
};

#endif
