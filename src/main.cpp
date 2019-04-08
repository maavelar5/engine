#include "game.h"
#include "timer.h"
#include "constants.h"
#include "camera.h"
#include "collision.h"
#include "player.h"
#include "platform.h"
#include "tileEditor.h"

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
    TileEditor te;
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
            collision::collide();
            timer::acumulator -= timer::timeStep;
        }

        SDL_RenderClear( game::renderer );

        te.render();
        player.render();

        SDL_RenderPresent( game::renderer );
    }

    return 0;
}
