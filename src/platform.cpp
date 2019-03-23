#include "platform.h"

Platform::Platform ()
{
    texture = Entity::loadTexture ( GENERIC_PLATFORM_FILE_PATH );

    for ( int x = 0;
          x < 1000;
          x += 32
        )
    {
        Entity * entity  = new Entity("none" , texture);

        entity->screen = { x , 224 , 32 , 32 };
        entity->position = { static_cast < float > ( x ) , 224 };
    }

    for ( int x = 200;
          x < 350;
          x += 32
        )
    {
        Entity * entity  = new Entity("none" , texture);

        entity->screen = { x , 150 , 32 , 32 };
        entity->position = { static_cast < float > ( x ) , 150 };
    }
}

Platform::~Platform () { }
