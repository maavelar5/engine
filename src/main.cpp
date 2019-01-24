#include "game.h"
#include "timer.h"
#include "constants.h"
#include "camera.h"
#include "player.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main( int argc, char* argv[] )
{
    game::init();

    Player player;
    SDL_Event event;

    while( !game::quit )
    {
        timer::update();
        
        while( SDL_PollEvent( &event ) )
        {
            game::event( event );
            player.event ( event );
        }

        while ( timer::acumulator >= timer::timeStep )
        {
            camera::move ( player , player.velocity );
            timer::acumulator -= timer::timeStep;
        }

        SDL_RenderClear( game::renderer );
        render( player , player.texture );
        SDL_RenderPresent( game::renderer );
    }

    return 0;
}
