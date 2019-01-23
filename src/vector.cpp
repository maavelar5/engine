#include "vector.h"

Vector::Vector ( float x , float y )
{
    this->x = x;
    this->y = y;
}

Vector::Vector ()
{
    x = y = 0;
}

Vector::~Vector () { }
