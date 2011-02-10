#ifndef MESH_TRIANGLE_H
#define MESH_TRIANGLE_H

/** \file 
 * Triangle Interface
 *
 * Part of the Glt C++ OpenGL Library
 * http://www.nigels.com/glt/
 *
 * \author  Nigel Stewart (nigels@nigels.com)
 * \author  RMIT Dept. Mechanical and Manufacturing Engineering, Australia
 */

#include <iosfwd>

#include <math/point.h>
#include <math/plane.h>

/** \class Triangle 
 *  \brief Triangle 
 *  \ingroup Mesh
 */

class Triangle 
{
public:

	/// Construct undefined triangle
	Triangle();
	/// Construct triangle from three points
	Triangle(Point *a,Point *b,Point *c);

	/// Access points [0,2]
	Point *operator[](int);
	/// Access points [0,2]
	const Point *operator[](int) const;

	/// Normal of triangle face
	Vector &normal();

	/// Normal of triangle face
	const Vector &normal() const;

	Plane   plane() const;

	/// Are triangles the same?
	bool operator==(const Triangle &tri) const;
	/// Are triangles different?
	bool operator!=(const Triangle &tri) const;

	/// Render triangle with OpenGL
	void glDraw() const;

	/// Write triangle to POV format
	std::ostream &writePOV(std::ostream &os) const;

private:

	/// Vertecies of triangle
	Point *_vertex[3];
	/// Normal of triangle face
	Vector _normal;
};

#endif
