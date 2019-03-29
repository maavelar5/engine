#include "projectile.h"

Projectile::Projectile () : Entities ( GENERIC_PROJECTILE_FILE_PATH )
{
    speed = 400;

    config ^= STATIC | BULLET;
    screen = { 0 , 0 , 4 , 4 };
}

Projectile::~Projectile () { }

Uint32 Projectile::add ( float x , float y )
{
    Uint32 index = Entities::add ( x , y );

    entities::linear[ index ]->velocity.x = speed;
    indices.push_back( index );

    return index;
}
