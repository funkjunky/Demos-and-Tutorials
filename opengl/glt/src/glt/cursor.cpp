#include "cursor.h"

/*! \file 
    \ingroup GLT
    
    $Id: cursor.cpp,v 1.7 2002/10/09 15:09:38 nigels Exp $
    
    $Log: cursor.cpp,v $
    Revision 1.7  2002/10/09 15:09:38  nigels
    Added RCS Id and Log tags


*/

#include <glt/font.h>
#include <glt/viewport.h>
#include <glt/error.h>

using namespace std;

GltCursor::GltCursor(const GltFont &font,const GltViewport &area)
: _font(font), _area(area) // , _y(0)
{
	GLERROR

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glPushAttrib(GL_VIEWPORT_BIT);

		GLERROR

		_area.set();

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0,GLdouble(area.width()),GLdouble(area.height()-1),-1.0,-1.0,1.0);

		GLERROR

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		GLERROR

//		_y = 0;
		glRasterPos2i(0,0);

		GLERROR
}

GltCursor::~GltCursor()
{
	GLERROR

	glPopAttrib();
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	GLERROR
}

void
GltCursor::print(const string &str)
{
	wstring s;
	string2wstring(s,str);
	print(s);
}

void
GltCursor::print(const wstring &str)
{
	wstring s;
	dos2unix(s,str);
	
	wstring::size_type i=0;
	wstring::size_type j=0;
	
	do
	{
		j = s.find('\n',i);
		if (j==wstring::npos)
		{
			printLine(s.substr(i));
			return;
		}

		printLine(s.substr(i,j-i));
		i = j+1;

	} while (j!=wstring::npos);
}

void 
GltCursor::printLine(const wstring &str)
{
	GLERROR

	// We set the raster position before drawing
	// any text because we want to apply the 
	// current color.

//	glRasterPos2i(0,_y);
	_font.print(str);
//	_y += _font.vStep();
//	glRasterPos2i(0,_y);

	// We set the raster position after drawing 
	// so that other routines can make use of the
	// current position.

	GLERROR
}

