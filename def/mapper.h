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
    extern std::map < uint8 , std::vector < std::string > > scenes;

    void init () , add ( float , float , int , int , std::string ), change (),
        render () , load () , update () , event ( SDL_Event ) , read ();

    namespace editor
    {
        extern SDL_Window * window;
        extern SDL_Renderer * renderer;

        void init () , render ();
    }
};

#endif
