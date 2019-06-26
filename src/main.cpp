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

    Enemies enemies ( &player );

    enemies.add ( 100 , 50 , 32 , 32  );

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
            player.move();
            enemies.update ();
            collision::collide();
            timer::acumulator -= timer::timeStep;
        }

        timer::interpolation = timer::acumulator / timer::timeStep;

        SDL_RenderClear( game::renderer );
        SDL_RenderClear ( game::debugRenderer );

        mapper.render();
        player.render();
        enemies.render();

        timer::updateFPS ();

        info::draw ( "FPS: " , std::to_string ( timer::FPS ) );
        info::draw ( "Projectiles: " , std::to_string (
                         player.projectile.entities.size() ) );
        info::draw ( "X: " , std::to_string ( player.position.x ) );
        info::draw ( "Y: " , std::to_string ( player.position.y ) );

        SDL_RenderPresent ( game::renderer );
        SDL_RenderPresent ( game::debugRenderer );

        info::x = info::y = 1;
    }

    SDL_Quit();

    return 0;
}
