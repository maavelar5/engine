#ifndef MAPPER
#define MAPPER

#include "enemy.h"
#include "platform.h"
#include "floating_enemy.h"

#include <any>
#include <fstream>
#include <map>
#include <regex>
#include <SDL2/SDL.h>
#include <string>

struct Mapper
{
    std::map < std::string , std::shared_ptr < Entities > > entities;

    Mapper ( Entity * entity = nullptr );
    ~Mapper ();

    void add ( float , float , int , int , std::string ),
        render () , load () , update ();
};

#endif
