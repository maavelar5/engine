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

namespace collision
{
    void collide () , iterate ( Entity & , std::vector < Entity * > & );

    void detect ( Entity & , Entity & ) , top ( Entity & , int ),
        bot ( Entity & , int ) , left ( Entity & , int ),
        right ( Entity & , int );
}

#endif
