#OBJ directory
DIRS=debug release obj

$(shell mkdir -p $(DIRS))

#BIN speficies the bin file
DEBUG_BIN = debug/marcoman
RELEASE_BIN = release/marcoman

#DEBUG commands
DEBUG_CP = $(shell cp -r sprites debug/)
DEBUG = $(DEBUG_BIN) $(DEBUG_CP)

#RELEASE commands
RELEASE_CP = $(shell cp dll/* release/) $(shell cp -r sprites release/)
RELEASE = $(RELEASE_BIN) $(RELEASE_CP)

#VPATH specifies the directories used
VPATH = ./src:./def:./obj

#OBJS specifies which files to compile as part of the project
OBJS = $(notdir $(patsubst %.cpp,%.o,$(wildcard src/*.cpp)))

#OBJS_DIR specifies the objects directory
OBJS_DIR = $(addprefix obj/,$(OBJS))

#CC specifies which compiler we're using
CC = g++ -std=c++17

#CFLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
CFLAGS = -g -w

#CPPFLAGS specifies the preprocesor flags
CPPFLAGS = -I def

#SDL2 linker flags
SDL2_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

#Static linker flags
STATIC_LINKER_FLAGS = -static-libgcc -static-libstdc++ -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive

#Windows specific flags
WINDOWS_FLAGS = -w -Wl,-subsystem,windows -lmingw32 -lSDL2main

#LINKER_FLAGS, condition to determine if windows or not
ifeq ($(OS),Windows_NT)
	LINKER_FLAGS = $(WINDOWS_FLAGS) $(SDL2_FLAGS) $(STATIC_LINKER_FLAGS)
else
	LINKER_FLAGS = $(SDL2_FLAGS)
endif


all : $(OBJS)
	$(CC) $(OBJS_DIR) $(CFLAGS) $(CPPFLAGS) $(LINKER_FLAGS) -o $(DEBUG)

release : $(OBJS)
	$(CC) $(OBJS_DIR) $(CFLAGS) $(CPPFLAGS) $(LINKER_FLAGS) -o $(RELEASE)

aabb.o : aabb.cpp
	$(CC) -c -w $(CPPFLAGS) src/aabb.cpp -o obj/aabb.o

automated_movement.o : automated_movement.cpp
	$(CC) -c -w $(CPPFLAGS) src/automated_movement.cpp -o obj/automated_movement.o

base.o : base.cpp
	$(CC) -c -w $(CPPFLAGS) src/base.cpp -o obj/base.o

bullet.o : bullet.cpp
	$(CC) -c -w $(CPPFLAGS) src/bullet.cpp -o obj/bullet.o

camera.o : camera.cpp
	$(CC) -c -w $(CPPFLAGS) src/camera.cpp -o obj/camera.o

config.o : config.cpp
	$(CC) -c -w $(CPPFLAGS) src/config.cpp -o obj/config.o

constants.o : constants.cpp
	$(CC) -c -w $(CPPFLAGS) src/constants.cpp -o obj/constants.o

controller.o : controller.cpp
	$(CC) -c -w $(CPPFLAGS) src/controller.cpp -o obj/controller.o

debug.o : debug.cpp
	$(CC) -c -w $(CPPFLAGS) src/debug.cpp -o obj/debug.o

directed_bullet.o : directed_bullet.cpp
	$(CC) -c -w $(CPPFLAGS) src/directed_bullet.cpp -o obj/directed_bullet.o

directed_projectile.o : directed_projectile.cpp
	$(CC) -c -w $(CPPFLAGS) src/directed_projectile.cpp -o obj/directed_projectile.o

enemy.o : enemy.cpp
	$(CC) -c -w $(CPPFLAGS) src/enemy.cpp -o obj/enemy.o

env_variables.o : env_variables.cpp
	$(CC) -c -w $(CPPFLAGS) src/env_variables.cpp -o obj/env_variables.o

floating_enemy.o : floating_enemy.cpp
	$(CC) -c -w $(CPPFLAGS) src/floating_enemy.cpp -o obj/floating_enemy.o

font.o : font.cpp
	$(CC) -c -w $(CPPFLAGS) src/font.cpp -o obj/font.o

game.o : game.cpp
	$(CC) -c -w $(CPPFLAGS) src/game.cpp -o obj/game.o

hud.o : hud.cpp
	$(CC) -c -w $(CPPFLAGS) src/hud.cpp -o obj/hud.o

info.o : info.cpp
	$(CC) -c -w $(CPPFLAGS) src/info.cpp -o obj/info.o

kinematic.o : kinematic.cpp
	$(CC) -c -w $(CPPFLAGS) src/kinematic.cpp -o obj/kinematic.o

main.o : main.cpp
	$(CC) -c -w $(CPPFLAGS) src/main.cpp -o obj/main.o

manager.o : manager.cpp
	$(CC) -c -w $(CPPFLAGS) src/manager.cpp -o obj/manager.o

mapper.o : mapper.cpp
	$(CC) -c -w $(CPPFLAGS) src/mapper.cpp -o obj/mapper.o

list.o : list.cpp
	$(CC) -c -w $(CPPFLAGS) src/list.cpp -o obj/list.o

particle.o : particle.cpp
	$(CC) -c -w $(CPPFLAGS) src/particle.cpp -o obj/particle.o

platform.o : platform.cpp
	$(CC) -c -w $(CPPFLAGS) src/platform.cpp -o obj/platform.o

player.o : player.cpp
	$(CC) -c -w $(CPPFLAGS) src/player.cpp -o obj/player.o

projectile.o : projectile.cpp
	$(CC) -c -w $(CPPFLAGS) src/projectile.cpp -o obj/projectile.o

sdl_inclusion.o : sdl_inclusion.cpp
	$(CC) -c -w $(CPPFLAGS) src/sdl_inclusion.cpp -o obj/sdl_inclusion.o

text.o : text.cpp
	$(CC) -c -w $(CPPFLAGS) src/text.cpp -o obj/text.o

texture.o : texture.cpp
	$(CC) -c -w $(CPPFLAGS) src/texture.cpp -o obj/texture.o

timer.o : timer.cpp
	$(CC) -c -w $(CPPFLAGS) src/timer.cpp -o obj/timer.o

utils.o : utils.cpp
	$(CC) -c -w $(CPPFLAGS) src/utils.cpp -o obj/utils.o

vector.o : vector.cpp
	$(CC) -c -w $(CPPFLAGS) src/vector.cpp -o obj/vector.o

clean_debug :
	rm -rf debug/*

clean_release :
	rm -rf release/*

clean_objs :
	rm -rf obj/*

clean : clean_debug clean_release clean_objs
