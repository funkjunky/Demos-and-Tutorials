#include "line.h"

/*! \file 
	\ingroup Node
*/

using namespace std;

///////////////////////////// GlutShapes ///////////////////////////////////////

GltLine::GltLine()
: _width(1.0f)
{
}

GltLine::~GltLine()
{
}

void 
GltLine::draw() const
{
	const bool noLighting = _normals.size()==0;

	glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT | GL_LINE_BIT);
	glPushMatrix();
		transformation().glMultMatrix();

		if (noLighting)
			glDisable(GL_LIGHTING);
		
		glColor();

		if (!solid())
			glPointSize(_width);
		else
			glLineWidth(_width);

		glBegin(solid() ? GL_LINE_STRIP : GL_POINTS);
			for (uint32 i=0; i<_points.size(); i++)
				_points[i].glVertex();
		glEnd();

	glPopMatrix();
	glPopAttrib();
}

bool 
GltLine::boundingBox(Vector &min,Vector &max) const
{
	return false;
}

string GltLine::description() const
{
	return "Line.";
}

const vector<Vector> &GltLine::points()  const { return _points; }
const vector<Vector> &GltLine::normals() const { return _normals; }

      vector<Vector> &GltLine::points()  { return _points; }
      vector<Vector> &GltLine::normals() { return _normals; }

const GLfloat &GltLine::width() const { return _width; }
	  GLfloat &GltLine::width()       { return _width; }

