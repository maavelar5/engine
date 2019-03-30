#include "entity.h"

Entities::Entities ( std::string filePath )
{
    SDL_Surface* surface = IMG_Load( filePath.c_str() );

    if ( surface )
    {
        texture = SDL_CreateTextureFromSurface( renderer , surface );
        SDL_FreeSurface( surface );
    }
    else { printf( "%s\n" , SDL_GetError() ); }
}

Entities::~Entities () { }


void Entities::move ()
{
    for ( int index = 0;
          index < position.size();
          index++ )
    {
        position[ index ].x += velocity[ index ].x * timer::acumulator;

        if ( config[ index ] & BULLET )
            return;

        if ( config[ index ] & CAMERA )
            cameraMove ( velocity[ index ] , screen[ index ]);

        if ( position[ index ].x <= 0 )
            position[ index ].x = 0;
        else if ( position[ index ].x >= SCENARIO_WIDTH )
            position[ index ].x = SCENARIO_WIDTH;

        //if ( !( sensor & BOT_SENSOR ) )
        //velocity.y += GRAVITY.y;

        position[ index ].y += velocity[ index ].y * timer::acumulator;
        sensor[ index ] &= ~BOT_SENSOR;
    }
}

void Entities::render ()
{
    for ( int index = 0;
          index < position.size();
          index++ )
    {
        adjust ( index );

        SDL_RenderCopy( renderer,
                        texture,
                        NULL,
                        &screen[ index ] );
    }
}

void Entities::adjust ( Uint32 index )
{
    screen[ index ].x = floor( position[ index ].x - cameraPosition.x );
    screen[ index ].y = floor( position[ index ].y - cameraPosition.y );
}

void Entities::add ()
{
    position.push_back ( { 0 , 0 } );
    velocity.push_back ( { 0 , 0 } );
    screen.push_back ( { 0 , 0 , 0 , 0 } );
    locator.push_back ( { 0 , 0 , 0 , 0 } );
    config.push_back ( STATIC );
    sensor.push_back ( 0 );
}
