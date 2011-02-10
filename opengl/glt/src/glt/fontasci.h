#ifndef GLT_FONTASCI_H
#define GLT_FONTASCI_H

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
    \brief   Ascii OpenGL Font Interface
    \ingroup GLT

    $Id: fontasci.h,v 1.11 2002/10/07 16:27:46 nigels Exp $

    $Log: fontasci.h,v $
    Revision 1.11  2002/10/07 16:27:46  nigels
    Added CVS version control info

*/

#include <glt/config.h>
#include <glt/font.h>

/*! \class GltFontAscii
    \brief GLT ASCII font class
    \ingroup GLT

    Fonts here are borrowed from the collection
    by Yossi Gil:
    http://www.simtel.net/pub/simtelnet/msdos/screen/fntcol16.zip
*/
 
class GltFontAscii : public GltFont
{
public:
	/// Constructor
	GltFontAscii(void *data = NULL);
	/// Destructor
	~GltFontAscii();

	void init(void *);	
	void clear(); 

	bool print(const wchar_t ch) const;
	bool print(const std::wstring &str) const;

	//
	// Convert between raw font data and a GLTF buffer
	//

	static bool  makeHeader(std::string &header,const int width,const int height);
	static void *getHeader(const void * const h,int &width,int &height);

private:

	bool print(const char ch) const;		
	bool print(const std::string &str) const;

	void compileLists(void *);

	int   _width;
	int   _height;
	int   _listBase;
};

#endif
