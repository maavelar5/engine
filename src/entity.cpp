#include "entity.h"

namespace entities
{
    std::vector < std::vector < std::vector < Entity * > > > entities;

    void init ()
    {
        int width = SCENARIO_WIDTH / 100 + 1,   //GAME_LOGICAL_WIDTH + 1,
            height = SCENARIO_HEIGHT / 100 + 1; //GAME_LOGICAL_HEIGHT + 1;
        
        for ( int y = 0;
              y < height;
              y++
            )
        {
            entities.push_back(std::vector< std::vector < Entity * > >());

            for ( int x = 0;
                  x < width;
                  x++
                )
            {
                entities[ y ].push_back(std::vector <  Entity * > ());
            }   
        }
    }
}

Entity::Entity ()
{
    screen = locator = { 0 , 0 , 0 , 0 };
    type = top = bot = left = right = SDL_FALSE;
    isActive = SDL_TRUE;

    entities::entities[ 0 ][ 0 ].push_back ( this );
}

Entity::~Entity () { }
