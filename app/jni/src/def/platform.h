#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

#include "entity.h"

#include <vector>

struct Platform : public Entities
{
    Platform ();
    ~Platform ();

    void add ( float , float );
};

#endif
