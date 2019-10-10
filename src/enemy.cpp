#include "enemy.h"

Enemy::Enemy ()
{
    texture = createTexture ( GENERIC_ENEMY_FILE_PATH , game::renderer );

    moves [ ENEMY_NONE ] = Timer ( 1000 );
    moves [ ENEMY_MOVE ] = Timer ( 3000 );

    current = ENEMY_NONE;

    moves[ current ].start();

    velocity.x = -100;
}

Enemy::~Enemy ()
{

}

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
            {
                velocity.y = -400;
            }

            break;
        default:
            break;
    }

    move ();
}

void Enemy::left ()
{
    velocity.x = 100;
}

void Enemy::right ()
{
    velocity.x = -100;
}
