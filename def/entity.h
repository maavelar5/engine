#ifndef ENTITY
#define ENTITY

#include "camera.h"
#include "game.h"
#include "texture.h"
#include "vector.h"

#if __ANDROID__
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include <vector>

#include <Box2D/Box2D.h>

struct Entity
{
    SDL_Rect screen;

    b2Vec2 position;

    b2BodyDef bodyDefinition;
    b2Body *body;
    b2PolygonShape polygonShape;
    b2FixtureDef fixtureDefinition;


    Uint8 movement;


    Entity ( float x , float y , float w , float h ,
             b2BodyType type = b2_staticBody );
    ~Entity ();

    void adjust() , render ( SDL_Texture * );
};

struct Entities : public Texture
{
    std::vector < std::shared_ptr < Entity > > entities;

    Entities ( std::string filePath = GENERIC_PLATFORM_FILE_PATH );
    ~Entities ();

    virtual void render () , add ( float , float , float , float );
};

#endif
