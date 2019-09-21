#include "env_variables.h"

/* Window size */
int WINDOW_WIDTH;
int WINDOW_HEIGHT;

std::string WINDOW_TITLE;

/* Window logical size */
int GAME_LOGICAL_WIDTH;
int GAME_LOGICAL_HEIGHT;

/* Debug & Info window size */
int DI_WINDOW_WIDTH;
int DI_WINDOW_HEIGHT;
int DI_LOGICAL_WIDTH;
int DI_LOGICAL_HEIGHT;

/* Game camera rect */
SDL_Rect CAMERA_OFFSET;

/* Physics */
Vector GRAVITY;

/* MAX GRAVITY */
float MAX_GRAVITY;

/* Scenario size */
int SCENARIO_WIDTH;
int SCENARIO_HEIGHT;

bool DEBUG_WINDOW;
bool INFO_WINDOW;
bool EDITOR_WINDOW;
