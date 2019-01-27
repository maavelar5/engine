#include "platform.h"

Platform::Platform ()
{
    texture = utils::createTexture ( GENERIC_PLATFORM_FILE_PATH );

    for ( int x = 0;
          x < 1000;
          x += 32
        )
    {
        Entity entity;

        entity.screen = { x , 224 , 32 , 32 };
        entity.position = { x , 224 };
        platforms.push_back ( entity );
    }

    for ( int x = 200;
          x < 350;
          x += 32
        )
    {
        Entity entity;

        entity.screen = { x , 150 , 32 , 32 };
        entity.position = { x , 150 };
        platforms.push_back ( entity );
    }
}

Platform::~Platform () { }
