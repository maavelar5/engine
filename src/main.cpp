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

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

int main( int argc, char* argv[] )
{
    game::init ();
    font::init ();

    Player player;
    Mapper mapper;
    SDL_Event event;

    SDL_RaiseWindow ( game::window );
    SDL_HideWindow ( game::debugWindow );

    while ( !game::quit )
    {
        SDL_RenderClear( game::renderer );
        SDL_RenderClear ( game::debugRenderer );

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

        timer::interpolation = timer::acumulator / timer::timeStep;

        mapper.render();
        player.render();
        
        timer::updateFPS ();

        info::draw ( "FPS: " , std::to_string ( timer::FPS ) );
        info::draw ( "Objects: " , std::to_string ( entities::queue.size() ));
        info::draw ( "interpolation: " , std::to_string ( timer::interpolation ));
        
        SDL_RenderPresent ( game::renderer );
        SDL_RenderPresent ( game::debugRenderer );

        info::x = info::y = 1;
 
    }

    return 0;
}
