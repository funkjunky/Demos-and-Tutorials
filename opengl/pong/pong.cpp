#include <iostream>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <cstdlib>
#include <ctime>

using namespace std;

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
	bool q;
	bool a;
	bool i;
	bool k;
	bool t;
	bool g;
	bool comma;
	bool period;
};

mykeys ispressed;
float x=-1,y=0,z=0, xrot=0, yrot=0;
int vwidth=640, vheight=480;
float lpaddle=-5, rpaddle=-5;
float upperbound=12, lowerbound=-20;
float leftbound=-40, rightbound=40;
bool gamestarted=false, leftsball=true;
float ballx=0, bally=-1; int xdir=1, ydir=1; float ballspeed=0.04;
int lscore=0, rscore=0;

void cleanup()
{
	SDL_Quit();
	exit(0);
}

void processstuff()
{
	if(ispressed.up)
		y+=.02;
	if(ispressed.down)
		y-=.02;
	if(ispressed.left)
		x+=.02;
	if(ispressed.right)
		x-=.02;
	if(ispressed.forward)
		z+=.02;
	if(ispressed.back)
		z-=.02;
	if(ispressed.q)
		if(lpaddle<upperbound)	lpaddle+=.02;
	if(ispressed.a)
		if(lpaddle>lowerbound)	lpaddle-=.02;
	if(ispressed.i)
		if(rpaddle<upperbound)	rpaddle+=.02;
	if(ispressed.k)
		if(rpaddle>lowerbound)	rpaddle-=.02;
	if(ispressed.comma)
		xrot-=0.2;
	if(ispressed.period)
		xrot+=0.2;
	if(ispressed.t)
		yrot-=0.2;
	if(ispressed.g)
		yrot+=0.2;

	if(gamestarted)
	{
		if((bally+=(float)ydir*ballspeed)>upperbound)
			ydir*=-1;
		if(bally < lowerbound)
			ydir*=-1;

		if((ballx+=(float)xdir*ballspeed) > rightbound)
		{
			if(bally > rpaddle && bally < rpaddle+8.0)
				xdir*=-1;
			else{
				lscore++;
				gamestarted=false;
				leftsball=true;
			}
		}
		if(ballx < leftbound)
		{
			if(bally > lpaddle && bally < lpaddle+8.0)
				xdir*=-1;
			else{
				rscore++;
				gamestarted=false;
				leftsball=false;
			}
		}
	}
}

void startgame()
{
	if(leftsball){
		ballx=-39;
		xdir=1;	
	}
	else{
		ballx=39;
		xdir=-1;
	}

	srand(time(0));
	if((bally=(rand()%36)-18) > 0)
		ydir=-1;
	else
		ydir=1;

	gamestarted=true;
}

void handleKeys(SDL_keysym* keysym, bool state)	//key listener. 
{						//State could be considered whether the key was pressed or released.

	switch(keysym->sym)	//this holds the key that triggered the event.
	{
		case SDLK_ESCAPE: if(!state) cleanup();	//if escape is released.
					break;
		case SDLK_UP:		ispressed.up=state;
					break;
		case SDLK_DOWN:		ispressed.down=state;
					break;
		case SDLK_LEFT:		ispressed.left=state;
					break;
		case SDLK_RIGHT:	ispressed.right=state;
					break;
		case SDLK_PAGEUP:	ispressed.forward=state;
					break;
		case SDLK_PAGEDOWN:	ispressed.back=state;
					break;
		case SDLK_q:	ispressed.q=state;	
				break;
		case SDLK_a:	ispressed.a=state;	
				break;
		case SDLK_i:	ispressed.i=state;	
				break;
		case SDLK_k:	ispressed.k=state;	
				break;
		case SDLK_COMMA:	ispressed.comma = state;
					break;	
		case SDLK_PERIOD:	ispressed.period = state;
					break;
		case SDLK_t:	ispressed.t = state;
				break;
		case SDLK_g:	ispressed.g = state;
				break;
		case SDLK_n:	if(!gamestarted)
				{
					lscore=0; rscore=0;
					startgame();
				}
				break;

		case SDLK_RETURN: if(!gamestarted)	startgame();	
					break;

		default: cerr << "unrecognized key..."<<endl;
	}
}

void processEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_KEYDOWN:	handleKeys(&event.key.keysym, true); 
						break;	
			case SDL_KEYUP	:	handleKeys(&event.key.keysym, false); 
						break;
			case SDL_QUIT	:	cleanup(); break;
		}
	}
	processstuff();
}

void setupgl()	//glMatrixMode decides which stack to add the functions to (i believe), if you put it on the wrong stack, it simply doesn't work.
{
	SDL_SetVideoMode(vwidth,vheight,24,SDL_OPENGL | SDL_GL_DOUBLEBUFFER);//setup window

	glViewport(0, 0, vwidth, vheight);
					
	glMatrixMode(GL_PROJECTION);	//setup where the projection will be coming from
		//scale, aspect-ratio, closest before not rendering, furtherest before not rendering.
		gluPerspective(45, (float)vwidth/vheight, .1, 1000);

	glMatrixMode(GL_MODELVIEW);	//after setting up projection, setup modelview...
	//model view is how you view the models, therefor it appears to be something you use from here on in.
	glPolygonMode(GL_BACK, GL_LINE);	//wireframe.
	glPolygonMode(GL_FRONT, GL_LINE);	//wireframe.
}

void drawprism(float xx, float yy, float zz, float width, float height, float depth)
{
	glBegin(GL_QUADS);
		glVertex3f(xx, yy, zz);		//bottom-left
		glVertex3f(xx, yy+height, zz);	//top-left
		glVertex3f(xx+width, yy+height, zz);	//top-right
		glVertex3f(xx+width, yy, zz);		//bottom-right
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(xx, yy, zz-depth);		//bottom-left
		glVertex3f(xx, yy+height, zz-depth);	//top-left
		glVertex3f(xx+width, yy+height, zz-depth);	//top-right
		glVertex3f(xx+width, yy, zz-depth);		//bottom-right
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(xx, yy, zz-depth);
		glVertex3f(xx, yy+height, zz-depth);
		glVertex3f(xx, yy+height, zz);
		glVertex3f(xx, yy, zz);
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(xx+width, yy, zz-depth);
		glVertex3f(xx+width, yy+height, zz-depth);
		glVertex3f(xx+width, yy+height, zz);
		glVertex3f(xx+width, yy, zz);
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(xx, yy, zz);
		glVertex3f(xx, yy, zz-depth);
		glVertex3f(xx+width, yy, zz-depth);
		glVertex3f(xx+width, yy, zz);		
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(xx, yy+height, zz);
		glVertex3f(xx, yy+height, zz-depth);
		glVertex3f(xx+width, yy+height, zz-depth);
		glVertex3f(xx+width, yy+height, zz);		
	glEnd();
}

void mainloop()
{
	while(true)	//encapsulates everything!
	{
		processEvents();	//process input devices.

		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	//clear screen.

		////Begin: Draw things!////

		glLoadIdentity();		//back to default
		glTranslatef(x,y,z-80);		//translate
		glRotatef(xrot,0,1,0);
		glRotatef(yrot,1,0,0);
		drawprism(leftbound,lowerbound,-5, rightbound-leftbound, upperbound-lowerbound, 1);	//general boundaries prism.
		drawprism(leftbound,lpaddle,0,2,8,2);	//left paddle
		drawprism(rightbound,rpaddle,0,2,8,2);	//right paddle
		drawprism(ballx,bally,0,1,1,1);		//ball
		
		for(int i=0; i<lscore; i++)
			drawprism(leftbound+(2*i), upperbound+1, 0, 1,3,1);

		for(int i=0; i<rscore; i++)
			drawprism(rightbound-(2*i), upperbound+1, 0, 1,3,1);
		////End: Draw things!////

		SDL_GL_SwapBuffers();	//places objects in memory on the screen.
	}
}

int main()
{
	setupgl();
	mainloop();
	//currently this is unreachable
	cleanup();
}
