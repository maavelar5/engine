#include "hud.h"

namespace hud
{
    void draw ( std::string message , SDL_Rect position , SDL_Color color )
    {
        SDL_Texture *texture = font::createTexture ( message );

        SDL_RenderCopy ( game::renderer , texture , nullptr , &position );

        SDL_DestroyTexture ( texture );
    }
}
