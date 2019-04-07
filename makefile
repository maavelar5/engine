#EXE speficies the exe file
EXE = marcoman

#VPATH specifies the directories used
VPATH = ./src:./def:./obj

#OBJS specifies which files to compile as part of the project
OBJS = $(notdir $(patsubst %.cpp,%.o,$(wildcard src/*.cpp)))

#OBJS_DIR specifies the objects directory
OBJS_DIR = $(addprefix obj/,$(OBJS))

#CC specifies which compiler we're using
CC = g++ -std=c++11

#CFLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
CFLAGS = -g -w

#CPPFLAGS specifies the preprocesor flags
CPPFLAGS = -I def

#SDL2_FLAGS
SDL2_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

#LINKER_FLAGS, condition to determine if windows or not
ifeq ($(OS),Windows_NT)
	LINKER_FLAGS = -w -Wl,-subsystem,windows -lmingw32 -lSDL2main $(SDL2_FLAGS)
else
	LINKER_FLAGS = $(SDL2_FLAGS)
endif

all : $(OBJS)
	$(CC) $(OBJS_DIR) $(CFLAGS) $(CPPFLAGS) $(LINKER_FLAGS) -o $(EXE)

camera.o : camera.cpp
	$(CC) -c -w $(CPPFLAGS) src/camera.cpp -o obj/camera.o

constants.o : constants.cpp
	$(CC) -c -w $(CPPFLAGS) src/constants.cpp -o obj/constants.o

collision.o : collision.cpp
	$(CC) -c -w $(CPPFLAGS) src/collision.cpp -o obj/collision.o

entity.o : entity.cpp
	$(CC) -c -w $(CPPFLAGS) src/entity.cpp -o obj/entity.o

game.o : game.cpp
	$(CC) -c -w $(CPPFLAGS) src/game.cpp -o obj/game.o

main.o : main.cpp
	$(CC) -c -w $(CPPFLAGS) src/main.cpp -o obj/main.o

platform.o : platform.cpp
	$(CC) -c -w $(CPPFLAGS) src/platform.cpp -o obj/platform.o

player.o : player.cpp
	$(CC) -c -w $(CPPFLAGS) src/player.cpp -o obj/player.o

projectile.o : projectile.cpp
	$(CC) -c -w $(CPPFLAGS) src/projectile.cpp -o obj/projectile.o

texture.o : texture.cpp
	$(CC) -c -w $(CPPFLAGS) src/texture.cpp -o obj/texture.o

tileEditor.o : tileEditor.cpp
	$(CC) -c -w $(CPPFLAGS) src/tileEditor.cpp -o obj/tileEditor.o

timer.o : timer.cpp
	$(CC) -c -w $(CPPFLAGS) src/timer.cpp -o obj/timer.o

vector.o : vector.cpp
	$(CC) -c -w $(CPPFLAGS) src/vector.cpp -o obj/vector.o

clean :
	rm $(EXE) $(OBJS_DIR)
