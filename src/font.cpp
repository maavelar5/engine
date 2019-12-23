#include "font.h"

namespace font
{
    std::map < uint8 , TTF_Font * > fonts;

    void init ( std::string path , std::vector < uint8 > sizes )
    {
        TTF_Init ();

        for ( auto & size : sizes )
        {
            fonts [ size ] = TTF_OpenFont ( path.c_str() , size );
        }
    }

    SDL_Texture * createTexture ( std::string message,
                                  SDL_Renderer * renderer,
                                  uint8 size,
                                  SDL_Color color )
    {
        SDL_Surface * surface =
            TTF_RenderText_Solid ( fonts[ size ] , message.c_str() , color );
        SDL_Texture * texture = nullptr;

        SDL_SetSurfaceBlendMode ( surface , SDL_BLENDMODE_BLEND );

        if ( surface )
        {
            texture = SDL_CreateTextureFromSurface( renderer, surface );
            SDL_FreeSurface( surface );

            if ( texture ) { return texture; }
        }

        return texture;
    }
}
