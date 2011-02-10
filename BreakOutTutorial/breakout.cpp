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
#include "breakout.h"
#ifndef GLUTILITIES_H
	#include "glUtilities.h"
#endif
#ifndef GAMEOBJECTS_H
	#include "gameObjects.h"
#endif

using namespace std;

////////////////////////////////
/*Some Function Prototypes    */
////////////////////////////////

void cleanup();

//////////////////////////
//GLobal consts for game//
//////////////////////////

const float	ballSpeed	= 28.0f;
const float	paddleMultiplier= 0.5f;
const float	paddleSpeed	= ballSpeed * paddleMultiplier;

const float	paddleWidth	= 12.0f;
const float	paddleHeight	= 3.0f;

const float	losingBound	= -35.0f;

const float	ballRadius	= 2.0f;

const float	blockWidth	= 12.0f;
const float	blockHeight	= 2.0f;

const float	startingX	= -40.0f;
const float	startingY	= 0.0f;
const float	seperationX	= 1.0f;
const float	seperationY	= 1.0f;
const int	numOfCols	= 6;
const int	numOfRows	= 5;

/////////////////////////////
//Global Variables for Game//
/////////////////////////////
KeyStates		isPressed;

vector<GLuint> 		textures;

Engine*			god;

Paddle* 		paddle;
vector<vector<Brick*>* > blocks;
BreakoutBall* 		ball;

void initialize()
{
	textures.push_back(loadTexture("paddle.png"));
	textures.push_back(loadTexture("blockred.png"));
	textures.push_back(loadTexture("blockblue.png"));
	textures.push_back(loadTexture("ball.png"));

	god	= new Engine();

	paddle	= new Paddle(-(paddleWidth/2),losingBound,0.0f,paddleWidth,paddleHeight,2.0f, textures[0], paddleSpeed);
	god->add(paddle);

	ball	= new BreakoutBall(0.0f, losingBound + (2 * ballRadius), -(ballRadius/2), ballRadius, textures[3], ballSpeed);
	god->add(ball);

	for(int i = 0; i < numOfRows; i++)
	{
		vector<Brick*>* newRow = new vector<Brick*>();
		for(int k = 0; k < numOfCols; k++)
		{
			newRow->push_back(new Brick(startingX + (blockWidth + seperationX)*k, 
								startingY + (blockHeight + seperationY)*i, 
								0.0f,
								blockWidth,
								blockHeight,
								2.0f,
								textures[1]	));
			god->add(newRow->back());
		}
		blocks.push_back(newRow);
	}

	ball->start();
}



void handleInputs()
{
	paddle->handleInputs(isPressed);
}

void update(float DT)
{
	god->update(DT);

	if(ball->x > 40.0f || ball->x < -40.0f) {
		ball->flipVX(); 
		ball->x = 40.0f * abs(ball->x)/ball->x; //this works because x is always negative for the lower bound.
	}	
	if(ball->y > 40.0f || ball->y < -40.0f) {	
		ball->flipVY();
		ball->y = 40.0f * abs(ball->y)/ball->y;	//this works because y is always negative for the lower bound.
	}

	paddle->update(DT);
	ball->update(DT);

	cerr <<"start update rows:" << endl;
	for(vector<vector<Brick*>* >::iterator p = blocks.begin(); p!= blocks.end(); p++)
	{
		for(vector<Brick*>::iterator q = (*p)->begin(); q!= (*p)->end(); q++){
			if((*q)->hasDied) {
				god->remove(*q);
				delete *q;
				(*p)->erase(q);
				cerr << "cols:" << (*p)->size() << endl;
				break;
			}
		}
	}
}

void draw()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	//clear screen.

	glLoadIdentity();
	glTranslatef(0,0,-100);		//translate

	paddle->draw();
	ball->draw();

	for(vector<vector<Brick*>* >::iterator p = blocks.begin(); p!= blocks.end(); p++)
		for(vector<Brick*>::iterator q = (*p)->begin(); q!= (*p)->end(); q++)
			(*q)->draw();

	SDL_GL_SwapBuffers();	//places objects in memory on the screen.
}

void mainloop()
{
	while(true)	//encapsulates everything!
	{
		if(true)//only when a tick happens.
		{		
			float DT;
			while((DT = updateReady()) != 0.0f) {
				processEvents(isPressed);
				handleInputs();
				update(DT);
			}
			draw();
		}
	}
}

void cleanup()
{
	delete god;

	delete paddle;

	delete ball;

	for(vector<vector<Brick*>* >::iterator p = blocks.begin(); p!= blocks.end(); p++)
	{
		for(vector<Brick*>::iterator q = (*p)->begin(); q!= (*p)->end(); q++){
			delete *q;
		}
		delete *p;
	}

	SDL_Quit();
	exit(0);
}

int main()
{
	setupGL(640, 480, GL_FILL);
	initialize();

	mainloop();

	cleanup();
}
