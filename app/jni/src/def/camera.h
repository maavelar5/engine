#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "constants.h"
#include "timer.h"
#include "vector.h"

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

namespace camera
{
    extern Vector position;

    void move ( Vector & , SDL_Rect & );
}

#endif // CAMERA_H_INCLUDED
