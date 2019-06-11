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

const std::string SPRITES_PATH = 
#if _WIN32 || __unix__ || __APPLE__
    CWD + "sprites" + DS;
#elif __ANDROID__
    "";
#endif

/* Physics */
const Vector GRAVITY( 0 , 400 );

/* Scenario size */
const int SCENARIO_WIDTH = 7168;
const int SCENARIO_HEIGHT = 240;

/* Entity configuration */
const Uint8 ACTIVE = 1;
const Uint8 STATIC = 2;
const Uint8 KINEMATIC = 4;
const Uint8 BULLET = 8;
const Uint8 CAMERA = 16;
const Uint8 TEMPLATE = 32;

/* Player */
const std::string MEGAMAN_SPRITE_SHEET = SPRITES_PATH + 
    "megamanSpriteSheet.png";

/* Player */
const std::string PLAYER_SPRITE_SHEET = SPRITES_PATH + 
    "player.png";

/* Generic platform */
const std::string GENERIC_PLATFORM_FILE_PATH = SPRITES_PATH + 
    "platform.png";

/* Generic enemy */
const std::string GENERIC_ENEMY_FILE_PATH = SPRITES_PATH + 
    "enemy.png";

/* Generic projectile */
const std::string GENERIC_PROJECTILE_FILE_PATH = SPRITES_PATH + 
    "projectile.png";

/* Mapper file */
const std::string MAPPER_FILE_PATH = SPRITES_PATH +
    "platforms.org";

/* Sensor values */
const Uint8 TOP_SENSOR = 1, RIGHT_SENSOR = 2, BOT_SENSOR = 4, LEFT_SENSOR = 8;

/* HUD colors and other shit */
const SDL_Color white = { 255 , 255 , 255 },
    black = { 0 , 0 , 0 };

const SDL_Rect LT = {  10 , 10 , 50 , 50 } , T = { 100 , 10 , 50 , 50 } , RT = { 200 , 10 , 50 , 50 };

