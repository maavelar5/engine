#include "collision.h"

AABB::AABB ( float x , float y , float w , float h )
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

AABB::~AABB () { }

bool AABB::left ( AABB intersection )
{
    if ( intersection.x >= x &&
         intersection.y >= y &&
         intersection.w <= x + 4 &&
         intersection.h <= h )
    {
        return true;        
    }

    else
    {
        return false;        
    }
}

bool AABB::right ( AABB intersection )
{
    if ( intersection.x >= x + 4 &&
         intersection.y >= y &&
         intersection.w <= w &&
         intersection.h <= h )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool AABB::top ( AABB intersection )
{
    if ( intersection.x >= x &&
         intersection.y >= y &&
         intersection.w <= w &&
         intersection.h <= y + 4 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool AABB::bot ( AABB intersection )
{
    if ( intersection.x >= x &&
         intersection.y >= y + 4 &&
         intersection.w <= w &&
         intersection.h <= h )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool AABB::checkIntersection ( AABB a , AABB b )
{
    
    if ( a.x < b.w &&
         a.w > b.x &&
         a.y < b.h &&
         a.h > b.y )
        return true;
    else
        return false;
}

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
                    entity->sensor = NONE_SENSOR;

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

    void detect ( Entity &entity , Entity &platform )
    {
        AABB a ( floor(entity.position.x), floor(entity.position.y),
                 floor(entity.position.x) + entity.screen.w,
                 floor(entity.position.y) + entity.screen.h );

        AABB b ( floor(platform.position.x) , floor(platform.position.y),
                 floor(platform.position.x) + platform.screen.w,
                 floor(platform.position.y) + platform.screen.h );

        if ( AABB::checkIntersection ( a , b ) )
        {
            AABB c ( ( a.x >= b.x ) ? a.x : b.x,
                     ( a.y >= b.y ) ? a.y : b.y,
                     ( a.w <= b.w ) ? a.w : b.w,
                     ( a.h <= b.h ) ? a.h : b.h );

            if ( a.top ( c ) )
            {
                if ( entity.velocity.y > 0 )
                    return;

                top ( entity , c.h - c.y );
            }
            else if ( a.bot ( c ) )
            { 
                if ( entity.velocity.y < 0 )
                    return;

                bot ( entity , c.h - c.y );
            }
            else if ( a.left ( c ) )
            { 
                left ( entity , c.w - c.x );               
            }
            else if ( a.right ( c ) )
            { 
                right ( entity , c.w - c.x );               
            }
            else if ( a.x == c.x &&
                      a.y == c.y &&
                      a.w == c.w &&
                      a.h == c.h )
            {
                if ( entity.previousVelocity.y > 0 )
                    top ( entity , c.h - c.y );
            }
            else
            {
                // FAIL: Check why the case failed
                SDL_Log ( "Player    => x1: %.2f y1: %.2f w1: %.2f h1: %.2f \n",
                          a.x , a.y , a.w , a.h );
                SDL_Log ( "Platform  => x2: %.2f y2: %.2f w2: %.2f h2: %.2f \n",
                          b.x , b.y , b.w , b.h );
                SDL_Log ( "Intersect => c.x: %.2f c.y: %.2f c.w: %.2f c.h: %.2f \n",
                          c.x , c.y , c.w , c.h );

                SDL_Log ( "\n\n" );
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
        entity.position.x += w - 1;
        entity.sensor |= LEFT_SENSOR;
    }
    void right ( Entity &entity , int w )
    {
        entity.position.x -= w - 1;
        entity.sensor |= RIGHT_SENSOR;
    }
}
