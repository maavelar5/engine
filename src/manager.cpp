#include "manager.h"

namespace manager
{
    SDL_Event _event;

    void init ()
    {
        game::init();
        timer::init();
        controller::init();
        font::init();
        debug::init();
        info::init();
        config::init();
        mapper::init();
    }

    void clear ()
    {
        SDL_RenderClear( game::renderer );
        SDL_RenderClear( debug::renderer );
        SDL_RenderClear( info::renderer );
    }

    void event ()
    {
        while( SDL_PollEvent( &_event ) )
        {
            game::event( _event );
            mapper::event ( _event );
            debug::event ( _event );
        }
    }

    void update ()
    {
        while ( timer::acumulator >= timer::timeStep )
        {
            mapper::update();
            collision::collide();
            timer::acumulator -= timer::timeStep;
        }

        timer::interpolation = timer::acumulator / timer::timeStep;
    }

    void render ()
    {
        mapper::render();
        info::draw( "FPS: " + std::to_string( timer::FPS ).substr( 0 , 4 ) );
        debug::render();

        SDL_RenderPresent( game::renderer );
        SDL_RenderPresent( info::renderer );
        SDL_RenderPresent( debug::renderer );

        info::y = 0;
        timer::update();
    }
}
