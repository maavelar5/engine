#ifndef ENTITIES
#define ENTITIES

#include "constants.h"
#include "entity.h"
#include "texture.h"

struct Entities : public Texture
{
    Entities ( std::string filePath );
    ~Entities ();

    virtual void render () = 0,
        move () = 0,
        update () = 0,
        add ( float , float , int , int ) = 0,
        event ( SDL_Event );

    virtual Entity * single ();
};

#endif
