#ifndef CONSTANTS
#define CONSTANTS

#include "vector.h"

#include <iostream>
#include <map>

#if __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <vector>

#if _WIN32
    #include <direct.h>
#elif __unix__ || __APPLE__
    #include <unistd.h>
#endif

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned int uint32;

/* Window size */
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

/* Window logical size */
extern const int GAME_LOGICAL_WIDTH;
extern const int GAME_LOGICAL_HEIGHT;

/* Debug & Info window size */
extern const int DI_WINDOW_WIDTH;
extern const int DI_WINDOW_HEIGHT;
extern const int DI_LOGICAL_WIDTH;
extern const int DI_LOGICAL_HEIGHT;

/* Game camera rect */
extern const SDL_Rect CAMERA_OFFSET;

/* Window title */
extern const std::string WINDOW_TITLE;

/* Directory separator */
extern const std::string DS;

/* Current working directory */
extern const std::string CWD;
extern const std::string SPRITES_PATH;

/* Physics */
extern const Vector GRAVITY;

/* Scenario size */
extern const int SCENARIO_WIDTH;
extern const int SCENARIO_HEIGHT;

/* Entity configuration */
extern const uint8 ACTIVE;
extern const uint8 STATIC;
extern const uint8 KINEMATIC;
extern const uint8 BULLET;
extern const uint8 DIRECTIONAL;
extern const uint8 CAMERA;
extern const uint8 PARTICLE;

/* Sensor valuess */
extern const uint8 TOP_SENSOR , RIGHT_SENSOR , BOT_SENSOR , LEFT_SENSOR,
    NONE_SENSOR , A_TOP_SENSOR , A_RIGHT_SENSOR, A_BOT_SENSOR , A_LEFT_SENSOR;

/* HUD colors and other shit */
extern const SDL_Color white , black;
extern const SDL_Rect LT , T , RT;

/* MAX GRAVITY */
extern const float MAX_GRAVITY;

/* ENEMY MOVES */
const uint8 ENEMY_NONE = 0;
const uint8 ENEMY_MOVE = 1;
const uint8 ENEMY_SEARCH = 2;
const uint8 ENEMY_ATTACK = 3;


/* Player */
extern std::string PLAYER_SPRITE_SHEET;
/* Generic platform */
extern std::string GENERIC_PLATFORM_FILE_PATH;
/* Generic enemy */
extern std::string GENERIC_ENEMY_FILE_PATH;
/* Arrow enemy */
extern std::string ARROW_FILE_PATH;
/* Generic projectile */
extern std::string GENERIC_PROJECTILE_FILE_PATH;
/* Mapper file */
extern std::string MAPPER_FILE_PATH;
/* Sans Font */
extern std::string SANS_FONT_FILE_PATH;
/* Path relative to binary */
extern std::string BIN_PATH, BIN_SPRITES_PATH;

extern std::string CONFIG_PATH;

void initCWD (std::string);

#endif
