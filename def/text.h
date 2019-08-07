#ifndef TEXT
#define TEXT

#include <SDL2/SDL.h>

struct Text
{
    SDL_Rect position;
    SDL_Texture * texture;

    Text ( SDL_Texture * );
    ~Text ();

    void render ( SDL_Renderer * renderer ) , adjust ();
};

#endif
