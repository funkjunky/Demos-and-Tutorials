#ifndef GLT_FONTTEX_H
#define GLT_FONTTEX_H

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
    \brief   Textured OpenGL Font 
    \ingroup GLT

    $Id: fonttex.h,v 1.2 2002/10/07 16:27:46 nigels Exp $

    $Log: fonttex.h,v $
    Revision 1.2  2002/10/07 16:27:46  nigels
    Added CVS version control info

*/

#include <glt/config.h>

#include <glt/font.h>
#include <glt/texture.h>

/*! \class GltFontTexture
    \brief GLT Textured font class
    \ingroup GLT

	Based on Mark Kilgard's article and code:

    A Simple OpenGL-based API for Texture Mapped Text
    http://www.opengl.org/developers/code/mjktips/TexFont/TexFont.html
*/
 
class GltFontTexture : public GltFont
{
public:
	/// Constructor
	GltFontTexture(void *data = NULL);
	/// Destructor
	~GltFontTexture();

	void init(void *);	
	void clear(); 

	bool print(const wchar_t ch) const;
	bool print(const std::wstring &str) const;
	int  width(const wchar_t ch) const;

	//
	// Convert between raw font data and a GLTF buffer
	//

	static bool  makeHeader(std::string &header,const int width,const int height);
	static void *getHeader(const void * const h,int &width,int &height);

private:

	typedef struct 
	{
		uint16 glyph;
		byte   width;
		byte   height;
		char   xoffset;
		char   yoffset;
		char   advance;
		char   dummy;			// Ensure 32-bit alignment
		int16  x;
		int16  y;
	} 
	GlyphInfo;

	typedef struct 
	{
		GLfloat t0[2];
		GLshort v0[2];
		GLfloat t1[2];
		GLshort v1[2];
		GLfloat t2[2];
		GLshort v2[2];
		GLfloat t3[2];
		GLshort v3[2];
		byte    width;
		GLfloat advance;
	} 
	GlyphVertexInfo;

	//

	bool print(const char ch) const;		
	bool print(const std::string &str) const;

	void compileLists(void *);

	GltTexture _texture;
	int32      _maxAscent;
	int32      _maxDescent;
	int32      _numGlyphs;
	int32      _minGlyph;
	int32      _range;

	GlyphInfo         *_glyph;
	GlyphVertexInfo   *_glyphVertex;
	GlyphVertexInfo  **_glyphLut;

//	int   _width;
//	int   _height;
//	int   _listBase;
};

#endif
