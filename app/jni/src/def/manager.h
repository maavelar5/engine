#ifndef MANAGER
#define MANAGER

#include "game.h"
#include "timer.h"
#include "constants.h"
#include "controller.h"
#include "camera.h"
#include "collision.h"
#include "player.h"
#include "mapper.h"
#include "hud.h"
#include "info.h"
#include "font.h"
#include "enemy.h"
#include "floating_enemy.h"
#include "config.h"

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
