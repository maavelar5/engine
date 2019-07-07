#include "floating_enemy.h"

FloatingEnemy::FloatingEnemy ( float x , float y , float w , float h ) :
    Entity ( x , y , w , h , ACTIVE | KINEMATIC | DIRECTIONAL ),
    projectiles ( 200 , this )
{

    moves [ ENEMY_MOVE ] = Timer ( 3000 );
    moves [ ENEMY_SEARCH ] = Timer ( 1000 );
    moves [ ENEMY_ATTACK ] = Timer ( 2000 );

    current = ENEMY_MOVE;

    moves[ current ].start();

    projectiles.delay = 200;
    
}

FloatingEnemy::~FloatingEnemy () { }

void FloatingEnemy::search ( Vector a )
{
    position.getAngle ( a );
}

void FloatingEnemy::update ( Vector a , uint16 speed )
{
    if ( moves [ current ].check() == 2 )
    {
        current = ( current >= ENEMY_ATTACK )
            ? ENEMY_MOVE
            : current + 1;
        moves [ current ].start ();
    }

    switch ( current )
    {
        case ENEMY_MOVE:
            projectiles.isActive = true;
            move ( a , 0 , 50 );
            search ( a );
            break;
        case ENEMY_SEARCH:
            projectiles.isActive = true;
            search ( a );
            break;
        case ENEMY_ATTACK:
            projectiles.isActive = true;
            search ( a );
            break;
        default:
            break;
    }
}

FloatingEnemies::FloatingEnemies ( Entity * entity ) :
    Entities ( ACTIVE | KINEMATIC , ARROW_FILE_PATH )
{
    speed = 100;
    this->entity = entity;
    minDistance = 50;
}

FloatingEnemies::~FloatingEnemies () { }

void FloatingEnemies::update ()
{
    for ( auto &entity : entities )
    {
        entity->update ( this->entity->position , speed );
        entity->projectiles.update ();
        entity->projectiles.move ( this->entity->position );
    }
}

void FloatingEnemies::render ()
{
    for ( auto &entity : entities )
    {
        entity->render ( texture );
        entity->projectiles.render ();
    }
}
