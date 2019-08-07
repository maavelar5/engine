#ifndef CONFIG
#define CONFIG

#include "constants.h"
#include "debug.h"

#include <fstream>
#include <regex>
#include <SDL2/SDL.h>
#include <string>
#include <map>

namespace config
{
    extern std::map < std::string , bool > values;

    void init ();
}

#endif
