#include "projectile.h"

Projectile::Projectile ( float x , float y , int w , int h ) :
    Entity ( x , y , w , h , ACTIVE | KINEMATIC | BULLET )
{

}

Projectile::~Projectile () { }

void Projectile::positionLimits ()
{
    if ( position.y <= -100 )
        config &= ~ACTIVE;
    else if ( position.y >= SCENARIO_HEIGHT )
        config &= ~ACTIVE;

    if ( position.x <= -100 )
        config &= ~ACTIVE;
    else if ( position.x >= SCENARIO_WIDTH )
        config &= ~ACTIVE;
}


Projectiles::Projectiles ( int speed , Entity * entity ) :
    Entities ( GENERIC_PROJECTILE_FILE_PATH ),
    Timer ( 1000 )
{
    this->speed = speed;
    this->entity = entity;
    isActive = false;
}

Projectiles::~Projectiles () { }

void Projectiles::render ()
{
    for ( auto entity = entities.begin(); entity != entities.end(); entity++ )
    {
        if ( (*entity)->config & ACTIVE )
        {
            (*entity)->render( texture );
        }
        else
        {
            (*entity)->deleteLocator ();
            entities.erase( entity-- );
        }
    }
}

void Projectiles::move ()
{
    for ( auto &entity : entities )
    {
        entity->move ();
    }
}

void Projectiles::add ( float x , float y , int w , int h )
{
    std::shared_ptr < Projectile > entity ( new Projectile ( x , y , w , h ) );

    entity->velocity.x = ( this->entity->flip == SDL_FLIP_HORIZONTAL )
        ? -speed
        : speed;

    entities.push_back ( entity );
}

void Projectiles::update ()
{
    if ( isActive )
    {
        if ( check() == 2 )
        {
            float x = ( entity->flip == SDL_FLIP_NONE )
                ? entity->position.x + entity->screen.w + 4
                : entity->position.x - 4;

            float y = entity->position.y + entity->screen.h / 3;

            add ( x , y );
            start();
        }
    }
}
