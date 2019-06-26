#ifndef PLAYER
#define PLAYER

#include "entity.h"
#include "game.h"
#include "projectile.h"
#include "texture.h"

struct Player : public Entity , Texture
{
    uint16 speed;
    Projectile projectile;

    Player ();
    ~Player ();

    void event( SDL_Event ) , render () , move ();
};

#endif
