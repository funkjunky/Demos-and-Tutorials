#ifndef MESH_READ3DSB_H
#define MESH_READ3DSB_H

//
// OpenGL Solid Modelling
//
// Nigel Stewart (nigels@eisa.net.au)
// RMIT Department of Mechanical and Manufacturing Engineering
// 11th December 1997
//

/*
 * Part of the Glt C++ OpenGL Library
 * http://www.nigels.com/glt/
 */

#include <iosfwd>
#include <vector>
#include <string>

#include <math/point.h>

typedef struct { unsigned short a,b,c; } TriangleIndex;

void read3DSbinary(std::istream &is,void (*mesh3DScallback)(std::vector<Point> &vertex,std::vector<TriangleIndex> &triangle,const std::string &name) = NULL);

extern std::ostream *read3DSbinaryDebugStream;
extern int           read3DSbinaryDebugLevel;

#endif

