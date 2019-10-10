#ifndef MANAGER
#define MANAGER

#include "controller.h"
#include "mapper.h"
#include "hud.h"
#include "font.h"
#include "enemy.h"
#include "floating_enemy.h"
#include "sdl_inclusion.h"

#include <algorithm>

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

namespace manager
{
    extern SDL_Event _event;

    void clear () , render () , event () , init () , update ();
}

#endif
