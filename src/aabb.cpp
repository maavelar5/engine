#include "aabb.h"

AABB::AABB ( float x , float y , float w , float h )
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

AABB::AABB ()
{
    x = y = w = h = 0;
}

AABB::~AABB () { }

bool AABB::left ( AABB a )
{
    float dw = x + ( ( ( w - x  ) / 10 ) * 4 );

    return ( a.x >= x && a.w <= dw && a.y >= y && a.h <= h )
        ? true
        : false;
}

bool AABB::right ( AABB a )
{
    float dx = x + ( ( ( w - x  ) / 10 ) * 6 );

    return ( a.x >= dx && a.w <= w && a.y >= y && a.h <= h )
        ? true
        : false;
}

bool AABB::top ( AABB a )
{
    float dh = y + ( ( ( h - y  ) / 10 ) * 1 );

    return ( a.x >= x && a.w <= w && a.y >= y && a.h <= dh )
        ? true
        : false;
}

bool AABB::bot ( AABB a )
{
    float dy = y + ( ( ( h - y ) / 10 ) * 9 );

    return ( a.x >= x && a.w <= w && a.y >= dy && a.h <= h )
        ? true
        : false;
}

bool AABB::fLeft ( AABB a )
{
    return ( x == a.x )
        ? true
        : false;
}

bool AABB::fRight ( AABB a )
{
    return ( w == a.w )
        ? true
        : false;
}

bool AABB::fTop ( AABB a )
{
    return ( y == a.y )
        ? true
        : false;
}

bool AABB::fBot ( AABB a )
{
    return ( h == a.h )
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
