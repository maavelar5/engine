#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include "vector.h"

#include <iostream>
#include <map>
#include <SDL2/SDL.h>
#include <vector>

#if _WIN32
    #include <direct.h>
#elif __unix__ || __APPLE__
    #if 1
        #include <unistd.h>
    #elif 0
        #include <experimental/filesystem>
    #endif
#endif

/* Window size */
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

/* Window logical size */
extern const int GAME_LOGICAL_WIDTH;
extern const int GAME_LOGICAL_HEIGHT;

/* Game camera rect */
extern const SDL_Rect CAMERA_OFFSET;


extern const std::string WINDOW_TITLE;
extern const std::string SPRITES;

/* Directory separator */
extern const std::string DS;

/* Current working directory */
extern const std::string CWD;

/* Physics */
extern const Vector GRAVITY;

/* Scenario size */
extern const int SCENARIO_WIDTH;
extern const int SCENARIO_HEIGHT;
extern const SDL_Color BLUE_SKY;

/* Brown block filepath */
extern const std::string BROWN_BLOCK_FILE_PATH;

/* States */
extern const Uint16 NONE;

extern const Uint16 WALKING;

extern const Uint16 CROUCHING;

extern const Uint16 SHOOTING;

extern const Uint16 MID_AIR_ASCENDING;
extern const Uint16 MID_AIR_DESCENDING;
extern const Uint16 MID_AIR;

extern const Uint16 RUNNING;

extern const Uint16 RIGHT;
extern const Uint16 LEFT;

extern const Uint16 ON_GROUND;

/* Entity configuration */

extern const Uint16 ACTIVE;
extern const Uint16 STATIC;
extern const Uint16 RIGID;
extern const Uint16 KINEMATIC;
extern const Uint16 MOVES_CAMERA;

/* Megaman */
extern const std::string MEGAMAN_SPRITE_SHEET;

/* Megaman spritesheet frames */
extern std::map<Uint16 , std::vector<SDL_Rect> > MEGAMAN_SPRITES;

/* Player */
extern const std::string PLAYER_SPRITE_SHEET;

/* Player spritesheet frames */
extern std::map < Uint16 , std::vector<SDL_Rect> > PLAYER_SPRITES;

/* Generic platform */
extern const std::string GENERIC_PLATFORM_FILE_PATH;

/* Generic enemy */
extern const std::string GENERIC_ENEMY_FILE_PATH;

/* Generic enemy sprites */
extern std::map <Uint16 , std::vector < SDL_Rect > > GENERIC_ENEMY_SPRITES;

#endif
