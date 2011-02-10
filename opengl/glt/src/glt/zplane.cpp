#include "zplane.h"

/*! \file 
    \ingroup GLT
    
    $Id: zplane.cpp,v 1.7 2002/10/09 15:09:38 nigels Exp $
    
    $Log: zplane.cpp,v $
    Revision 1.7  2002/10/09 15:09:38  nigels
    Added RCS Id and Log tags


*/

#include <glt/viewport.h>
#include <math/real.h>

void 
drawZat(const GLdouble z)
{
	glPushAttrib(GL_ENABLE_BIT);

		glDisable(GL_LIGHTING);

		GltViewport viewport(true);

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrtho(0,viewport.width(),0,viewport.height(),0,1);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glTranslated(0,0,-CLAMP(z,0.0,1.0));
		viewport.drawQuad();

		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);

	glPopAttrib();
}

void 
drawZnear()
{
	drawZat(0.0);
}

void 
drawZfar()
{
	drawZat(1.0);
}

