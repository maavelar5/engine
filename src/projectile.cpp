#include "projectile.h"

Projectile::Projectile () : Entities ( GENERIC_PROJECTILE_FILE_PATH )
{
    speed = 400;
}

Projectile::~Projectile () { }

void Projectile::add ( float x , float y )
{
    Entities::add ();

    Uint32 index = position.size() - 1;

    config[ index ] ^= STATIC | BULLET;
    screen[ index ] = { 0 , 0 , 4 , 4 };
    velocity[ index ].x = speed;
}
