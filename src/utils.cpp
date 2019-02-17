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
        deleteLocator ( entity );
        entity.screen.x = floor(entity.position.x - camera::position.x );
        entity.screen.y = floor(entity.position.y - camera::position.y );
        setLocator ( entity );
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

        if ( entity.position.x <= 0 )
            entity.position.x = 0;
        else if ( entity.position.x >= SCENARIO_WIDTH )
            entity.position.x = SCENARIO_WIDTH;

        if ( !( entity.sensor & BOT_SENSOR ) )
            entity.velocity.y += GRAVITY.y;

        entity.position.y += entity.velocity.y * timer::acumulator;
        entity.sensor &= ~BOT_SENSOR;
        adjust ( entity );
    }

    void locator ( Entity &entity )
    {
        deleteLocator ( entity );
        setLocator ( entity );
    }

    void setLocator ( Entity &entity )
    {
        int xId = entity.position.x / 100,
            yId = entity.position.y / 100,
            wId = ( entity.position.x + entity.screen.w ) / 100,
            hId = ( entity.position.y + entity.screen.h ) / 100;

        for ( int y = yId;
              y <= hId;
              y++
            )
        {
            for ( int x = xId;
                  x <= wId;
                  x++
                )
            {
                entities::entities[ y ][ x ].push_back( &entity );
            }
        }

        entity.locator = { xId , yId , wId , hId };
    }

    void deleteLocator ( Entity &entity )
    {
        for ( int y = entity.locator.y;
              y <= entity.locator.h;
              y++
            )
        {
            for ( int x = entity.locator.x;
                  x <= entity.locator.w;
                  x++
                )
            {

                entities::entities[ y ][ x ]
                    .erase(std::remove(
                               entities::entities[ y ][ x ].begin(),
                               entities::entities[ y ][ x ].end(),
                               &entity),
                           entities::entities[ y ][ x ].end());
            }
        }
    }
}
