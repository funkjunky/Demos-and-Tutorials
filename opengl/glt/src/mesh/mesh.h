#ifndef MESH_MESH_H
#define MESH_MESH_H

/** \file 
 * Mesh Interface
 *
 * Part of the Glt C++ OpenGL Library
 * http://www.nigels.com/glt/
 *
 * \author  Nigel Stewart (nigels@nigels.com)
 * \author  RMIT Dept. Mechanical and Manufacturing Engineering, Australia
 */

#include <glt/config.h>

#ifdef GLT_WIN32
#pragma warning(disable: 4786)		
#endif

#include <node/shape.h>
#include <math/point.h>
#include <mesh/triangle.h>
#include <mesh/quad.h>

#include <iosfwd>
#include <deque>
#include <string>


/** \brief Supported file types for import and/or export
 *  \ingroup Mesh
 */
typedef enum
{
	MESH_3DS_BINARY = 0,	/*!< 3D Studio Binary Format */
	MESH_VRML,				/*!< VRML 97 */
	MESH_OFF,				/*!< OFF */
	MESH_AUTO
} MeshFileType;

/** \class Mesh 
 *  \brief Triangle Mesh
 *  \ingroup Mesh
 *  \todo  Quad support not yet complete
 */
class Mesh : public GltShape 
{
public:
	/// Constructor
	Mesh();
	/// Copy constructor
	Mesh(const Mesh &mesh);
	/// Read from file
	Mesh(const std::string &filename,MeshFileType type = MESH_AUTO);

	/// Destructor
	virtual ~Mesh();

	Mesh &operator=(const Mesh &mesh);
	//
	// GltShape interface
	//

	virtual void draw() const;
	virtual void boundingBox(BoundingBox &box) const;
	virtual std::string description() const;
	virtual bool povrayExport(std::ostream &os) const;

	/// Mesh points
	      std::deque<Point> &point();
	/// Mesh points
	const std::deque<Point> &point() const;

	/// Mesh triangles
	      std::deque<Triangle> &triangle();
	/// Mesh triangles
	const std::deque<Triangle> &triangle() const;

	/// Mesh quads
	      std::deque<Quad> &quad();
	/// Mesh quads
	const std::deque<Quad> &quad() const;

	///
	      bool &cullFace();
	///
	const bool &cullFace() const;

	/// Is a point inside the mesh? (Works only for convex polyhedra)
	bool inside(const Vector &pos) const;

	std::ostream &writeDebugInfo(std::ostream &os) const;
	std::ostream &writeAOff(std::ostream &os) const;

private:

	/// Mesh points
	std::deque<Point>    _point;
	/// Mesh triangles
	std::deque<Triangle> _triangle;
	/// Mesh quads
	std::deque<Quad>     _quad;

	bool                 _cullFace;

	/// Read from 3D Studio stream
	void read3ds(std::istream &is);
	/// Read from OFF stream
	void readOff(std::istream &is);

	/// Find point index (position in container)
	int index(const Point *point) const;
};

#endif
