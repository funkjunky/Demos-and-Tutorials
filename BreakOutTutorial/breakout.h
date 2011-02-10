//////////////////////////
//standard library	//
//////////////////////////
#include <iostream>
#include <vector>

//////////////////////////
//openGL library	//
//////////////////////////
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

////////////////////
//Personal Headers//
////////////////////
#ifndef GLUTILITIES_H
	#include "glUtilities.h"
#endif

#ifndef GAMEOBJECTS_H
	#include "gameObjects.h"
#endif

void initialize();
void handleInputs();
void update(float DT);
void draw();
void mainloop();
void cleanup();
int main();
