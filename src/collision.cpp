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
        float x1 = floor(a.position.x) , y1 = floor(a.position.y) , w1 = x1 + a.screen.w , h1 = y1 + a.screen.h,
            x2 = floor(b.position.x) , y2 = floor(b.position.y) , w2 = x2 + b.screen.w , h2 = y2 + b.screen.h;

        if ( x1 < w2 && w1 > x2 && y1 < h2 && h1 > y2 )
        {
            float x3 = ( x1 >= x2 ) ? x1 : x2,
                y3 = ( y1 >= y2 ) ? y1 : y2,
                w3 = ( w1 <= w2 ) ? w1 : w2,
                h3 = ( h1 <= h2 ) ? h1 : h2;

            float topX = x1 , topY = y1 , topW = w1 , topH = y1 + 12;
            float botX = x1 , botY = y1 + 4 , botW = w1 , botH = h1;
            float leftX = x1 , leftY = y1, leftW = x1 + 12 , leftH = h1;
            float rightX = x1 + 4 , rightY = y1 , rightW = w1 , rightH = h1;


            if ( x3 >= topX && w3 <= topW && y3 >= topY && h3 <= topH && a.velocity.y < 0 )
            {
                top ( a , h3 - y3 );
                //SDL_Log ( "top \n\n\n" );
            }
            else if ( x3 >= botX && w3 <= botW && y3 >= botY && h3 <= botH )
            { 
                bot ( a , h3 - y3 );               
                //SDL_Log ( "bot \n\n\n" );
            }
            else if ( x3 >= leftX && w3 <= leftW && y3 >= leftY && h3 <= leftH )
            { 
                left ( a , w3 - x3 );               
                //SDL_Log ( "left \n\n\n" );
            }
            else if ( x3 >= rightX && w3 <= rightW && y3 >= rightY && h3 <= rightH )
            { 
                right ( a , w3 - x3 );               
                //SDL_Log ( "right \n\n\n" );
            }
            else
            {
                // FAIL: Check why the case failed
                SDL_Log ( "Player    => x1: %.2f y1: %.2f w1: %.2f h1: %.2f \n" , x1 , y1 , w1 , h1 );
                SDL_Log ( "Platform  => x2: %.2f y2: %.2f w2: %.2f h2: %.2f \n" , x2 , y2 , w2 , h2 );
                SDL_Log ( "Intersect => x3: %.2f y3: %.2f w3: %.2f h3: %.2f \n\n\n\n" , x3 , y3 , w3 , h3 );
        
                if ( x1 == x3 && y1 == y3 && w1 == w3 && h1 == h3 )
                {
                    // TODO: Check edge cases
                    return;
                }
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
        //entity.velocity.x = 0;
        entity.sensor |= LEFT_SENSOR;
    }
    void right ( Entity &entity , int w )
    {
        entity.position.x -= w;
        //entity.velocity.x = 0;
        entity.sensor |= RIGHT_SENSOR;
    }
}
