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

        //entities::queue.clear();
    }

    void iterate ( Entity &entity , std::vector < Entity * > &entities )
    {
        Entity *a;

        for ( auto &platform : entities )
        {
            detect ( entity , (*platform));
        }
    }

    void detect ( Entity &a , Entity &b )
    {
        SDL_Rect result = { 0 , 0 , 0 , 0 };

        if ( SDL_IntersectRect ( &a.screen , &b.screen , &result ) )
        {
            int collisionType = getCollisionType ( a.screen , result );

            if ( a.config & BULLET ) a.config &= ~ACTIVE;
            if ( b.config & BULLET ) b.config &= ~ACTIVE;

            if ( collisionType == BOT_SENSOR )
            {
                if ( a.config & KINEMATIC && a.velocity.y >= 0 ) { bot ( a , result.h ); }
                if ( b.config & KINEMATIC && b.velocity.y <= 0 ) { top ( b , result.h ); }
            }

            else if ( collisionType == TOP_SENSOR )
            {
                if ( a.config & KINEMATIC && a.velocity.y <= 0 ) { top ( a , result.h ); }
                if ( b.config & KINEMATIC && b.velocity.y >= 0 ) { bot ( b , result.h ); }
            }

            else if ( collisionType == RIGHT_SENSOR )
            {
                if ( a.config & KINEMATIC ) { right( a , result.w ); }
                if ( b.config & KINEMATIC ) { left( b , result.w ); }
            }

            else if ( collisionType == LEFT_SENSOR )
            {
                if ( a.config & KINEMATIC ) { left( a , result.w ); }
                if ( b.config & KINEMATIC ) { right( b , result.w ); }
            }
        }
    }

    int getCollisionType ( SDL_Rect a , SDL_Rect b )
    {
        int collisionType = -1;

        if ( b.w >= b.h )
        {
            if ( a.y == b.y ) { collisionType = TOP_SENSOR; }
            else { collisionType = BOT_SENSOR; }
        }
        else
        {
            if ( a.x == b.x ) { collisionType = LEFT_SENSOR; }
            else { collisionType = RIGHT_SENSOR; }
        }

        return collisionType;        
    }

    void bot ( Entity &entity , int h )
    {
        entity.velocity.y = 0;
        entity.position.y -= h - 1;
        entity.sensor |= BOT_SENSOR;

        entity.adjust();
    }

    void top ( Entity &entity , int h )
    {
        entity.velocity.y = 0;
        entity.position.y += h;
        entity.sensor |= TOP_SENSOR;

        entity.adjust();
    }

    void left ( Entity &entity , int w )
    {
        entity.position.x += w;

        entity.adjust();
    }
    void right ( Entity &entity , int w )
    {
        entity.position.x -= w;

        entity.adjust();
    }
}
