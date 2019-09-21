#ifndef DEBUG
#define DEBUG

#include "config.h"
#include "constants.h"
#include "font.h"
#include "text.h"

#include <memory>

namespace debug
{
    extern SDL_Window * window;
    extern SDL_Renderer * renderer;

    extern Vector position;
    extern std::vector < std::shared_ptr < Text > > content;
    extern bool show;

    void init () , draw ( std::string , SDL_Color color = white ),
        event ( SDL_Event ) , render ();
}

#endif
