#ifndef DEBUG
#define DEBUG

#include "config.h"
#include "constants.h"
#include "font.h"
#include "text.h"

#include "frame.h"

#include <memory>

struct Debug
{
    Frame frame;

    std::vector < std::shared_ptr < Text > > content;

    Debug ();
    ~Debug ();

    void init () , event ( SDL_Event ) , render (),
        draw ( std::string , SDL_Color color = white );
};

namespace debug
{
    extern SDL_Window * window;
    extern SDL_Renderer * renderer;

    extern Vector position;
    extern std::vector < std::shared_ptr < Text > > content;
    extern bool show;

    void init () ,
        draw ( std::string , SDL_Color color = white ),
        event ( SDL_Event ) , render ();
}

#endif
