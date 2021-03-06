//////////////////////////
//standard library	//
//////////////////////////
#include <iostream>

//////////////////////////
//openGL library	//
//////////////////////////
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define GLUTILITIES_H


#define MILLISECONDS_IN_A_SECOND 1000

/////////////////////////
//structures and enums///
/////////////////////////

struct KeyStates
{
	KeyStates();

	bool up;
	bool down;
	bool left;
	bool right;
	bool forward;
	bool back;
	bool comma;
	bool period;

	bool z;
	bool x;
};

struct Point3f
{
	Point3f();

	Point3f(float ,float ,float );

	float x,y,z;
};
///////////////////
//used prototypes//
///////////////////
void cleanup();

/////////////////////
//Utility Functions//
/////////////////////
GLuint loadTexture(char filename[], bool mipmap=true);
void handleKeys(SDL_keysym*, bool, KeyStates&);

void processEvents(KeyStates& IsPressed, void (*keyHandler)(SDL_keysym*, bool, KeyStates&) = handleKeys);

float updateReady();
void setupGL(int screenWidth, int screenHeight, GLenum polygonMode);
