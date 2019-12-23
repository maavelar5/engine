#include "vector.h"

Vector::Vector ( float x , float y )
{
    this->x = x;
    this->y = y;
    angle = 0;
}

Vector::Vector ()
{
    x = y = angle = 0;
}

Vector::~Vector () { }

void Vector::getAngle ( Vector a )
{
    angle = -90 + atan2 ( y - a.y , x - a.x ) * 180.0 / 3.141592;
    angle = ( angle >= 0 ) ? angle : 360 + angle;
}

float Vector::length ()
{
    return sqrt ( x * x + y * y );
}

void Vector::normalize ()
{
    (*this) = (*this)/length();
}

Vector Vector::operator+ ( Vector a )
{
    return Vector ( x + a.x , y + a.y );
}

Vector Vector::operator- ( Vector a )
{
    return Vector ( a.x - x , a.y - y );
}

Vector Vector::operator* ( float value )
{
    return Vector ( x * value , y * value );
}

Vector Vector::operator/ ( float value )
{
    return Vector ( x / value , y / value );
}

void Vector::operator+= ( Vector a )
{
    (*this) = (*this) + a;
}

void Vector::operator-= ( Vector a )
{
    (*this) = (*this) - a;
}

void Vector::operator*= ( float value )
{
    (*this) = (*this) * value;
}

void Vector::operator/= ( float value )
{
    (*this) = (*this) / value;
}

bool Vector::operator!= ( Vector a )
{
    return ( x != a.x || y != a.y ) ? true : false;
}

bool Vector::operator== ( Vector a )
{
    return ( x == a.x && y == a.y ) ? true : false;
}
