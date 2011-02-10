#ifndef MESH_SWEEP_H
#define MESH_SWEEP_H

/*
 * Part of the Glt C++ OpenGL Library
 * http://www.nigels.com/glt/
 */

#include <glt/config.h>

class GltPath3D;
class GltShape;

GltShape *MeshSweep(const GltPath3D &f,const double radius,const int slices,const int stacks,const bool convex = false);

#endif
