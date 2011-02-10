#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>
#include <map>
#include <string>


using namespace std;

struct quad{
	float x[4],y[4],z[4];
	int r,g,b,a;
	string texture;
	bool fulltex;
	float tx[4],ty[4],tz[4];

	quad(float xx[], float yy[], float zz[], 
		int rr=255, int gg=255, int bb=255, int aa=255, string texture1=eof, 
		float txx[]={0}, float tyy[]={0}, float tzz[]={0},bool isfulltex=true)
	:r(rr), g(gg), b(bb), a(aa), texture(texture1)	
	{
		for(int i=0; i<4; i++)
		{
			x[i] = xx[i];
			y[i] = yy[i];
			z[i] = zz[i];
			tx[i] = txx[i];
			ty[i] = tyy[i];
			tz[i] = tzz[i];
		}
		
		fulltex=isfulltex;
	}

	quad(float x, float y, float z, float height, float width)
	{
	}
}

class mygl
{
public:
	mygl()
	{
		upheld=0;
		downheld=0;
		 rightheld=0;
		 leftheld=0;
		 forwardheld=0;
		 backheld=0;
		 x=0;
		 y=0;
		 z=0;
		 atexture=0;
		 height=0;
		 width=0;
	}

	mygl(vector<string> textures, vector<quad> quads, 
		bool lightson=false, bool blendon=false, bool fogon=false)
	{
		//build textures and add them to a map with the strings as keys, and the GLuints as second.
		//pass everything else.
	}

	void processevents();
	
	void processevents()
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
private:
void handlekeys(SDL_keysym*, bool);
void setupGL();

	void setupGL()
	{
		glViewPort(0,0,width,height);
		glMatrixMode(GL_PROJECTION);	//specifies the stack to be used.
		glBlendFunc(GL_SRC_ALPHA,GL_ONE);
		glEnable(GL_BLEND);
		//glEnable(GL_DEPTH_TEST);
		//allows depth buffer to distinguish between surfaces.
		gluPerspective(45, (float)width/height, .1, 100);

		//setup textures			
		glEnable(GL_TEXTURE_2D);
		//add the textures here or something...
	
		//setup lights

		//setup fog

		//cool drawing effects like grids?
		glPolygonMode(GL_BACK, GL_FILL);
		glPolygonMode(GL_FRONT, GL_LINE);
	}

	//handle SDL keypresses
	void handlekeys(SDL_keysym* keysym, bool state)	//key listener. 
	{						//State could be considered whether the key was pressed or released.

		switch(keysym->sym)	//this holds the key that triggered the event.		
		{
			case SDLK_PAGEDOWN:	downheld=state;	break;
			case SDLK_PAGEUP:	forwardheld=state;	break;
			case SDLK_LEFT:		leftheld=state;	break;
			case SDLK_RIGHT: 	rightheld=state;	break;
			case SDLK_DOWN:		downheld=state;	break;
			case SDLK_UP:		upheld=state;	break;
			case SDLK_ESCAPE:	endProgram(0);	//if escape is hit
						break;
			default: cerr << "unrecognized key..."<<endl;
		}
	}


	/**some class variables**/
	bool fogon;
	bool blendon;
	bool lighton;

	bool upheld;
	bool downheld;
	bool rightheld;
	bool leftheld;
	bool forwardheld;
	bool backheld;
	int x;
	int y;
	int z;
	GLuint atexture;
	int height;
	int width;
};

int main()
{
}
