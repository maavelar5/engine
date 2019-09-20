#ifndef CAMERA_
#define CAMERA_

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

    void move ( float , SDL_Rect & );
}

#endif // CAMERA_H_INCLUDED
