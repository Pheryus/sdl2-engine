CXX=g++
CFLAGS=-std=c++11 -c -g
SDL=-lSDL2main -lSDL2 -lSDL2_image -lsqlite3 -lSDL2_mixer
OBJS=bin/main.o bin/System.o bin/GameObject.o bin/Mask.o bin/TextureBank.o \
bin/FileManager.o bin/Stringify.o bin/Texture.o bin/bitmask.o bin/GameControl.o \
	bin/Card.o bin/DataBase.o bin/SongBank.o bin/Event.o
OUT=bin/game

all: main DataBase
	${CXX} ${OBJS} ${SDL} -o ${OUT}
link:
	${CXX} ${OBJS} ${SDL} -o ${OUT}

main: System GameObject
	${CXX} ${CFLAGS} -c src/main.cpp -o bin/main.o

System: GameObject TextureBank SongBank Event GameControl
	${CXX} ${CFLAGS} -c src/System.cpp -o bin/System.o

GameControl: GameObject Event
	${CXX} ${CFLAGS} -c src/GameControl.cpp -o bin/GameControl.o

GameObject: FileManager Stringify TextureBank Mask
	${CXX} ${CFLAGS} -c src/GameObject.cpp -o bin/GameObject.o

TextureBank: Texture Mask Stringify
	${CXX} ${CFLAGS} -c src/TextureBank.cpp -o bin/TextureBank.o

Mask: bitmask
	${CXX} ${CFLAGS} -c src/Mask.cpp -o bin/Mask.o

Texture: FileManager
	${CXX} ${CFLAGS} -c src/Texture.cpp -o bin/Texture.o

SongBank: FileManager
	${CXX} ${CFLAGS} -c src/SongBank.cpp -o bin/SongBank.o

FileManager: Stringify
	${CXX} ${CFLAGS} -c src/FileManager.cpp -o bin/FileManager.o

Stringify:
	${CXX} ${CFLAGS} -c src/Stringify.cpp -o bin/Stringify.o

Event:
	${CXX} ${CFLAGS} -c src/Event.cpp -o bin/Event.o

bitmask:
	${CXX} ${CFLAGS} -c src/ExternalLibs/bitmask.cpp -o bin/bitmask.o

Card:
	${CXX} ${CFLAGS} -c src/CardGame/Card.cpp -o bin/Card.o

DataBase:
	${CXX} ${CFLAGS} -c src/DataBase/DataBase.cpp -o bin/DataBase.o


run:
	bin/game

clean:
	rm -f *.o */*.o
