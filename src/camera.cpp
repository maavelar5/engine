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
        }
        else
        {
            if( entity.screen.x <= CAMERA_OFFSET.x &&
                camera::position.x > 0 )
            {
                position.x += distance;
            }
        }

        utils::move ( entity );
    }
}
