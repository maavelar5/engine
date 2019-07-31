#include "text.h"

Text::Text ( SDL_Texture * texture ) : Texture ( texture )
{

}

Text::~Text () { }

void Text::render ( SDL_Renderer * renderer , bool adjust )
{
    if ( adjust )
    {
        position.y -= 32;
    }

    SDL_RenderCopy ( renderer , texture , NULL , &position );
}

