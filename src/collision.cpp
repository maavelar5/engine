#include "collision.h"

namespace collision
{
    const int TOP = 1, RIGHT = 2, BOT = 3, LEFT = 4;

    void collide ()
    {
        Entity *a = nullptr , *b = nullptr;

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
                    a = entities::entities[ x ][ y ][ z ];

                    for ( int w = z + 1;
                          w < entities::entities[ x ][ y ].size();
                          w++
                        )
                    {
                        b = entities::entities[ x ][ y ][ w ];

                        detect ( *a, *b );
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

            if ( collisionType == BOT )
            {
                if ( a.type && a.velocity.y >= 0 ) { bot ( a , result.h ); }
                if ( b.type && b.velocity.y <= 0 ) { top ( b , result.h ); }
            }

            else if ( collisionType == TOP )
            {
                if ( a.type && a.velocity.y <= 0 ) { top ( a , result.h ); }
                if ( b.type && b.velocity.y >= 0 ) { bot ( b , result.h ); }
            }

            else if ( collisionType == RIGHT )
            {
                if ( a.type ) { right( a , result.w ); }
                if ( b.type ) { left( b , result.w ); }
            }

            else if ( collisionType == LEFT )
            {
                if ( a.type ) { left( a , result.w ); }
                if ( b.type ) { right( b , result.w ); }
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

    void bot ( Entity &entity , int h )
    {
        entity.velocity.y = 0;
        entity.position.y -= h - 1;
        entity.bot = SDL_TRUE;
    }

    void top ( Entity &entity , int h )
    {
        entity.velocity.y = 0;
        entity.position.y += h;
        entity.top = SDL_TRUE;
    }

    void left ( Entity &entity , int w )
    {
        entity.position.x += w;
    }

    void right ( Entity &entity , int w )
    {
        entity.position.x -= w;
    }
}
