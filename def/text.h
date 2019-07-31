#ifndef TEXT
#define TEXT

#include "texture.h"

#include <SDL2/SDL.h>

struct Text : public Texture
{
    SDL_Rect position;

    Text ( SDL_Texture * );
    ~Text ();

    void render ( SDL_Renderer * renderer = game::renderer,
                  bool adjust = false );
};

#endif
