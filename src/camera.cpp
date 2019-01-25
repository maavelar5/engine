#include "camera.h"

namespace camera
{
    Vector position = { 0 , 0 };

    void move( Entity &entity )
    {
        float distance = entity.velocity.x * timer::acumulator;

        if( entity.velocity.x > 0 )
        {
            if( entity.screen.x >= CAMERA_OFFSET.w  &&
                camera::position.x <= ( SCENARIO_WIDTH - WINDOW_WIDTH )
                )
            {
                position.x += distance;
            }
            if( entity.position.x >= SCENARIO_WIDTH - 25 ) { }
            else { entity.position.x += distance; }
        }
        else
        {
            if( entity.screen.x <= CAMERA_OFFSET.x &&
                camera::position.x > 0 )
            {
                position.x += distance;
            }
            if( entity.position.x <= entity.screen.w ) { }
            else { entity.position.x += distance; }
        }

        if ( !entity.bot )
            entity.velocity.y += GRAVITY.y;

        entity.position.y += entity.velocity.y * timer::acumulator;
        entity.bot = SDL_FALSE;
    }
}
