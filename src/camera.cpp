#include "camera.h"

namespace camera
{
    Vector position;

    void move ( float distance , SDL_Rect &screen )
    {
        if ( distance > 0 )
        {
            if( screen.x >= CAMERA_OFFSET.w  &&
                position.x <= ( SCENARIO_WIDTH - std::stoi( config::values["WINDOW_WIDTH"] ) ) )
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
