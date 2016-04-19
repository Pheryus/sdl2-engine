CXX=g++
CFLAGS=-std=c++11 -g
SDL=-lSDL2main -lSDL2 -lSDL2_image
#SRCS=main.cpp System.cpp GameObject.cpp Mask.cpp TextureBank.cpp FileManager.cpp Stringify.cpp Texture.cpp ExternalLibs/bitmask.cpp
OBJS=bin/main.o bin/System.o bin/GameObject.o bin/Mask.o bin/TextureBank.o bin/FileManager.o bin/Stringify.o bin/Texture.o bin/bitmask.o
OUT=bin/game

all: main System GameObject TextureBank Mask FileManager Stringify Texture bitmask
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

run:
	bin/game

clean:
	rm -f *.o */*.o
