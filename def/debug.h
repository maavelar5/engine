#ifndef DEBUG
#define DEBUG

#include "config.h"
#include "constants.h"
#include "font.h"
#include "text.h"

#include <memory>
#if __ANDROID__
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif

namespace debug
{
    extern SDL_Window * window;
    extern SDL_Renderer * renderer;

    extern Vector position;
    extern std::vector < std::shared_ptr < Text > > content;
    extern bool show , loaded;

    void init () , draw ( std::string , SDL_Color color = white ),
        event ( SDL_Event ) , render ();
}

#endif
