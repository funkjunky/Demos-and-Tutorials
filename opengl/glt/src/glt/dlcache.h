#ifndef GLT_DLCACHE_H
#define GLT_DLCACHE_H

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
    \brief   Display List Cache
    \ingroup GLT

    $Id: dlcache.h,v 1.5 2002/10/07 16:27:46 nigels Exp $

    $Log: dlcache.h,v $
    Revision 1.5  2002/10/07 16:27:46  nigels
    Added CVS version control info


*/

#include <glt/gl.h>
#include <glt/config.h>
#include <misc/lru.h>

#ifdef GLT_WIN32
#pragma warning(disable : 4786)     
#endif

#include <vector>
//#include <map>

///////////////////////////// GltDisplayListCache //////////////////////////////////

/*! \class   GltDisplayListCache 
	\brief   Display List Cache
	\ingroup GLT
*/

class GltDisplayListCache
{
public:
	GltDisplayListCache(const uint32 capacity = 100);
	virtual ~GltDisplayListCache();

	void draw(const uint32 seed);
	void clear();

	virtual void OnDraw(const uint32 seed) const = 0;

private:

	uint32              _capacity;
	lru<uint32,GLuint>  _lru;
	std::vector<GLuint> _lists;
};

#endif

