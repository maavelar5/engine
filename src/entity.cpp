#include "entity.h"

const float M2P = 5.0;
const float P2M = 1/M2P;

Entity::Entity ( float x , float y , float w , float h,
                 b2BodyType type )
{
    screen.w = w;
    screen.h = h;

    bodyDefinition.type = type;
    bodyDefinition.position.Set ( x * P2M , y * P2M );

    body = physics::world.CreateBody ( &bodyDefinition );

    polygonShape.SetAsBox ( P2M * w / 2 , P2M * h / 2);
    
    fixtureDefinition.shape = &polygonShape;
    fixtureDefinition.density = 1;

    body->CreateFixture (&fixtureDefinition);
}

Entity::~Entity () { }

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
    //screen.x = floor( position.x - camera::position.x );
    //screen.y = floor( position.y - camera::position.y );

    screen.x = floor ( ( body->GetPosition().x * M2P ) - screen.w / 2 );
    screen.y = floor ( ( body->GetPosition().y * M2P ) - screen.h / 2 );

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

void Entities::add ( float x , float y , float w , float h )
{
    entities.push_back ( std::shared_ptr < Entity > (new Entity ( x , y , w , h ) ));
}
