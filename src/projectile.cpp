#include "projectile.h"

Projectile::Projectile ()
    : Entities ( ACTIVE | KINEMATIC | BULLET , GENERIC_PROJECTILE_FILE_PATH )
{
    speed = 400;
}

Projectile::~Projectile () { }

void Projectile::add ( float x , float y )
{
    std::shared_ptr < Entity > entity ( new Entity ( x , y , 4 , 4 , config ) );
    entity->velocity.x = speed;
    entities.push_back ( entity );
}
