#ifndef PLAYER
#define PLAYER

#include "entities.h"
#include "entity.h"
#include "game.h"
#include "projectile.h"
#include "texture.h"
#include "debug.h"

struct Player : public Entity
{
    uint16 speed;
    Projectiles projectiles;
    bool canDoubleJump;

    Player ();
    ~Player ();

    void botSensorCallback ( Entity & ) , move () , render ( SDL_Texture * ),
        event ( SDL_Event );
};

struct Players : public Entities
{
    Player player;

    Players ();
    ~Players ();

    void move () , update () , render () , event ( SDL_Event ),
        add ( float , float , int , int );

    Entity * single ();
};

#endif
