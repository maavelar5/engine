#include "collision.h"

namespace collision
{
    void collide ()
    {
        for ( auto &entity : entities::queue )
        {
            for ( int y = entity->locator.y;
                  y <= entity->locator.h;
                  y++
                )
            {
                for ( int x = entity->locator.x;
                      x <= entity->locator.w;
                      x++
                    )
                {
                    std::string positionHash = Entity::getPositionHash ( x , y );
                    iterate ( (*entity) , entities::statics[ positionHash ] );
                }
            }
        }

        entities::queue.clear();
    }

    void iterate ( Entity &entity , std::vector < Entity * > &entities )
    {
        for ( auto &platform : entities )
        {
            detect ( entity , (*platform));
        }
    }

    void detect ( Entity &a , Entity &b )
    {
        float x1 = a.position.x , y1 = a.position.y , w1 = x1 + a.screen.w , h1 = y1 + a.screen.h,
            x2 = b.position.x , y2 = b.position.y , w2 = x2 + b.screen.w , h2 = y2 + b.screen.h;

        if ( x1 < w2 && w1 > x2 && y1 < h2 && h1 > y2 )
        {
            float x3 = ( x1 >= x2 ) ? x1 : x2,
                y3 = ( y1 >= y2 ) ? y1 : y2,
                w3 = ( w1 <= w2 ) ? w1 : w2,
                h3 = ( h1 <= h2 ) ? h1 : h2;

            if ( w3 - x3 >= h3 - y3 )
            {
                if ( y1 == y3 ) { top ( a , h3 - y3 ); }
                else { bot ( a , h3 - y3 ); }
            }
            else
            {
                if ( x1 == x3 ) { left ( a , w3 - x3 ); }
                else { right ( a , w3 - x3 ); }
            }
        }
    }

    int getCollisionType ( SDL_Rect a , SDL_Rect b )
    {
        int collisionType = -1;

        return collisionType;        
    }

    void bot ( Entity &entity , int h )
    {
        entity.velocity.y = 0;
        entity.position.y -= h - 1;
        entity.sensor |= BOT_SENSOR;
    }

    void top ( Entity &entity , int h )
    {
        entity.velocity.y = 0;
        entity.position.y += h + 1;
        entity.sensor |= TOP_SENSOR;
    }

    void left ( Entity &entity , int w )
    {
        entity.position.x += w;
        entity.sensor |= LEFT_SENSOR;
    }
    void right ( Entity &entity , int w )
    {
        entity.position.x -= w;
        entity.sensor |= RIGHT_SENSOR;
    }
}
