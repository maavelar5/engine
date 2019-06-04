#include "hud.h"

const SDL_Color white = { 255 , 255 , 255 },
    black = { 0 , 0 , 0 };

const SDL_Rect LT = {  10 , 10 , 50 , 50 } , T = { 100 , 10 , 50 , 50 } , RT = { 200 , 10 , 50 , 50 };

namespace hud
{
    TTF_Font *Sans = nullptr;
    SDL_Texture *texture = nullptr;

    void init ()
    {
        TTF_Init ();

        std::string filePath = SPRITES_PATH + "OpenSans-Regular.ttf"; 

        Sans = TTF_OpenFont( filePath.c_str() , 128 );
    }

    void draw ( std::string message , SDL_Rect position , SDL_Color color )
    {
        SDL_Surface *surface = TTF_RenderText_Solid ( Sans , message.c_str() , color );
        
        if ( surface )
        {
            texture = SDL_CreateTextureFromSurface ( game::renderer , surface );

            if ( texture )
            {
                SDL_FreeSurface ( surface );

                SDL_RenderCopy ( game::renderer , texture , NULL , &position );

                SDL_DestroyTexture ( texture );
            }
        }
    }
}
