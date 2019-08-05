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
                    positionHash = entities::getPositionHash ( x , y );

                    iterate ( *entity , entities::statics[ positionHash ] );
                    iterate ( *entity , entities::kinematics[ positionHash ] );
                }
            }
        }

        entities::queue.clear();
    }

    void iterate ( Entity & a , std::vector < Entity * > &entities )
    {
        for ( auto &b : entities )
        {
            solve ( a , ( *b ) );
        }
    }

    void solve ( Entity & entityA , Entity & entityB )
    {
        AABB a ( floor ( entityA.position.x ), floor ( entityA.position.y ),
                 floor ( entityA.position.x ) + entityA.screen.w,
                 floor ( entityA.position.y ) + entityA.screen.h );

        AABB b ( floor ( entityB.position.x ) , floor ( entityB.position.y ),
                 floor ( entityB.position.x ) + entityB.screen.w,
                 floor ( entityB.position.y ) + entityB.screen.h );

        if ( AABB::checkIntersection( a , b ) )
        {
            AABB c = AABB::getIntersection( a , b );

            if ( entityB.config & KINEMATIC )
            {
                kinematics::solve ( entityA , entityB , a , c );
            }
            else { statics::solve ( entityA , entityB , a , c ); }
        }

        if ( false )
        {
            std::ostringstream oss;

            AABB c = AABB::getIntersection( a , b );

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

    void bot ( Entity &entity , int h )
    {
        entity.velocity.y = 0;
        entity.position.y -= ( h - 1 );
    }

    void top ( Entity &entity , int h )
    {
        entity.velocity.y = 0;
        entity.position.y += ( h - 1 );
    }

    void left ( Entity &entity , int w )
    {
        entity.position.x += ( w - 1 );
    }
    void right ( Entity &entity , int w )
    {
        entity.position.x -= ( w - 1 );
    }

    namespace statics
    {
        void top ( Entity & a , Entity & b , AABB c )
        {
            if ( a.velocity.y <= 0 ) { collision::top ( a , c.h - c.y ); }

            a.topSensorCallback( b );
        }

        void bot ( Entity & a , Entity & b , AABB c )
        {
            if ( a.velocity.y >= 0 ) { collision::bot ( a , c.h - c.y ); }

            a.botSensorCallback ( b );
        }

        void left ( Entity & a , Entity & b , AABB c )
        {
            collision::left ( a , c.w - c.x );

            a.leftSensorCallback ( b );
        }

        void right ( Entity & a , Entity & b , AABB c )
        {
            collision::right ( a , c.w - c.x );

            a.rightSensorCallback ( b );
        }

        void fallback ( Entity & entityA , Entity & entityB , AABB a , AABB c )
        {
            if ( a.fTop( c ) ) { top ( entityA , entityB , c ); }
            else if ( a.fBot( c ) ) { bot ( entityA , entityB , c ); }
            else if ( a.fLeft( c ) ) { left ( entityA , entityB , c ); }
            else if ( a.fRight( c ) ) { right ( entityA , entityB , c ); }
        }

        void solve ( Entity & entityA , Entity & entityB , AABB a , AABB c )
        {
            if ( a.top ( c ) ) { top ( entityA , entityB , c ); }
            else if ( a.bot ( c ) ) { bot ( entityA , entityB , c ); }
            else if ( a.left ( c ) ) { left ( entityA , entityB , c ); }
            else if ( a.right ( c ) ) { right ( entityA , entityB , c ); }
            else { fallback ( entityA , entityB , a , c ); }
        }
    }

    namespace kinematics
    {
        void top ( Entity & a , Entity & b , AABB c )
        {
            if ( a.velocity.y <= 0 && !( a.sensor & A_BOT_SENSOR ) )
            {
                collision::top ( a , c.h - c.y );
            }

            a.topSensorCallback( b );
            b.botSensorCallback( a );
        }

        void bot ( Entity & a , Entity & b , AABB c )
        {
            if ( a.velocity.y >= 0 && !( a.sensor & A_TOP_SENSOR ) )
            {
                collision::bot ( a , c.h - c.y );
            }

            if ( b.sensor & A_BOT_SENSOR ) { a.sensor |= A_BOT_SENSOR; }

            a.botSensorCallback ( b );
            b.topSensorCallback ( a );
        }

        void left ( Entity & a , Entity & b , AABB c )
        {
            if ( !( a.sensor & A_RIGHT_SENSOR ) )
            {
                collision::left ( a , c.w - c.x );
            }

            a.leftSensorCallback ( b );
            b.rightSensorCallback ( a );
        }

        void right ( Entity & a , Entity & b , AABB c )
        {
            if ( !( a.sensor & A_LEFT_SENSOR ) )
            {
                collision::right ( a , c.w - c.x );
            }

            a.rightSensorCallback ( b );
            b.leftSensorCallback ( a );
        }

        void fallback ( Entity & entityA , Entity & entityB , AABB a , AABB c )
        {
            if ( a.fTop( c ) ) { top ( entityA , entityB , c ); }
            else if ( a.fBot( c ) ) { bot ( entityA , entityB , c ); }
            else if ( a.fLeft( c ) ) { left ( entityA , entityB , c ); }
            else if ( a.fRight( c ) ) { right ( entityA , entityB , c ); }
        }

        void solve ( Entity & entityA , Entity & entityB , AABB a , AABB c )
        {
            if ( ( &entityA ) == ( &entityB ) ) { return; }

            if ( entityA.config & BULLET ) { entityA.config &= ~ACTIVE; }
            if ( entityB.config & BULLET ) { entityB.config &= ~ACTIVE; }

            if ( a.top ( c ) ) { top ( entityA , entityB , c ); }
            else if ( a.bot ( c ) ) { bot ( entityA , entityB , c ); }
            else if ( a.left ( c ) ) { left ( entityA , entityB , c ); }
            else if ( a.right ( c ) ) { right ( entityA , entityB , c ); }
            else { fallback ( entityA , entityB , a , c ); }
        }
    }
}
