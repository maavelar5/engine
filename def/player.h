#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "entity.h"
#include "game.h"
#include "utils.h"

struct Sword
{
    SDL_Texture *texture;
    float speed;
    SDL_bool flag;
    SDL_Rect screen;
    double angle;
    Uint32 transition;
    Sword ();

    void render ( int , int );
};


struct Player : public Entity
{
    SDL_Texture *texture;
    float speed;
    Sword sword;

    Player ();

    void event( SDL_Event );
};

#endif
