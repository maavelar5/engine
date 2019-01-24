#include "collision.h"

namespace collision
{
    const int TOP = 1, RIGHT = 2, BOT = 3, LEFT = 4;

    void collide ()
    {
        for ( int x = 0;
              x < entities::entities.size();
              x++
            )
        {
            for ( int y = 0;
                  y < entities::entities[ x ].size();
                  y++
                )
            {
                for ( int z = 0;
                      z < entities::entities[ x ][ y ].size();
                      z++
                    )
                {

                    for ( int w = z + 1;
                          w < entities::entities[ x ][ y ].size();
                          w++
                        )
                    {
                        detect ( *entities::entities [ x ][ y ][ z ],
                                 *entities::entities [ x ][ y ][ w ]);
                    }
                }
            }
        }
    }

    int detect ( Entity &a , Entity &b )
    {
        SDL_Rect result = { 0 , 0 , 0 , 0 };

        if ( SDL_IntersectRect ( &a.screen , &b.screen , &result ) )
        {
            int collisionType = getCollisionType ( a.screen , result );

            if ( collisionType == BOT && a.velocity.y >= 0 )
            {
                a.position.y -= result.h - 1;
                a.velocity.y = 0;
                a.bot = SDL_TRUE;
            }

            if ( collisionType == TOP && a.velocity.y <= 0 )
            {
                a.position.y += result.h;
                a.velocity.y = 0;
                a.top = SDL_TRUE;                
            }

            if ( collisionType == LEFT )
            {
                a.position.x += result.w;
            }

            if ( collisionType == RIGHT )
            {
                a.position.x -= result.w;
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
