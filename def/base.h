#ifndef BASE
#define BASE

#include "aabb.h"
#include "constants.h"
#include "sdl_inclusion.h"

#include <memory>

struct Base
{
    SDL_Texture * texture;

    Base ();
    virtual ~Base ();

    virtual void render () = 0,
        move () = 0,
        update () = 0,
        set ( float , float , int , int ) = 0,
        event ( SDL_Event ) = 0,
        collide ( std::shared_ptr < Base > , AABB ) = 0,
        adjust () = 0;

    virtual bool clear () = 0;
    virtual std::string getPositionHash ( int x , int y ) = 0;
    virtual uint8 collisionType () = 0;
};

#endif
