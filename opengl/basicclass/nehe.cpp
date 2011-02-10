//First, setting up opengl and sdl, involved installing opengl, 
//via apt-get install mesa-common-dev libglu1-mesa-dev
// Then I had to install sdl, which i did using synaptic, as their are
//A lot oflibraries to install. I installed everything ending with -dev, 
//as Nick instructed me, and I installed "libsdl1.2debian" and 
//libsdl1.2debian-alsa" although the second one was already installed O.o.
//compile using -lSDL -lGL -lGLU flags

#include <iostream>
#include <string>
#include <GL/gl.h>		//header for opengl32
#include <GL/glu.h>		//header for glu32
#include <cstdlib>
#include <SDL/SDL.h>		//header for general sdl features
#include <SDL/SDL_image.h>	//header for sdl_image features, such as simpler texture creations.

#define width 640
#define height 480

using namespace std;

float angle=0.0;
GLuint mytexture;

//kill program	--	we need this to quit SDL and exit.
void endProgram(int code)
{
	SDL_Quit();	//exits SDL, by cleaning up variables and the like
	exit(code);	//then we exit =)
}

//handle SDL keypresses
void handleKeys(SDL_keysym* keysym, bool state)	//key listener. 
{						//State could be considered whether the key was pressed or released.

	switch(keysym->sym)	//this holds the key that triggered the event.
	{
		case SDLK_ESCAPE:	endProgram(0);	//if escape is hit
					break;
		default: cerr << "unrecognized key..."<<endl;
	}
}

//process SDL events
void processEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_KEYDOWN:	handleKeys(&event.key.keysym, true); break;	
			case SDL_KEYUP	:	handleKeys(&event.key.keysym, false); break;
			case SDL_QUIT	:	endProgram(0); break;
		}
	}
}

GLuint loadTexture_deprecated(char filename[]){
	GLuint texture;					//this is the format opengl wants.
	SDL_Surface* imgFile = IMG_Load(filename);	//this is the sdl function to do the work for us.
	glGenTextures(1,&texture);			//this creates the texture in opengl, not sure about the 1???
	glBindTexture(GL_TEXTURE_2D, texture);		//this binds teh texture to opengl????		
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, imgFile->w, imgFile->h, GL_RGB, GL_UNSIGNED_BYTE, imgFile->pixels);	//this does the final preparation for opengl
	return texture;	//this returns the prepared texture.
}

GLuint loadTexture(char filename[], bool mipmap=true)
{
 glPushAttrib (GL_ALL_ATTRIB_BITS);
 GLuint texture;
 SDL_Surface* imgFile = IMG_Load(filename);
 glGenTextures(1,&texture);
 glBindTexture(GL_TEXTURE_2D,texture);
 if(mipmap)
 {
 	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
 	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, imgFile->w, imgFile->h, GL_RGB, GL_UNSIGNED_BYTE, imgFile->pixels);
 } 
 else 
 {
 	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
 	glTexImage2D (GL_TEXTURE_2D, 0, 3, imgFile->w, imgFile->h, 0, GL_RGB, GL_UNSIGNED_BYTE, imgFile->pixels);
 }
 glPopAttrib ();
 return texture;
}

void rotatingrectprism()
{
	glBindTexture(GL_TEXTURE_2D, mytexture);

	glTranslatef(0,0,-10);
	glRotatef(angle,1,2,1);
	glBegin(GL_QUADS);
	glTexCoord2f(0,0); glVertex3f(-2,2,0);
	glTexCoord2f(1,0); glVertex3f(2,2,0);
	glTexCoord2f(1,1); glVertex3f(2,-2,0);
	glTexCoord2f(0,1); glVertex3f(-2,-2,0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0,0); glVertex3f(-2,2,-2);
	glTexCoord2f(1,0); glVertex3f(2,2,-2);
	glTexCoord2f(1,1); glVertex3f(2,-2,-2);
	glTexCoord2f(0,1); glVertex3f(-2,-2,-2);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0,0); glVertex3f(2,2,0);
	glTexCoord2f(1,0); glVertex3f(2,2,-2);
	glTexCoord2f(1,1); glVertex3f(2,-2,-2);
	glTexCoord2f(0,1); glVertex3f(2,-2,0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0,0); glVertex3f(-2,2,0);
	glTexCoord2f(1,0); glVertex3f(-2,2,-2);
	glTexCoord2f(1,1); glVertex3f(-2,-2,-2);
	glTexCoord2f(0,1); glVertex3f(-2,-2,0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0,0); glVertex3f(-2,2,0);
	glTexCoord2f(1,0); glVertex3f(-2,2,-2);
	glTexCoord2f(1,1); glVertex3f(2,2,-2);
	glTexCoord2f(0,1); glVertex3f(2,2,0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0,0); glVertex3f(-2,-2,0);
	glTexCoord2f(1,0); glVertex3f(-2,-2,-2);
	glTexCoord2f(1,1); glVertex3f(2,-2,-2);
	glTexCoord2f(0,1); glVertex3f(2,-2,0);
	glEnd();

	angle=(angle>359.5)?0:angle + .25;		
}

void rotatingsquare()
{
		glTranslatef(0,0,-10);
		glRotatef(angle,0,1,0);
		glBegin(GL_QUADS);
		//order of vertices matters!
		glColor3f(1,0,0);
		glVertex3f(1,1,0);
		glColor3f(1,1,0);		
		glVertex3f(1,-1,0);
		glColor3f(0,1,1);
		glVertex3f(-1,-1,0);
		glColor3f(0,0,1);
		glVertex3f(-1,1,0);
		glEnd();

		/*glTranslatef(-2,0,0);
		glRotatef(-angle,0,0,1);
		glBegin(GL_QUADS);
		glColor3f(0,0,1);
		glVertex3f(1,1,0);
		glVertex3f(1,-1,0);
		glVertex3f(-1,-1,0);
		glVertex3f(-1,1,0);*/
		angle=(angle>359.5)?0:angle + .25;
}

//main loop for doing stuff with opengl or creating sdl events.
void mainLoop()
{				//REMEMBER: opengl is a STATE-MACHINE anything changed, usually stays changed.
	while(true)
	{
		processEvents();
		
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	//clear color and depth buffer.
		glLoadIdentity();	//reset orientation

		//graphical stuffs go here.
		//rotatingsquare();
		rotatingrectprism();
		//graphical stuff ends?
		
		//cerr << "angle = " << angle << endl;
		SDL_GL_SwapBuffers();	//Update screen
	}
}

//setup opengl perspective
void setupOpengl()
{
	glViewport(0, 0, width, height);	//the window. (I think: top, left, width, height)
	glMatrixMode(GL_PROJECTION);		//no idea.
	glEnable(GL_DEPTH_TEST);		//no idea
	gluPerspective(45, (float)width/height, .1, 100);	//no idea
	glMatrixMode(GL_MODELVIEW);		//no idea

	//setup textures
	glEnable(GL_TEXTURE_2D);
	mytexture = loadTexture("mytexture.png");

	//setup fog
	GLfloat fColor[4]={0.0f, 1.0f, 0.0f, 1.0f};
	glClearColor(0.0f,1.0f,0.0f,1.0f);
	glFogi(GL_FOG_MODE, GL_EXP2);	//try different styles
	//glFogi(GL_FOG_MODE, GL_EXP);	//try different styles
	//glFogi(GL_FOG_MODE, GL_LINEAR);	//try different styles
	glFogfv(GL_FOG_COLOR, fColor);
	glFogf(GL_FOG_DENSITY, 0.15f);
	glFogf(GL_FOG_START, 0.0f);
	glFogf(GL_FOG_END, 2.0f);
	glEnable(GL_FOG);
}

int main()
{
	cout << "we are running"<<endl;
	//after initial couts

	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetVideoMode(width,height,24,SDL_OPENGL | SDL_GL_DOUBLEBUFFER);
	setupOpengl();
	mainLoop();
	return 0;
}
