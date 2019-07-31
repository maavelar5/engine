#include "info.h"

namespace info
{
    uint8 y = 0;

    SDL_Window * window = nullptr;
    SDL_Renderer * renderer = nullptr;

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
                SDL_SetRenderDrawColor( renderer , 50 , 50, 50 , 50 );
            }
        }

    }

    void draw ( std::string text , SDL_Color color )
    {
        SDL_Texture * texture =
            font::createTexture( text , 32 , white , renderer );

        SDL_Rect position = { 0 , y , text.size() * 32 , 48 };

        y += 48;

        SDL_RenderCopy(renderer, texture, NULL, &position );

        SDL_DestroyTexture( texture );
    }
}

