#ifndef MESH_QUAD_H
#define MESH_QUAD_H

/** \file 
 * Quad Interface
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

/** \class Quad 
 *  \brief Quad 
 *  \ingroup Mesh
 */

class Quad 
{
public:

	/// Construct undefined quad
	Quad();
	/// Construct triangle from three points
	Quad(Point *a,Point *b,Point *c,Point *d);

	/// Access points [0,3]
	Point *operator[](int);
	/// Access points [0,3]
	const Point *operator[](int) const;

	/// Normal of quad face
	Vector &normal();

//	///
//	bool   &odd();

	/// Normal of quad face
	const Vector &normal() const;

	Plane   plane() const;

	/// Are quads the same?
	bool operator==(const Quad &quad) const;
	/// Are quads different?
	bool operator!=(const Quad &quad) const;

	/// Render quad with OpenGL
	void glDraw() const;

	/// Write quad to POV format
	std::ostream &writePOV(std::ostream &os) const;

private:

	/// Vertecies of quad
	Point *_vertex[4];
	/// Normal of quad face
	Vector _normal;
	///  Parity-bit for z-buffer matching of subsequent quads
	bool   _odd;
};

#endif
