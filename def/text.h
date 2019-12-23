#ifndef TEXT
#define TEXT

#include "sdl_inclusion.h"

struct Text
{
    SDL_Rect position;
    SDL_Texture * texture;

    Text ( SDL_Texture * texture );
    ~Text ();

    void render ( SDL_Renderer * renderer ) , adjust ();
};

#endif
