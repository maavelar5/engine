#ifndef VECTOR
#define VECTOR

#include <iostream>
#include <math.h>

#if __ANDROID__
#include <SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif


struct Vector
{
    float x , y , angle;

    Vector ( float , float );
    Vector ();
    ~Vector ();

    void getAngle ( Vector ) , normalize ();
    float length ();

    Vector operator- ( Vector ),
        operator+ ( Vector ),
        operator* ( float ),
        operator/ ( float );

    void operator-= ( Vector ),
        operator+= ( Vector ),
        operator*= ( float ),
        operator/= ( float );

    bool operator!= ( Vector ),
        operator== ( Vector );
};

#endif
