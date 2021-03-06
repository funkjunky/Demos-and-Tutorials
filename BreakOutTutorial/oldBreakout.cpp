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

using namespace std;

#define MILLISECONDS_IN_A_SECOND 1000

////////////////////////////////
/*Some Function Prototypes    */
////////////////////////////////

void cleanup();


/////////////////////////
//structures and enums///
/////////////////////////
namespace Side{
	enum side {none, left, right, top, bottom};
}

struct KeyStates{
	KeyStates()
		:up(false), down(false), left(false), right(false), forward(false), back(false), comma(false), period(false), z(false), x(false)
	{}

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
	Point3f()
		:x(0), y(0), z(0)
	{}

	Point3f(float xx,float yy,float zz)
		:x(xx), y(yy), z(zz)
	{}

	float x,y,z;
};

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

		Box(float X,float Y,float Z,float Width,float Height,float Depth, BoxType boxtype = box_none)
			:x(X), y(Y), z(Z), width(Width), height(Height), depth(Depth), boxType(boxtype)
		{}

		//who needs properties... just make functions!
		//Box.origin() will give the x,y,z origin of the box in point form. box.origin(point) will set it from a point.
		Point3f origin()
		{
			return Point3f(x,y,z);
		}
		void origin(Point3f Origin)
		{
			x = Origin.x;
			y = Origin.y;
			z = Origin.z;
		}


		Point3f topLeftPoint()
		{
			return Point3f(x,y+height,z);
		}
		Point3f topRightPoint()
		{
			return Point3f(x+width,y+height,z);
		}
		Point3f bottomRightPoint()
		{
			return Point3f(x+width,y,z);
		}
		Point3f bottomLeftPoint()
		{
			return origin();
		}

		virtual void onCollide(Side::side collisionSide, Box* boxCollidedWith){}
};

class Engine
{
	public:
		vector<Box*> things;

		Engine()
		{}

		void add(Box* thing)
		{
			things.push_back(thing);		
		}

		void remove(Box* thing)
		{
			std::remove(things.begin(), things.end(), thing);
		}

		void update(float DT)
		{
			//check every box against every other box.
			//for iterator.
			//if then handleCollision.

			Side::side tempCollisionSide;
			for(int i=0; i<things.size()-1; i++)
				for(int k=i+1; k<things.size(); k++)
					handlePossibleCollision(things[i], things[k]);
		}

		void handleCollision(Box* thingA, Box* thingB, Side::side collisionSide)
		{	
			cerr << "doing a collision... " << thingA->boxType << " - " << thingB->boxType << "collisionSide = " << collisionSide << endl;
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
		void handlePossibleCollision(Box* thingA, Box* thingB)
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
		pair<Point3f, Box*>* pointInsideBox(Box* thingA, Box* thingB)
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

		bool isPointInSquare(float X,float Y, Box* square)
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
		bool haveCollided(Box* thingA, Box* thingB)
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
////////////////////////////
////////////////////////////
};

class Block : public Box
{
	public:
		float vx, vy, vz;	//velocity of x y or z. Not only useful for physics, but for keys being held down.
		GLuint texture;

		Block(float X, float Y, float Z, float Width, float Height, float Depth, GLuint Texture = 0, BoxType boxtype = box_none)
			: Box(X,Y,Z,Width,Height,Depth, boxtype), texture(Texture), vx(0), vy(0), vz(0)
		{}

		virtual void onCollide(Side::side collisionSide, Box* boxCollidedWith)
		{
			switch(collisionSide)
			{
				case Side::left:	cerr << "block: ball hit our left" << endl;	break;
				case Side::right:	cerr << "block: ball hit our right" << endl;	break;
				case Side::top:		cerr << "block: ball hit our top" << endl;	break;
				case Side::bottom:	cerr << "block: ball hit our bottom" << endl;	break;
			}
		}

		void update(float DT)
		{
			const float secondsPassed = DT / MILLISECONDS_IN_A_SECOND; //convert DT to seconds before applying it to vx.
			x += vx*(secondsPassed);
			//cerr << "DT = " << DT << "secondPassed = " << secondsPassed << ", paddle->vx = " << vx << ",paddle->x = " << x << endl;
			y += vy*(secondsPassed);
			z += vz*(secondsPassed);
		}

		void draw()
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
};

class Brick : public Block
{
	public:
		int row, col;

		bool hasDied;

		Brick(float X, float Y, float Z, float Width, float Height, float Depth, GLuint Texture = 0, int Row=-1, int Col=-1, BoxType boxtype = box_brick)
			: Block( X,  Y,  Z,  Width,  Height,  Depth,  Texture,  boxtype), row(Row), col(Col), hasDied(false)
		{}

		void onCollide(Side::side collisionSide, Box* boxCollidedWith)
		{	cerr << "**onCollide for Brick happened?**" << endl;
			if(boxCollidedWith->boxType == Box::box_ball)
				hasDied = true;	
		}
};

class Paddle : public Block
{
	public:
		float strafeSpeed;

		Paddle(float X, float Y, float Z, float Width, float Height, float Depth, GLuint Texture, float StrafeSpeed, BoxType boxtype = box_paddle)
			: Block( X,  Y,  Z,  Width,  Height,  Depth,  Texture,  boxtype), strafeSpeed(StrafeSpeed)
		{}

		void handleInputs(KeyStates& keys)
		{
			vx = 0;

			if(keys.z)
				vx -= 	strafeSpeed;

			if(keys.x)
				vx += 	strafeSpeed;
		}
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

		BreakoutBall(float X, float Y, float Z, float Radius, GLuint Texture = 0, float Speed=0, BoxType boxtype = box_ball)
			:Box(X,Y,Z,Radius,Radius,Radius,boxtype), radius(Radius), texture(Texture), speed(Speed), angleFromPosX(0.0f), isMoving(false) 
				,vz(0), vx(0), vy(0)	
		{
			quadratic	= gluNewQuadric();		// Create A Pointer To The Quadric Object
			gluQuadricNormals (quadratic, GLU_SMOOTH);	// Create Smooth Normals
			gluQuadricTexture (quadratic, GL_TRUE);		// Create Texture Coords
		}

		void start()
		{
			angleFromPosX	= M_PI / 4.0f;	//pi over 4, is 45 degrees
			isMoving	= true;
		}

		void onCollide(Side::side collisionSide, Box* boxCollidedWith)
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

		void update(float DT)
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

		void flipVX()
		{
			vx *= -1;
			recalculateAngle();
		}

		void flipVY()
		{
			vy *= -1;
			recalculateAngle();
		}

		void recalculateAngle()
		{
			angleFromPosX = atan2(vy, vx);
		}

		void draw()
		{
			if(texture)
				glBindTexture(GL_TEXTURE_2D, texture);

			glTranslatef(x,y,z);
			gluSphere(quadratic,radius,32,32);
			glTranslatef(-x,-y,-z);
		}
};

/////////////////////
//Utility Functions//
/////////////////////
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

		default: cerr << "unrecognized key..."<<endl;
	}
}

void processEvents(KeyStates& IsPressed, void (*keyHandler)(SDL_keysym*, bool, KeyStates&) = handleKeys)
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

vector<GLuint> 			textures;

Engine*			god;

Paddle* 		paddle;
vector<vector<Brick*>* > blocks;
BreakoutBall* 		ball;

//////////////////////////////
//OpenGL necessary functions//
//////////////////////////////
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
								textures[1],
								i,
								k	));
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
