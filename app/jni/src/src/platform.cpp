#include "platform.h"

Platform::Platform () : Entities ( GENERIC_PLATFORM_FILE_PATH )
{
    screen = { 0 , 0 , 32 , 32 };

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
