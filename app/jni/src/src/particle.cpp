#include "particle.h"

Particle::Particle ( float x , float y , int w , int h ) :
    Entity ( x , y , w , h , ACTIVE | PARTICLE )
{

}

Particle::~Particle ()
{

}

void Particle::update ()
{

}

Particles::Particles () : Entities ( GENERIC_PROJECTILE_FILE_PATH ),
                          timer ( 50 )
{

}

void Particles::render ()
{
    for ( auto entity = entities.begin(); entity != entities.end(); entity++ )
    {
        if ( (*entity)->config & ACTIVE )
        {
            (*entity)->render ( texture );
        }
        else
        {
            (*entity)->deleteLocator ();
            entities.erase ( entity-- );
        }
    }
}

void Particles::move ()
{
    for ( auto &entity : entities )
    {
        entity->move ();
    }
}

void Particles::update ()
{
    for ( auto &entity : entities )
    {
        entity->update ();
    }
}

void Particles::add ( float x , float y , int w , int h )
{
    std::shared_ptr < Particle > particle ( new Particle ( x , y , w , h ) );
    particle->speed = 50;

    entities.push_back ( particle );
}

void Particles::clear ()
{
    entities.clear();
}
