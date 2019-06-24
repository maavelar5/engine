#include "enemy.h"

Enemy::Enemy ( float x , float y , float w , float h ) :
    Entity ( x , y , w , h , ACTIVE | KINEMATIC ),
    projectiles ( 1000 , this )
{

    moves [ ENEMY_NONE ] = Timer ( 3000 );
    moves [ ENEMY_MOVE ] = Timer ( 3000 );
    moves [ ENEMY_SEARCH ] = Timer ( 3000 );
    moves [ ENEMY_ATTACK ] = Timer ( 3000 );

    current = ENEMY_NONE;

    moves[ current ].start();
}

Enemy::~Enemy () { }

void Enemy::search ( Vector a )
{
    position.getAngle ( a );
}

void Enemy::update ( Vector a , Uint8 speed )
{
    if ( moves [ current ].check() == 2 )
    {
        current = ( current >= ENEMY_ATTACK )
            ? ENEMY_NONE
            : current + 1;
        moves [ current ].start ();
    }

    switch ( current )
    {
        case ENEMY_MOVE:
            projectiles.isActive = false;
            move ( a , speed , 50 );
            break;
        case ENEMY_SEARCH:
            projectiles.isActive = false;
            search ( a );
            break;
        case ENEMY_ATTACK:
            projectiles.isActive = true;
            break;
        default:
            break;
    }

}

Enemies::Enemies () : Entities ( ACTIVE | KINEMATIC , ARROW_FILE_PATH )
{
    speed = 200;
}

Enemies::~Enemies () { }

void Enemies::update ( Vector a )
{
    for ( auto &entity : entities )
    {
        entity->update ( a , speed );
        entity->projectiles.update ();
        entity->projectiles.move ( a );
    }
}

void Enemies::add ( float x , float y , int w , int h )
{
    entities.push_back ( std::shared_ptr < Enemy > (
                             new Enemy ( x , y , w , h  ) ) );
}

void Enemies::render ()
{
    for ( auto &entity : entities )
    {
        entity->render ( texture );
        entity->projectiles.render ();
    }
}
