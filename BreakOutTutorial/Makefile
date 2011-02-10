#my make file for my nehe thingy
LIBS=-lSDL -lGL -lGLU -lSDL_image

all: breakout

clean:
	rm -f *.o breakout

breakout: breakout.cpp gameObjects.o glUtilities.o breakout.h glUtilities.h gameObjects.h 
	g++ $(LIBS) -o breakout breakout.cpp glUtilities.o gameObjects.o

glUtilities.o: glUtilities.cpp
	g++ -c glUtilities.cpp

gameObjects.o: gameObjects.cpp
	g++ -c gameObjects.cpp

run: breakout
	./breakout
