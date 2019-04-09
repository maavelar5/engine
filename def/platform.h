#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

#include "entity.h"

#include <vector>

struct Platform : public Entities
{
    Platform ( std::string filePath = GENERIC_PLATFORM_FILE_PATH );
    ~Platform ();

    void add ( float , float );
};

#endif
