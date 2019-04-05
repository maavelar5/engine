#include "game.h"
#include "timer.h"
#include "constants.h"
#include "camera.h"
#include "collision.h"
#include "player.h"
#include "platform.h"

#if __ANDROID__
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
            player.move();
            timer::acumulator -= timer::timeStep;
        }

        collision::collide();

        SDL_RenderClear( game::renderer );

        platform.render();
        player.render();

        SDL_RenderPresent( game::renderer );

        entities::toCollide.clear();
    }

    return 0;
}
