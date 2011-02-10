#ifndef MESH_YYPARSE_H
#define MESH_YYPARSE_H

/*
 * Part of the Glt C++ OpenGL Library
 * http://www.nigels.com/glt/
 */

#include <cstdio>
using namespace std;

#include <mesh/vrml.h>

class Mesh;

extern Mesh   *yyVrmlMesh;
extern FILE   *Vrmlin;

int Vrmlparse(void);

extern void (*VrmlParseMaterial)      (MaterialPtr       &material);
extern void (*VrmlParseIndexedFaceSet)(IndexedFaceSetPtr &faceSet);
extern void (*VrmlParseShape)         (GltShapePtr       &shape);

#endif

