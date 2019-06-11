#include "timer.h"

namespace timer
{
    float acumulator, timeStep , currentTime , previousTime , frameTime , FPS;
    Uint32 frames , nextTime;
    Uint8 TICK_INTERVAL;

    void init () 
    {
        previousTime = ( SDL_GetTicks() / 1000.f );
        acumulator = frameTime = currentTime = acumulator = 0;
        timeStep = 0.01;
        frames = 1;
        TICK_INTERVAL = 10;
        nextTime = SDL_GetTicks() + TICK_INTERVAL;
    }

    void update ()
    {
        currentTime = ( SDL_GetTicks() / 1000.f );
        frameTime = currentTime - previousTime;
        previousTime = currentTime;

        if ( frameTime > 0.25 ) { frameTime = 0.25; }
        else { } 

        acumulator += frameTime;
    }

    void updateFPS ()
    {
        FPS = frames / ( SDL_GetTicks() / 1000.f );

        if ( FPS > 2000000 )
            FPS = 0;

        frames++;
    }

    Uint32 timeLeft ()
    {
        Uint32 now;

        now = SDL_GetTicks();
        if(nextTime <= now)
            return 0;
        else
            return nextTime - now;
    }
}
