#include "collision.h"

namespace collision
{
    const int TOP = 1, RIGHT = 2, BOT = 3, LEFT = 4;

    int detect ( Entity &a , Entity &b )
    {
        SDL_Rect result = { 0 , 0 , 0 , 0 };

        if ( SDL_IntersectRect ( &a.screen , &b.screen , &result ) )
        {
            int collisionType = getCollisionType ( a.screen , result );

            if ( collisionType == BOT )
            {
                a.position.y -= result.h - 1;
                a.velocity.y = 0;
                a.bot = SDL_TRUE;
            }

            if ( collisionType == TOP )
            {
                a.position.y += result.h;
                a.top = SDL_TRUE;                
            }

        }
    }

    int getCollisionType ( SDL_Rect a , SDL_Rect b )
    {
        int collisionType = -1;

        if ( b.w >= b.h )
        {
            if ( a.y == b.y ) { collisionType = TOP; }
            else { collisionType = BOT; }
        }
        else
        {
            if ( a.x == b.x ) { collisionType = LEFT; }
            else { collisionType = RIGHT; }
        }

        return collisionType;        
    }
}
