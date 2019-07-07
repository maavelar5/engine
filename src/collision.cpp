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
    float value = ( ( w - x ) / 10 ) * 2;

    return ( a.x == x )
        ? true
        : false;
}

bool AABB::right ( AABB a )
{
    return ( a.w == w )
        ? true
        : false;
}

bool AABB::top ( AABB a )
{
    return ( a.y == y && a.h < h )
        ? true
        : false;
}

bool AABB::bot ( AABB a )
{
    return ( a.h == h && a.y > y )
        ? true
        : false;
}

AABB AABB::getIntersection ( AABB a , AABB b )
{
    return AABB ( ( a.x >= b.x ) ? a.x : b.x,
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
        std::string positionHash = "";

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

                    positionHash = Entity::getPositionHash ( x , y );

                    iterate ( *entity , entities::statics[ positionHash ] );
                    iterate ( *entity , entities::kinematics[ positionHash ] );
                }
            }
        }

        entities::queue.clear();
    }

    void iterate ( Entity &entity , std::vector < Entity * > &entities )
    {
        for ( auto &platform : entities )
        {
            if ( entity.config & ACTIVE && &entity != platform )
            {
                detect ( entity , (*platform));
            }
        }
    }

    void detect ( Entity &entityA , Entity &entityB )
    {
        AABB a ( floor ( entityA.position.x ), floor ( entityA.position.y ),
                 floor ( entityA.position.x ) + entityA.screen.w,
                 floor ( entityA.position.y ) + entityA.screen.h );

        AABB b ( floor ( entityB.position.x ) , floor ( entityB.position.y ),
                 floor ( entityB.position.x ) + entityB.screen.w,
                 floor ( entityB.position.y ) + entityB.screen.h );

        if ( AABB::checkIntersection ( a , b ) )
        {
            AABB c = AABB::getIntersection ( a , b );

            if ( entityB.config & BULLET )
            {
                entityB.config &= ~ACTIVE;
            }

            if ( entityA.config & BULLET )
            {
                entityA.config &= ~ACTIVE;
                return;
            }

            if ( a.top ( c ) &&
                 ( entityA.velocity.y < 0 || entityA.config & DIRECTIONAL ) )
            {
                top ( entityA , c.h - c.y );
            }
            else if ( a.bot ( c ) &&
                      ( entityA.velocity.y >= 0 || entityA.config & DIRECTIONAL ) )
            { 
                bot ( entityA , c.h - c.y );
                entityA.botSensorCallback ( entityB );
                entityB.topSensorCallback ( entityA );
            }
            else if ( a.left ( c ) )
            { 
                left ( entityA , c.w - c.x );
                entityA.leftSensorCallback ( entityB );
                entityB.rightSensorCallback ( entityA );
            }
            else if ( a.right ( c ) )
            { 
                right ( entityA , c.w - c.x );
                entityA.rightSensorCallback ( entityB );
                entityB.leftSensorCallback ( entityA );
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
                SDL_Log ( "EntityA => x: %.2f y: %.2f w: %.2f h: %.2f \n",
                          a.x , a.y , a.w , a.h );
                SDL_Log ( "EntityB  => x: %.2f y: %.2f w: %.2f h: %.2f \n",
                          b.x , b.y , b.w , b.h );
                SDL_Log ( "Intersect => x: %.2f y: %.2f w: %.2f h: %.2f \n",
                          c.x , c.y , c.w , c.h );
                SDL_Log ( "Collision detection failed\n\n" );
            }
        }
    }

    void bot ( Entity &entity , int h )
    {
        entity.velocity.y = 0;
        entity.position.y -= h;
        entity.sensor |= BOT_SENSOR;
    }

    void top ( Entity &entity , int h )
    {
        entity.velocity.y = 0;
        entity.position.y += h;
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
