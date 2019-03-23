#include "camera.h"

namespace camera
{
    Vector position = { 0 , 0 };

    void move( Vector velocity , SDL_Rect screen )
    {
        float distance = velocity.x * timer::acumulator;

        if( velocity.x > 0 )
        {
            if( screen.x >= CAMERA_OFFSET.w  &&
                camera::position.x <= ( SCENARIO_WIDTH - WINDOW_WIDTH )
                )
            {
                position.x += distance;
            }
        }
        else
        {
            if( screen.x <= CAMERA_OFFSET.x &&
                camera::position.x > 0 )
            {
                position.x += distance;
            }
        }
    }
}
