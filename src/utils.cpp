#include "utils.h"

namespace utils
{
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
        entity.screen.x = entity.position.x - camera::position.x - entity.screen.w;
        entity.screen.y = entity.position.y - camera::position.y - entity.screen.h;
    }

    void render ( Entity &entity , SDL_Texture* texture )
    {
        adjust ( entity );

        SDL_RenderCopy( game::renderer,
                        texture,
                        NULL,
                        &entity.screen );
    }

    void move ( Entity &entity )
    {
        entity.position.x += entity.velocity.x * timer::acumulator;
        if ( !entity.bot )
            entity.velocity.y += GRAVITY.y;

        entity.position.y += entity.velocity.y * timer::acumulator;
    }
}
