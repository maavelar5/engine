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

    std::string getPositionHash ( int x , int y )
    {
        return std::to_string ( y ) + "," + std::to_string ( x );
    }
}
Entity::Entity ( float x , float y , int w , int h , uint8 config )
{
    locator = { 0 , 0 , 0 , 0 };

    screen = { floor ( x - camera::position.x ),
               floor ( y - camera::position.y ),
               w , h };

    renderPosition = previousPosition = position = { x , y };

    this->config = config;

    collection = ( config & STATIC )
        ? &entities::statics
        : &entities::kinematics;

    sensor = 1;
    flip = SDL_FLIP_NONE;

    setLocator ();
}

Entity::~Entity () { }

void Entity::move ()
{
    previousPosition = position;

    if ( !( sensor & BOT_SENSOR ) && !( config & BULLET ) )
    {
        velocity.y += GRAVITY.y * timer::timeStep;
        velocity.y = ( velocity.y > MAX_GRAVITY )
            ? MAX_GRAVITY
            : velocity.y;
    }
    
    position += velocity * timer::timeStep;

    positionLimits ();

    if ( previousPosition != position )
        updateLocator ();

    entities::queue.push_back ( this );
}

void Entity::move ( Vector a , uint16 speed , uint8 minDistance )
{
    previousPosition = position;
    direction = position - a;

    if ( direction.length() > minDistance )
    {
        direction.normalize();
        position += direction * ( speed * timer::timeStep );
        positionLimits ();
    }

    if ( previousPosition != position )
        updateLocator ();

    entities::queue.push_back ( this );
    position.getAngle ( a );
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
                      flip );
}

void Entity::adjust ()
{
    Vector position = this->position;

    if ( config & KINEMATIC )
    {
        Vector renderPosition = ( position * timer::interpolation ) +
            ( previousPosition * ( 1.0 - timer::interpolation ) );

        if ( abs( renderPosition.x - this->renderPosition.x ) >= 1 ||
             abs( renderPosition.y - this->renderPosition.y ) >= 1 )
        {
            if ( config & CAMERA )
                camera::move ( renderPosition.x - this->renderPosition.x,
                               screen );

            position = this->renderPosition = renderPosition;
        }

        if ( velocity.x < 0 )
        {
            flip = SDL_FLIP_HORIZONTAL;
        }
        else if ( velocity.x > 0 )
        {
            flip = SDL_FLIP_NONE;
        }
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
            positionHash = entities::getPositionHash ( x , y );

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
            positionHash = entities::getPositionHash ( x , y );
            
            ( *collection )[ positionHash ].erase (
                std::remove ( ( *collection )[ positionHash ].begin(),
                              ( *collection )[ positionHash ].end(),
                              this ),
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


void Entity::topSensorCallback ( Entity & entity )
{
    //TODO: Base case scenarion
    sensor |= TOP_SENSOR;
}

void Entity::botSensorCallback ( Entity & entity )
{
    //TODO: Base case scenarion
    sensor |= BOT_SENSOR;
}

void Entity::leftSensorCallback ( Entity & entity )
{
    //TODO: Base case scenarion
    sensor |= LEFT_SENSOR;
}

void Entity::rightSensorCallback ( Entity & entity )
{
    //TODO: Base case scenarion
    sensor |= RIGHT_SENSOR;
}

void Entity::update ()
{
    
}
