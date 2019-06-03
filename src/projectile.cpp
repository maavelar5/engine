#include "projectile.h"

Projectile::Projectile () : Entities ( GENERIC_PROJECTILE_FILE_PATH )
{
    speed = 400;
}

Projectile::~Projectile () { }

void Projectile::add ( float x , float y )
{
    std::shared_ptr < Entity > entity ( new Entity ( x , y , 4 , 4 ) );

    entity->config ^= STATIC | BULLET;
    entity->velocity.x = speed;

    entity->adjust();

    entities.push_back ( entity );
}
