#ifndef MISC_TEXT2SRC_H
#define MISC_TEXT2SRC_H

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
	\brief   Routines for converting data to C/C++ source code
	\ingroup Misc
*/

#include <glt/config.h>

#include <iosfwd>

/*! 
	\brief		Convert text to C/C++ source code
	\ingroup	Misc
*/
void text2source  (std::ostream &os,std::istream &is);

/*! 
	\brief		Convert binary data to C/C++ source code
	\ingroup	Misc
*/
void binary2source(std::ostream &os,std::istream &is);



#endif
