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
    Entities::add();

    Uint32 index = position.size() - 1;

    position[ index ] = { x , y };
    screen[ index ] = { x , y , 32 , 32 };
}
