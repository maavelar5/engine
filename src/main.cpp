#include "game.h"
#include "timer.h"
#include "constants.h"
#include "camera.h"
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
    hud::init ();

    Player player;
    Mapper mapper;
    SDL_Event event;

    Uint32 frames = 0;

    while ( !game::quit )
    {
        timer::update ();

        while ( SDL_PollEvent( &event ) )
        {
            game::event( event );
            player.event ( event );
        }

        physics::world.Step(1.0/60.0, 6, 2);

        

        SDL_RenderClear( game::renderer );

        mapper.render();
        player.render();

//        hud::draw (std::to_string ( entities::toCollide.size() ) , black );

        float avgFPS = frames / ( SDL_GetTicks() / 1000.f );

        if ( avgFPS > 2000000 )
        {
            avgFPS = 0;
        }

        //hud::draw ( std::to_string ( avgFPS ) );

        hud::draw (std::to_string ( player.screen.x ) + " - " +
                   std::to_string ( player.screen.y ));

        hud::draw (std::to_string ( player.body->GetPosition().x ) + " - " +
                   std::to_string ( player.body->GetPosition().y ) , RT);

        /*hud::draw (std::to_string ( player.body->GetWorldCenter().x ) + " - " +
          std::to_string ( player.body->GetWorldCenter().y ) , LT);*/

        hud::draw (std::to_string ( player.body->GetLinearVelocity().x), LT);

        SDL_RenderPresent( game::renderer );

        frames++;
    }

    return 0;
}
