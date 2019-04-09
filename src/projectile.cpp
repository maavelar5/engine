#include "projectile.h"

Projectile::Projectile () : Entities ( GENERIC_PROJECTILE_FILE_PATH )
{
    speed = 400;
}

Projectile::~Projectile () { }

void Projectile::add ( float x , float y )
{
    std::shared_ptr < Entity > entity ( new Entity ());

    entity->config ^= STATIC | BULLET;
    entity->position = { x , y };
    entity->screen = { 0 , 0 , 4 , 4 };
    entity->velocity.x = speed;

    entity->adjust();

    entities.push_back ( entity );
}
