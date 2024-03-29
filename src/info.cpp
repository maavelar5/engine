#include "info.h"

namespace info
{
    uint8 y = 0;

    SDL_Window * window = nullptr;
    SDL_Renderer * renderer = nullptr;
    bool show = false;

    void init ()
    {
        if ( !INFO_WINDOW ) { return; }

        window = SDL_CreateWindow( "Info", 0 , 0 , DI_WINDOW_WIDTH , DI_WINDOW_HEIGHT,
                                   SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE |
                                   SDL_WINDOW_TOOLTIP );

        if ( window )
        {
            renderer = SDL_CreateRenderer( window , -1,
                                          SDL_RENDERER_ACCELERATED |
                                          SDL_RENDERER_PRESENTVSYNC );

            if ( renderer )
            {
                SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY  , "linear" );

                SDL_RenderSetLogicalSize( renderer,
                                          DI_LOGICAL_WIDTH,
                                          DI_LOGICAL_HEIGHT );

                SDL_SetWindowMinimumSize( window,
                                          DI_WINDOW_WIDTH,
                                          DI_WINDOW_HEIGHT );

                SDL_SetRenderDrawColor( renderer , 50 , 50 , 50 , 50 );
                SDL_RenderClear ( renderer );
            }
        }

    }

    void draw ( std::string text , SDL_Color color )
    {
        if ( !INFO_WINDOW ) { return; }

        SDL_Texture * texture =
            font::createTexture( text , renderer );

        SDL_Rect position = { 0 , y , static_cast<int>(text.size()) * 18 , 32 };

        y += 32;

        SDL_RenderCopy(renderer, texture, NULL, &position );

        SDL_DestroyTexture( texture );
    }

    void event ( SDL_Event event )
    {
        if ( !INFO_WINDOW ) { return; }

        if( event.type == SDL_KEYDOWN && event.key.repeat == 0 )
        {
            switch( event.key.keysym.sym )
            {
                case SDLK_i:
                    show = (show) ? false : true;

                    if ( show ) { SDL_ShowWindow ( window ); }
                    else { SDL_HideWindow( window ); }

                    break;
                case SDLK_h: SDL_HideWindow ( window ); break;
            }
        }
    }
}
