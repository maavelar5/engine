#include "collision.h"

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

                    positionHash = entities::getPositionHash ( x , y );

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
            if ( entity.config & ACTIVE &&
                 &entity != platform &&
                 platform->config & ACTIVE )
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
                entityB.config &= ~ACTIVE;

            if ( entityA.config & BULLET )
                entityA.config &= ~ACTIVE;

            std::ostringstream oss;

            if ( a.top ( c ) )
            {
                if ( entityA.velocity.y <= 0 )
                    top ( entityA , c.h - c.y );

                entityA.topSensorCallback( entityB );
                entityB.botSensorCallback( entityA );

            }
            else if ( a.bot ( c ) )
            { 
                if ( entityA.velocity.y >= 0 )
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
                oss << "EntityA => a.x: " << a.x << " a.y: "
                    << a.y << " a.w: " << a.w << " a.h: " << a.h;
                debug::draw ( oss.str() );
                oss.str("");

                oss << "EntityB => b.x: " << b.x << " b.y: "
                    << b.y << " b.w: " << b.w << " b.h: " << b.h;
                debug::draw ( oss.str() );
                oss.str("");

                oss << "Intersect => x: " << c.x << " y: "
                    << c.y << " w: " << c.w << " h: " << c.h;
                debug::draw ( oss.str() );
                oss.str("");

                oss << "Collision detection failed";
                debug::draw ( oss.str() );
            }
        }
    }

    void bot ( Entity &entity , int h )
    {
        entity.velocity.y = 0;
        entity.position.y -= h - 1;
    }

    void top ( Entity &entity , int h )
    {
        entity.velocity.y = 0;
        entity.position.y += h + 1;
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
