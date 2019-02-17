#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "entity.h"
#include "game.h"
#include "utils.h"

struct Projectiles
{
    SDL_Texture *texture;
    std::vector < Entity > entities;
    float speed;
    
    Projectiles ( const std::string filePath = GENERIC_PROJECTILE_FILE_PATH );
};

struct Player : public Entity
{
    SDL_Texture *texture;
    float speed;

    Player ();

    void event( SDL_Event );
};

#endif
