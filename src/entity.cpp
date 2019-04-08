#include "entity.h"

namespace entities
{
    std::vector
    < std::vector < std::vector
                    < Entity * > > > entities;

    std::vector < Entity * > toCollide;

    void init ()
    {
        int width = SCENARIO_WIDTH / 100 + 1,   //GAME_LOGICAL_WIDTH + 1,
            height = SCENARIO_HEIGHT / 100 + 1; //GAME_LOGICAL_HEIGHT + 1;
        
        for ( int y = 0;
              y < height;
              y++
            )
        {
            entities.push_back(std::vector < std::vector < Entity * > > ());

            for ( int x = 0;
                  x < width;
                  x++
                )
            {
                entities[ y ].push_back(std::vector <  Entity * > ());
            }
        }
    }

}

Entity::Entity ()
{
    screen = locator = { 0 , 0 , 0 , 0 };
    config = ACTIVE | STATIC;

    entities::entities[ 0 ][ 0 ].push_back( this );
}

Entity::~Entity () { }

void Entity::move ()
{
    position.x += velocity.x * timer::acumulator;

    if ( config & BULLET )
        return;

    if ( config & CAMERA )
        camera::move ( velocity , screen );

    if ( position.x <= 0 )
        position.x = 0;
    else if ( position.x >= SCENARIO_WIDTH )
        position.x = SCENARIO_WIDTH;

    if ( !( sensor & BOT_SENSOR ) )
        velocity.y += GRAVITY.y;

    position.y += velocity.y * timer::acumulator;
    sensor &= ~BOT_SENSOR;

    adjust();

    if ( std::find ( entities::toCollide.begin() , entities::toCollide.end(), this ) == entities::toCollide.end() )
        entities::toCollide.push_back ( this );
}

void Entity::render ( SDL_Texture *texture )
{
    adjust ();

    SDL_RenderCopy( game::renderer,
                    texture,
                    nullptr,
                    &screen );
}

void Entity::adjust ()
{
    deleteLocator();

    screen.x = floor( position.x - camera::position.x );
    screen.y = floor( position.y - camera::position.y );

    setLocator();
}

void Entity::setLocator ()
{
    int xId = position.x / 100,
        yId = position.y / 100,
        wId = ( position.x + screen.w ) / 100,
        hId = ( position.y + screen.h ) / 100;

    for ( int y = yId;
          y <= hId;
          y++
        )
    {
        for ( int x = xId;
              x <= wId;
              x++
            )
        {
            entities::entities[ y ][ x ].push_back( this );
        }
    }

    locator = { xId , yId , wId , hId };
}

void Entity::deleteLocator ()
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

            entities::entities[ y ][ x ]
                .erase(std::remove(
                           entities::entities[ y ][ x ].begin(),
                           entities::entities[ y ][ x ].end(),
                           this),
                       entities::entities[ y ][ x ].end());
        }
    }
}

Entities::Entities ( std::string filePath ) : Texture ( filePath )
{
    
}

Entities::~Entities () { }

void Entities::render ()
{
    for ( auto entity : entities )
    {
        entity->render ( texture );
    }
}


void Entities::add ( float x , float y )
{
    
}
