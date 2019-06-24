#include "projectile.h"

Projectile::Projectile ( Uint8 speed )
    : Entities ( ACTIVE | KINEMATIC | BULLET , GENERIC_PROJECTILE_FILE_PATH )
{
    this->speed = speed;
}

Projectile::~Projectile () { }

void Projectile::add ( float x , float y )
{
    std::shared_ptr < Entity > entity ( new Entity ( x , y , 4 , 4 , config ) );

    entity->velocity.x = speed;
    entities.push_back ( entity );
}
