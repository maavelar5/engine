#include "enemy.h"

Enemy::Enemy ( float x , float y , int w , int h ) :
    Entity ( x , y , w , h , ACTIVE | KINEMATIC )
{

    moves [ ENEMY_NONE ] = Timer ( 1000 );
    moves [ ENEMY_MOVE ] = Timer ( 3000 );

    current = ENEMY_NONE;

    moves[ current ].start();

    velocity.x = -100;
}

Enemy::~Enemy () { }

void Enemy::update ()
{
    if ( moves [ current ].check() == 2 )
    {
        current = ( current >= ENEMY_MOVE )
            ? ENEMY_NONE
            : current + 1;
        moves [ current ].start ();
    }

    switch ( current )
    {
        case ENEMY_MOVE:
            if ( sensor & BOT_SENSOR && !( sensor & TOP_SENSOR ) )
                velocity.y -= 400;
            if ( !velocity.x )
                velocity.x = 100;
            break;
        default:
            velocity.x = 0;
            break;
    }

    move ();
}

void Enemy::leftSensorCallback ( Entity & entity )
{
    Entity::leftSensorCallback ( entity );
    velocity.x = 100;
}

void Enemy::rightSensorCallback ( Entity & entity )
{
    Entity::rightSensorCallback ( entity );
    velocity.x = -100;
}

Enemies::Enemies () : Entities ( GENERIC_ENEMY_FILE_PATH )
{
    speed = 100;
}

Enemies::~Enemies () { }

void Enemies::render ()
{
    for ( auto entity = entities.begin(); entity != entities.end(); entity++ )
    {
        if ( (*entity)->config & ACTIVE )
        {
            (*entity)->render ( texture );     
        }
        else
        {
            (*entity)->deleteLocator ();
            entities.erase ( entity-- );                
        }
    }
}

void Enemies::move ()
{
    for ( auto &entity : entities )
    {
        entity->move ();
    }
}

void Enemies::update ()
{
    for ( auto &entity : entities )
    {
        entity->update ();
    }
}

void Enemies::add ( float x , float y , int w , int h )
{
    entities.push_back ( std::shared_ptr < Enemy >
                         ( new Enemy ( x , y , w , h ) ) );
}
