#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

#include "constants.h"
#include "entity.h"
#include "vector.h"

namespace collision
{
    void collide () , iterate ( std::vector < Entity * > & );

    int getCollisionType ( SDL_Rect , SDL_Rect );

    void detect ( Entity & , Entity & ),
        top ( Entity & , int ),
        bot ( Entity & , int ),
        left ( Entity & , int ),
        right ( Entity & , int );
}

#endif
