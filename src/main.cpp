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
    game::init ();
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
        SDL_RenderClear ( game::debugRenderer );

        mapper.render();
        player.render();

        timer::updateFPS ();

        info::draw ( "FPS: " , std::to_string ( timer::FPS ) );
        info::draw ( "Projectiles: " , std::to_string (
                         player.projectiles.entities.size() ) );
        info::draw ( "X: " , std::to_string ( player.position.x ) );
        info::draw ( "Y: " , std::to_string ( player.position.y ) );
        info::draw ( "velY: " , std::to_string ( player.velocity.y ) );
        info::draw ( "sensor: " , std::to_string ( player.sensor ) );

        SDL_RenderPresent ( game::renderer );
        SDL_RenderPresent ( game::debugRenderer );

        info::x = info::y = 1;
    }

    SDL_Quit();

    return 0;
}
