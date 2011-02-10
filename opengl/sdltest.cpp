#include "SDL/SDL.h"

int main(int argc, char* argv[])
{
	//fireup SDL, starting all subsystems,.
		SDL_Init(SDL_INIT_EVERYTHING);
	//now shut it down
		SDL_Quit(); 

	return 0;
}
