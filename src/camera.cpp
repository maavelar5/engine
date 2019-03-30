#include "camera.h"

Vector cameraPosition;

void cameraMove ( Vector &velocity , SDL_Rect &screen )
{
    float distance = velocity.x * timer::acumulator;

    if( velocity.x > 0 )
    {
        if( screen.x >= CAMERA_OFFSET.w  &&
            cameraPosition.x <= ( SCENARIO_WIDTH - WINDOW_WIDTH ) )
        {
            cameraPosition.x += distance;
        }
    }
    else
    {
        if( screen.x <= CAMERA_OFFSET.x &&
            cameraPosition.x > 0 )
        {
            cameraPosition.x += distance;
        }
    }
}
