#ifndef NODE_HISTOGRM_H
#define NODE_HISTOGRM_H

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
	\brief   Histogram Node
	\ingroup Node
*/

#ifdef GLT_WIN32
#pragma warning(disable: 4786)		
#endif

#include <node/shape.h>
#include <node/field.h>

#include <vector>

/*! \class   GltHistogram
	\brief   Histogram Node
	\ingroup Node
*/

class GltHistogram : public GltShape 
{
public:

	GltHistogram();
	~GltHistogram();

	void draw() const;

	void reset();
	void add(const double x);
	void add(const int    n);

	GltFieldPtr settings(); 

	double &min();
	double &max();
	int    &size();
	bool   &cumulative();

	bool   &drawLine();

	unsigned int samples() const;
	unsigned int outlyers() const;
	unsigned int minCount() const;
	unsigned int maxCount() const;

private:

	double	_min;			
	double	_max;	
	int     _size;
	bool    _cumulative;

	bool    _drawLine;

	unsigned int	_samples;
	unsigned int	_outlyers;

	std::vector<unsigned int> _count;
};

#endif
