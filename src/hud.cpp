#include "hud.h"

namespace hud
{
    TTF_Font *Sans = nullptr;
    SDL_Texture *texture = nullptr;

    void init ()
    {
        TTF_Init ();

        std::string filePath = SPRITES_PATH + "OpenSans-Regular.ttf"; 

        Sans = TTF_OpenFont( filePath.c_str() , 24 );
    }

    void draw ( std::string message )
    {
        SDL_Color color = { 255 , 255 , 255 };

        SDL_Surface *surface = TTF_RenderText_Solid ( Sans , message.c_str() , color );
        
        if ( surface )
        {
            texture = SDL_CreateTextureFromSurface ( game::renderer , surface );

            if ( texture )
            {
                SDL_Rect screen = { 200 , 10 , 50 , 50 };

                SDL_FreeSurface ( surface );

                SDL_RenderCopy ( game::renderer , texture , NULL , &screen );
            }
        }
    }
}
