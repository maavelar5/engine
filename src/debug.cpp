#include "debug.h"

namespace debug
{
    Vector position ( 0 , 0 );
    std::vector < std::shared_ptr < Text > > text;
    SDL_Window * window = nullptr;
    SDL_Renderer * renderer = nullptr;
    bool show = true;

    void init ()
    {
        window = SDL_CreateWindow( "Debug", 0 , 0 , 1280 , 720,
                                   SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );

        if ( window )
        {
            renderer = SDL_CreateRenderer( window , -1,
                                           SDL_RENDERER_ACCELERATED |
                                           SDL_RENDERER_PRESENTVSYNC );

            if ( renderer )
            {
                SDL_SetRenderDrawColor( renderer , 0 , 0, 0 , 0 );
            }
        }

    }

    void draw ( std::string text , SDL_Color color )
    {
        std::shared_ptr < Text > storage
            ( new Text ( font::createTexture ( text , 16 , white , renderer ) ) );

        storage->position = {  debug::position.x , debug::position.y , text.size() * 16 , 24 };

        storage->render ( renderer );

        debug::text.push_back ( storage );
        debug::position.y += 32;

        if ( debug::position.y > 512 )
        {
            SDL_RenderClear( renderer );

            for ( auto & line : debug::text )
            {
                line->render (renderer , true);
            }

            debug::position.y -= 32;
        }
    }

    void event ( SDL_Event event )
    {
        int x , y;

        SDL_GetWindowPosition(window, &x, &y);

        if( event.type == SDL_KEYDOWN && event.key.repeat == 0 )
        {
            draw ( SDL_GetKeyName ( event.key.keysym.sym ) );
            switch( event.key.keysym.sym )
            {
                case SDLK_o:
                    show = (show)
                        ? false
                        : true;

                    if (show) { SDL_ShowWindow ( window ); }
                    else { SDL_HideWindow( window ); }

                    break;
                case SDLK_h: SDL_HideWindow ( window ); break;
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

        SDL_SetWindowPosition( window , x , y );
    }
}
