#include "game.h"

namespace game
{
    bool quit = false;

    SDL_Window * window = nullptr;
    SDL_Renderer * renderer = nullptr;

    bool init ()
    {
        SDL_Init( SDL_INIT_EVERYTHING );

        window = SDL_CreateWindow ( WINDOW_TITLE.c_str(),
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    WINDOW_WIDTH,
                                    WINDOW_HEIGHT,
                                    SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );


        if ( !window ) { return false; }

        renderer = SDL_CreateRenderer( window, -1,
                                       SDL_RENDERER_ACCELERATED |
                                       SDL_RENDERER_PRESENTVSYNC );

        if ( !renderer ) { return false; }

        // make the scaled rendering look smoother.
        SDL_SetHint ( SDL_HINT_RENDER_SCALE_QUALITY  , "linear" );
        SDL_RenderSetLogicalSize ( renderer,
                                   GAME_LOGICAL_WIDTH,
                                   GAME_LOGICAL_HEIGHT );
        SDL_SetWindowMinimumSize ( window,
                                   GAME_LOGICAL_WIDTH,
                                   GAME_LOGICAL_HEIGHT );
        SDL_SetRenderDrawColor ( renderer , 0 , 0 , 0 , 0 );

        return true;
    }

    void event ( SDL_Event event )
    {
        if ( event.type == SDL_QUIT )
        {
            quit = true;
        }
        else if( event.type == SDL_KEYDOWN && event.key.repeat == 0 )
        {
            switch( event.key.keysym.sym )
            {
                case SDLK_l: game::quit = true; break;
            }
        }
    }
}
