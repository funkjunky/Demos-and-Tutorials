#ifndef GLT_CURSOR_H
#define GLT_CURSOR_H

/*

  GLT OpenGL C++ Toolkit      
  Copyright (C) 2000-2002 Nigel Stewart
  Email: nigels@nigels.com   WWW: http://www.nigels.com/glt/

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

/*! \file 
    \brief OpenGL Cursor Interface
    \ingroup GLT

    $Id: cursor.h,v 1.7 2002/10/07 16:27:46 nigels Exp $

    These functions manage the raster position, and provide
    a wrapper for the OpenGL font routines.
  
    Part of the Glt C++ OpenGL Library
    http://www.nigels.com/glt/
 
    \author  Nigel Stewart (nigels@nigels.com)
    \author  RMIT Dept. Mechanical and Manufacturing Engineering, Australia

    $Log: cursor.h,v $
    Revision 1.7  2002/10/07 16:27:46  nigels
    Added CVS version control info


*/

class GltFont;
class GltViewport;

#include <misc/string.h>

/*! \class   GltCursor
    \brief   Cursor position class
    \ingroup GLT
*/

class GltCursor
{
public:
	/// Constructor
	GltCursor(const GltFont &font,const GltViewport &area);
	/// Destructor
	~GltCursor();

	/// Print a string at the current position
	void print(const std::string  &str);
	/// Print a wide string at the current position
	void print(const std::wstring &str);

private:

	const GltFont     &_font;
	const GltViewport &_area;

//	int       _y;

	void printLine(const std::wstring &str);
};

#endif
