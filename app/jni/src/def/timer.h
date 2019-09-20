#ifndef TIMER
#define TIMER

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

namespace timer
{
    extern float acumulator, timeStep , currentTime , previousTime , frameTime,
        FPS , interpolation;
    extern Uint32 frames;

    void init () , update () , updateFPS ();
}

#endif // TIMER_H_INCLUDED
