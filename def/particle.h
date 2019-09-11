#ifndef _PARTICLE
#define _PARTICLE

#include "constants.h"
#include "entity.h"
#include "entities.h"
#include "automated_movement.h"

#include <memory>
#include <vector>

struct Particle : public Entity
{
    uint8 shape , distance;

    Particle ( float , float , int , int );
    ~Particle ();

    void update ();
};

struct Particles : public Entities
{
    Entity * entity;

    std::vector < std::shared_ptr < Particle > > entities;

    Timer timer;

    Particles ();
    ~Particles ();

    void move () , update () , render () , clear (),
        add ( float , float , int , int );
};

#endif
