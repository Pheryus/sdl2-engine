CXX=g++
CFLAGS=-std=c++11 -c -g
SDL=-lSDL2main -lSDL2 -lSDL2_image -lsqlite3 -lSDL2_mixer
OBJS=bin/main.o bin/System.o bin/GameObject.o bin/Mask.o bin/TextureBank.o \
bin/FileManager.o bin/Stringify.o bin/Texture.o bin/bitmask.o \
	bin/Card.o bin/Create_Deck.o bin/In_Play.o bin/Player.o bin/DataBase.o bin/SongBank.o
OUT=bin/game
all: main System GameObject TextureBank Mask FileManager Stringify Texture bitmask Card Create_Deck In_Play Player DataBase SongBank
			${CXX} ${OBJS} ${SDL} -o ${OUT}
			rm bin/*.o

main:
	${CXX} ${CFLAGS} -c src/main.cpp -o bin/main.o

System:
	${CXX} ${CFLAGS} -c src/System.cpp -o bin/System.o

GameObject:
	${CXX} ${CFLAGS} -c src/GameObject.cpp -o bin/GameObject.o

TextureBank:
	${CXX} ${CFLAGS} -c src/TextureBank.cpp -o bin/TextureBank.o

Mask:
	${CXX} ${CFLAGS} -c src/Mask.cpp -o bin/Mask.o

FileManager:
	${CXX} ${CFLAGS} -c src/FileManager.cpp -o bin/FileManager.o

Stringify:
	${CXX} ${CFLAGS} -c src/Stringify.cpp -o bin/Stringify.o

Texture:
	${CXX} ${CFLAGS} -c src/Texture.cpp -o bin/Texture.o

bitmask:
	${CXX} ${CFLAGS} -c src/ExternalLibs/bitmask.cpp -o bin/bitmask.o

Card:
	${CXX} ${CFLAGS} -c src/CardGame/Card.cpp -o bin/Card.o	

In_Play:
	${CXX} ${CFLAGS} -c src/CardGame/In_Play.cpp -o bin/In_Play.o	

Create_Deck:
	${CXX} ${CFLAGS} -c src/CardGame/Create_Deck.cpp -o bin/Create_Deck.o

Player:
	${CXX} ${CFLAGS} -c src/CardGame/Player.cpp -o bin/Player.o

DataBase:
	${CXX} ${CFLAGS} -c src/DataBase/DataBase.cpp -o bin/DataBase.o

SongBank:
	${CXX} ${CFLAGS} -c src/SongBank.cpp -o bin/SongBank.o

run:
	bin/game

clean:
	rm -f *.o */*.o
