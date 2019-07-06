#include "directed_projectile.h"

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
            // TODO: Research position max value based on direction vector

            Vector position = entity->position;

            position += ( entity->direction * ( speed * timer::timeStep ) );

            add ( position.x , position.y );
            start();
        }
    }
}
