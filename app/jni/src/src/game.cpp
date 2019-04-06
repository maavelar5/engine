#include "game.h"

namespace game
{
    bool quit = false;

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    bool init ()
    {
        SDL_Init( SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER );

        window = SDL_CreateWindow(  WINDOW_TITLE.c_str(),
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    WINDOW_WIDTH,
                                    WINDOW_HEIGHT,
                                    SDL_WINDOW_SHOWN );
        if( window )
        {
            renderer = SDL_CreateRenderer( window,
                                           -1,
                                           SDL_RENDERER_ACCELERATED );

            if ( renderer )
            {
                // make the scaled rendering look smoother.
                SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "linear" );
                SDL_RenderSetLogicalSize( renderer,
                                          GAME_LOGICAL_WIDTH,
                                          GAME_LOGICAL_HEIGHT );
                SDL_SetWindowMinimumSize( window,
                                          GAME_LOGICAL_WIDTH,
                                          GAME_LOGICAL_HEIGHT );
                SDL_SetRenderDrawColor( renderer , 0 , 0 , 0 , 0 );

                timer::init();

                SDL_GameController *controller = NULL;

                for ( int i = 0;
                      i < SDL_NumJoysticks();
                      ++i )
                {
                    if ( SDL_IsGameController( i ) )
                    {
                        controller = SDL_GameControllerOpen( i );
                        if ( controller )
                            break;
                        else
                            fprintf( stderr, "Could not open gamecontroller %i: %s\n" , i, SDL_GetError() );
                    } 
                }

                return SDL_TRUE;
            }
        }
    
        return SDL_FALSE;
    }

    void event ( SDL_Event event )
    {
        if ( event.type == SDL_QUIT )
            quit = SDL_TRUE;
    }
    
}
