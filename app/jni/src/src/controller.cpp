#include "controller.h"

namespace controller
{
    SDL_GameController * controller = nullptr;

    void init ()
    {
        for ( int i = 0;
              i < SDL_NumJoysticks();
              ++i )
        {
            if ( SDL_IsGameController( i ) )
            {
                controller = SDL_GameControllerOpen( i );

                //if ( !controller ) { debug::draw ( SDL_GetError () ); }
            }
        }
    }
}
