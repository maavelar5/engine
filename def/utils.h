#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "camera.h"
#include "entity.h"
#include "game.h"
#include "timer.h"
#include "vector.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture* createTexture ( const std::string );
void adjust ( Entity & );
void render ( Entity & , SDL_Texture * );
void move ( Vector & , Vector );

#endif
