#ifndef TIMER
#define TIMER

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

namespace timer
{
    extern float acumulator, timeStep , currentTime , previousTime , frameTime;
    
    void init () , update ();
}

#endif // TIMER_H_INCLUDED
