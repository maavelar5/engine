#ifndef COLLISION
#define COLLISION

#include "constants.h"
#include "entity.h"
#include "vector.h"

#include <algorithm>

struct AABB
{
    float x , y , w , h;

    AABB ( float , float , float , float );
    ~AABB ();

    bool top ( AABB ) , right ( AABB ) , bot ( AABB ) , left ( AABB );

    static AABB getIntersection  ( AABB , AABB );

    static bool checkIntersection ( AABB , AABB );
};

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
