#include "enemy.h"


Enemy::Enemy ( float x , float y , float w , float h ) :
    Entity ( x , y , w , h , ACTIVE | KINEMATIC )
{
    current = 0;
    moves[ current ] = Timer( 1000 );
}

void Enemy::search ( Vector a )
{
    position.getAngle ( a );
}

Enemies::Enemies () : Entities ( ACTIVE | KINEMATIC , ARROW_FILE_PATH )
{
    
}

Enemies::~Enemies () { }
