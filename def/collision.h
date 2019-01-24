#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

#include "entity.h"
#include "vector.h"

#include <SDL2/SDL.h>

namespace collision
{
    extern const int TOP , RIGHT , BOT , LEFT;

    void collide ();
    int detect ( Entity & , Entity & );
    int getCollisionType ( SDL_Rect , SDL_Rect );
}

#endif
