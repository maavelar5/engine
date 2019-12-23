#include "debug.h"

Debug::Debug ()
{
    frame.windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_TOOLTIP;
    frame.rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    frame.size = { 512 , 0 , DI_WINDOW_WIDTH , DI_WINDOW_HEIGHT };
    frame.color = { 25 , 50, 100 , 0 };
}

Debug::~Debug () { }

void Debug::init ()
{
    //frame.init ();
}

void Debug::render ()
{
    if ( !DEBUG_WINDOW ) { return; }

    for ( auto & line : content )
    {

    }
}

void Debug::draw ( std::string text , SDL_Color color )
{
    if ( !DEBUG_WINDOW ) { return; }

    SDL_Surface * surface =
        TTF_RenderText_Solid ( font::fonts [ 18 ] , text.c_str () , white );

    SDL_Texture * texture =
        SDL_CreateTextureFromSurface ( frame.renderer, surface );

    SDL_FreeSurface ( surface );

    SDL_Rect position = { static_cast < int > ( debug::position.x ),
                          static_cast < int > ( debug::position.y ),
                          static_cast < int > ( text.size() * 18 ),
                          32 };

    debug::position.y += 32;
}

namespace debug
{
    Vector position ( 0 , 0 );
    std::vector < std::shared_ptr < Text > > text;
    SDL_Window * window = nullptr;
    SDL_Renderer * renderer = nullptr;
    bool show = false;

    void init ()
    {
        if ( !DEBUG_WINDOW ) { return; }

        window = SDL_CreateWindow( "Debug",
                                   512,
                                   0,
                                   DI_WINDOW_WIDTH,
                                   DI_WINDOW_HEIGHT,
                                   SDL_WINDOW_SHOWN | SDL_WINDOW_TOOLTIP );

        if ( !window ) return;

        SDL_SetWindowOpacity( window , 0.0f );

        renderer = SDL_CreateRenderer( window,
                                       -1,
                                       SDL_RENDERER_ACCELERATED |
                                       SDL_RENDERER_PRESENTVSYNC );

        if ( !renderer ) return;

        SDL_BlendMode blend = SDL_BLENDMODE_BLEND;

        SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY , "linear" );

        SDL_RenderSetLogicalSize( renderer,
                                  DI_LOGICAL_WIDTH,
                                  DI_LOGICAL_HEIGHT );

        SDL_SetWindowMinimumSize( window,
                                  DI_WINDOW_WIDTH,
                                  DI_WINDOW_HEIGHT );

        SDL_SetRenderDrawBlendMode ( renderer , blend );
        SDL_SetRenderDrawColor ( renderer , 25 , 50, 100 , 0 );
        SDL_RenderClear( renderer );
    }

    void draw ( std::string text , SDL_Color color )
    {
        if ( !DEBUG_WINDOW ) { return; }

        std::shared_ptr < Text > storage
            ( new Text ( font::createTexture ( text , renderer ) ) );

        storage->position = { static_cast<int>(debug::position.x),
                              static_cast<int>(debug::position.y),
                              static_cast<int>(text.size() * 18),
                              32 };

        debug::text.push_back( storage );

        debug::position.y += 32;

        if ( debug::position.y > DI_WINDOW_HEIGHT )
        {
            for ( auto & line : debug::text )
            {
                line->adjust();
            }

            debug::position.y -= 32;
        }
    }

    void render ()
    {
        if ( !DEBUG_WINDOW ) { return; }

        for ( auto & line : debug::text )
        {
            line->render( renderer );
        }

        SDL_RenderDrawLine(renderer, 0 , 0 , 20 , 20 );
    }

    void event ( SDL_Event event )
    {
        if ( !DEBUG_WINDOW ) { return; }

        int x , y;

        SDL_GetWindowPosition( window, &x, &y );

        if( event.type == SDL_KEYDOWN && event.key.repeat == 0 )
        {
            draw ( SDL_GetKeyName( event.key.keysym.sym ) );

            switch( event.key.keysym.sym )
            {
                case SDLK_o:
                    show = ( show ) ? false : true;

                    if ( show ) { SDL_ShowWindow ( window ); }
                    else { SDL_HideWindow( window ); }

                    break;
                case SDLK_h: SDL_HideWindow ( window ); break;
            }
        }
        if( event.type == SDL_KEYDOWN )
        {
            switch( event.key.keysym.sym )
            {
                case SDLK_LEFT: x -= 10; break;
                case SDLK_RIGHT: x += 10; break;
                case SDLK_UP: y -= 10; break;
                case SDLK_DOWN: y += 10; break;
                case SDLK_c:
                    text.clear();
                    position = { 0 , 0 };
                    break;
            }
        }

        SDL_SetWindowPosition( window , x , y );
    }
}
