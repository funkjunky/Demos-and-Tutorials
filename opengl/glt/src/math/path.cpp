#include "path.h"

/*! \file 
	\ingroup Math
*/

#include <cmath>
#include <cassert>
using namespace std;

GltPath3D::GltPath3D()
{
}

GltPath3D::~GltPath3D()
{
}

///

GltPath3DLine::GltPath3DLine(const Vector &origin,const Vector &direction)
: _origin(origin), _direction(direction)
{
}

Vector
GltPath3DLine::f(const real t) const
{
	return _origin + _direction*t;
}

Vector 
GltPath3DLine::df(const real t) const
{
	return _direction;
}

Vector 
GltPath3DLine::ddf(const real t) const
{
	return Vector0;
}

///

GltPath3DHelix::GltPath3DHelix(const Vector &origin,const Vector &direction,const real radius,const real freq,const real phase)
: _origin(origin), _direction(direction), _radius(radius), _freq(freq), _phase(phase)
{
	Vector dir = _direction;
	dir.normalize();
	const real angle = acos(dir*VectorZ);

	if (fabs(angle)>0.01)
		_trans = matrixRotate(xProduct(_direction,VectorZ),angle);
}

Vector
GltPath3DHelix::f(const real t) const
{
	Vector orbit = VectorX*sin(t*_freq*M_2PI+_phase) + VectorY*cos(t*_freq*M_2PI+_phase);
	orbit = orbit * _radius;
	return _origin + _direction*t + _trans*orbit; 
}

Vector 
GltPath3DHelix::df(const real t) const
{
	Vector orbit = VectorX*cos(t*_freq*M_2PI+_phase) - VectorY*sin(t*_freq*M_2PI+_phase);
	orbit = orbit * (_radius * _freq * M_2PI);

	return _direction + _trans*orbit;
}

Vector 
GltPath3DHelix::ddf(const real t) const
{
	Vector orbit = -VectorX*sin(t*_freq*M_2PI+_phase) - VectorY*cos(t*_freq*M_2PI+_phase);
	orbit = orbit * _radius * SQ(_freq*M_2PI);

	return _trans*orbit;
}

/////

GltPath3DSegment::GltPath3DSegment(const GltPath3D &func,const real begin,const real end)
: _func(func), _begin(begin), _end(end)
{
	assert(_begin<_end);
	assert(CLAMP<real>(_begin,0.0,1.0)==_begin);
	assert(CLAMP<real>(_end,0.0,1.0)==_end);
}


Vector 
GltPath3DSegment::f(const real t) const
{
	return _func.f(segT(t));
}

Vector 
GltPath3DSegment::df(const real t) const
{
	return _func.df(segT(t));
}

Vector 
GltPath3DSegment::ddf(const real t) const
{
	return _func.ddf(segT(t));
}

real 
GltPath3DSegment::segT(const real t) const
{
	return (_end-_begin)*t+_begin;
}



