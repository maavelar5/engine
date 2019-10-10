#include "kinematic.h"

Kinematic::Kinematic ()
{
    flip = SDL_FLIP_NONE;
    previousPosition = position;
    sensor = NONE_SENSOR;
    status = ACTIVE;
    config = 0;
}

Kinematic::~Kinematic ()
{

}

void Kinematic::adjust ()
{
    Vector position = this->position,
        renderPosition = ( position * timer::interpolation ) +
        ( previousPosition * ( 1.0 - timer::interpolation ) );

    if ( abs( renderPosition.x - this->renderPosition.x ) >= 1 ||
         abs( renderPosition.y - this->renderPosition.y ) >= 1 )
    {

        if ( config & CAMERA )
        {
            camera::move ( renderPosition.x - this->renderPosition.x,
                           screen );
        }

        position = this->renderPosition = renderPosition;
    }

    if ( velocity.x < 0 )
    {
        flip = SDL_FLIP_HORIZONTAL;
    }
    else if ( velocity.x > 0 )
    {
        flip = SDL_FLIP_NONE;
    }

    screen.x = floor( position.x - camera::position.x );
    screen.y = floor( position.y - camera::position.y );
}

void Kinematic::move ()
{
    previousPosition = position;

    if ( !( sensor & BOT_SENSOR ) )
    {
        velocity.y += GRAVITY.y * timer::timeStep;

        velocity.y = ( velocity.y > MAX_GRAVITY )
            ? MAX_GRAVITY
            : velocity.y;
    }

    position += velocity * timer::timeStep;
    sensor = NONE_SENSOR;

    positionLimits ();
    setCollisionBox ();
    setLocator ();
    pushToGrid ();
}

bool Kinematic::positionLimits ()
{
    if ( position.y <= 0 )
    {
        position.y = 0;
        return true;
    }
    else if ( position.y >= SCENARIO_HEIGHT )
    {
        position.y = SCENARIO_HEIGHT;
        return true;
    }

    if ( position.x <= 0 )
    {
        position.x = 0;
        return true;
    }
    else if ( position.x >= SCENARIO_WIDTH )
    {
        position.x = SCENARIO_WIDTH;
        return true;
    }

    return false;
}

void Kinematic::pushToGrid ()
{
    for ( int y = locator.y;
          y <= locator.h;
          y++
        )
    {
        for ( int x = locator.x;
              x <= locator.w;
              x++
            )
        {
            gridKinematics [ getPositionHash ( x , y ) ]
                .push_back ( shared_from_this () );
        }
    }
}

std::string Kinematic::getPositionHash ( int x , int y )
{
    std::string hash = std::to_string ( y ) + "," + std::to_string ( x );

    if ( gridKinematics.find ( hash ) == gridKinematics.end () )
    {
        gridKinematics [ hash ] = std::vector < std::shared_ptr < Base > > ();
    }

    return hash;
}

uint8 Kinematic::collisionType ()
{
    return sensor;
}

void Kinematic::collide ( std::shared_ptr < Base > a , AABB aBox )
{
    if ( AABB::checkIntersection ( collisionBox , aBox ) )
    {
        AABB c = AABB::getIntersection ( collisionBox , aBox );

        uint8 type = a->collisionType ();

        if ( collisionBox.top ( c ) )
        {
            if ( velocity.y <= 0 && !( sensor & A_BOT_SENSOR ) )
            {
                velocity.y = 0;
                position.y += ( c.h - c.y - 1 );
            }

            sensor |= ( type & A_TOP_SENSOR )
                ? TOP_SENSOR | A_TOP_SENSOR
                : TOP_SENSOR;

            top ();
        }
        else if ( collisionBox.bot ( c ) )
        {
            if ( velocity.y >= 0 && !( sensor & A_TOP_SENSOR ) )
            {
                velocity.y = 0;
                position.y -= ( c.h - c.y - 1 );
            }

            sensor |= ( type & A_BOT_SENSOR )
                ? BOT_SENSOR | A_BOT_SENSOR
                : BOT_SENSOR;

            bot ();
        }
        else if ( collisionBox.left ( c ) )
        {
            if ( !( sensor & A_RIGHT_SENSOR ) )
            {
                position.x += ( c.w - c.x - 1 );
            }

            sensor |= ( type & A_LEFT_SENSOR )
                ? LEFT_SENSOR | A_LEFT_SENSOR
                : LEFT_SENSOR;

            left ();
        }
        else if ( collisionBox.right ( c ) )
        {
            if ( !( sensor & A_LEFT_SENSOR ) )
            {
                position.x -= ( c.w - c.x -  1 );
            }

            sensor |= ( type & A_RIGHT_SENSOR )
                ? RIGHT_SENSOR | A_RIGHT_SENSOR
                : RIGHT_SENSOR;

            right ();
        }
        else
        {
            if ( collisionBox.fTop ( c ) )
            {
                if ( velocity.y <= 0 && !( sensor & A_BOT_SENSOR ) )
                {
                    velocity.y = 0;
                    position.y += ( c.h - c.y - 1 );
                }

                sensor |= ( type & A_TOP_SENSOR )
                    ? TOP_SENSOR | A_TOP_SENSOR
                    : TOP_SENSOR;

                top ();
            }
            else if ( collisionBox.fBot ( c ) )
            {
                if ( velocity.y >= 0 && !( sensor & A_TOP_SENSOR ) )
                {
                    velocity.y = 0;
                    position.y -= ( c.h - c.y - 1 );
                }

                sensor |= ( type & A_BOT_SENSOR )
                    ? BOT_SENSOR | A_BOT_SENSOR
                    : BOT_SENSOR;

                bot ();
            }
            else if ( collisionBox.fLeft ( c ) )
            {
                if ( !( sensor & A_RIGHT_SENSOR ) )
                {
                    position.x += ( c.w - c.x - 1 );
                }

                sensor |= ( type & A_LEFT_SENSOR )
                    ? LEFT_SENSOR | A_LEFT_SENSOR
                    : LEFT_SENSOR;

                left ();
            }
            else if ( collisionBox.fRight ( c ) ) {
                if ( !( sensor & A_LEFT_SENSOR ) )
                {
                    position.x -= ( c.w - c.x -  1 );
                }

                sensor |= ( type & A_RIGHT_SENSOR )
                    ? RIGHT_SENSOR | A_RIGHT_SENSOR
                    : RIGHT_SENSOR;

                right ();
            }
        }
        setCollisionBox ();
    }
}

void Kinematic::top () { }

void Kinematic::bot () { }

void Kinematic::left () { }

void Kinematic::right () { }

bool Kinematic::clear ()
{
    return ( status & ACTIVE )
        ? false
        : true;
}
