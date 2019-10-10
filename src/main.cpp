#include "manager.h"

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

        gridKinematics.clear ();
    }

    SDL_Quit ();

    return 0;
}
