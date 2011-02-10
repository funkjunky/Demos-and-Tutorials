#ifndef NODE_INTERP_H
#define NODE_INTERP_H

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
	\brief   Interpolation Nodes
	\ingroup Node
*/

#include <glt/colmap.h>

#include <node/shape.h>
#include <misc/timer.h>

class GltColor;
class Matrix;

/*! \class   GltInterpolator 
	\brief   Interpolator Base-Class
	\ingroup Node
*/

class GltInterpolator : public GltShape
{
public:
	GltInterpolator();
	virtual ~GltInterpolator();

	/// Start in real-time mode
	void start(const double duration,const bool loop = false);

	/// Start in per-frame mode
	void start(const bool loop = false);

	/// Stop the interpolator
	void stop();

	/// Restart the interpolator
	void restart(void);

	// 
	// Get/Set
	//

	const bool   &active()   const;
	const bool   &loop()     const;
	const bool   &realTime() const;
	const double &duration() const;
	const int    &frame()    const;

	      bool   &active();
	      bool   &loop();
	      bool   &realTime();
	      double &duration();
	      int    &frame();

protected:
	bool          _active;
	bool          _loop;
	bool          _realTime;
	Timer         _timer;
	double        _duration;
	int           _frame;
};

/*! \class   GltInterpolatorColor 
	\brief   Color Interpolator Node
	\ingroup Node
	\author  Nigel Stewart (nigels@nigels.com)
*/

class GltInterpolatorColor : public GltInterpolator
{
public:
	GltInterpolatorColor(GltColor &color);
	~GltInterpolatorColor();

	virtual void draw() const;

	      GltColorMap &colorMap();
	const GltColorMap &colorMap() const;

private:
	GltColor    &_color;
	GltColorMap  _colorMap;
};

/*! \class   GltInterpolatorRotation 
	\brief   Rotation Interpolator Node
	\ingroup Node
	\author  Nigel Stewart (nigels@nigels.com)
*/

class GltInterpolatorRotation : public GltInterpolator
{
public:
	GltInterpolatorRotation(Matrix &matrix);
	~GltInterpolatorRotation();

	virtual void draw() const;

	      Vector &axis();
	const Vector &axis() const;

	      Vector &center();
	const Vector &center() const;
	       
private:
	Matrix    &_matrix;
	Vector     _axis;
	Vector     _center;
};

#endif
