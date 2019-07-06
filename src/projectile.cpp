#include "projectile.h"

Projectile::Projectile ( float x , float y , float w , float h ) :
    Entity ( x , y , w , h , ACTIVE | KINEMATIC | BULLET )
{
    
}

Projectile::~Projectile () { }

void Projectile::positionLimits ()
{
    if ( position.y <= -100 )
        config &= ~ACTIVE;
    else if ( position.y >= SCENARIO_HEIGHT )
        config &= ~ACTIVE;

    if ( position.x <= -100 )
        config &= ~ACTIVE;
    else if ( position.x >= SCENARIO_WIDTH )
        config &= ~ACTIVE;
}


Projectiles::Projectiles ( uint16 speed , Entity * entity ) :
    Entities ( ACTIVE | KINEMATIC | BULLET , GENERIC_PROJECTILE_FILE_PATH ),
    Timer ( 1000 )
{
    this->speed = speed;
    this->entity = entity;
    isActive = false;
}

Projectiles::~Projectiles () { }

void Projectiles::add ( float x , float y )
{
    std::shared_ptr < Projectile > entity ( new Projectile ( x , y , 4 , 4 ) );

    entity->velocity.x = ( this->entity->flip == SDL_FLIP_HORIZONTAL )
        ? -speed
        : speed;

    entities.push_back ( entity );
}

void Projectiles::update ()
{
    if ( isActive )
    {
        if ( check() == 2 )
        {
            float x = ( entity->flip == SDL_FLIP_NONE )
                ? entity->position.x + entity->screen.w + 4
                : entity->position.x - 4;

            float y = entity->position.y + entity->screen.h / 3;

            add ( x , y );
            start();
        }
    }
}

DirectedProjectiles::DirectedProjectiles ( uint16 speed , Entity * entity ) :
    Entities ( ACTIVE | KINEMATIC | BULLET , GENERIC_PROJECTILE_FILE_PATH ),
    Timer ( 1000 )
{
    this->speed = speed;
    this->entity = entity;
    isActive = false;
}

DirectedProjectiles::~DirectedProjectiles () { }

void DirectedProjectiles::add ( float x , float y )
{
    std::shared_ptr < Projectile > entity ( new Projectile ( x , y , 4 , 4 ) );

    entities.push_back ( entity );
}

void DirectedProjectiles::update ()
{
    if ( isActive )
    {
        if ( check() == 2 )
        {
            // TODO: Resarch position max value based on direction vector

            Vector position = entity->position;

            position += ( entity->direction * ( speed * timer::timeStep ) );

            add ( position.x , position.y );
            start();
        }
    }
}
