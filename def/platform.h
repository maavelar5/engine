#ifndef PLATFORMS
#define PLATFORMS

#include "entity.h"
#include "entities.h"
#include "constants.h"

#include <vector>

struct Platforms : public Entities
{
    std::vector < std::shared_ptr < Entity > > entities;

    Platforms ( std::string filePath = GENERIC_PLATFORM_FILE_PATH );
    ~Platforms ();

    void render () , move () , update () , clear (),
        add ( float , float , int , int );
};

#endif
