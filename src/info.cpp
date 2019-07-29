#include "info.h"

namespace info
{
    Uint8 x = 1 , y = 1;

    void draw ( std::string type , std::string message , SDL_Color color )
    {
        SDL_Texture *typeTexture = font::createTexture ( type , white , game::debugRenderer ),
            *messageTexture = font::createTexture ( message , white , game::debugRenderer );

        SDL_Rect typePosition = { 100 * x++, 100  * y , 100 , 100 },
            messagePosition = { 100 * x++, 100  * y++ , 100 , 100 };

        x = 1;

        SDL_RenderCopy ( game::debugRenderer , typeTexture , NULL , &typePosition );
        SDL_RenderCopy ( game::debugRenderer , messageTexture , NULL , &messagePosition );
            
        SDL_DestroyTexture ( typeTexture );
        SDL_DestroyTexture ( messageTexture );
    }
}
