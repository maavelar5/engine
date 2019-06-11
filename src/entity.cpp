#include "entity.h"

namespace entities
{
    std::map < std::string , std::vector < Entity * > > kinematics , statics;
    std::vector < Entity * > queue;

    void addHashIfNotExists ( std::string positionHash,
                              std::map < std::string , std::vector < Entity * > > * collection )
    {
        if ( collection->find ( positionHash ) == collection->end () ) 
        {
            ( *collection )[ positionHash ] = std::vector < Entity * > ();
        }
    }
}
Entity::Entity ( float x , float y , int w , int h , Uint8 config )
{
    locator = { 0 , 0 , 0 , 0 };

    screen.x = floor ( x - camera::position.x );
    screen.y = floor ( y - camera::position.y );
    screen.w = w;
    screen.h = h;

    position = { x , y };
    this->config = ACTIVE | config;

    collection = ( config & STATIC )
        ? &entities::statics
        : &entities::kinematics;

    setLocator ();
}

Entity::~Entity () { }

void Entity::move ()
{
    position.x += velocity.x * timer::acumulator;

    if ( config & CAMERA )
        camera::move ( velocity , screen );

    if ( position.x <= 0 )
        position.x = 0;
    else if ( position.x >= SCENARIO_WIDTH )
        position.x = SCENARIO_WIDTH;

    position.y += velocity.y * timer::acumulator;

    if ( position.y <= 0 )
        position.y = 0;
    else if ( position.y >= SCENARIO_HEIGHT )
        position.y = 220;

    sensor &= ~BOT_SENSOR;

    adjust();

    if ( !( sensor & BOT_SENSOR ) )
        velocity.y += GRAVITY.y;

    if ( std::find ( entities::queue.begin(),
                     entities::queue.end(),
                     this ) == entities::queue.end() )
                     entities::queue.push_back ( this );

    updateLocator ();
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
    screen.x = floor( position.x - camera::position.x );
    screen.y = floor( position.y - camera::position.y );
}

void Entity::setLocator ()
{
    SDL_Rect locator = { floor ( position.x / 100 ),
                         floor ( position.y / 100 ),
                         floor ( ( position.x + screen.w ) / 100 ),
                         floor ( ( position.y + screen.h ) / 100 ) };

    std::string positionHash = "";
 

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
            positionHash = getPositionHash ( x , y );

            entities::addHashIfNotExists ( positionHash , collection );
            (*collection) [ positionHash ].push_back ( this );
        }
    }

    this->locator = locator;
}

void Entity::deleteLocator ()
{
    std::string positionHash = "";

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
            positionHash = getPositionHash ( x , y );
            
            ( *collection )[ positionHash ].erase (
                std::remove (
                    ( *collection )[ positionHash ].begin(),
                    ( *collection )[ positionHash ].end(),
                    this
                    ),
                ( *collection )[ positionHash ].end());
        }
    }
}

void Entity::updateLocator ()
{
    deleteLocator ();
    setLocator ();
}

std::string Entity::getPositionHash ( int x , int y )
{
    return "(" + std::to_string ( y ) + ")" + "(" + std::to_string ( x ) + ")";
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

void Entities::move ()
{
    for ( auto entity : entities )
    {
        entity->move();
    }
}

void Entities::add ( float x , float y , int w , int h )
{
    entities.push_back ( std::shared_ptr < Entity > (new Entity ( x , y , w , h ) ));
}
