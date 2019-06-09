#ifndef COLLISION
#define COLLISION

#include "constants.h"
#include "entity.h"
#include "vector.h"

namespace collision
{
    void collide () , iterate ( Entity & , std::vector < Entity * > & );

    int getCollisionType ( SDL_Rect , SDL_Rect );

    void detect ( Entity & , Entity & ),
        top ( Entity & , int ),
        bot ( Entity & , int ),
        left ( Entity & , int ),
        right ( Entity & , int );
}

#endif
