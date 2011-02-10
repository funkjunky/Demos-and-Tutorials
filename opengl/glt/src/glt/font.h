#ifndef GLT_FONT_H
#define GLT_FONT_H

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
    \brief OpenGL Font Interface
    \ingroup GLT

    $Id: font.h,v 1.14 2002/10/07 16:27:46 nigels Exp $

    $Log: font.h,v $
    Revision 1.14  2002/10/07 16:27:46  nigels
    Added CVS version control info


*/

#include <glt/config.h>
#include <glt/gl.h>

#include <misc/string.h>

class GltFont;

/*! \class GltFont
    \brief Abstract base class for bitmap fonts
    \ingroup GLT
*/
 
class GltFont
{
public:

	//
	// Constructor/Destructor
	//

	/// Constructor
	GltFont();
	/// Destructor
	virtual ~GltFont();

private:
	/// Private copy constructor to prevent copying
	GltFont(const GltFont &);
	/// Private assignment operator to prevnt copying
	GltFont &operator=(const GltFont &);

public:

	/// Initialise font using current OpenGL context.
	virtual void init(void *) = 0; 
	/// Free all OpenGL resources (textures and display lists)
	virtual void clear() = 0; 

	/// Print a character at the current OpenGL raster position
	virtual bool print(const wchar_t ch) const = 0;
	/// Print a string at the current OpenGL raster position
	virtual bool print(const std::wstring &str) const = 0;

	/// Get the size (in pixels) of a string
	virtual void size(int &width,int &height,const std::wstring &str) const;
	/// Get the width of a particular character
	virtual int width(const wchar_t ch) const;

	/// Maximum horizontal distance between characters
	const int hStep()  const;	
	/// Maximum vertical distance between characters
	const int vStep()  const;	

protected:

	int   _hStep;
	int   _vStep;
	bool  _init;
};

#endif
