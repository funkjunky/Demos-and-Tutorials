#ifndef GLUTM_CONFIG_H
#define GLUTM_CONFIG_H

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
	\brief   GlutMaster configuration file
	\ingroup GlutMaster
	\note    Depends on <glt/config.h> for Win32/Unix detection.
	\note    Open Inventor support can be configured here.
*/

#include <glt/config.h>

#ifdef GLT_WIN32
#define GLUTM_WIN32
#endif

#ifdef GLT_UNIX
#define GLUTM_UNIX
#endif

// GLUTM_OPEN_INVENTOR		Define this for SGI OSS Open Inventor support
// GLUTM_RAYPP              Define this for Ray++ Raytracing support
// GLUTM_DEBUG				Define this for debug info 
// GLUTM_SAVER				Define this for WIN32 screen saver
// GLUT_STATIC				Define this to link GLUT statically

#ifdef GLUTM_WIN32
//#define GLUTM_OPEN_INVENTOR
//#define GLUTM_RAYPP
//#define GLUTM_SAVER
#define GLUT_STATIC
#endif

#ifdef GLUTM_UNIX
//#define GLUTM_OPEN_INVENTOR
//#define GLUTM_RAYPP
//#define GLUTM_DEBUG
#endif

//
//

#ifdef GLUTM_SAVER
#pragma comment (lib, "scrnsave")
#pragma comment (lib, "advapi32")
#pragma comment (lib, "winmm")
#endif

#endif
