#include "projectile.h"

Projectile::Projectile () : Entities ( GENERIC_PROJECTILE_FILE_PATH )
{
    speed = 400;

    config ^= STATIC | BULLET;
    screen = { 0 , 0 , 4 , 4 };
}

Projectile::~Projectile () { }

Entity * Projectile::add ( float x , float y )
{
    Entity *entity = Entities::add ( x , y );
    entity->velocity.x = speed;
}
