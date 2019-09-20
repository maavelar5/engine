#ifndef COLLISION
#define COLLISION

#include "aabb.h"
#include "constants.h"
#include "debug.h"
#include "entity.h"
#include "info.h"
#include "vector.h"

#include <algorithm>
#include <iomanip>
#include <sstream>

namespace collision
{
    void collide () , iterate ( Entity & , std::vector < Entity * > & ),
        ktos ( Entity & , Entity & ) , ktok ( Entity & , Entity & ),
        solve ( Entity & , Entity & );

    void top ( Entity & , int ) , bot ( Entity & , int ),
        left ( Entity & , int ) , right ( Entity & , int );

    namespace statics
    {
        void solve ( Entity & , Entity & , AABB , AABB );
        void top ( Entity & , Entity & , AABB ),
            bot ( Entity & , Entity & , AABB ),
            left ( Entity & , Entity & , AABB ),
            right ( Entity & , Entity & , AABB );
    }

    namespace kinematics
    {
        void solve ( Entity & , Entity & , AABB , AABB );
        void top ( Entity & , Entity & , AABB ) ,
            bot ( Entity & , Entity & , AABB ),
            left ( Entity & , Entity & , AABB ),
            right ( Entity & , Entity & , AABB );
    }
}

#endif
