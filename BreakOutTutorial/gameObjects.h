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
	#include "glUtilities.h"
#endif

#define GAMEOBJECTS_H

/////////////////////////
//structures and enums///
/////////////////////////
namespace Side{
	enum side {none, left, right, top, bottom};
}

/////////////////////////
//Classes              //
/////////////////////////
class Box
{
	public:
		enum BoxType{box_none, box_paddle, box_ball, box_brick};
		
		BoxType boxType;

		float x, y, z;		//position of bottom left corner.
		float width, height, depth;

		Box(float X,float Y,float Z,float Width,float Height,float Depth, BoxType boxtype = box_none);

		Point3f origin();
		void origin(Point3f Origin);
		Point3f topLeftPoint();
		Point3f topRightPoint();
		Point3f bottomRightPoint();
		Point3f bottomLeftPoint();
		virtual void onCollide(Side::side collisionSide, Box* boxCollidedWith);
};

class Engine
{
	public:
		std::vector<Box*> things;

		Engine();
		void add(Box* thing);
		void remove(Box* thing);
		void update(float DT);
		void handleCollision(Box* thingA, Box* thingB, Side::side collisionSide);
		void handlePossibleCollision(Box* thingA, Box* thingB);
		std::pair<Point3f, Box*>* pointInsideBox(Box* thingA, Box* thingB);
		bool isPointInSquare(float X,float Y, Box* square);
		bool haveCollided(Box* thingA, Box* thingB);
};

class Block : public Box
{
	public:
		float vx, vy, vz;	//velocity of x y or z. Not only useful for physics, but for keys being held down.
		GLuint texture;

		Block(float X, float Y, float Z, float Width, float Height, float Depth, GLuint Texture = 0, BoxType boxtype = box_none);
		virtual void onCollide(Side::side collisionSide, Box* boxCollidedWith);
		void update(float DT);
		void draw();
};

class Brick : public Block
{
	public:
		int row, col;

		bool hasDied;

		Brick(float X, float Y, float Z, float Width, float Height, float Depth, GLuint Texture = 0, BoxType boxtype = box_brick);
		void onCollide(Side::side collisionSide, Box* boxCollidedWith);
};

class Paddle : public Block
{
	public:
		float strafeSpeed;

		Paddle(float X, float Y, float Z, float Width, float Height, float Depth, GLuint Texture, float StrafeSpeed, BoxType boxtype= box_paddle);
		void handleInputs(KeyStates& keys);
};

class BreakoutBall : public Box
{
	public:
		float 		vx,vy,vz;
		float 		radius;
		GLuint 		texture;
		GLUquadricObj*	quadratic;
		bool 		isMoving;
		float		speed;
		float		angleFromPosX;	//in radians. cos and sin only work for radians =(.

		BreakoutBall(float X, float Y, float Z, float Radius, GLuint Texture, float Speed, BoxType boxtype = box_ball);
		void start();
		void onCollide(Side::side collisionSide, Box* boxCollidedWith);
		void update(float DT);
		void flipVX();
		void flipVY();
		void recalculateAngle();
		void draw();
};
