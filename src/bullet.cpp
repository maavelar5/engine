#include "bullet.h"

Bullet:: Bullet () { }
Bullet::~Bullet () { }

void Bullet::move ()
{
    previousPosition = position;
    position += velocity * timer::timeStep;
    sensor = NONE_SENSOR;

    positionLimits ();
    setCollisionBox ();
    setLocator ();
    pushToGrid ();
}

void Bullet::top ()
{
    status &= ~ACTIVE;
}

void Bullet::bot ()
{
    status &= ~ACTIVE;
}

void Bullet::left ()
{
    status &= ~ACTIVE;
}

void Bullet::right ()
{
    status &= ~ACTIVE;
}
