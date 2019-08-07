#include "entities.h"

Entities::Entities ( std::string filePath ) :
    Texture ( filePath )
{

}

Entities::~Entities () { }

void Entities::event ( SDL_Event event )
{

}

Entity * Entities::single ()
{
    return nullptr;
}
