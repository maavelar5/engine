#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#if __APPLE__ || __ANDROID__
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

namespace timer
{
    extern float acumulator, timeStep , currentTime , previousTime , frameTime;
    
    void init();
    void update();
};

#endif // TIMER_H_INCLUDED
