
#include "aabb.h"

AABB::AABB ( float x , float y , float w , float h )
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

AABB::~AABB () { }

bool AABB::left ( AABB a )
{
    return ( a.x == x )
        ? true
        : false;
}

bool AABB::right ( AABB a )
{
    return ( a.w == w )
        ? true
        : false;
}

bool AABB::top ( AABB a )
{
    return ( a.y == y && a.h < h )
        ? true
        : false;
}

bool AABB::bot ( AABB a )
{
    return ( a.h == h && a.y > y )
        ? true
        : false;
}

AABB AABB::getIntersection ( AABB a , AABB b )
{
    return AABB ( ( a.x >= b.x ) ? a.x : b.x,
                  ( a.y >= b.y ) ? a.y : b.y,
                  ( a.w <= b.w ) ? a.w : b.w,
                  ( a.h <= b.h ) ? a.h : b.h );
}

bool AABB::checkIntersection ( AABB a , AABB b )
{
    return ( a.x < b.w && a.w > b.x && a.y < b.h && a.h > b.y )
        ? true
        : false;
}
