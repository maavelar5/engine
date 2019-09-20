#include "manager.h"

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

int main ( int argc, char* argv[] )
{
    initCWD( std::string( argv[ 0 ] ) );

    manager::init();

    while ( !game::quit )
    {
        manager::clear();
        manager::event();
        manager::update();
        manager::render();
    }

    SDL_Quit();

    return 0;
}
