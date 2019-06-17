#include "camera.h"

namespace camera
{
    Vector position;

    void move ( Vector &velocity , SDL_Rect &screen )
    {
        float distance = velocity.x * timer::acumulator;

        if ( velocity.x > 0 )
        {
            if( screen.x >= CAMERA_OFFSET.w  &&
                position.x <= ( SCENARIO_WIDTH - WINDOW_WIDTH ) )
            {
                position.x += distance;
            }
        }
        else
        {
            if ( screen.x <= CAMERA_OFFSET.x &&
                position.x > 0 )
            {
                position.x += distance;
            }
        }
    }
}
