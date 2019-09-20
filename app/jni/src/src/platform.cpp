#include "platform.h"

Platforms::Platforms ( std::string filePath ) :
    Entities ( filePath )
{

}

Platforms::~Platforms () { }

void Platforms::render ()
{
    for ( auto & entity : entities )
    {
        entity->render ( texture );
    }
}

void Platforms::move () { }
void Platforms::update () { }

void Platforms::add ( float x , float y , int w , int h )
{
    entities.push_back ( std::shared_ptr < Entity >
                         ( new Entity ( x , y , w , h , ACTIVE | STATIC ) ) );
}

void Platforms::clear ()
{
    entities.clear();
}
