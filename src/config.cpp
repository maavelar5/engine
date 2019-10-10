#include "config.h"

std::map < std::string , std::string > config;

void initConfig ()
{
    std::string s = readFile ( CONFIG_PATH );
    const std::regex e ( "(\\S+)=(\\S*)" );
    std::smatch m;

    while ( std::regex_search ( s , m , e ) )
    {
        config [ m [ 1 ] ] = std::string ( m [ 2 ] );
        s = m.suffix().str ();
    }

    WINDOW_WIDTH = std::stoi( config["WINDOW_WIDTH"]);
    WINDOW_HEIGHT = std::stoi( config["WINDOW_HEIGHT"]);

    GAME_LOGICAL_WIDTH = std::stoi( config["GAME_LOGICAL_WIDTH"]);
    GAME_LOGICAL_HEIGHT = std::stoi( config["GAME_LOGICAL_HEIGHT"]);

    CAMERA_OFFSET = {
        ( GAME_LOGICAL_WIDTH / 2 ) - 25,
        ( GAME_LOGICAL_HEIGHT / 2 ) - 25,
        ( GAME_LOGICAL_WIDTH / 2 ) + 25,
        ( GAME_LOGICAL_HEIGHT / 2 ) + 25
    };

    MAX_GRAVITY = std::stoi ( config["MAX_GRAVITY"]);
    GRAVITY.y = std::stoi ( config["GRAVITY"]);

    SCENARIO_WIDTH = std::stoi ( config [ "SCENARIO_WIDTH"]);
    SCENARIO_HEIGHT = std::stoi ( config [ "SCENARIO_HEIGHT"]);

    DI_WINDOW_WIDTH = std::stoi ( config [ "DI_WINDOW_WIDTH"]);
    DI_WINDOW_HEIGHT = std::stoi ( config [ "DI_WINDOW_HEIGHT"]);
    DI_LOGICAL_WIDTH = std::stoi ( config [ "DI_LOGICAL_WIDTH"]);
    DI_LOGICAL_HEIGHT = std::stoi ( config [ "DI_LOGICAL_HEIGHT"]);

    DEBUG_WINDOW = std::stoi ( config [ "DEBUG_WINDOW"]);
    INFO_WINDOW = std::stoi ( config [ "INFO_WINDOW"]);
    EDITOR_WINDOW = std::stoi ( config [ "EDITOR_WINDOW"]);

    WINDOW_TITLE = config [ "WINDOW_TITLE" ];
}
