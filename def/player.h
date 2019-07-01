#ifndef PLAYER
#define PLAYER

#include "entity.h"
#include "game.h"
#include "projectile.h"
#include "texture.h"

struct Player : public Entity , Texture
{
    uint16 speed;
    Projectiles projectiles;

    Player ();
    ~Player ();

    void event( SDL_Event ) , render () , move ();
};

#endif
