#ifndef TIMER
#define TIMER

#include "sdl_inclusion.h"

namespace timer
{
    extern float acumulator, timeStep , currentTime , previousTime , frameTime,
        FPS , interpolation;
    extern Uint32 frames;

    void init () , update () , updateFPS ();
}

#endif // TIMER_H_INCLUDED
