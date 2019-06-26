#ifndef MAPPER
#define MAPPER

#include "entity.h"

#include <fstream>
#include <map>
#include <regex>
#include <SDL2/SDL.h>
#include <string>

struct Mapper
{
    std::map < std::string , std::shared_ptr < Entities < Entity > > > entities;

    Mapper ();
    ~Mapper ();

    void add ( float , float , int , int , std::string ),
        render () , load ();
};

#endif
