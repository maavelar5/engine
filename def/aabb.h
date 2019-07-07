#ifndef _AABB
#define _AABB

struct AABB
{
    float x , y , w , h;

    AABB ( float , float , float , float );
    ~AABB ();

    bool top ( AABB ) , right ( AABB ) , bot ( AABB ) , left ( AABB );

    static AABB getIntersection  ( AABB , AABB );
    static bool checkIntersection ( AABB , AABB );
};

#endif
