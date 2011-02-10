#include "text.h"

/*! \file 
	\ingroup Node
*/

#include <node/fade.h>

#include <glt/cursor.h>
#include <glt/font.h>
#include <glt/error.h>
#include <glt/glu.h>
#include <glt/rgb.h>

#include <algorithm>
using namespace std;

GltTextOverlay::GltTextOverlay(const GltFont &font,const GltViewport &window)
: 
  _font(font),
  _window(window),
  _textShadow(true),
  _textShadowColor(black),
  _textAlignHorizontal(GLT_ALIGN_LEFT),
  _textAlignVertical(GLT_ALIGN_TOP),
  _spacing(4), 
  _margin(4)
{
	color() = white;
	_textFade.color() = black;
	_textFade.color().alpha() = 0.3;

	_textFade.border() = true;
	_textFade.borderColor() = black;
}

GltTextOverlay::GltTextOverlay(const GltTextOverlay &overlay)
: 
  _font(overlay._font),
  _window(overlay._window), 
  _textShadow(overlay._textShadow),
  _textShadowColor(overlay._textShadowColor),
  _textAlignHorizontal(overlay._textAlignHorizontal),
  _textAlignVertical(overlay._textAlignVertical),
  _spacing(overlay._spacing),
  _margin(overlay._margin)
{
}

GltTextOverlay::~GltTextOverlay()
{
}

bool      &GltTextOverlay::shadow()      { return _textShadow;      }
GltColor  &GltTextOverlay::shadowColor() { return _textShadowColor; }

bool      &GltTextOverlay::border()       { return _textFade.border(); }
GltColor  &GltTextOverlay::borderColor()  { return _textFade.borderColor(); }

GltHorizontalAlignment &GltTextOverlay::alignHorizontal() { return _textAlignHorizontal; }
GltVerticalAlignment   &GltTextOverlay::alignVertical()   { return _textAlignVertical;   }

GltColor  &GltTextOverlay::fadeColor()  { return _textFade.color(); }

int       &GltTextOverlay::spacing() { return _spacing; }
int       &GltTextOverlay::margin()  { return _margin;  }

/*
void 
GltTextOverlay::stringDimensions(const std::wstring &str,int &width,int &height)
{
	height = 0;
	width = 0;

	// Get the first line of text

	int i = 0;
	int j = str.find('\n',i);

	// Process each line of text

	while (i!=string::npos)
	{
		height++;

		if (j==string::npos)
		{
			width = MAX(width,int(str.length()-i));
			break;
		}
		else
			width = MAX(width,j-i);

		i = j+1;
		j = str.find('\n',i);
	}
}
*/

void 
GltTextOverlay::draw() const
{
	if (_text.length()==0)
		return;

	// Window viewport

	GltViewport window = _window;
	window.shrink(_spacing);


	// Get text dimensions

	int width;
	int height;
//	stringDimensions(_text,width,height);
	_font.size(width,height,_text);

	//

	GltViewport viewport = _window;

	// Make viewport big enough to fit text

	viewport.width()  = width;
	viewport.height() = height;

	// Include margin

	viewport.shrink(-_margin);
	viewport.align(_textAlignHorizontal,window);
	viewport.align(_textAlignVertical,window);

	GLERROR

	glPushAttrib(GL_ENABLE_BIT);

		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);

		GLERROR

		glPushAttrib(GL_VIEWPORT_BIT);
			viewport.set();
			_textFade.draw();
		glPopAttrib();

		viewport.shrink(_margin);

		if (_textShadow)
		{
			viewport.x()++;
			viewport.y()--;
			_textShadowColor.glColor();
			GltCursor cursor(_font,viewport);
			cursor.print(_text);
			viewport.x()--;
			viewport.y()++;
		}

		GLERROR

		{
			glColor();
			GltCursor cursor(_font,viewport);
			cursor.print(_text);
		}

	glPopAttrib();
}

      std::wstring &GltTextOverlay::text()       { return _text; }
const std::wstring &GltTextOverlay::text() const { return _text; }


