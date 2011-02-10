#ifndef MISC_CONFIG_H
#define MISC_CONFIG_H

/*

  GLT OpenGL C++ Toolkit (LGPL)
  Copyright (C) 2000-2002 Nigel Stewart  

  Email: nigels@nigels.com   
  WWW:   http://www.nigels.com/glt/

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
	\brief   GLT Misc configuration file
	\ingroup Misc
	\note    zLib and PNG support can be configured here
*/

#include <glt/config.h>

// GLT_ZLIB					Define this for zlib support
// GLT_PNG                  Define this for PNG support

#ifdef GLT_WIN32
#define GLT_ZLIB
#define GLT_PNG
#endif

#ifdef GLT_UNIX
#define GLT_ZLIB
#define GLT_PNG
#endif

//

// PNG depends on ZLib

#if defined(GLT_PNG) && !defined(GLT_ZLIB)
#define GLT_ZLIB
#endif

#ifdef GLT_WIN32
#pragma comment (lib, "advapi32")	 // Windows registry interface

#ifdef GLT_ZLIB
#pragma comment(lib, "zlib.lib")      // zLib compression library
#endif

#ifdef GLT_PNG
#pragma comment(lib, "png.lib")      // zLib compression library
#endif

#endif

#endif
