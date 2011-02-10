#include "fonttex.h"

/*! \file 
    \ingroup GLT
    
    $Id: fonttex.cpp,v 1.2 2002/10/09 15:09:38 nigels Exp $
    
    $Log: fonttex.cpp,v $
    Revision 1.2  2002/10/09 15:09:38  nigels
    Added RCS Id and Log tags


*/

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;

#include <misc/endian.h>
#include <misc/image.h>
#include <math/real.h>

GltFontTexture::GltFontTexture(void *data)
{
	if (data)
		init(data);
}

GltFontTexture::~GltFontTexture()
{
	clear();
}

void
GltFontTexture::init(void *data)
{
	clear();

	if (data)
	{
		char *ptr = (char *) data;

		// Check the header

		if (strncmp(ptr,"\377txf",4))
		{
			cerr << "ERROR: Texture font not recognised" << endl;
			return;
		}

		ptr+=4;

		// Check endianness 

		const uint32 code = *reinterpret_cast<uint32 *>(ptr);
		if (code!=0x12345678 && code!=0x78563412)
		{
			cerr << "ERROR: Texture font not recognised" << endl;
			return;
		}

		const bool swap = code==0x78563412;

		ptr+=4;

		_init = true;

		// 

		int32 format = *reinterpret_cast<int32 *>(ptr); ptr+=4;
		int32 width  = *reinterpret_cast<int32 *>(ptr); ptr+=4;
		int32 height = *reinterpret_cast<int32 *>(ptr); ptr+=4;

		_maxAscent  = *reinterpret_cast<int32 *>(ptr); ptr+=4;
		_maxDescent = *reinterpret_cast<int32 *>(ptr); ptr+=4;
		_numGlyphs  = *reinterpret_cast<int32 *>(ptr); ptr+=4;

		if (swap)
		{
			format = flip(format);
			width  = flip(width);
			height = flip(height);

			_maxAscent  = flip(_maxAscent);
			_maxDescent = flip(_maxDescent);
			_numGlyphs  = flip(_numGlyphs);
		}

		// Read glyph info

		_glyph = new GlyphInfo[_numGlyphs];
		memcpy(_glyph,ptr,sizeof(GlyphInfo)*_numGlyphs);
		ptr += sizeof(GlyphInfo)*_numGlyphs;

		uint32 i;
			
		if (swap)
			for (i=0; i<_numGlyphs; i++)
			{
				_glyph[i].glyph = flip(_glyph[i].glyph);
				_glyph[i].x     = flip(_glyph[i].x);
				_glyph[i].y     = flip(_glyph[i].y);
			}

		// Find first and last glyphs

		if (!_numGlyphs)
		{
			cerr << "ERROR: Texture font contains no glyphs" << endl;
			clear();
			return;
		}

		uint16 minGlyph = _glyph[0].glyph;
		uint16 maxGlyph = _glyph[0].glyph;
		
		_hStep = _glyph[0].advance;
		_vStep = _glyph[0].height;

		for (i=1; i<_numGlyphs; i++)
		{
			minGlyph = MIN(minGlyph,_glyph[i].glyph);
			maxGlyph = MAX(maxGlyph,_glyph[i].glyph);
			_hStep = MAX(_hStep,_glyph[i].advance);
			_vStep = MAX(_vStep,_glyph[i].height);
		}

		_minGlyph = minGlyph;
		_range    = maxGlyph - minGlyph + 1;

		// Initialise vertex info

		_glyphVertex = new GlyphVertexInfo[_numGlyphs];
		
		const GLfloat w = width;
		const GLfloat h = height;
		const GLfloat xstep = 0.5f/w;
		const GLfloat ystep = 0.5f/h;

		for (i=0; i<_numGlyphs; i++)
		{
			const GlyphInfo &tgi = _glyph[i];
			GlyphVertexInfo &vi  = _glyphVertex[i];

			// Texture co-ordinates

			{
				const GLfloat left   = tgi.x/w + xstep;
				const GLfloat right  = (tgi.x + tgi.width)/w + xstep;
				const GLfloat bottom = (tgi.y + tgi.height)/h + ystep;
				const GLfloat top    = tgi.y/h + ystep;

				vi.t0[0]   = left;	vi.t0[1]   = top;
				vi.t1[0]   = right;	vi.t1[1]   = top;
				vi.t2[0]   = right;	vi.t2[1]   = bottom;
				vi.t3[0]   = left;	vi.t3[1]   = bottom;
			}

			//

			{
				const GLshort left   = 0;
				const GLshort right  = tgi.width;
				const GLshort bottom = _vStep - tgi.yoffset - tgi.height;
				const GLshort top    = _vStep - tgi.yoffset;

				vi.v0[0]   = left;	vi.v0[1]   = top;
				vi.v1[0]   = right;	vi.v1[1]   = top;
				vi.v2[0]   = right;	vi.v2[1]   = bottom;
				vi.v3[0]   = left;	vi.v3[1]   = bottom;

				vi.advance = tgi.advance;	
				vi.width   = tgi.width;		// Need this for width()
			}
		}

		// Build LUT

		_glyphLut = new GlyphVertexInfo *[_range];
		memset(_glyphLut,0,_range*sizeof(GlyphVertexInfo *));

		for (i=0; i<_numGlyphs; i++) 
			_glyphLut[_glyph[i].glyph-_minGlyph] = _glyphVertex + i;

		//
		const bool mipmap = true;

		switch (format)
		{
		case 0:		// GREYSCALE
			{
				byte *buffer = new byte[width*height*2];
				for (i=0; i<width*height; i++)
					buffer[i*2] = buffer[i*2+1] = ptr[i];
				_texture.init(width,height,buffer,2,mipmap);
				delete [] buffer;
			}
			break;

		case 1:		// BITMAP
			break;
		}
	}
}

void 
GltFontTexture::clear()
{
	if (_init)
	{
		_init = false;

		delete [] _glyph;
		delete [] _glyphVertex;
		delete [] _glyphLut;

		_glyph = NULL;
		_glyphVertex = NULL;
		_glyphLut = NULL;

		_texture.clear();
	}
}

void
GltFontTexture::compileLists(void *data)
{
/*
	if (_listBase==-1 && data)
	{
		GLubyte *ptr = (GLubyte *) data;
		const int bytesPerChar = ((_width+7)>>3)*_height;

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		_listBase = glGenLists(256);
		for (int i = 0; i < 255; i++) 
		{
			glNewList(i+_listBase, GL_COMPILE);
			glBitmap(_width,_height,0,_height-1,hStep(),0,(GLubyte *) ptr);
			glEndList();
			ptr += bytesPerChar;
		}
	}
*/
}

bool 
GltFontTexture::print(const wchar_t ch) const
{
	assert(_init);

	if (_init)
		return print(char(ch));
	else
		return false;
}

bool 
GltFontTexture::print(const wstring &str) const
{
	assert(_init);

	if (_init)
	{
		string s;
		wstring2string(s,str);
		return print(s);
	}
	else
		return false;
}

bool 
GltFontTexture::print(const char ch) const
{
	assert(_init);

	if (_init)
	{
		if (uint16(ch)<_minGlyph || uint16(ch)>=_minGlyph+_range)
			return false;

		const GlyphVertexInfo *vi = _glyphLut[uint16(ch)-_minGlyph];

		if (vi)
		{
			glPushAttrib(GL_ENABLE_BIT);
				_texture.set();
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBegin(GL_QUADS);
					glTexCoord2fv(vi->t0); glVertex2sv(vi->v0);
					glTexCoord2fv(vi->t1); glVertex2sv(vi->v1);
					glTexCoord2fv(vi->t2); glVertex2sv(vi->v2);
					glTexCoord2fv(vi->t3); glVertex2sv(vi->v3);
				glEnd();
				glTranslatef(vi->advance,0,0);
			glPopAttrib();
			return true;
		}
	}

	return false;
}

bool 
GltFontTexture::print(const string &str) const
{
	assert(_init);

	if (_init)
	{
		glPushMatrix();
			for (int i=0; i<str.size(); i++)
				print(str[i]);
		glPopMatrix();
		glTranslatef(0,_vStep,0);
		return true;
	}
	else
		return false;
}

int
GltFontTexture::width(const wchar_t ch) const
{
	assert(_init);

	if (_init)
	{
		if (uint16(ch)<_minGlyph || uint16(ch)>=_minGlyph+_range)
			return false;

		const GlyphVertexInfo *vi = _glyphLut[uint16(ch)-_minGlyph];
		if (vi)
			return vi->advance;
	}

	return 0;
}

////////////////////////////////////////////////////////////////////

// Create variable-length header for font data

bool 
GltFontTexture::makeHeader
(
	string &header,
	const int            width,
	const int            height
)
{
	// 11 characters is big enough for integer 2^32 + \0

	char buffer[5+11+11];
	sprintf(buffer,"GLTF %u %u",width,height);
	header = buffer;
	header += '\0';

	return true;
}

// Decode variable-length header for texture data

void *
GltFontTexture::getHeader
(
	const void * const data,
	int            &width,
	int            &height
)
{
	const char * const h = (const char * const) data;
	
	if (h[0]=='G' && h[1]=='L' && h[2]=='T' && h[3]=='F' && h[4]==' ')
	{
		if (sscanf(h+5,"%i %i",&width,&height)==2)
			return (void *) (h + strlen(h) + 1);
	}

	return NULL;
}
