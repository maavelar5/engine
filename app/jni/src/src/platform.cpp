#include "platform.h"

Platform::Platform () : Entities ( GENERIC_PLATFORM_FILE_PATH )
{
    for ( int x = 0;
          x < 1000;
          x += 32
        )
    {
        add ( x , 224 );
    }

    for ( int x = 200;
          x < 350;
          x += 32
        )
    {
        add ( x , 150 );
    }
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
