#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "constants.h"
#include "entity.h"
#include "timer.h"
#include "utils.h"
#include "vector.h"

namespace camera
{
    extern Vector position;

    void move( Entity & );
}

#endif // CAMERA_H_INCLUDED
