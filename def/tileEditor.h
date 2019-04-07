#ifndef TILE_EDITOR_INCLUDED
#define TILE_EDITOR_INCLUDED

#include "entity.h"

#include <SDL2/SDL.h>
#include <vector>

struct TileEditor 
{
    Uint32 selected;
    std::vector < std::shared_ptr < Entities > > entities;

    TileEditor ();
    ~TileEditor ();

    void add ( float , float ) , event ( SDL_Event ) , render ();
};

#endif
