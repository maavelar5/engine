#ifndef ENV_VARIABLES
#define ENV_VARIABLES

#include "sdl_inclusion.h"
#include "vector.h"

#include <iostream>

/* Window size */
extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

extern std::string WINDOW_TITLE;

/* Window logical size */
extern int GAME_LOGICAL_WIDTH;
extern int GAME_LOGICAL_HEIGHT;

/* Debug & Info window size */
extern int DI_WINDOW_WIDTH;
extern int DI_WINDOW_HEIGHT;
extern int DI_LOGICAL_WIDTH;
extern int DI_LOGICAL_HEIGHT;

/* Game camera rect */
extern SDL_Rect CAMERA_OFFSET;

/* Physics */
extern Vector GRAVITY;

/* MAX GRAVITY */
extern float MAX_GRAVITY;

/* Scenario size */
extern int SCENARIO_WIDTH;
extern int SCENARIO_HEIGHT;

extern bool DEBUG_WINDOW;
extern bool INFO_WINDOW;
extern bool EDITOR_WINDOW;

#endif
