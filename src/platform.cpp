#include "platform.h"

Platform::Platform ( std::string filePath ) : Entities ( filePath )
{

}

Platform::~Platform () { }

void Platform::add ( float x , float y )
{
    std::shared_ptr < Entity >  entity (new Entity ());

    entity->position = { x , y };
    entity->screen = { 0 , 0 , 32, 32 };
    entity->adjust();

    entities.push_back ( entity );
}
