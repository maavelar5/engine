#include "utils.h"

SDL_Texture* createTexture ( const std::string filePath )
{
    SDL_Surface* surface = IMG_Load( filePath.c_str() );
    SDL_Texture* texture = nullptr;

    if ( surface )
    {
        texture = SDL_CreateTextureFromSurface( game::renderer , surface );
        SDL_FreeSurface( surface );
    }
    else { printf("%s",SDL_GetError()); }

    return texture;
}

void adjust ( Entity &entity )
{
    entity.screen.x = entity.position.x - camera::screen.x - entity.screen.w;
    entity.screen.y = entity.position.y - camera::screen.y - entity.screen.h;
}

void render ( Entity &entity , SDL_Texture* texture )
{
    adjust ( entity );

    SDL_RenderCopy( game::renderer,
                    texture,
                    NULL,
                    &entity.screen );
}

void move ( Vector &position , Vector velocity )
{
    position.x += velocity.x * timer::acumulator;
}
