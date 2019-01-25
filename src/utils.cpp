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
        int xId = entity.position.x / 1000, //GAME_LOGICAL_WIDTH,
            yId = entity.position.y / 1000; //GAME_LOGICAL_HEIGHT;

        entity.screen.x = floor(entity.position.x - camera::position.x - entity.screen.w);
        entity.screen.y = floor(entity.position.y - camera::position.y - entity.screen.h);

        entities::entities[ entity.xId ][ entity.yId ]
            .erase(std::remove(
                       entities::entities[ entity.xId ][ entity.yId ].begin(),
                       entities::entities[ entity.xId ][ entity.yId ].end(),
                       &entity),
                   entities::entities[ entity.xId ][ entity.yId ].end());
                    
        entities::entities[ xId ][ yId ].push_back (&entity);

        entity.xId = xId;
        entity.yId = yId;
    }

    void render ( Entity &entity , SDL_Texture* texture )
    {
        adjust ( entity );

        SDL_RenderCopy( game::renderer,
                        texture,
                        NULL,
                        &entity.screen );
    }

    void render ( std::vector < Entity > &entities , SDL_Texture* texture )
    {
        for ( int x = 0;
              x < entities.size();
              x++
            )
        {
            adjust ( entities[ x ] );

            SDL_RenderCopy( game::renderer,
                            texture,
                            NULL,
                            &entities[ x ].screen );
        }
    }

    void move ( Entity &entity )
    {
        entity.position.x += entity.velocity.x * timer::acumulator;
        if ( !entity.bot )
            entity.velocity.y += GRAVITY.y;

        entity.position.y += entity.velocity.y * timer::acumulator;

        entity.bot = SDL_FALSE;
    }
}
