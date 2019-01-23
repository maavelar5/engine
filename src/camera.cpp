#include "camera.h"

namespace camera
{
    Vector position = { 0 , 0 };
    SDL_Rect screen = { 0 , 0 , GAME_LOGICAL_WIDTH , GAME_LOGICAL_HEIGHT };

    void move( Entity &entity , Vector velocity )
    {
        float distance = velocity.x * timer::acumulator;

        if( velocity.x > 0 )
        {
            if( entity.screen.x >= CAMERA_OFFSET.w  &&
                camera::screen.x <= ( SCENARIO_WIDTH - WINDOW_WIDTH )
                )
            {
                camera::position.x += distance;
                camera::screen.x = floor(position.x);
            }
            if( entity.position.x >= SCENARIO_WIDTH - 25 ) { }
            else { entity.position.x += distance; }
        }
        else
        {
            if( entity.screen.x <= CAMERA_OFFSET.x &&
                camera::screen.x > 0 )
            {
                camera::position.x += distance;
                camera::screen.x = floor(position.x);
            }
            if( entity.position.x <= entity.screen.w ) { }
            else { entity.position.x += distance; }
        }
    }
}
