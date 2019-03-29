#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

#include "constants.h"
#include "entity.h"
#include "vector.h"

#include <algorithm>

#if __APPLE__ || __ANDROID__
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

namespace collision
{
    void collide ();

    int getCollisionType ( SDL_Rect , SDL_Rect );

    void detect ( Entity &, Entity &),
        top ( Entity &, int ),
        bot ( Entity &, int ),
        left ( Entity &, int ),
        right ( Entity &, int );
}

#endif
