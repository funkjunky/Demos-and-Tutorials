#include "info.h"

/*! \file 
    \ingroup GLT
    \todo i2string
    
    $Id: info.cpp,v 1.7 2002/10/09 15:09:38 nigels Exp $
    
    $Log: info.cpp,v $
    Revision 1.7  2002/10/09 15:09:38  nigels
    Added RCS Id and Log tags


*/

#include <glt/gl.h>
#include <glt/error.h>
#include <misc/config.h>

#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
using namespace std;

#ifdef GLT_ZLIB
#include <zlib.h>
#endif

#ifdef GLT_PNG
#include <png.h>
#endif

/// Utility function for converting integers to strings
static string i2string(const int i)
{
	char buffer[100];
	sprintf(buffer,"%d",i);
	return buffer;
}

string GltInfo()
{
	string str;

	GLERROR;

	str += "          Vendor : ";
	str += (char *) glGetString(GL_VENDOR);
	str += '\n';
	
	str += "        Renderer : ";
	str += (char *) glGetString(GL_RENDERER);
	str += '\n';

	str += "         Version : ";
	str += (char *) glGetString(GL_VERSION);
	str += '\n';

	GLint doubleBuffering;
	GLint rgbaMode;
	GLint zDepth;
	GLint stencilDepth;

	glGetIntegerv(GL_DOUBLEBUFFER,&doubleBuffering);
	glGetIntegerv(GL_RGBA_MODE,&rgbaMode);
	glGetIntegerv(GL_DEPTH_BITS,&zDepth);
	glGetIntegerv(GL_STENCIL_BITS,&stencilDepth);

	GLERROR

	str += "Double-buffering : ";
	str += (doubleBuffering ? "" : "not " );
	str += "supported.\n";

	str += "       RGBA mode : ";
	str += (rgbaMode ? "" : "not " );
	str += "enabled.\n";
	
	str += "    Depth buffer : ";
	str += i2string(zDepth);
	str += " bit-planes.\n";

	str += "  Stencil buffer : ";
	str += i2string(stencilDepth);
	str += " bit-planes.";

	return str;
}

string GltDate()
{
	time_t clock;
	time(&clock);
	return asctime(localtime(&clock));
}

string GltVersion()
{
	return GLT_VERSION_STRING;
}

string GltVersionInformation()
{
	string str;

	str += "GLT    " + GltVersion() + "\n";

	#ifdef GLT_ZLIB
	str += "zLib   " + string(ZLIB_VERSION) + "\n";
	#endif

	#ifdef GLT_PNG
	str += "libPNG " + string(PNG_LIBPNG_VER_STRING) + "\n";
	#endif

	return str;
}
