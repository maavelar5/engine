#include "constants.h"

/* Directory separator */
const std::string DS = 
#if _WIN32
    "\\";
#elif __unix__ || __APPLE__
    "/";
#endif

/* Entity configuration */
const uint8 ACTIVE = 1;
const uint8 STATIC = 2;
const uint8 KINEMATIC = 4;
const uint8 BULLET = 8;
const uint8 DIRECTIONAL = 16;
const uint8 CAMERA = 32;
const uint8 PARTICLE = 64;

/* Sensor values */
const uint8 TOP_SENSOR = 1, RIGHT_SENSOR = 2, BOT_SENSOR = 4, LEFT_SENSOR = 8,
    NONE_SENSOR = 0 , A_TOP_SENSOR = 16 , A_RIGHT_SENSOR = 32,
    A_BOT_SENSOR = 64 , A_LEFT_SENSOR = 128;

/* HUD colors and other shit */
const SDL_Color white = { 255 , 255 , 255 , 255 },
    black = { 0 , 0 , 0 , 0 };

const SDL_Rect LT = {  10 , 10 , 50 , 50 } , T = { 100 , 10 , 50 , 50 },
    RT = { 200 , 10 , 50 , 50 };

/* Player */
std::string MEGAMAN_SPRITE_SHEET;
/* Player */
std::string PLAYER_SPRITE_SHEET;
/* Generic platform */
std::string GENERIC_PLATFORM_FILE_PATH;
/* Generic enemy */
std::string GENERIC_ENEMY_FILE_PATH;
/* Arrow enemy */
std::string ARROW_FILE_PATH;
/* Generic projectile */
std::string GENERIC_PROJECTILE_FILE_PATH;
/* Mapper file */
std::string MAPPER_FILE_PATH;
/* Sans font file */
std::string SANS_FONT_FILE_PATH;

/* Relative to BIN instead of CWD */
std::string BIN_PATH;
std::string BIN_SPRITES_PATH;
/* Config filepath */
std::string CONFIG_PATH;

void initCWD ( std::string argv )
{
    BIN_PATH = argv.substr(0, argv.size() - 8 );
    BIN_SPRITES_PATH = BIN_PATH + "sprites" + DS;

#if __ANDROID__
    BIN_PATH = "";
    BIN_SPRITES_PATH = "";
#endif

    PLAYER_SPRITE_SHEET = BIN_SPRITES_PATH + "player.png";
    GENERIC_ENEMY_FILE_PATH = BIN_SPRITES_PATH + "enemy.png";
    GENERIC_PLATFORM_FILE_PATH = BIN_SPRITES_PATH + "platform.png";
    GENERIC_PROJECTILE_FILE_PATH = BIN_SPRITES_PATH + "projectile.png";
    MAPPER_FILE_PATH = BIN_SPRITES_PATH + "platforms.org";
    ARROW_FILE_PATH = BIN_SPRITES_PATH + "arrow.png";
    MEGAMAN_SPRITE_SHEET = BIN_SPRITES_PATH + "megamanSpriteSheet.png";
    SANS_FONT_FILE_PATH = BIN_SPRITES_PATH + "OpenSans-Regular.ttf";
    CONFIG_PATH = BIN_SPRITES_PATH + "config";
}
