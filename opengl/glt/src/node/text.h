#ifndef NODE_TEXT_H
#define NODE_TEXT_H

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
	\brief   Text Overlay Node
	\ingroup Node
*/

#include <iosfwd>
#include <string>

#include <glt/viewport.h>
#include <glt/color.h>
#include <glt/font.h>

#include <node/shapes.h>
#include <node/fade.h>

/*! \class   GltTextOverlay 
	\brief   Text Overlay Node
	\ingroup Node
*/

class GltTextOverlay : public GltShape
{
public:
	/// Constructor
	GltTextOverlay(const GltFont &font,const GltViewport &window);
	/// Constructor
	GltTextOverlay(const GltTextOverlay &overlay);
	/// Destructor
	~GltTextOverlay();

	virtual void draw() const;

												/// Current overlay text
	      std::wstring &text();
												/// Current overlay text
	const std::wstring &text() const;

												/// Fade colour of overlay viewport
	GltColor  &fadeColor();

												/// Draw overlay border
	bool      &border();
												/// Overlay border color
	GltColor  &borderColor();
												/// Draw text shadow
	bool      &shadow();
												/// Text shadow color
    GltColor  &shadowColor();

												/// Text spacing
	int       &spacing();
												/// Text margin
	int       &margin();
												/// Horizontal alignment
	GltHorizontalAlignment &alignHorizontal();
												/// Vertical alignment
	GltVerticalAlignment   &alignVertical();

//	/// Calculate the (pixel) dimensions of a string of text
//	static void stringDimensions(const std::wstring &str,int &width,int &height);

private:

	const GltFont     &_font;
	const GltViewport &_window;

	std::wstring		   _text;
	GltFadeViewport        _textFade;
	bool                   _textShadow;
	GltColor               _textShadowColor;
	GltHorizontalAlignment _textAlignHorizontal;
	GltVerticalAlignment   _textAlignVertical;

	int             _spacing;
	int             _margin;
};

#endif
