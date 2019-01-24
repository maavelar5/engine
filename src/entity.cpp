#include "entity.h"


Entity::Entity ()
{
    screen = { 0 , 0 , 0 , 0 };
    top = bot = left = right = SDL_FALSE;
}

Entity::~Entity () { }
