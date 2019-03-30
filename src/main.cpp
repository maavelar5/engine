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
    gameInit();

    Player player;
    Platform platform;
    SDL_Event event;

    while( !quit )
    {
        timer::update();
        
        while( SDL_PollEvent( &event ) )
        {
            gameEvent( event );
            player.event ( event );
        }

        while ( timer::acumulator >= timer::timeStep )
        {
            player.move();
            timer::acumulator -= timer::timeStep;
        }

        SDL_RenderClear( renderer );
        platform.render();
        player.render();

        SDL_RenderPresent( renderer );
    }

    return 0;
}
