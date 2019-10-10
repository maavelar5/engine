#ifndef UTILS
#define UTILS

#include "base.h"
#include "constants.h"
#include "sdl_inclusion.h"

#include <map>
#include <memory>

std::string readFile ( std::string filePath );
SDL_Texture * createTexture ( std::string filePath , SDL_Renderer * renderer );

extern std::map < std::string , SDL_Texture * > textures;

extern std::map < std::string , std::vector
                  < std::shared_ptr < Base > > > gridKinematics;
extern std::map < std::string , std::vector
                  < std::shared_ptr < Base > > > gridPlatforms;

#endif
