#include "game.h"
#include "timer.h"
#include "constants.h"
#include "camera.h"
#include "collision.h"
#include "player.h"
#include "mapper.h"
#include "hud.h"

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

int main( int argc, char* argv[] )
{
    game::init ();
    entities::init ();
    hud::init ();

    Player player;
    Mapper mapper;
    SDL_Event event;

    Uint32 frames = 0;

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

        mapper.render();
        player.render();

//        hud::draw (std::to_string ( entities::toCollide.size() ) , black );

        float avgFPS = frames / ( SDL_GetTicks() / 1000.f );

        if( avgFPS > 2000000 )
        {
            avgFPS = 0;
        }

        hud::draw ( std::to_string ( avgFPS ) );

        SDL_RenderPresent( game::renderer );

        frames++;
    }

    return 0;
}
