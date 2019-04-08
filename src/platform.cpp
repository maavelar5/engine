#include "platform.h"

Platform::Platform () : Entities ( GENERIC_PLATFORM_FILE_PATH )
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
