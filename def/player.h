#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "entity.h"
#include "game.h"

struct Player : public Entity
{
    float speed;

    Player ();

    void event( SDL_Event );
};

#endif
