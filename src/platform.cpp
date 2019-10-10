#include "platform.h"

Platform::Platform ()
{
    texture = createTexture ( GENERIC_PLATFORM_FILE_PATH , game::renderer );
}

Platform::~Platform () { }

void Platform::adjust ()
{
    screen.x = floor( position.x - camera::position.x );
    screen.y = floor( position.y - camera::position.y );
}

void Platform::render ()
{
    adjust ();

    SDL_RenderCopyEx( game::renderer,
                      texture,
                      nullptr,
                      &screen,
                      position.angle,
                      nullptr,
                      SDL_FLIP_NONE );
}

void Platform::move ()
{

}

void Platform::update ()
{

}

void Platform::set ( float x , float y , int w , int h )
{
    renderPosition = position = { x , y };

    screen.x = static_cast < int > ( x );
    screen.y = static_cast < int > ( y );
    screen.w = w;
    screen.h = h;

    setCollisionBox ();
    setLocator ();
    pushToGrid ();
}

void Platform::event ( SDL_Event event )
{

}

bool Platform::clear ()
{
    return false;
}

void Platform::setLocator ()
{
    locator.x = static_cast < int > ( floor ( position.x / 100 ) );
    locator.y = static_cast < int > ( floor ( position.y / 100 ) );
    locator.w = static_cast < int > ( floor( position.x + screen.w ) / 100 );
    locator.h = static_cast < int > ( floor( position.y + screen.h ) / 100 );
}

void Platform::pushToGrid ()
{
    for ( int y = locator.y;
          y <= locator.h;
          y++
        )
    {
        for ( int x = locator.x;
              x <= locator.w;
              x++
            )
        {
            gridPlatforms [ getPositionHash ( x , y ) ]
                .push_back ( shared_from_this () );
        }
    }
}

std::string Platform::getPositionHash ( int x , int y )
{
    std::string hash = std::to_string ( y ) + "," + std::to_string ( x );

    if ( gridPlatforms.find ( hash ) == gridPlatforms.end () )
    {
        gridPlatforms [ hash ] = std::vector < std::shared_ptr < Base > > ();
    }

    return hash;
}

uint8 Platform::collisionType ()
{
    return 240;
}

void Platform::collide ( std::shared_ptr < Base > a , AABB aBox )
{
    return;
}

void Platform::setCollisionBox ()
{
    collisionBox.x = floor ( position.x );
    collisionBox.y = floor ( position.y );
    collisionBox.w = ceil ( position.x + screen.w );
    collisionBox.h = ceil ( position.y + screen.h );
}
