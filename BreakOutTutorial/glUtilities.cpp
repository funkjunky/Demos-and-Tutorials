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

////////////////////
//Personal Headers//
////////////////////
#ifndef GLUTILITIES_H
	#include "glUtilities.h"
#endif

/////////////////////////
//structures and enums///
/////////////////////////

	KeyStates::KeyStates()
		:up(false), down(false), left(false), right(false), forward(false), back(false), comma(false), period(false), z(false), x(false)
	{}

	Point3f::Point3f()
		:x(0), y(0), z(0)
	{}

	Point3f::Point3f(float xx,float yy,float zz)
		:x(xx), y(yy), z(zz)
	{}

/////////////////////
//Utility Functions//
/////////////////////
GLuint loadTexture(char filename[], bool mipmap)
{
 glPushAttrib (GL_ALL_ATTRIB_BITS);
 GLuint texture1;
 SDL_Surface* imgFile = IMG_Load(filename);
 glGenTextures(1,&texture1);
 glBindTexture(GL_TEXTURE_2D,texture1);
 if(mipmap)
 {
 	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);		//LINEAR is best, NEAREST is bad, but more effecient.
 	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);	//i think mipmapping solves all thou.
 	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, imgFile->w, imgFile->h, GL_RGB, GL_UNSIGNED_BYTE, imgFile->pixels);
 } 
 else 
 {
 	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
 	glTexImage2D (GL_TEXTURE_2D, 0, 3, imgFile->w, imgFile->h, 0, GL_RGB, GL_UNSIGNED_BYTE, imgFile->pixels);
 }
 glPopAttrib ();
 return texture1;
}

void handleKeys(SDL_keysym* keysym, bool state, KeyStates& IsPressed)	//key listener. 
{						//State could be considered whether the key was pressed or released.

	switch(keysym->sym)	//this holds the key that triggered the event.
	{
		case SDLK_ESCAPE: if(!state) cleanup();	//if escape is released.
					break;
		case SDLK_LEFT:		IsPressed.left = state;
					break;
		case SDLK_UP:		IsPressed.up = state;
					break;
		case SDLK_DOWN:		IsPressed.left = state;
					break;
		case SDLK_PAGEUP:	IsPressed.forward=state;
					break;
		case SDLK_PAGEDOWN:	IsPressed.back=state;
					break;
		case SDLK_COMMA:	IsPressed.comma = state;
					break;
		case SDLK_PERIOD:	IsPressed.period = state;
					break;
		case SDLK_z:		IsPressed.z = state;
					break;
		case SDLK_x:		IsPressed.x = state;
					break;

		default: std::cerr << "unrecognized key..."<<std::endl;
	}
}

void processEvents(KeyStates& IsPressed, void (*keyHandler)(SDL_keysym*, bool, KeyStates&))
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_KEYDOWN:	keyHandler(&event.key.keysym, true, IsPressed); 
						break;	
			case SDL_KEYUP	:	keyHandler(&event.key.keysym, false, IsPressed); 
						break;
			case SDL_QUIT	:	cleanup(); break;
		}
	}
}

const int TICKS_PER_SECOND = 60;
const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
const int MAX_FRAMESKIP = 5;

int loops=0;
int next_game_tick = 0;
//float interpolation;

int fps=0;
int fpsTick = 0;
int ups=0;
int upsTick = 0;
float updateReady()
{
	//find fps value.
	if(fpsTick + 1000 < SDL_GetTicks()) {
		//std::cerr << "frames per second: " << fps << std::endl;
		fpsTick = SDL_GetTicks();
		fps = 0;			
	}
	else
		fps++;

	if(SDL_GetTicks() > next_game_tick && loops < MAX_FRAMESKIP)
	{
		next_game_tick += SKIP_TICKS;
		loops++;
		//if(loops > 1)
		//	std::cerr << "we're running slow. Forced to loop. Loops = " << loops << std::endl;

		if(upsTick + 1000 < SDL_GetTicks()) {
			//std::cerr << "updates per second: " << ups << std::endl;
			upsTick = SDL_GetTicks();
			ups = 0;			
		}
		else
			ups++;
	
		return SKIP_TICKS;
	}
	else {
		loops = 0;
		return 0.0f;
	}	
}

void setupGL(int screenWidth, int screenHeight, GLenum polygonMode)	//glMatrixMode decides which stack to add the functions to (i believe), if you put it on the wrong stack, it simply doesn't work.
{
	SDL_SetVideoMode(screenWidth,screenHeight,24,SDL_OPENGL | SDL_GL_DOUBLEBUFFER);//setup window

	glViewport(0, 0, screenWidth, screenHeight);
					
	glMatrixMode(GL_PROJECTION);	//setup where the projection will be coming from
		//field of view angle in degrees, aspect-ratio, closest before not rendering, furtherest before not rendering.
		gluPerspective(45, (float)screenWidth/screenHeight, .1, 1000);

	glMatrixMode(GL_MODELVIEW);	//after setting up projection, setup modelview...
	//model view is how you view the models, therefor it appears to be something you use from here on in.
	glPolygonMode(GL_BACK, polygonMode);	//wireframe.
	glPolygonMode(GL_FRONT, polygonMode);	//wireframe.

	if(polygonMode == GL_FILL) 
	{
		//setup textures
		glEnable(GL_TEXTURE_2D);

		glMatrixMode(GL_TEXTURE);
		glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
		glScalef(-1.0f, 1.0f,1.0f);
		glMatrixMode(GL_MODELVIEW);

		//glBlendFunc(GL_SRC_ALPHA,GL_ONE);
		//glEnable(GL_BLEND);

		/*GLfloat LightAmbient[]  =	{0.5f, 0.5f,1.0f, 1.0f};
		GLfloat LightDiffuse[]  =	{1.0f, 1.0f, 1.0f, 0.5f};
		GLfloat LightPosition[] =	{-10.0f, -4.0f, 2.0f, 1.0f};

		glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHTING);
		*/
	}
}
