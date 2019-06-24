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

    screen = { floor ( x - camera::position.x ),
               floor ( y - camera::position.y ),
               w , h };

    previousPosition = position = { x , y };

    this->config = config;

    collection = ( config & STATIC )
        ? &entities::statics
        : &entities::kinematics;

    sensor = 1;

    setLocator ();
}

Entity::~Entity () { }

void Entity::move ()
{
    previousPosition = position;

    if ( !( sensor & BOT_SENSOR ) && !( config & BULLET ) )
    {
        velocity.y += GRAVITY.y * timer::timeStep;
        velocity.y = ( velocity.y > MAX_GRAVITY ) ? MAX_GRAVITY : velocity.y;
    }
    
    position.x += velocity.x * timer::timeStep;
    position.y += velocity.y * timer::timeStep;

    positionLimits ();

    entities::queue.push_back ( this );
    updateLocator ();
}

void Entity::move ( Vector a )
{
    previousPosition = position;

    if ( !( sensor & BOT_SENSOR ) && !( config & BULLET ) )
    {
        velocity.y += GRAVITY.y * timer::timeStep;
        velocity.y = ( velocity.y > MAX_GRAVITY )
            ? MAX_GRAVITY
            : velocity.y;
    }

    Vector direction = position - a;

    if ( direction.length() > 50 )
    {
        direction.normalize();
        position += direction * 1;

        position.getAngle ( a );
        positionLimits ();

        entities::queue.push_back ( this );
        updateLocator ();        
    }
}

void Entity::render ( SDL_Texture *texture )
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

void Entity::adjust ()
{
    Vector position = this->position;

    if ( config & KINEMATIC )
    {
        float cameraDistance = renderPosition.x;

        renderPosition.x = position.x * timer::interpolation +
            previousPosition.x * ( 1.0 - timer::interpolation );

        renderPosition.y = position.y * timer::interpolation +
            previousPosition.y * ( 1.0 - timer::interpolation );

        if ( config & CAMERA )
            camera::move ( renderPosition.x - cameraDistance , screen );

        position = renderPosition;
    }

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
    SDL_Rect locator = { floor ( position.x / 100 ),
                         floor ( position.y / 100 ),
                         floor ( ( position.x + screen.w ) / 100 ),
                         floor ( ( position.y + screen.h ) / 100 ) };

    if ( this->locator.x != locator.x ||
         this->locator.y != locator.y ||
         this->locator.w != locator.w ||
         this->locator.h != locator.h )
    {
        deleteLocator ();
        setLocator ();
    }
}

void Entity::positionLimits ()
{
    if ( position.y <= 0 )
        position.y = 0;
    else if ( position.y >= SCENARIO_HEIGHT )
        position.y = SCENARIO_HEIGHT;

    if ( position.x <= 0 )
        position.x = 0;
    else if ( position.x >= SCENARIO_WIDTH )
        position.x = SCENARIO_WIDTH;
}

std::string Entity::getPositionHash ( int x , int y )
{
    return std::to_string ( y ) + "," + std::to_string ( x );
}

Entities::Entities ( Uint8 config , std::string filePath )
    : Texture ( filePath )
{
    this->config = config;
}

Entities::~Entities () { }

void Entities::render ()
{
    for ( auto entity = entities.begin(); entity != entities.end(); entity++ )
    {
        if ( (*entity)->config & ACTIVE )
            (*entity)->render ( texture );
        else
            entities.erase ( entity-- );
    }
}

void Entities::move ()
{
    for ( auto &entity : entities )
    {
        entity->move();
    }
}

void Entities::move ( Vector a )
{
    for ( auto &entity : entities )
    {
        entity->move( a );
    }
}

void Entities::add ( float x , float y , int w , int h )
{
    entities.push_back ( std::shared_ptr < Entity > (
                             new Entity ( x , y , w , h  , config ) ));
}
