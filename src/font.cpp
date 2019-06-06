#include "font.h"

namespace font
{
    TTF_Font *Sans = nullptr;

    void init ( std::string fileName , Uint8 size )
    {
        TTF_Init ();

        std::string filePath = SPRITES_PATH + fileName;
        Sans = TTF_OpenFont( filePath.c_str() , 128 );
    }

    SDL_Texture * createTexture ( std::string message , SDL_Color color , SDL_Renderer *renderer )
    {
        SDL_Surface *surface = TTF_RenderText_Solid ( Sans , message.c_str() , color );
        SDL_Texture *texture = nullptr;

        if ( surface )
        {
            SDL_Texture * texture = SDL_CreateTextureFromSurface ( renderer , surface );

            SDL_FreeSurface ( surface );

            if ( texture )
            {
                return texture;
            }
        }

        return texture;
    }
}


