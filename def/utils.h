#ifndef UTILS
#define UTILS

#include <iostream>

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

namespace utils
{
    std::string readFile ( std::string filePath );
}

#endif
