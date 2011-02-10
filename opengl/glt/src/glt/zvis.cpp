#include "zvis.h"

/*! \file 
    \ingroup GLT
    
    $Id: zvis.cpp,v 1.5 2002/10/09 15:09:38 nigels Exp $
    
    $Log: zvis.cpp,v $
    Revision 1.5  2002/10/09 15:09:38  nigels
    Added RCS Id and Log tags


*/

#include <glt/buffer.h>

#include <iostream>
using namespace std;

void zBufferVisualise(ostream &os)
{
	GltFrameBufferZUint zBuffer;

	GLuint freq[64];
	zBuffer.histogram(freq);

	for (GLuint i=0; i<64; i++)
		os << (freq[i]==0 ? ' ' : 'x');

	os << endl;
}
