#ifndef AUTOMATED_MOVEMENT
#define AUTOMATED_MOVEMENT

#include <map>
#include <memory>
#include <SDL2/SDL.h>

struct Timer
{
    Uint32 delay , currentTime;
    Uint8 status , config;

    Timer ( Uint32 , Uint8 config = 1 );
    Timer ();
    ~Timer ();

    void start () , stop () , pause ();
    Uint8 check ();    
};

struct AutomatedMovement
{
    std::map < Uint8 , Timer > moves;

    Uint8 current;

    AutomatedMovement ();
    ~AutomatedMovement ();
};

#endif
