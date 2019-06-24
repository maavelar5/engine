#ifndef VECTOR
#define VECTOR

#include <math.h>

struct Vector
{
    float x , y;

    float angle;

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
