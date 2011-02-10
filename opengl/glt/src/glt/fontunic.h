#ifndef GLT_FONTUNIC_H
#define GLT_FONTUNIC_H

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
    \brief OpenGL Unicode Font Class
    \ingroup GLT
    
    $Id: fontunic.h,v 1.14 2002/10/07 16:27:46 nigels Exp $
    
    $Log: fontunic.h,v $
    Revision 1.14  2002/10/07 16:27:46  nigels
    Added CVS version control info

    
*/

#include <glt/config.h>
#include <glt/font.h>
#include <glt/dlcache.h>

#include <iosfwd>
#include <string>

/*! \class GltFontUnicode
    \brief OpenGL Unicode Font Class
    \ingroup GLT
*/
 
class GltFontUnicode : public GltFont, private GltDisplayListCache
{
public:
	/// Constructor
	GltFontUnicode(void *data = NULL);
	/// Destructor
	~GltFontUnicode();

	void init(void *);	
	void clear(); 

	bool print(const wchar_t ch) const;
	bool print(const std::wstring &str) const;
	int  width(const wchar_t ch) const;

	//
	// Convert between raw font data and a GLTU buffer
	// 

	static bool  makeHeader(std::string &header,const int compressed);
	static void *getHeader(const void * const h,int &compressed);

private:

	void OnDraw(const uint32 seed) const;

	//

	unsigned char *_data;
	unsigned int   _index[0x10001];
};

#endif
