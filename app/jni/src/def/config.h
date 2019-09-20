#ifndef CONFIG
#define CONFIG

#include "constants.h"
#include "utils.h"

#include <fstream>
#include <regex>

#if __ANDROID__
#include <SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

#include <string>
#include <map>

namespace config
{
    extern std::map < std::string , bool > values;

    void init ();
}

#endif
