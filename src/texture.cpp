#include "texture.h"

Texture::Texture ( std::string filePath )
{
    SDL_Surface* surface = IMG_Load( filePath.c_str() );

    if ( surface )
    {
        texture = SDL_CreateTextureFromSurface( game::renderer , surface );
        SDL_FreeSurface( surface );
    }
    else
    {
        SDL_Log( "%s\n" , SDL_GetError() );

        surface = IMG_Load ( GENERIC_PLATFORM_FILE_PATH.c_str() );
        texture = SDL_CreateTextureFromSurface( game::renderer , surface );

        SDL_FreeSurface( surface );
    }
}

Texture::Texture ( SDL_Texture * texture )
{
    this->texture = texture;
}

Texture::~Texture ()
{
    SDL_DestroyTexture ( texture );
}
