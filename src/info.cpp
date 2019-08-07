#include "info.h"

namespace info
{
    uint8 y = 0;

    SDL_Window * window = nullptr;
    SDL_Renderer * renderer = nullptr;
    bool show = false;

    void init ()
    {
        window = SDL_CreateWindow( "Info", 512 , 0 , 512 , 512,
                                   SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );

        if ( window )
        {
            renderer = SDL_CreateRenderer( window , -1,
                                          SDL_RENDERER_ACCELERATED |
                                          SDL_RENDERER_PRESENTVSYNC );

            if ( renderer )
            {
                SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY  , "linear" );
                SDL_RenderSetLogicalSize( renderer , DI_LOGICAL_WIDTH , DI_LOGICAL_HEIGHT );
                SDL_SetWindowMinimumSize( window, DI_LOGICAL_WIDTH , DI_LOGICAL_HEIGHT );
                SDL_SetRenderDrawColor( renderer , 50 , 50 , 50 , 50 );

                SDL_RenderClear ( renderer );
            }
        }

    }

    void draw ( std::string text , SDL_Color color )
    {
        SDL_Texture * texture =
            font::createTexture( text , renderer );

        SDL_Rect position = { 0 , y , text.size() * 18 , 32 };

        y += 32;

        SDL_RenderCopy(renderer, texture, NULL, &position );

        SDL_DestroyTexture( texture );
    }

    void event ( SDL_Event event )
    {
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
