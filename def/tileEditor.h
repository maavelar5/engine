#ifndef TILE_EDITOR_INCLUDED
#define TILE_EDITOR_INCLUDED

#include "entity.h"

#include <fstream>
#include <map>
#include <regex>
#include <SDL2/SDL.h>
#include <string>

#include "platform.h"

struct TileEditor 
{
    std::map < std::string , std::shared_ptr < Entities > > entities;

    TileEditor ();
    ~TileEditor ();

    void add ( float , float , std::string ) , render () , load ();
};

#endif
