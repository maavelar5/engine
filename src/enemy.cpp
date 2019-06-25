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

Enemies::Enemies ( Entity * entity ) : Entities ( ACTIVE | KINEMATIC , ARROW_FILE_PATH )
{
    speed = 200;
    this->entity = entity;
}

Enemies::~Enemies () { }

void Enemies::update ()
{
    for ( auto &entity : entities )
    {
        entity->update ( entity->position , speed );
        entity->projectiles.update ();
        entity->projectiles.move ( entity->position );
    }
}

void Enemies::add ( float x , float y )
{
    entities.push_back ( std::shared_ptr < Enemy > (
                             new Enemy ( x , y , 32 , 32  ) ) );
}

void Enemies::render ()
{
    for ( auto &entity : entities )
    {
        entity->render ( texture );
        entity->projectiles.render ();
    }
}
