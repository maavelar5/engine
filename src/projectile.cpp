#include "projectile.h"

Projectile::Projectile ( uint16 speed , Entity * entity ) :
    Entities ( ACTIVE | KINEMATIC | BULLET , GENERIC_PROJECTILE_FILE_PATH ),
    Timer ( 1000 )
{
    this->speed = speed;
    this->entity = entity;
    isActive = false;
}

Projectile::~Projectile () { }

void Projectile::add ( float x , float y )
{
    std::shared_ptr < Entity > entity ( new Entity ( x , y , 4 , 4 , config ) );

    entity->velocity.x = speed;
    entities.push_back ( entity );
}

void Projectile::update ()
{
    if ( isActive )
    {
        if ( check() == 2 )
        {
            add ( entity->position.x , entity->position.y );
            start();
        }
    }
}
