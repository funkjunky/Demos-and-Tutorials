//First, setting up opengl and sdl, involved installing opengl, 
//via apt-get install mesa-common-dev libglu1-mesa-dev
// Then I had to install sdl, which i did using synaptic, as their are
//A lot oflibraries to install. I installed everything ending with -dev, 
//as Nick instructed me, and I installed "libsdl1.2debian" and 
//libsdl1.2debian-alsa" although the second one was already installed O.o.
//compile using -lSDL -lGL -lGLU flags

#include <cmath>
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

void setupOpengl();
void mainLoop();

struct mykeys{
	mykeys()
		:up(false), down(false), left(false), right(false), forward(false), back(false), plus(false), neg(false)
	{}

	bool up;
	bool down;
	bool left;
	bool right;
	bool forward;
	bool back;
	bool plus;
	bool neg;
};

struct stars{
	stars()
	{}
	stars(int rr, int gg, int bb, GLfloat d, GLfloat a)
		:r(rr), g(gg), b(bb), dist(d), angle(a)
	{}
	int r,g,b;
	GLfloat dist;
	GLfloat angle;
};

GLvoid KillFont(GLvoid);

float angle=0.0;
GLuint mytexture;
float x=0,z=0,y=0;
mykeys ispressed;

bool light=true;
bool fullscreen=false;	//always start without fullscreen. (this variable doesn't decide fullscreen at startup)

GLfloat LightAmbient[] = { 0.5f, 0.5f,1.0f, 1.0f};
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 0.5f};
GLfloat LightPosition[] = {1.0f, 4.0f, 2.0f, 1.0f};

GLuint texture[5];

bool blend=true;
bool twinkle=true;	//not using next three variables.
const int num=50;
stars star[num];

int r1=250,g1=250,b1=250;
int rb=-1,gb=-1,bb=-1;

float points[45][45][3];
int wiggle_count = 0;
GLfloat hold;
float xrot=0, yrot=0, zrot=0;
int wavespeed=10;
int xx,yy;

GLuint box;
GLuint top;
GLuint xloop;
GLuint yloop;

GLuint abase;

/*static GLfloat boxcol[5][3]
{								// Array For Box Colors
	// Bright:  Red, Orange, Yellow, Green, Blue
	{1.0f,0.0f,0.0f},{1.0f,0.5f,0.0f},{1.0f,1.0f,0.0f},{0.0f,1.0f,0.0f},{0.0f,1.0f,1.0f}
};

static GLfloat topcol[5][3]
{								// Array For Top Colors
	// Dark:  Red, Orange, Yellow, Green, Blue
	{0.5f,0.0f,0.0f},{0.5f,0.25f,0.0f},{0.5f,0.5f,0.0f},{0.0f,0.5f,0.0f},{0.0f,0.5f,0.5f}
};*/

//kill program	--	we need this to quit SDL and exit.
void endProgram(int code)
{
	SDL_Quit();	//exits SDL, by cleaning up variables and the like
	exit(code);	//then we exit =)
}

void restartscreen(bool isfullscreen)
{
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_TEXTURE_2D);
	fullscreen=isfullscreen;
	SDL_Quit();
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetVideoMode(width,height,24,SDL_OPENGL | SDL_GL_DOUBLEBUFFER | (isfullscreen)?SDL_FULLSCREEN:0);	// |SDL_FULLSCREEN for fullscreen
	setupOpengl();
	mainLoop();
}

//handle SDL keypresses
void handleKeys(SDL_keysym* keysym, bool state)	//key listener. 
{						//State could be considered whether the key was pressed or released.

	switch(keysym->sym)	//this holds the key that triggered the event.
	{
		case SDLK_ESCAPE: if(!state) endProgram(0);	//if escape is released.
					break;
		case SDLK_UP:	ispressed.up=state;
					break;
		case SDLK_DOWN:	ispressed.down=state;
					break;
		case SDLK_LEFT:	ispressed.left=state;
					break;
		case SDLK_RIGHT:ispressed.right=state;
					break;
		case SDLK_PAGEUP:ispressed.forward=state;
					break;
		case SDLK_PAGEDOWN:ispressed.back=state;
					break;
		case SDLK_f:	if(!state) restartscreen(!fullscreen); 	//causes segmentation fault.
					break;
		case SDLK_l:	if(state){ if(light=!light) glEnable(GL_LIGHTING); else glDisable(GL_LIGHTING);}cerr<<"light off is "<<light<<endl;
				break;
		case SDLK_b:	if(state){ if(blend=!blend){ glDisable(GL_DEPTH_TEST); glEnable(GL_BLEND);}else {glDisable(GL_BLEND); glEnable(GL_DEPTH_TEST);}}
				break;
		case SDLK_KP_PLUS: 	ispressed.plus = state;
					break;
		case SDLK_KP_MINUS:	ispressed.neg = state;
					break;
		default: cerr << "unrecognized key..."<<endl;
	}
}

void processkeys()
{
	//cerr<<"up = " << ispressed.up<<endl;
	if(ispressed.up)
		y+=.01;
	if(ispressed.down)
		y-=.01;
	if(ispressed.left)
		x+=.01;
	if(ispressed.right)
		x-=.01;
	if(ispressed.forward)
		z+=.01;
	if(ispressed.back)
		z-=.01;
	if(ispressed.plus)
		if(wavespeed!=1) wavespeed--;
	if(ispressed.neg)
		if(wavespeed!=200) wavespeed++;
}

//process SDL events
void processEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{//cerr<<"blargy";
		switch(event.type)
		{
			case SDL_KEYDOWN:	handleKeys(&event.key.keysym, true); break;	
			case SDL_KEYUP	:	handleKeys(&event.key.keysym, false); break;
			case SDL_QUIT	:	endProgram(0); break;
		}
	}
	processkeys();
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

void ptboflag()
{
	float fx, fy, fxb, fyb;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//clears screen and depth buffer?
	glLoadIdentity();

	glTranslatef(x+4, y, z-14);

	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(zrot, 0.0f, 0.0f, 1.0f);

	glBindTexture(GL_TEXTURE_2D, texture[3]);

	glBegin(GL_QUADS);
	glColor4ub(255,255,255,255);//r1
	for(xx=0; xx<44; xx++)
	{	
		for(yy=0; yy<44; yy++)
		{
			fx = float(xx)/44.0f;	//splits the texturemap into 44 chunks.
			fy = float(yy)/44.0f;
			fxb = float(xx+1)/44.0f;
			fyb = float(yy+1)/44.0f;
			//cerr << fx << "-"<< fy << "-"<< fxb << "-"<< fyb << endl;
			//then applies them to our quads	
			glTexCoord2f(fx,fy);
			glVertex3f(points[xx][yy][0], points[xx][yy][1], points[xx][yy][2]);
			
			glTexCoord2f(fx,fyb);
			glVertex3f(points[xx][yy+1][0], points[xx][yy+1][1], points[xx][yy+1][2]);

			glTexCoord2f(fxb,fyb);
			glVertex3f(points[xx+1][yy+1][0], points[xx+1][yy+1][1], points[xx+1][yy+1][2]);

			glTexCoord2f(fxb,fy);
			glVertex3f(points[xx+1][yy][0], points[xx+1][yy][1], points[xx+1][yy][2]);

		}
	}
	glEnd();
	if(++wiggle_count==wavespeed)
	{
		//create new points. (move points to left, creating wave effect.)	
		for(yy=0; yy<45; yy++)
		{
			hold=points[0][yy][2];
			for(xx=0;xx<44;xx++)
				points[xx][yy][2] = points[xx+1][yy][2];
			points[44][yy][2]=hold;
		}
		wiggle_count=0;
	}

	//roations
	xrot+=0.15f;
	yrot+=0.1f;
	zrot+=0.2f;
}

void rotatingrectprism()
{
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, texture[0]);
//front face
	glTranslatef(x,y,z-14);
	glRotatef(angle,1,1,0);
	glColor4ub(255,255,255,r1);
	glBegin(GL_QUADS);
	glNormal3f(0.0f,0.0f,1.0f);
	glTexCoord2f(0,0); glVertex3f(-2,2,0);
	glTexCoord2f(1,0); glVertex3f(2,2,0);
	glTexCoord2f(1,1); glVertex3f(2,-2,0);
	glTexCoord2f(0,1); glVertex3f(-2,-2,0);
	glEnd();

	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, texture[1]);
//backface
	glTranslatef(x,y,z-14);
	glRotatef(angle,1,1,0);
	glColor4ub(255,255,255,255);
	glBegin(GL_QUADS);
	glNormal3f(0.0f,0.0f,-1.0f);
	glTexCoord2f(0,0); glVertex3f(-2,2,-2);
	glTexCoord2f(1,0); glVertex3f(2,2,-2);
	glTexCoord2f(1,1); glVertex3f(2,-2,-2);
	glTexCoord2f(0,1); glVertex3f(-2,-2,-2);
	glEnd();

	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, texture[2]);
//rightface
	glTranslatef(x,y,z-14);
	glRotatef(angle,1,1,0);
	glColor4ub(255,255,255,255);
	glBegin(GL_QUADS);
	glNormal3f(1.0f,0.0f,0.0f);
	glTexCoord2f(0,0); glVertex3f(2,2,0);
	glTexCoord2f(1,0); glVertex3f(2,2,-2);
	glTexCoord2f(1,1); glVertex3f(2,-2,-2);
	glTexCoord2f(0,1); glVertex3f(2,-2,0);
	glEnd();
//leftface
	glBegin(GL_QUADS);
	glNormal3f(-1.0f,0.0f,0.0f);
	glTexCoord2f(0,0); glVertex3f(-2,2,0);
	glTexCoord2f(1,0); glVertex3f(-2,2,-2);
	glTexCoord2f(1,1); glVertex3f(-2,-2,-2);
	glTexCoord2f(0,1); glVertex3f(-2,-2,0);
	glEnd();
//topface
	glBegin(GL_QUADS);
	glNormal3f(0.0f,1.0f,0.0f);
	glTexCoord2f(0,0); glVertex3f(-2,2,0);
	glTexCoord2f(1,0); glVertex3f(-2,2,-2);
	glTexCoord2f(1,1); glVertex3f(2,2,-2);
	glTexCoord2f(0,1); glVertex3f(2,2,0);
	glEnd();
//bottomface
	glBegin(GL_QUADS);
	glNormal3f(0.0f,-1.0f,0.0f);
	glTexCoord2f(0,0); glVertex3f(-2,-2,0);
	glTexCoord2f(1,0); glVertex3f(-2,-2,-2);
	glTexCoord2f(1,1); glVertex3f(2,-2,-2);
	glTexCoord2f(0,1); glVertex3f(2,-2,0);
	glEnd();

	r1=(r1>254 || r1<1)?(rb*=-1)+r1:rb+r1;
	angle=(angle>359.8)?0:angle + .05;
	//cerr << r1<<endl;	
}

void rotatingsquare()
{
		glLoadIdentity();
		glTranslatef(x-3,y,z-14);
		glRotatef(angle,0,1,0);
		glBegin(GL_QUADS);
		//order of vertices matters!
				glNormal3f(0.0f,0.0f,1.0f);
			glColor4ub(r1,255-r1,255-r1,255);	//lighting breaks any color options.
			glVertex3f(1,1,0);
			glColor4ub(r1,r1,255-r1,255);		
			glVertex3f(1,-1,0);
			glColor4ub(255-r1,r1,r1,255);
			glVertex3f(-1,-1,0);
			glColor4ub(255-r1,255-r1,r1,255);
			glVertex3f(-1,1,0);
		glEnd();

		/*glTranslatef(-2,0,0);
		glRotatef(-angle,0,0,1);
		glBegin(GL_QUADS);
			glColor3f(0,0,1);
			glVertex3f(1,1,0);
			glVertex3f(1,-1,0);
			glVertex3f(-1,-1,0);
			glVertex3f(-1,1,0);
		glEnd();*/
		//angle=(angle>359.5)?0:angle + .25;
}

void qbert()//this coiuld be used to store cubes and such then place them in various locations on the screen.
{
	//glTranlatef() place the list shape somewhere.
	//glRotatef() rotate it or whatever.
	//glColor3fv()//select a box color.
	//glCallList(box);	//draw predefined shapes. 
}

void makeq()
{
	box = glGenLists(2);
	glNewList(box, GL_COMPILE);
		//add shapes in here.
	glEndList();
	top=box+1;	//next address, already created by "glGenLists(2)"
	glNewList(top, GL_COMPILE);
		//add shapes in here.
	glEndList();
}

GLvoid BuildFont(GLvoid)
{
	float cx;
	float cy;

	abase = glGenLists(256);
	glBindTexture(GL_TEXTURE_2D, texture[4]);

	for(int i=0; i<256; i++)
	{
		cx = float(i%16)/16.0f;
		cy = float((i/16)%16);

		glNewList(abase+i, GL_COMPILE);
			glBegin(GL_QUADS);
				glTexCoord2f(cx,1-cy-0.0625f);
				glVertex2i(0,0);
				glTexCoord2f(cx+0.0625f,1-cy-0.0625f);
				glVertex2i(16,0);
				glTexCoord2f(cx+0.0625f,1-cy);
				glVertex2i(16,16);
				glTexCoord2f(cx,1-cy);
				glVertex2i(0,16);
			glEnd();
			glTranslated(10,0,0);
		glEndList();
	}
}

GLvoid glPrint(GLint x, GLint y, char *string, unsigned set)
{
	if(set>1)
		set=1;

	glBindTexture(GL_TEXTURE_2D, texture[4]);

	glTranslatef(x,y,0);
	glColor4ub(255,255,255,255);
	glListBase(abase-32+(128*set));

	glCallLists(strlen(string), GL_UNSIGNED_BYTE,string);
}

GLvoid KillFont(GLvoid)								
{
	glDeleteLists(abase,256);						
}

void printtext()
{
	glTranslatef(x-0.0f,y-0.0f,z-10.0f);
	glBegin(GL_QUADS);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,2.0f,0.0f);
		glVertex3f(4.0f,2.0f,0.0f);
		glVertex3f(4.0f,0.0f,0.0f);
	glEnd();
}

//main loop for doing stuff with opengl or creating sdl events.
void mainLoop()
{				//REMEMBER: opengl is a STATE-MACHINE anything changed, usually stays changed.
	while(true)
	{
		processEvents();
		
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	//clear color and depth buffer.
		glLoadIdentity();	//reset orientation WE SHOULD DO THIS BEFORE EVERY NEW OBJECT! So we know that we are back at 0,0, incase we don't set translate, and rotate.

		//graphical stuffs go here.
		//qbert();
		//ptboflag();
		rotatingrectprism();
		rotatingsquare();
		//graphical stuff ends?
		//glPrint(1,1,"awesome",0);
		//cerr << "angle = " << angle << endl;
		SDL_GL_SwapBuffers();	//Update screen
	}
}

//makes fog
void makefog()
{
	GLfloat fColor[4]={1.0f, 1.0f, 1.0f, 0.1f};
	glClearColor(1.0f,1.0f,1.0f,0.1f);
	glFogi(GL_FOG_MODE, GL_EXP2);	//try different styles
	//glFogi(GL_FOG_MODE, GL_EXP);	//try different styles
	//glFogi(GL_FOG_MODE, GL_LINEAR);	//this is best one!
	//glHint(GL_FOG_HINT, GL_NICEST);	//this way the nicest rendering is done.
	glFogfv(GL_FOG_COLOR, fColor);
	glFogf(GL_FOG_DENSITY, 0.05f);
	glFogf(GL_FOG_START, 0.0f);
	glFogf(GL_FOG_END, 2.0f);
	glEnable(GL_FOG);
}

//setup opengl perspective
void setupOpengl()
{
	glViewport(0, 0, width, height);	//the window. (I think: top, left, width, height)
	glMatrixMode(GL_PROJECTION);		//no idea.
	//for blending (to take off, comment out first 3 lines and uncomment 4th
	//glColor4f(1.0f,1.0f,1.0f,0.5f);

	//glEnable(GL_DEPTH_TEST);		//no idea
	gluPerspective(45, (float)width/height, .1, 100);	//no idea
	glMatrixMode(GL_MODELVIEW);		//no idea
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	glEnable(GL_BLEND);
	//setup textures
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);		//I'm not sure if this is needed yet.
	texture[0] = loadTexture("ptbo2.png");
	texture[1] = loadTexture("funny.png");
	texture[2] = loadTexture("rofl.png");
	texture[3] = loadTexture("mytexture.png");
	//texture[4] = loadTexture("electrox.ttf"); //loading a ttf causes a seg fault!

	//setup fog
	//makefog();

	//setup lights
	//glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);	//light affecting alpha?
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
	glEnable(GL_LIGHT1);
	//glEnable(GL_LIGHT2);
	glEnable(GL_LIGHTING);

	//draw types?
	glPolygonMode(GL_BACK, GL_LINE);	//very interesting!
	glPolygonMode(GL_FRONT, GL_FILL);

	//BuildFont();

	//loop through x and y plane
	for(int x=0; x<45; x++)
	{
		for(int y=0; y<45; y++)
		{
			//apply the wave to our "mesh" of squares.
			points[x][y][0] = float((x/5.0f)-4.5f);
			points[x][y][1] = float((y/5.0f)-4.5f);
			points[x][y][2] = float(sin((((x/5.0f)*40.0f)/360.0f)*M_PI*2.0f));
		}
	}
}

int main()
{
	cout << "we are running"<<endl;
	//after initial couts

	//SDL_Init(SDL_INIT_VIDEO);
	SDL_SetVideoMode(width,height,24,SDL_OPENGL | SDL_GL_DOUBLEBUFFER);	// |SDL_FULLSCREEN for fullscreen
	setupOpengl();
	mainLoop();
	return 0;
}
