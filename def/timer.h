#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <SDL2/SDL.h>

namespace timer
{
    extern float acumulator, timeStep , currentTime , previousTime , frameTime;
    
    void init();
    void update();
};

#endif // TIMER_H_INCLUDED
