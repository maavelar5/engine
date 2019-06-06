#ifndef PLAYER
#define PLAYER

#include "entity.h"
#include "game.h"
#include "projectile.h"
#include "texture.h"

struct Player : public Entity , Texture
{
    float speed;
    Projectile projectile;

    Player ();
    ~Player ();

    void event( SDL_Event ) , render () , update ();
};

#endif
