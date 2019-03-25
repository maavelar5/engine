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
            entities::move();
            collision::collide();
            timer::acumulator -= timer::timeStep;
        }

        SDL_RenderClear( game::renderer );
        entities::render();
        player.render();
        SDL_RenderPresent( game::renderer );

        entities::remove();
    }

    return 0;
}
