CXX=g++
CFLAGS=-std=c++11
SDL=-lSDL2main -lSDL2 -lSDL2_image
SRCS=main.cpp App.cpp TextureBank.cpp FileManager.cpp Stringify.cpp Texture.cpp
OBJS=${SRCS:.cpp=.o}
OUT=game

all:
	${CXX} ${CFLAGS} ${SRCS} ${SDL} -o ${OUT}

clean:
	rm -f *.o ${OUT}
