CXX=g++
CFLAGS=-std=c++11
DEBUG=-g -O2
SDL=-lSDL2main -lSDL2 -lSDL2_image
SRCS=main.cpp App.cpp GameObject.cpp Mask.cpp TextureBank.cpp FileManager.cpp Stringify.cpp Texture.cpp ExternalLibs/bitmask.cpp
OBJS=${SRCS:.cpp=.o}
OUT=game

all: compile moveLibObjs
	${CXX} ${OBJS} ${SDL} -o ${OUT}
	make clean

debug: compile-debug moveLibObjs
	${CXX} ${OBJS} $(SDL) -o ${OUT} 

compile:
	${CXX} ${CFLAGS} -c ${SRCS}

compile-debug:
	${CXX} ${CFLAGS} ${DEBUG} -c ${SRCS}


moveLibObjs:
	mv bitmask.o ExternalLibs

clean:
	rm -f *.o */*.o
