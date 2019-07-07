#include "enemy.h"

Enemy::Enemy ( float x , float y , float w , float h ) :
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
            move ();
            break;
        default:
            break;
    }
}

void Enemy::leftSensorCallback ( Entity & entity )
{
    velocity.x = 100;
}

void Enemy::rightSensorCallback ( Entity & entity )
{
    velocity.x = -100;
}

Enemies::Enemies () :
    Entities ( ACTIVE | KINEMATIC , GENERIC_ENEMY_FILE_PATH )
{
    speed = 100;
}

Enemies::~Enemies () { }

void Enemies::update ()
{
    for ( auto &entity : entities )
    {
        entity->update ();
    }
}
