#include "game.h"
#include "timer.h"
#include "constants.h"
#include "camera.h"
#include "collision.h"
#include "player.h"
#include "platform.h"

#if __APPLE__ || __ANDROID__
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

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
        SDL_RenderPresent( game::renderer );
        entities::remove();
    }

    return 0;
}
