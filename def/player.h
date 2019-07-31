#ifndef PLAYER
#define PLAYER

#include "entity.h"
#include "game.h"
#include "projectile.h"
#include "texture.h"
#include "debug.h"

struct Player : public Entity , Texture
{
    uint16 speed;
    Projectiles projectiles;
    bool canDoubleJump;

    Player ();
    ~Player ();

    void event( SDL_Event ) , render () , move (),
        botSensorCallback ( Entity & );
};

#endif
