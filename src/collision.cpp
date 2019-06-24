#include "collision.h"

AABB::AABB ( float x , float y , float w , float h )
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

AABB::~AABB () { }

bool AABB::left ( AABB a )
{
    float value = ( ( w - x ) / 10 ) * 9;

    return ( a.x >= x && a.y >= y && a.w <= x + value && a.h <= h )
        ? true
        : false;
}

bool AABB::right ( AABB a )
{
    float value = ( w - x ) / 10;

    return ( a.x >= x + value && a.y >= y && a.w <= w && a.h <= h )
        ? true
        : false;
}

bool AABB::top ( AABB a )
{
    float value = ( h - y ) / 10 * 9;

    return ( a.x >= x && a.y >= y && a.w <= w && a.h <= y + value )
        ? true
        : false;
}

bool AABB::bot ( AABB a )
{
    float value = ( h - y ) / 10;

    return (a.x >= x && a.y >= y + value && a.w <= w && a.h <= h )
        ? true
        : false;
}

AABB AABB::getIntersection ( AABB a , AABB b )
{
    return AABB( ( a.x >= b.x ) ? a.x : b.x,
                 ( a.y >= b.y ) ? a.y : b.y,
                 ( a.w <= b.w ) ? a.w : b.w,
                 ( a.h <= b.h ) ? a.h : b.h );
}

bool AABB::checkIntersection ( AABB a , AABB b )
{
    return ( a.x < b.w && a.w > b.x && a.y < b.h && a.h > b.y )
        ? true
        : false;
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
            if ( entity.config & ACTIVE )
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
            if ( entity.config & BULLET )
            {
                entity.config &= ~ACTIVE;
                return;
            }

            AABB c = AABB::getIntersection ( a , b );

            if ( a.top ( c ) && entity.velocity.y < 0 )
            {
                top ( entity , c.h - c.y );
            }
            else if ( a.bot ( c ) && entity.velocity.y >= 0 )
            { 
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
            else if ( a.x == c.x && a.y == c.y &&
                      a.w == c.w && a.h == c.h )
            {
                // This shouldn't happen
                // TODO: Validate nearest wall and set proper collision
            }
            else
            {
                // FAIL: Check coordinates in which the resolution failed
                SDL_Log ( "Kinematic => x: %.2f y: %.2f w: %.2f h: %.2f \n",
                          a.x , a.y , a.w , a.h );
                SDL_Log ( "Platform  => x: %.2f y: %.2f w: %.2f h: %.2f \n",
                          b.x , b.y , b.w , b.h );
                SDL_Log ( "Intersect => x: %.2f y: %.2f w: %.2f h: %.2f \n",
                          c.x , c.y , c.w , c.h );
                SDL_Log ( "Collision detection failed\n\n" );
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
