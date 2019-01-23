#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "constants.h"
#include "entity.h"
#include "timer.h"
#include "vector.h"

namespace camera
{
    extern Vector position;
    extern SDL_Rect screen;

    void move( Entity &, Vector );
}

#endif // CAMERA_H_INCLUDED
