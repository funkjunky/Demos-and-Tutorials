#include "volume.h"

/*! \file 
	\ingroup Math
*/

#include <math/real.h>

double sphereVolume(const double radius)
{
	return (4.0/3.0)*M_PI*radius*radius*radius;
}

double cylinderVolume(const double radius,const double height)
{
	return M_PI*radius*radius*height;
}

double coneVolume(const double radius,const double height)
{
	return (1.0/3.0)*M_PI*radius*radius*height;
}

double boxVolume(const double width,const double height,const double depth)
{
	return width*height*depth;
}
