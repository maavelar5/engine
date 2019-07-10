#include "directed_projectile.h"

DirectedProjectiles::DirectedProjectiles ( uint16 speed , Entity * entity ) :
    Projectiles ( speed , entity )
{

}

DirectedProjectiles::~DirectedProjectiles () { }

void DirectedProjectiles::move ( Vector a )
{
    for ( auto & entity : entities )
    {
        entity->move ( a , speed );
    }
}

void DirectedProjectiles::update ()
{
    if ( isActive )
    {
        if ( check() == 2 )
        {
            // TODO: Research position max value based on direction vector

            Vector position = entity->position;

            position += ( entity->direction * ( speed * timer::timeStep ) );

            add ( position.x , position.y );
            start();
        }
    }
}
