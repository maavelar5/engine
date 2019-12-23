#ifndef FRAME
#define FRAME

#include "constants.h"
#include "game.h"

#include <map>

struct Frame
{
    bool status;

    SDL_Rect size;
    SDL_Color color;

    Uint32 windowFlags , rendererFlags;

    SDL_Window * window;
    SDL_Renderer * renderer;

    Frame ();
    ~Frame ();

    void createWindowAndRenderer ();
};

#endif
