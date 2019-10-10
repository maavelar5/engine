#include "utils.h"

std::map < std::string , SDL_Texture * > textures;

std::map < std::string , std::vector < std::shared_ptr < Base > > > gridKinematics;
std::map < std::string , std::vector < std::shared_ptr < Base > > > gridPlatforms;

// Example from sdl.org
std::string readFile ( std::string filePath )
{
    SDL_RWops * rw = SDL_RWFromFile ( filePath.c_str () , "r" );

    if ( rw == NULL ) return "";

    Sint64 res_size = SDL_RWsize ( rw );
    char * res = ( char * ) malloc ( res_size + 1 );
    Sint64 nb_read_total = 0 , nb_read = 1;
    char * buf = res;

    while ( nb_read_total < res_size && nb_read != 0 )
    {
        nb_read = SDL_RWread ( rw , buf , 1 , ( res_size - nb_read_total ) );
        nb_read_total += nb_read;
        buf += nb_read;
    }

    SDL_RWclose ( rw );

    if ( nb_read_total != res_size )
    {
        free ( res );
        return "";
    }

    res [ nb_read_total ] = '\0';

    return res;
}

SDL_Texture * createTexture ( std::string filePath , SDL_Renderer * renderer )
{
    if ( textures.find ( filePath ) != textures.end () )
    {
        return textures [ filePath ];
    }

    SDL_Surface * surface = IMG_Load ( filePath.c_str () );
    SDL_Texture * texture = nullptr;

    if ( !surface )
    {
        SDL_Log( "%s\n" , SDL_GetError () );
        filePath = GENERIC_PLATFORM_FILE_PATH;
        surface = IMG_Load ( GENERIC_PLATFORM_FILE_PATH.c_str() );
    }

    texture = SDL_CreateTextureFromSurface ( renderer , surface );
    textures [ filePath ] = texture;

    SDL_FreeSurface ( surface );

    return texture;
}
