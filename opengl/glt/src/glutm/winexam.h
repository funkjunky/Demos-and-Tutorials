#ifndef GLUTM_WINEXAM_H
#define GLUTM_WINEXAM_H

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
    \brief   Examiner Style Window Class
    \ingroup GlutMaster
*/

#include <glutm/window.h>
#include <math/matrix4.h>
#include <glt/project.h>

/*! \class   GlutWindowExaminer
    \brief   Examiner Style Window Class
    \ingroup GlutMaster
*/     

class GlutWindowExaminer : public GlutWindow
{
public:
	/// Constructor
	GlutWindowExaminer
	(
		const std::string &title = titleDefault,
		int width                = widthDefault, 
		int height               = heightDefault,
		int x                    = xDefault, 
		int y                    = yDefault,
		unsigned int displayMode = displayModeDefault
	);
	/// Destructor
	virtual ~GlutWindowExaminer();

	void OnOpen();
	void OnClose();
	void OnReshape(int w, int h);   
	void OnKeyboard(unsigned char key, int x, int y);
	void OnSpecial(int key, int x, int y);   
	void OnMenu(int value);
	void OnMouse(int button, int state, int x, int y);
	void OnMotion(int x, int y);
	void OnPassiveMotion(int x, int y);

	/// Callback handler for changes in viewing direction
	virtual void OnOrient(const Matrix &viewing,const Matrix &inverse);

	/// Callback handler for getting a refernce point from mouse x and y
	virtual Vector getReferencePoint(int x,int y,const Vector &pos,const Matrix &modelView,const Matrix &modelViewInverse) const;

	/// Current reference point
	Vector &referencePoint();

	//
	// Config
	//

	/// Enable mouse zooming
	bool &mouseZoom();
	/// Enable mouse panning
	bool &mousePan();
	/// Enable mouse rotation
	bool &mouseRotate();

	/// Mouse zoom-pan-rotate mode
	typedef enum
	{
		MODE_MOUSE_ONLY = 0,
		MODE_MOUSE_RIGHT,
		MODE_MAX
	} MouseMode;
	
	/// Mouse mode
	MouseMode &mouseMode();
		
protected:

	/// Is any mouse button currently pressed?
	bool mousePressed() const;

	/// Calculate x-axis rotation in transformed co-ordinates
	Vector xAxisOfRotation() const;
	/// Calculate y-axis rotation in transformed co-ordinates
	Vector yAxisOfRotation() const;
	/// Calculate rotation axis in transformed co-ordinates
	Vector axisOfRotation(const Vector &v) const;

	/// Apply current transformation matrix before doing anything else
	void OnPreDisplay();

	/// Convert from screen co-ordinates to world co-ordinates
	Vector dragPos(const int x,const int y) const;  

	/// Current transformation matrix
	Matrix    _viewMatrix;
	/// Current transformation matrix inverse
	Matrix    _viewMatrixInverse;		

	GltOrtho  _ortho;

private:

	bool      _mouseZoom;
	bool      _mousePan;
	bool      _mouseRotate;
	
	MouseMode _mouseMode;
	
	/// Reference point for zooming and rotation
	Vector    _referencePoint;

	//
	//
	//

	bool   _mouseLeft;
	bool   _mouseMiddle;
	bool   _mouseRight;
	int    _mouseX;
	int    _mouseY;
	bool   _wasIdle;				// Stop idle while manipulating with mouse
	int    _oldCursor;				// Remember old cursor while manipulating
	Vector _dragPosPrev;
};

#endif
