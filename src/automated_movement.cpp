#include "automated_movement.h"

Timer::Timer ( Uint32 delay , Uint8 config )
{
    this->delay = delay;
    status = 0;
    currentTime = 0;
}

Timer::Timer () { }

Timer::~Timer () { }

void Timer::start ()
{
    currentTime = SDL_GetTicks ();
    status = 1;
}

void Timer::stop ()
{
    status = 0;
}

void Timer::pause ()
{

}

Uint8 Timer::check ()
{
    if ( SDL_GetTicks () - currentTime >= delay )
    {
        status = 2;
    }

    return status;
}

AutomatedMovement::AutomatedMovement () { }

AutomatedMovement::~AutomatedMovement () { }
