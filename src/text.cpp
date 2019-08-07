#include "text.h"

Text::Text ( SDL_Texture * texture )
{
    this->texture = texture;
}

Text::~Text ()
{
    SDL_DestroyTexture( texture );
}

void Text::render ( SDL_Renderer * renderer )
{
    SDL_RenderCopy ( renderer , texture , NULL , &position );
}

void Text::adjust ()
{
    position.y -= 32;
}
