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
	LINKER_FLAGS = $(SDL2_FLAGS) $(STATIC_LINKER_FLAGS)
endif


all : $(OBJS)
	$(CC) $(OBJS_DIR) $(CFLAGS) $(CPPFLAGS) $(LINKER_FLAGS) -o $(DEBUG)

release : $(OBJS)
	$(CC) $(OBJS_DIR) $(CFLAGS) $(CPPFLAGS) $(LINKER_FLAGS) -o $(RELEASE)

automated_movement.o : automated_movement.cpp
	$(CC) -c -w $(CPPFLAGS) src/automated_movement.cpp -o obj/automated_movement.o

camera.o : camera.cpp
	$(CC) -c -w $(CPPFLAGS) src/camera.cpp -o obj/camera.o

constants.o : constants.cpp
	$(CC) -c -w $(CPPFLAGS) src/constants.cpp -o obj/constants.o

collision.o : collision.cpp
	$(CC) -c -w $(CPPFLAGS) src/collision.cpp -o obj/collision.o

enemy.o : enemy.cpp
	$(CC) -c -w $(CPPFLAGS) src/enemy.cpp -o obj/enemy.o

entity.o : entity.cpp
	$(CC) -c -w $(CPPFLAGS) src/entity.cpp -o obj/entity.o

font.o : font.cpp
	$(CC) -c -w $(CPPFLAGS) src/font.cpp -o obj/font.o

game.o : game.cpp
	$(CC) -c -w $(CPPFLAGS) src/game.cpp -o obj/game.o

hud.o : hud.cpp
	$(CC) -c -w $(CPPFLAGS) src/hud.cpp -o obj/hud.o

info.o : info.cpp
	$(CC) -c -w $(CPPFLAGS) src/info.cpp -o obj/info.o

main.o : main.cpp
	$(CC) -c -w $(CPPFLAGS) src/main.cpp -o obj/main.o

mapper.o : mapper.cpp
	$(CC) -c -w $(CPPFLAGS) src/mapper.cpp -o obj/mapper.o

platform.o : platform.cpp
	$(CC) -c -w $(CPPFLAGS) src/platform.cpp -o obj/platform.o

player.o : player.cpp
	$(CC) -c -w $(CPPFLAGS) src/player.cpp -o obj/player.o

projectile.o : projectile.cpp
	$(CC) -c -w $(CPPFLAGS) src/projectile.cpp -o obj/projectile.o

texture.o : texture.cpp
	$(CC) -c -w $(CPPFLAGS) src/texture.cpp -o obj/texture.o

timer.o : timer.cpp
	$(CC) -c -w $(CPPFLAGS) src/timer.cpp -o obj/timer.o

vector.o : vector.cpp
	$(CC) -c -w $(CPPFLAGS) src/vector.cpp -o obj/vector.o

clean_debug :
	rm -rf debug/*

clean_release :
	rm -rf release/*

clean_objs :
	rm -rf obj/*

clean : clean_debug clean_release clean_objs
