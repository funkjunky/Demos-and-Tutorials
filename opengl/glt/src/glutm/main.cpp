#include "main.h"

/*! \file 
	\ingroup GlutMaster
*/

#include <glutm/master.h>

#if defined(GLUTM_WIN32) && !defined(GLUTM_SAVER)

#include <windows.h>

int WINAPI   WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpCmdLine,
                     int nCmdShow)
{
	GlutMaster::init();

	std::vector<std::string> arg;  // TODO

	if (GlutMain(arg))
		GlutMaster::mainLoop();

	// Never reaches here, but compiler is happy
	return EXIT_SUCCESS;
}

#endif

int main(int argc,char** argv)
{
	GlutMaster::init(argc,argv);
	
	bool ok;

	{
		// Convert args into vector of strings,
		// and free memory before going into
		// main GLUT loop

		std::vector<std::string> arg(argc);
		for (int i=0; i<argc; i++)
			arg[i] = argv[i];
		
		ok = GlutMain(arg);
	}
	
	if (ok)
		GlutMaster::mainLoop();

	// Never reaches here, but compiler is happy
	return EXIT_SUCCESS;
}



