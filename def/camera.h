#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "constants.h"
#include "timer.h"
#include "vector.h"

#include <SDL2/SDL.h>

extern Vector cameraPosition;

void cameraMove ( Vector & , SDL_Rect & );

#endif // CAMERA_H_INCLUDED
