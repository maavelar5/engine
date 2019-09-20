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
        if ( !config::values["debug"] ) return;

        window = SDL_CreateWindow( "Debug",
                                   513,
                                   0,
                                   DI_WINDOW_WIDTH,
                                   DI_WINDOW_HEIGHT,
                                   SDL_WINDOW_SHOWN |
                                   SDL_WINDOW_RESIZABLE |
                                   SDL_WINDOW_TOOLTIP );

        if ( window )
        {
            SDL_SetWindowOpacity(window , 0.0f);

            renderer = SDL_CreateRenderer( window,
                                           -1,
                                           SDL_RENDERER_ACCELERATED |
                                           SDL_RENDERER_PRESENTVSYNC );

            if ( renderer )
            {
                SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY , "linear" );

                SDL_RenderSetLogicalSize( renderer,
                                          DI_LOGICAL_WIDTH,
                                          DI_LOGICAL_HEIGHT );

                SDL_SetWindowMinimumSize( window,
                                          DI_WINDOW_WIDTH,
                                          DI_WINDOW_HEIGHT );

                SDL_SetRenderDrawBlendMode( renderer , SDL_BLENDMODE_BLEND );
                SDL_SetRenderDrawColor ( renderer , 25 , 50, 100 , 255 );
                SDL_RenderClear( renderer );
            }
        }

    }

    void draw ( std::string text , SDL_Color color )
    {
        if ( !config::values["debug"] ) return;

        std::shared_ptr < Text > storage
            ( new Text ( font::createTexture ( text , renderer ) ) );

        storage->position = { static_cast<int>(debug::position.x),
                              static_cast<int>(debug::position.y),
                              static_cast<int>(text.size() * 18),
                              32 };


        debug::text.push_back( storage );

        debug::position.y += 32;

        if ( debug::position.y > DI_WINDOW_HEIGHT )
        {
            for ( auto & line : debug::text )
            {
                line->adjust();
            }

            debug::position.y -= 32;
        }
    }

    void render ()
    {
        if ( !config::values["debug"] ) return;

        for ( auto & line : debug::text )
        {
            line->render( renderer );
        }
    }

    void event ( SDL_Event event )
    {
        if ( !config::values["debug"] ) return;

        int x , y;

        SDL_GetWindowPosition( window, &x, &y );

        if( event.type == SDL_KEYDOWN && event.key.repeat == 0 )
        {
            draw ( SDL_GetKeyName( event.key.keysym.sym ) );

            switch( event.key.keysym.sym )
            {
                case SDLK_o:
                    show = ( show ) ? false : true;

                    if ( show ) { SDL_ShowWindow ( window ); }
                    else { SDL_HideWindow( window ); }

                    break;
                case SDLK_h: SDL_HideWindow ( window ); break;
            }
        }
        if( event.type == SDL_KEYDOWN )
        {
            switch( event.key.keysym.sym )
            {
                case SDLK_LEFT: x -= 10; break;
                case SDLK_RIGHT: x += 10; break;
                case SDLK_UP: y -= 10; break;
                case SDLK_DOWN: y += 10; break;
                case SDLK_c:
                    text.clear();
                    position = { 0 , 0 };
                    break;
            }
        }

        SDL_SetWindowPosition( window , x , y );
    }
}
