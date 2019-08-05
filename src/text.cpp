#include "text.h"

Text::Text ( SDL_Texture * texture ) : Texture ( texture )
{

}

Text::~Text () { }

void Text::render ( SDL_Renderer * renderer )
{
    SDL_RenderCopy ( renderer , texture , NULL , &position );
}

void Text::adjust ()
{
    position.y -= 32;
}
