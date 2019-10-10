#include "floating_enemy.h"

FloatingEnemy::FloatingEnemy () : projectiles ( this )
{
    moves [ ENEMY_MOVE ] = Timer ( 3000 );
    moves [ ENEMY_SEARCH ] = Timer ( 1000 );
    moves [ ENEMY_ATTACK ] = Timer ( 2000 );

    current = ENEMY_MOVE;

    projectiles.delay = 200;

    texture = createTexture ( ARROW_FILE_PATH , game::renderer );

    moves[ current ].start();
    speed = 0;
}

FloatingEnemy::~FloatingEnemy () { }

void FloatingEnemy::search ()
{
    position.getAngle ( destination->position );
}

void FloatingEnemy::move ()
{
    previousPosition = position;
    direction = position - destination->position;

    if ( direction.length() > distance )
    {
        direction.normalize();
        position += direction * ( speed * timer::timeStep );
        positionLimits ();
    }

    position.getAngle ( destination->position );

    sensor = NONE_SENSOR;

    positionLimits ();
    setCollisionBox ();
    setLocator ();
    pushToGrid ();
}

void FloatingEnemy::update ()
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
            //projectiles.active = true;
            move ();
            search ();
            break;
        case ENEMY_SEARCH:
            //projectiles.active = true;
            search ();
            break;
        case ENEMY_ATTACK:
            //projectiles.active = true;
            search ();
            break;
        default:
            break;
    }

    projectiles.update ();
}

FloatingEnemies::FloatingEnemies ( Platform * destination )
{
    this->destination = destination;
}

FloatingEnemies::~FloatingEnemies () { }

void FloatingEnemies::set ( float x , float y , int w , int h )
{
    std::shared_ptr < FloatingEnemy > object =
        std::make_shared < FloatingEnemy > ();

    object->set ( x , y , w , h );
    object->destination = destination;
    object->distance = 50;
    objects.push_back ( std::move ( object ) );
}
