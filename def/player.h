#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "entity.h"
#include "game.h"
#include "utils.h"

struct Player : public Entity
{
    SDL_Texture *texture;
    float speed;

    Player ();

    void event( SDL_Event );
};

#endif
