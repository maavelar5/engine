#ifndef PLAYER
#define PLAYER

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
