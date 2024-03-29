#ifndef MAPPER
#define MAPPER

#include "player.h"
#include "enemy.h"
#include "platform.h"
#include "floating_enemy.h"
#include "utils.h"

#include <any>
#include <fstream>
#include <map>
#include <regex>

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <string>
#include <sstream>

namespace mapper
{
    extern std::map < std::string , std::shared_ptr < Base > > entities;
    extern std::map < uint8 , std::vector < std::string > > scenes;
    extern uint8 scene;

    void init () , add ( float , float , int , int , std::string ), change (),
        render () , load () , update () , event ( SDL_Event ) , read (),
        clear () , collide ();

    namespace editor
    {
        extern SDL_Window * window;
        extern SDL_Renderer * renderer;
        extern bool show , loaded;

        void init () , render ();
    }
};

#endif
