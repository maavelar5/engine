#ifndef TEXT
#define TEXT

#if __ANDROID__
#include <SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif


struct Text
{
    SDL_Rect position;
    SDL_Texture * texture;

    Text ( SDL_Texture * );
    ~Text ();

    void render ( SDL_Renderer * renderer ) , adjust ();
};

#endif
