#include "texture.h"

Texture::Texture ( std::string filePath )
{
    this->filePath = filePath;
    this->texture = copy( game::renderer );
}

Texture::Texture ( SDL_Texture * texture )
{
    this->texture = texture;
}

Texture::~Texture ()
{
    SDL_DestroyTexture ( texture );
}

SDL_Texture * Texture::copy ( SDL_Renderer * renderer )
{
    SDL_Surface * surface = IMG_Load( filePath.c_str() );
    SDL_Texture * texture = nullptr;

    if ( surface )
    {
        texture = SDL_CreateTextureFromSurface( renderer , surface );
        SDL_FreeSurface( surface );
    }
    else
    {
        SDL_Log( "%s\n" , SDL_GetError() );

        surface = IMG_Load ( GENERIC_PLATFORM_FILE_PATH.c_str() );
        texture = SDL_CreateTextureFromSurface( renderer , surface );

        SDL_FreeSurface( surface );
    }

    return texture;
}
