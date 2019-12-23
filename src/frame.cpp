#include "frame.h"

Frame::Frame () {}
Frame::~Frame () {}

void Frame::createWindowAndRenderer ()
{
    window = SDL_CreateWindow( "Debug",
                               size.x,
                               size.y,
                               size.w,
                               size.h,
                               windowFlags );

    if ( window )
    {
        renderer = SDL_CreateRenderer ( window , -1 , rendererFlags );

        if ( renderer )
        {
            SDL_SetHint ( SDL_HINT_RENDER_SCALE_QUALITY , "linear" );

            SDL_SetRenderDrawColor ( renderer,
                                     color.r,
                                     color.g,
                                     color.b,
                                     color.a );

            status = true;
        }
    }
}
