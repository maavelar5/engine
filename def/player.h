#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "entity.h"
#include "game.h"
#include "projectile.h"
#include "texture.h"

struct Player : public Entity , Texture
{
    int speed;
    Projectile projectile;

    Player ();
    ~Player ();

    void event( SDL_Event ) , render () , move ();
};

#endif
