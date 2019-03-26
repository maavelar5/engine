#include "entity.h"

namespace entities
{
    std::vector < std::vector < std::vector <  Entity * > > > entities;
    std::vector < Entity > linear;

    void init ()
    {
        int width = SCENARIO_WIDTH / 100 + 1,   //GAME_LOGICAL_WIDTH + 1,
            height = SCENARIO_HEIGHT / 100 + 1; //GAME_LOGICAL_HEIGHT + 1;
        
        for ( int y = 0;
              y < height;
              y++
            )
        {
            entities.push_back(std::vector< std::vector < Entity * > >());

            for ( int x = 0;
                  x < width;
                  x++
                )
            {
                entities[ y ].push_back(std::vector < Entity * > ());
            }   
        }
    }

    void move ()
    {
        for ( auto &entity : linear )
        {
            entity.move();
        }
    }

    void render ()
    {
        for ( auto &entity : linear )
        {
            entity.render();
        }
    }

    void remove () { }

    Entity * add ( std::string filePath , SDL_Texture *texture )
    {
        linear.push_back( Entity ( filePath , texture ) );
        Entity * entity = &linear[ linear.size() - 1 ];

        entities::entities[ 0 ][ 0 ].push_back ( entity );

        return entity;
    }
}

Entity::Entity ( std::string filePath , SDL_Texture *texture )
{
    screen = locator = { 0 , 0 , 0 , 0 };
    sensor = 0;
    config = ACTIVE | STATIC;

    if ( texture ) this->texture = texture;
    else this->texture = loadTexture ( filePath );
}

Entity::~Entity () { }

void Entity::adjust ()
{
    deleteLocator ();

    screen.x = floor( position.x - camera::position.x );
    screen.y = floor( position.y - camera::position.y );

    setLocator ();
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
void Entity::move ()
{
    if ( config & STATIC ) return;

    position.x += velocity.x * timer::acumulator;

    if ( config & BULLET ) return;

    if ( config & CAMERA ) camera::move ( velocity , screen );

    if ( position.x <= 0 ) position.x = 0;
    else if ( position.x >= SCENARIO_WIDTH ) position.x = SCENARIO_WIDTH;

    if ( !( sensor & BOT_SENSOR ) ) velocity.y += GRAVITY.y;

    position.y += velocity.y * timer::acumulator;
    sensor &= ~BOT_SENSOR;

    adjust ();
}

void Entity::render ()
{
    adjust ();

    SDL_RenderCopy( game::renderer,
                    texture,
                    NULL,
                    &screen );    
}

SDL_Texture * Entity::loadTexture ( std::string filePath )
{
    SDL_Surface *surface = IMG_Load( filePath.c_str() );
    SDL_Texture *texture = nullptr;

    if ( surface )
    {
        texture = SDL_CreateTextureFromSurface( game::renderer , surface );
        SDL_FreeSurface( surface );
    }
    else { printf("%s",SDL_GetError()); }

    return texture;
}

Entities::Entities ( std::string filePath )
{
    texture = Entity::loadTexture ( filePath );
    screen = { 0 , 0 , 0 , 0 };
    config = ACTIVE | STATIC;
}

Entities::~Entities () { }

Entity * Entities::add ( float x , float y )
{
    entities::linear.push_back( Entity ( "" , texture ) );

    Entity * entity = &entities::linear[ entities::linear.size() - 1 ];

    entities::entities[ 0 ][ 0 ].push_back ( entity );

    entity->config = config;
    entity->position = { x , y };
    entity->screen.w = screen.w;
    entity->screen.h = screen.h;

    entity->adjust();

    return entity;
}
