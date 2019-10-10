#ifndef PLATFORMS
#define PLATFORMS

#include "aabb.h"
#include "game.h"
#include "list.h"
#include "camera.h"

struct Platform : public Base , std::enable_shared_from_this < Base >
{
    SDL_Rect screen , locator;
    Vector position , renderPosition , direction;

    AABB collisionBox;

    Platform ();
    ~Platform ();

    void render () , move () , update () , adjust () , setLocator (),
        event ( SDL_Event ), setCollisionBox () ,
        collide ( std::shared_ptr < Base > , AABB a_box ),
        set ( float x , float y , int w , int h );

    virtual void pushToGrid ();
    virtual std::string getPositionHash ( int x , int y );

    bool clear ();
    uint8 collisionType ();
};

#endif
