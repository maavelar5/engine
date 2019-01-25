#include "game.h"
#include "timer.h"
#include "constants.h"
#include "camera.h"
#include "collision.h"
#include "player.h"
#include "platform.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main( int argc, char* argv[] )
{
    game::init();
    entities::init();

    Player player;
    Platform platform;
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
            camera::move ( player );
            collision::collide();
            timer::acumulator -= timer::timeStep;
        }

        SDL_RenderClear( game::renderer );
        utils::render( player , player.texture );
        utils::render( platform.platforms , platform.texture );
        SDL_RenderPresent( game::renderer );
    }

    return 0;
}
