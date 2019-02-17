#include "constants.h"

/* Window size */
const int WINDOW_WIDTH = 512;
const int WINDOW_HEIGHT = 480;

/* Window logical size */
const int GAME_LOGICAL_WIDTH = 256;
const int GAME_LOGICAL_HEIGHT = 240;

/* Game camera rect */
const SDL_Rect CAMERA_OFFSET =
{
    ( GAME_LOGICAL_WIDTH / 2 ) - 25,
    ( GAME_LOGICAL_HEIGHT / 2 ) - 25,
    ( GAME_LOGICAL_WIDTH / 2 ) + 25,
    ( GAME_LOGICAL_HEIGHT / 2 ) + 25
};

const std::string WINDOW_TITLE = "Qntra!";
const std::string SPRITES = "/home/marco/gamedev/MarcoMan/sprites/";


/* Directory separator */
const std::string DS = 
#if _WIN32
    "\\";
#elif __unix__ || __APPLE__
    "/";
#endif

/* Current working directory */
const std::string CWD = 
#if _WIN32
    _getcwd( NULL, 0 ) + DS;
#elif __unix__ || __APPLE__
    #if 1
        getcwd( NULL, 0 ) + DS;
    #elif 0
        std::experimental::filesystem::current_path().string() + DS;
    #endif
#endif

/* Physics */
const Vector GRAVITY( 0 , 6 );

/* Scenario size */
const int SCENARIO_WIDTH = 7168;
const int SCENARIO_HEIGHT = 240;
const SDL_Color BLUE_SKY = { 92 , 148 , 252 , 0 };

/* Brown block filepath */
const std::string BROWN_BLOCK_FILE_PATH = CWD+"sprites"+DS+"brownBlock.bmp";

/* States */
const Uint16 NONE = 0;

const Uint16 ON_GROUND = 2;

const Uint16 WALKING = 4;

const Uint16 CROUCHING = 8;

const Uint16 SHOOTING = 16;

const Uint16 MID_AIR_ASCENDING = 32;
const Uint16 MID_AIR_DESCENDING = 64;
const Uint16 MID_AIR = 96;

const Uint16 RUNNING = 128;

const Uint16 RIGHT = 256;
const Uint16 LEFT = 512;

/* Entity configuration */
const Uint8 ACTIVE = 1;
const Uint8 STATIC = 2;
const Uint8 KINEMATIC = 4;
const Uint8 BULLET = 8;

/* Player */
const std::string MEGAMAN_SPRITE_SHEET = CWD+"sprites"+DS+
    "megamanSpriteSheet.png";

/* Player spritesheet frames */
std::map<Uint16 , std::vector < SDL_Rect > > MEGAMAN_SPRITES =
{

    {
        ON_GROUND,
        {
            { 8 , 13 , 21 , 24  } ,
            { 58 , 13 , 21 , 24 }
        }
    },
    {
        WALKING,
        {
            {
                108 , 13 , 24 , 24
            }
        }
    },
    {
        RUNNING,
        {
            {
                156 , 15 , 24 , 22
            },
            {
                209 , 13 , 16 , 24
            },
            {
                255 , 15 , 21 , 22
            }
        }
    },
    {
        MID_AIR,
        {
            {
                306 , 13 , 26 , 30
            }
        }
    },
    {
        MID_AIR | SHOOTING,
        {
            {
                306 , 63 , 29 , 30
            }
        }
    },
    {
        SHOOTING,
        {
            {
                108 , 63 , 32 , 24
            }
        }
    },
    {
        RUNNING | SHOOTING,
        {
            {
                156 , 65 , 29 , 22
            },
            {
                209 , 63 , 26 , 24
            },
            {
                255 , 65 , 30 , 22
            }
        }
    },
};


/* Player */
const std::string PLAYER_SPRITE_SHEET = CWD+"sprites"+DS+
    "player.png";

/* Player spritesheet frames */
std::map<Uint16 , std::vector < SDL_Rect > > PLAYER_SPRITES =
{
    {
        ON_GROUND,
        {
            { 0 , 0 , 32 , 32  } ,
        }
    }
};

/* Generic platform */
const std::string GENERIC_PLATFORM_FILE_PATH = CWD+"sprites"+DS+
    "platform.png";

/* Generic enemy */
const std::string GENERIC_ENEMY_FILE_PATH = CWD+"sprites"+DS+
    "enemy.png";

/* Generic projectile */
const std::string GENERIC_PROJECTILE_FILE_PATH = CWD+"sprites"+DS+
    "projectile.png";

/* Generic enemy spritesheet frames */
std::map<Uint16 , std::vector < SDL_Rect > > GENERIC_ENEMY_SPRITES =
{
    {
        ON_GROUND,
        {
            { 0 , 0 , 32 , 32  } ,
        }
    }
};

/* Sensor values */
const Uint8 TOP_SENSOR = 1, RIGHT_SENSOR = 2, BOT_SENSOR = 4, LEFT_SENSOR = 8;
