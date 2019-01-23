#include "timer.h"

namespace timer
{
    float acumulator, timeStep , currentTime , previousTime , frameTime;
    
    void init() 
    {
        previousTime = ( SDL_GetTicks() / 1000.f );
        acumulator = frameTime = currentTime = acumulator = 0;
        timeStep = 0.01;
    }

    void update()
    {
        currentTime = ( SDL_GetTicks() / 1000.f );
        frameTime = currentTime - previousTime;
        previousTime = currentTime;

        if ( frameTime > 0.25 ) { frameTime = 0.25; }
        else { } 

        acumulator += frameTime;
    }
}
