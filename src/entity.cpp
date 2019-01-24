#include "entity.h"

namespace entities
{
    std::vector < std::vector < std::vector < Entity * > > > entities;

    void init ()
    {
        int width = SCENARIO_WIDTH / 1000 + 1,   //GAME_LOGICAL_WIDTH + 1,
            height = SCENARIO_HEIGHT / 1000 + 1; //GAME_LOGICAL_HEIGHT + 1;
        
        for ( int x = 0;
              x < width;
              x++
            )
        {
            entities.push_back(std::vector< std::vector < Entity * > >());
            for ( int y = 0;
                  y < height;
                  y++
                )
            {
                entities[ x ].push_back(std::vector <  Entity * > ());
            }   
        }
    }
}



Entity::Entity ()
{
    screen = { 0 , 0 , 0 , 0 };
    isActive = top = bot = left = right = SDL_FALSE;

    xId = yId = 0;

    entities::entities[ 0 ][ 0 ].push_back ( this );
}

Entity::~Entity () { }
