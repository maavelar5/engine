#ifndef TIMER
#define TIMER

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

namespace timer
{
    extern float acumulator, timeStep , currentTime , previousTime , frameTime , FPS , interpolation;
    extern Uint32 frames , loops , nextGameTick;
    
    extern const int TICKS_PER_SECOND;
    extern const int SKIP_TICKS;
    extern const int MAX_FRAMESKIP;

    void init () , update () , updateFPS ();
}

#endif // TIMER_H_INCLUDED
