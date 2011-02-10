/*

  Glt OpenGL C++ Toolkit (Glt)
  Copyright (C) 2000 Nigel Stewart
  Email: nigels@nigels.com   WWW: http://www.nigels.com/glt/

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

#include "vrmlview.h"

#include <mesh/vrmlpars.h>

#include <iostream>
using namespace std;

GltShapes *insert = NULL;
void insertShape(GltShapePtr &shape)
{
	if (insert)
		insert->push_back(shape);
}


GlutVrmlViewer::GlutVrmlViewer(const std::string &filename,int width,int height,int x,int y,unsigned int displayMode)
: GlutWindowExaminer(filename,width,height,x,y,displayMode)
#ifdef OPENVRML
, _scene(NULL)
, _viewer(NULL)
#else
//, _mesh(filename,MESH_VRML)
#endif
{
	#ifdef OPENVRML
	loadScene(filename);
	#else

	insert = &_shapes;
	VrmlParseShape = insertShape;

	Vrmlin = fopen(filename.c_str(),"rt");
	if (Vrmlin)
	{
		Vrmlparse();
		fclose(Vrmlin);
	}

	Vrmlin = NULL;
	insert = NULL;
	VrmlParseShape = NULL;

	// Fit the object into the unit cube.

	BoundingBox box;
	_shapes.boundingBox(box);

	if (box.defined())
	{
		_shapes.transformation() *= matrixTranslate(-box.center());

		const double size = MAX(box.width(),MAX(box.height(),box.depth()));

		if (size>1e-6)
			_shapes.transformation() *= matrixScale(1.8/size);
	}
	#endif

	// Setup raytracing data structures

	#ifdef GLUTM_RAYPP
	initScene();
	initSceneMesh(_mesh);
	#endif
}

GlutVrmlViewer::~GlutVrmlViewer()
{
}

void GlutVrmlViewer::OnOpen()
{
	// Setup OpenGL lighting

	_light0.ambient()  = GltColor(0.1, 0.1, 0.1, 1.0);
	_light0.specular() = GltColor(0.5, 0.5, 0.5, 0.0);
	_light0.position() = Vector(1.5, 1.5, 5.0);
	_light0.enabled()  = true;
	_light0.set();

	_material.ambient()   = GltColor(0.0, 0.0, 0.0, 0.0);
	_material.diffuse()   = GltColor(0.0, 0.0, 0.0, 0.0);
	_material.specular()  = GltColor(1.0, 1.0, 1.0, 0.0);
	_material.shininess() = 40.0;
	_material.set();

	_lightModel.setAmbient(0.0, 0.0, 0.0, 0.0);
	_lightModel.setLocalViewer(GL_FALSE);
	_lightModel.setTwoSide(GL_TRUE);

	glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
//	glShadeModel(GL_FLAT);

	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_DITHER);
	glEnable(GL_LIGHTING);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	glClearColor(0.2, 0.2, 0.2, 0.0);

	// Compile the display list

	#ifndef OPENVRML
	_list.newList();
//	_mesh.draw();
	_shapes.draw();
	_list.endList();
	#endif
}

void 
GlutVrmlViewer::OnClose()
{
	_list.reset();
}

void GlutVrmlViewer::OnDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	#ifdef OPENVRML
	drawScene();
	#else
	_list.draw();
	#endif
}

void 
GlutVrmlViewer::OnKeyboard(unsigned char key, int x, int y)
{
	GlutWindowExaminer::OnKeyboard(key,x,y);

	switch (key)
	{
	#ifdef GLUTM_RAYPP
	case 'r':	
		raytraceScene("vrmlview.tga",_viewport.width(),_viewport.height(),Matrix(GL_MODELVIEW_MATRIX)); 
		break;
	#endif
	default:
		break;
	}
}

#include <glutm/main.h>

/*
   Sources of VRML models...

   RC CAD 
   http://209.15.130.75/index.html

*/

bool GlutMain(const std::vector<std::string> &arg)
{
	string filename("sample.wrl");

	if (arg.size()>1)
		filename = arg[1];

	static GlutWindow *main = new GlutVrmlViewer(filename.c_str(),450,450,10,10);
	main->open();

	return true;
}


