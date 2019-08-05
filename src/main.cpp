#include "game.h"
#include "timer.h"
#include "constants.h"
#include "camera.h"
#include "collision.h"
#include "player.h"
#include "mapper.h"
#include "hud.h"
#include "info.h"
#include "font.h"
#include "enemy.h"
#include "floating_enemy.h"

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

int main ( int argc, char* argv[] )
{
    initCWD ( std::string( argv[0] ) );

    game::init ();
    debug::init ();
    info::init ();
    font::init ();

    Player player;
    Mapper mapper ( &player );
    SDL_Event event;

    while ( !game::quit )
    {
        timer::update();

        while( SDL_PollEvent( &event ) )
        {
            game::event( event );
            player.event ( event );
            debug::event ( event );
        }

        while ( timer::acumulator >= timer::timeStep )
        {
            player.move ();
            mapper.update ();
            collision::collide();
            timer::acumulator -= timer::timeStep;
        }

        timer::interpolation = timer::acumulator / timer::timeStep;

        SDL_RenderClear( game::renderer );
        SDL_RenderClear ( debug::renderer );
        SDL_RenderClear ( info::renderer );

        mapper.render();
        player.render();

        timer::updateFPS ();

        info::draw ( "FPS: " + std::to_string( timer::FPS ).substr( 0 , 4 ) );
        info::draw ( "X: " + std::to_string ( player.position.x ).substr( 0 , 4 ) );
        info::draw ( "Y: " + std::to_string ( player.position.y ).substr( 0 , 4 ) );
        info::draw ( "sensor: " + std::to_string( player.sensor ) );

        debug::render();

        SDL_RenderPresent ( game::renderer );
        SDL_RenderPresent ( info::renderer );
        SDL_RenderPresent ( debug::renderer );

        info::y = 0;
    }

    SDL_Quit();

    return 0;
}
