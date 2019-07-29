#include "game.h"

namespace game
{
    bool quit = false;
    bool show = false;

    SDL_Window *window = nullptr , *debugWindow = nullptr;
    SDL_Renderer *renderer = nullptr , *debugRenderer = nullptr;

    bool init ()
    {
        SDL_Init( SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER );

        window = SDL_CreateWindow( WINDOW_TITLE.c_str(),
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   WINDOW_WIDTH , WINDOW_HEIGHT,
                                   SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALWAYS_ON_TOP );



        if( window )
        {
            renderer = SDL_CreateRenderer( window,
                                           -1,
                                           SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if ( renderer )
            {
                // make the scaled rendering look smoother.
                SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY  , "linear" );
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

                        fprintf( stderr, "Could not open gamecontroller %i: %s\n" , i, SDL_GetError() );
                    }
                }

                initDebugObjects ();
                TTF_Init();

                return SDL_TRUE;
            }
        }
    
        return SDL_FALSE;
    }

    bool initDebugObjects ()
    {
        debugWindow = SDL_CreateWindow( "Debugging Window",
                                        512 , 0,
                                        512 , 512,
                                        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_POPUP_MENU );

        if ( debugWindow )
        {
            debugRenderer = SDL_CreateRenderer( debugWindow , -1,
                                                SDL_RENDERER_ACCELERATED |
                                                SDL_RENDERER_PRESENTVSYNC );

            if ( debugRenderer )
            {
                SDL_SetRenderDrawColor( debugRenderer , 50 , 50, 50 , 50 );
            }
        }
    }

    void event ( SDL_Event event )
    {
        int x , y;

        SDL_GetWindowPosition(game::debugWindow, &x, &y);

        if ( event.type == SDL_QUIT )
        {
            quit = SDL_TRUE;            
        }
        else if( event.type == SDL_KEYDOWN && event.key.repeat == 0 )
        {
            switch( event.key.keysym.sym )
            {
                case SDLK_l: game::quit = SDL_TRUE; break;
                case SDLK_o:
                    show = (show)
                        ? false
                        : true;

                    if (show) { SDL_ShowWindow ( game::debugWindow ); }
                    else { SDL_HideWindow( game::debugWindow ); }

                    break;
                case SDLK_h: SDL_HideWindow ( game::debugWindow ); break;
            }
        }
        else if( event.type == SDL_KEYDOWN )
        {
            switch( event.key.keysym.sym )
            {
                case SDLK_LEFT: x -= 10; break;
                case SDLK_RIGHT: x += 10; break;
                case SDLK_UP: y -= 10; break;
                case SDLK_DOWN: y += 10; break;
            }
        }
    }

    SDL_SetWindowPosition( game::debugWindow , x , y );
}
