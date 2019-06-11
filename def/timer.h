#ifndef TIMER
#define TIMER

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

namespace timer
{
    extern float acumulator, timeStep , currentTime , previousTime , frameTime , FPS;
    extern Uint32 frames , nextTime;
    extern Uint8 TICK_INTERVAL;

    void init () , update () , updateFPS ();
    Uint32 timeLeft ();
}

#endif // TIMER_H_INCLUDED
