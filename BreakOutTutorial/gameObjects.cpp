//////////////////////////
//standard library	//
//////////////////////////
#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

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
	#include "gameObjects.h"
#endif
#ifndef GAMEOBJECTS_H
	#include "glUtilities.h"
#endif

using namespace std;

/////////////////////////
//Classes              //
/////////////////////////
///////
//Box//
///////
		Box::Box(float X,float Y,float Z,float Width,float Height,float Depth, BoxType boxtype)
			:x(X), y(Y), z(Z), width(Width), height(Height), depth(Depth), boxType(boxtype)
		{}

		//who needs properties... just make functions!
		//Box.origin() will give the x,y,z origin of the box in point form. box.origin(point) will set it from a point.
		Point3f Box::origin()
		{
			return Point3f(x,y,z);
		}
		void Box::origin(Point3f Origin)
		{
			x = Origin.x;
			y = Origin.y;
			z = Origin.z;
		}


		Point3f Box::topLeftPoint()
		{
			return Point3f(x,y+height,z);
		}
		Point3f Box::topRightPoint()
		{
			return Point3f(x+width,y+height,z);
		}
		Point3f Box::bottomRightPoint()
		{
			return Point3f(x+width,y,z);
		}
		Point3f Box::bottomLeftPoint()
		{
			return origin();
		}

		void Box::onCollide(Side::side collisionSide, Box* boxCollidedWith){}
///////
///////
///////

//////////
//Engine//
//////////
		Engine::Engine()
		{}

		void Engine::add(Box* thing)
		{
			things.push_back(thing);		
		}

		void Engine::remove(Box* thing)
		{
			std::remove(things.begin(), things.end(), thing);
		}

		void Engine::update(float DT)
		{
			//check every box against every other box.
			//for iterator.
			//if then handleCollision.

			Side::side tempCollisionSide;
			for(int i=0; i<things.size()-1; i++)
				for(int k=i+1; k<things.size(); k++)
					handlePossibleCollision(things[i], things[k]);
		}

		void Engine::handleCollision(Box* thingA, Box* thingB, Side::side collisionSide)
		{	
			cerr << "doing a collision... " << thingA->boxType << " - " << thingB->boxType << "collisionSide = " << collisionSide << endl;
			cerr << "thingA->x = " << thingA->x << "thingA->y = " << thingA->y << "thingA->width = " << thingA->width << "thingA->height = " << thingA->height << endl;
			
			thingA->onCollide(collisionSide, thingB);
			cerr << "done onCollide for A, now doing B..." << endl;
			switch(collisionSide)
			{
				case Side::left:	thingB->onCollide(Side::right, thingA);		break;
				case Side::right:	thingB->onCollide(Side::left, thingA);		break;
				case Side::top:		thingB->onCollide(Side::bottom, thingA);	break;
				case Side::bottom:	thingB->onCollide(Side::top, thingA);		break;
				default:	cerr << "handleCollision is coded wrong =/." << endl;
			}
			cerr << "finishing a collision..." << endl;
		}

		//we will return an enum for left right top or bottom. 
		void Engine::handlePossibleCollision(Box* thingA, Box* thingB)
		{
			pair<Point3f, Box*>* pointBoxTemp;

			//if their was a collision...
			if((pointBoxTemp = pointInsideBox(thingA, thingB)))
			{
				//extract the *point* inside the *box* from the returned pair.
				Point3f point	= pointBoxTemp->first;
				Box*	box1	= pointBoxTemp->second;
				Box*	box2	= (box1==thingA) ? thingB : thingA;

				delete pointBoxTemp; 			//we're done with the pair.

				//what's closer? A horizontal line or a vertical line?
				if(box1->topRightPoint().x - point.x <= box1->topRightPoint().y - point.y)
				{
					//what's closer? The left or the right?
					if((box1->x + (box1->width/2)) - point.x >= 0)
						handleCollision(box1, box2, Side::right);
					else
						handleCollision(box1, box2, Side::left);			
				}
				else
				{
					if((box1->y + (box1->height/2)) - point.y <= 0)
						handleCollision(box1, box2, Side::top);
					else
						handleCollision(box1, box2, Side::bottom);
				}
			}
		}

		//looks at two boxes and returns what point is in what box if their are any. Returns null if none are found.
		pair<Point3f, Box*>* Engine::pointInsideBox(Box* thingA, Box* thingB)
		{
			if	(isPointInSquare(thingA->x			,thingA->y			, thingB))
				return new pair<Point3f, Box*>(thingA->bottomLeftPoint()	,thingB);
			else if	(isPointInSquare(thingA->x			,thingA->y + thingA->height	, thingB))
				return new pair<Point3f, Box*>(thingA->topLeftPoint()	,thingB);
			else if	(isPointInSquare(thingA->x + thingA->width	,thingA->y + thingA->height	, thingB))
				return new pair<Point3f, Box*>(thingA->topRightPoint()	,thingB);
			else if	(isPointInSquare(thingA->x + thingA->width	,thingA->y			, thingB))
				return new pair<Point3f, Box*>(thingA->bottomRightPoint(),thingB);

			if	(isPointInSquare(thingB->x			,thingB->y			, thingA))
				return new pair<Point3f, Box*>(thingB->bottomLeftPoint()	,thingA);
			else if	(isPointInSquare(thingB->x			,thingB->y + thingB->height	, thingA))
				return new pair<Point3f, Box*>(thingB->topLeftPoint()	,thingA);
			else if	(isPointInSquare(thingB->x + thingB->width	,thingB->y + thingB->height	, thingA))
				return new pair<Point3f, Box*>(thingB->topRightPoint()	,thingA);
			else if	(isPointInSquare(thingB->x + thingB->width	,thingB->y			, thingA))
				return new pair<Point3f, Box*>(thingB->bottomRightPoint(),thingA);

			return NULL;
		}

		bool Engine::isPointInSquare(float X,float Y, Box* square)
		{
			return 
				X	>	square->x 
				&& X	<	square->x + square->width
				&& Y	>	square->y
				&& Y	<	square->y + square->height;
		}
////////////////////////////////////////////////////////
//The following is Unnecessary. Used for explanations.//
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
		//remember to check both ways. if a square is entirely in another, then a one way check may be incorrect.
		//________
		//|       |
		//|       |
		//|   __  |
		//|___| |_|
		//    |_|
    
		//first figure out how we decide that their was a collision
		bool Engine::haveCollided(Box* thingA, Box* thingB)
		{
			//We will manually check every point of thingA to see if it is within the bounds of thingB and vice versa.
			//To make things simpler we will ignore z.
			
			return  //check if points in A are in B
				isPointInSquare(thingA->x			,thingA->y			, thingB)
				||
				isPointInSquare(thingA->x			,thingA->y + thingA->height	, thingB)
				||
				isPointInSquare(thingA->x + thingA->width	,thingA->y + thingA->height	, thingB)
				||
				isPointInSquare(thingA->x + thingA->width	,thingA->y			, thingB)

				//check if point in B are in A
				||
				isPointInSquare(thingB->x			,thingB->y			, thingA)
				||
				isPointInSquare(thingB->x			,thingB->y + thingA->height	, thingA)
				||
				isPointInSquare(thingB->x + thingA->width	,thingB->y + thingA->height	, thingA)
				||
				isPointInSquare(thingB->x + thingA->width	,thingB->y			, thingA);
		}

//////////
//////////
//////////

/////////
//Block//
/////////
		Block::Block(float X, float Y, float Z, float Width, float Height, float Depth, GLuint Texture, BoxType boxtype)
			: Box(X,Y,Z,Width,Height,Depth, boxtype), texture(Texture), vx(0), vy(0), vz(0)
		{}

		void Block::onCollide(Side::side collisionSide, Box* boxCollidedWith)
		{
			switch(collisionSide)
			{
				case Side::left:	cerr << "block: ball hit our left" << endl;	break;
				case Side::right:	cerr << "block: ball hit our right" << endl;	break;
				case Side::top:		cerr << "block: ball hit our top" << endl;	break;
				case Side::bottom:	cerr << "block: ball hit our bottom" << endl;	break;
			}
		}

		void Block::update(float DT)
		{
			const float secondsPassed = DT / MILLISECONDS_IN_A_SECOND; //convert DT to seconds before applying it to vx.
			x += vx*(secondsPassed);
			//cerr << "DT = " << DT << "secondPassed = " << secondsPassed << ", paddle->vx = " << vx << ",paddle->x = " << x << endl;
			y += vy*(secondsPassed);
			z += vz*(secondsPassed);
		}

		void Block::draw()
		{
			if(texture)
				glBindTexture(GL_TEXTURE_2D, texture);

			glBegin(GL_QUADS);
				if(texture) glTexCoord2f(0,0);
				glVertex3f(x, y, z);		//bottom-left
				if(texture) glTexCoord2f(0,1);
				glVertex3f(x, y+height, z);	//top-left
				if(texture) glTexCoord2f(1,1);
				glVertex3f(x+width, y+height, z);	//top-right
				if(texture) glTexCoord2f(1,0);
				glVertex3f(x+width, y, z);		//bottom-right

				//if(texture) glNormal3f(0.0f,0.0f,1.0f);
			glEnd();

			glBegin(GL_QUADS);
				if(texture) glTexCoord2f(0,0);
				glVertex3f(x, y, z-depth);		//bottom-left
				if(texture) glTexCoord2f(0,1);
				glVertex3f(x, y+height, z-depth);	//top-left
				if(texture) glTexCoord2f(1,1);
				glVertex3f(x+width, y+height, z-depth);	//top-right
				if(texture) glTexCoord2f(1,0);
				glVertex3f(x+width, y, z-depth);		//bottom-right

				//if(texture) glNormal3f(0.0f,0.0f,-1.0f);
			glEnd();

			glBegin(GL_QUADS);
				if(texture) glTexCoord2f(0,0);
				glVertex3f(x, y, z-depth);
				if(texture) glTexCoord2f(0,1);
				glVertex3f(x, y+height, z-depth);
				if(texture) glTexCoord2f(1,1);
				glVertex3f(x, y+height, z);
				if(texture) glTexCoord2f(1,0);
				glVertex3f(x, y, z);

				//if(texture) glNormal3f(-1.0f,0.0f,0.0f);
			glEnd();

			glBegin(GL_QUADS);
				if(texture) glTexCoord2f(0,0);
				glVertex3f(x+width, y, z-depth);
				if(texture) glTexCoord2f(0,1);
				glVertex3f(x+width, y+height, z-depth);
				if(texture) glTexCoord2f(1,1);
				glVertex3f(x+width, y+height, z);
				if(texture) glTexCoord2f(1,0);
				glVertex3f(x+width, y, z);

				//if(texture) glNormal3f(1.0f,0.0f,0.0f);
			glEnd();

			glBegin(GL_QUADS);
				if(texture) glTexCoord2f(0,0);
				glVertex3f(x, y, z);
				if(texture) glTexCoord2f(0,1);
				glVertex3f(x, y, z-depth);
				if(texture) glTexCoord2f(1,1);
				glVertex3f(x+width, y, z-depth);
				if(texture) glTexCoord2f(1,0);
				glVertex3f(x+width, y, z);

				//if(texture) glNormal3f(0.0f,-1.0f,0.0f);	
			glEnd();

			glBegin(GL_QUADS);
				if(texture) glTexCoord2f(0,0);
				glVertex3f(x, y+height, z);
				if(texture) glTexCoord2f(0,1);
				glVertex3f(x, y+height, z-depth);
				if(texture) glTexCoord2f(1,1);
				glVertex3f(x+width, y+height, z-depth);
				if(texture) glTexCoord2f(1,0);
				glVertex3f(x+width, y+height, z);	
			
				//if(texture) glNormal3f(0.0f,1.0f,0.0f);
			glEnd();

		}
/////////
/////////
/////////

/////////
//Brick//
/////////
		Brick::Brick(float X, float Y, float Z, float Width, float Height, float Depth, GLuint Texture, BoxType boxtype)
			: Block( X,  Y,  Z,  Width,  Height,  Depth,  Texture,  boxtype), hasDied(false)
		{}

		void Brick::onCollide(Side::side collisionSide, Box* boxCollidedWith)
		{	cerr << "**onCollide for Brick happened?**" << endl;
			if(boxCollidedWith->boxType == Box::box_ball)
				hasDied = true;	
		}
/////////
/////////
/////////
		Paddle::Paddle(float X, float Y, float Z, float Width, float Height, float Depth, GLuint Texture, float StrafeSpeed, BoxType boxtype)
			: Block( X,  Y,  Z,  Width,  Height,  Depth,  Texture,  boxtype), strafeSpeed(StrafeSpeed)
		{}

		void Paddle::handleInputs(KeyStates& keys)
		{
			vx = 0;

			if(keys.z)
				vx -= 	strafeSpeed;

			if(keys.x)
				vx += 	strafeSpeed;
		}
////////
////////
////////

////////////////
//BreakoutBall//
////////////////

		BreakoutBall::BreakoutBall(float X, float Y, float Z, float Radius, GLuint Texture = 0, float Speed=0, BoxType boxtype)
			:Box(X,Y,Z,Radius,Radius,Radius,boxtype), radius(Radius), texture(Texture), speed(Speed), angleFromPosX(0.0f), isMoving(false) 
				,vz(0), vx(0), vy(0)	
		{
			quadratic	= gluNewQuadric();		// Create A Pointer To The Quadric Object
			gluQuadricNormals (quadratic, GLU_SMOOTH);	// Create Smooth Normals
			gluQuadricTexture (quadratic, GL_TRUE);		// Create Texture Coords
		}

		void BreakoutBall::start()
		{
			angleFromPosX	= M_PI / 4.0f;	//pi over 4, is 45 degrees
			isMoving	= true;
		}

		void BreakoutBall::onCollide(Side::side collisionSide, Box* boxCollidedWith)
		{
			switch(collisionSide)
			{
				case Side::left:	cerr << "ball: block hit our left" << endl;
							if(vx < 0.0f)	//this helps stop crazy glitchyness
								flipVX();
							break;

				case Side::right:	cerr << "ball: block hit our right" << endl;
							if(vx > 0.0f)
								flipVX();
							break;

				case Side::top:		cerr << "ball: block hit our top" << endl;
							if(vy > 0.0f)
								flipVY();
							break;

				case Side::bottom:	cerr << "ball: block hit our bottom" << endl;
							if(vy < 0.0f)
							{
								if(boxCollidedWith->boxType == Box::box_paddle)
								{
									//put this in its own functions
									vx = -(((boxCollidedWith->x + (boxCollidedWith->width/2)) - x) 
											/ (boxCollidedWith->width/2)) * speed;		
									vy = (1 - abs(((boxCollidedWith->x + (boxCollidedWith->width/2)) - x) 
											/ (boxCollidedWith->width/2))) * speed;
									recalculateAngle();
								}	
								else
									flipVY();
							}
							break;
			}
		}

		void BreakoutBall::update(float DT)
		{
			if(isMoving)
			{
				vx = cos(angleFromPosX) * speed;
				vy = sin(angleFromPosX) * speed;
				//cerr << "vx = " << vx << ", vy = " << vy << ", vz = " << vz << ",z = " << z << ", speed = " << speed << endl;

				const float secondsPassed = DT / MILLISECONDS_IN_A_SECOND; //convert DT to seconds before applying it to vx.
				x += vx*secondsPassed;
				y += vy*secondsPassed;
				z += vz*secondsPassed;			
			}
		}

		void BreakoutBall::flipVX()
		{
			vx *= -1;
			recalculateAngle();
		}

		void BreakoutBall::flipVY()
		{
			vy *= -1;
			recalculateAngle();
		}

		void BreakoutBall::recalculateAngle()
		{
			angleFromPosX = atan2(vy, vx);
		}

		void BreakoutBall::draw()
		{
			if(texture)
				glBindTexture(GL_TEXTURE_2D, texture);

			glTranslatef(x,y,z);
			gluSphere(quadratic,radius,32,32);
			glTranslatef(-x,-y,-z);
		}
//////////
//////////
//////////
