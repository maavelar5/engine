#ifndef TILE_EDITOR_INCLUDED
#define TILE_EDITOR_INCLUDED

struct TileEditor 
{
    Uint32 selected;

    TileEditor ();
    ~TileEditor ();

    std::vector < Entities > entities;

    void add ( float , float );
}

#endif
