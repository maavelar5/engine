#include "directed_bullet.h"

DirectedBullet::DirectedBullet () { }
DirectedBullet::~DirectedBullet () { }

void DirectedBullet::move ()
{
    previousPosition = position;

    direction.normalize ();
    position += direction * ( speed * timer::timeStep );

    sensor = NONE_SENSOR;

    positionLimits ();
    setCollisionBox ();
    setLocator ();
    pushToGrid ();
}
