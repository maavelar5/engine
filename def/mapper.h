#ifndef MAPPER
#define MAPPER

#include "player.h"
#include "enemy.h"
#include "platform.h"
#include "floating_enemy.h"

#include <fstream>
#include <map>
#include <regex>
#include <SDL2/SDL.h>
#include <string>

namespace mapper
{
    extern std::map < std::string , std::shared_ptr < Entities > > entities;

    void init () , add ( float , float , int , int , std::string ),
        render () , load () , update () , event ( SDL_Event );
};

#endif
