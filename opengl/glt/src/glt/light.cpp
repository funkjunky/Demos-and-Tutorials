#include "light.h"

/*! \file 
    \ingroup GLT
    
    $Id: light.cpp,v 1.7 2002/10/09 15:09:38 nigels Exp $
    
    $Log: light.cpp,v $
    Revision 1.7  2002/10/09 15:09:38  nigels
    Added RCS Id and Log tags


*/

#include <cstring>
#include <cassert>
using namespace std;

#include <glt/error.h>

// OpenGL Defaults

const GltColor GltLight::_ambientDefault      (0,0,0,1);
const GltColor GltLight::_diffuseDefault      (1,1,1,1);
const GltColor GltLight::_specularDefault     (1,1,1,1);
const Vector   GltLight::_positionDefault     (0,0,1);
const Vector   GltLight::_spotDirectionDefault(0,0,-1);
const GLfloat  GltLight::_spotExponentDefault (0.0);
const GLfloat  GltLight::_spotCutoffDefault   (180.0);
const GLfloat  GltLight::_attenuationConstantDefault(1);
const GLfloat  GltLight::_attenuationLinearDefault(0);
const GLfloat  GltLight::_attenuationQuadraticDefault(0);

GltLight::GltLight(const GLenum light,const bool getIt)
: 
  _light(light), 
  _enabled(false),
  _ambient(_ambientDefault),
  _diffuse(_diffuseDefault),
  _specular(_specularDefault),
  _position(_positionDefault),
  _spotDirection(_spotDirectionDefault),
  _spotExponent(_spotExponentDefault),
  _spotCutoff(_spotCutoffDefault),
  _attenuationConstant(_attenuationConstantDefault),
  _attenuationLinear(_attenuationLinearDefault),
  _attenuationQuadratic(_attenuationQuadraticDefault)
{
	assert(_light>=GL_LIGHT0 && _light<=GL_LIGHT7);

	if (getIt)
		get();
}

GltLight::~GltLight()
{
}

void 
GltLight::get()
{
	assert(_light>=GL_LIGHT0 && _light<=GL_LIGHT7);

	GLERROR

	_enabled = glIsEnabled(_light)!=0;

	_ambient .glGetLight(_light,GL_AMBIENT);
	_diffuse .glGetLight(_light,GL_DIFFUSE);
	_specular.glGetLight(_light,GL_SPECULAR);
	
	GltColor tmp;

	tmp.glGetLight(_light,GL_POSITION);       _position = tmp;
	tmp.glGetLight(_light,GL_SPOT_DIRECTION); _spotDirection = tmp;

	glGetLightfv(_light,GL_SPOT_EXPONENT ,&_spotExponent);
	glGetLightfv(_light,GL_SPOT_CUTOFF   ,&_spotCutoff);

	glGetLightfv(_light,GL_CONSTANT_ATTENUATION ,&_attenuationConstant);
	glGetLightfv(_light,GL_LINEAR_ATTENUATION   ,&_attenuationLinear);
	glGetLightfv(_light,GL_QUADRATIC_ATTENUATION,&_attenuationQuadratic);

	GLERROR
}

void 
GltLight::set() const
{
	assert(_light>=GL_LIGHT0 && _light<=GL_LIGHT7);

	if (_enabled)
		glEnable(_light);
	else
		glDisable(_light);

	_ambient .glLight(_light,GL_AMBIENT);
	_diffuse .glLight(_light,GL_DIFFUSE);
	_specular.glLight(_light,GL_SPECULAR);

	GltColor tmp;
	tmp = _position;      tmp.glLight(_light,GL_POSITION);
	tmp = _spotDirection; tmp.glLight(_light,GL_SPOT_DIRECTION);

	glLightf (_light,GL_SPOT_EXPONENT ,_spotExponent);
	glLightf (_light,GL_SPOT_CUTOFF   ,_spotCutoff);

	glLightf (_light,GL_CONSTANT_ATTENUATION ,_attenuationConstant);
	glLightf (_light,GL_LINEAR_ATTENUATION   ,_attenuationLinear);
	glLightf (_light,GL_QUADRATIC_ATTENUATION,_attenuationQuadratic);
}

GLenum   &GltLight::light()         { return _light; }
bool     &GltLight::enabled()       { return _enabled; }
GltColor &GltLight::ambient()       { return _ambient; }
GltColor &GltLight::diffuse()       { return _diffuse; }
GltColor &GltLight::specular()      { return _specular; }
Vector   &GltLight::position()      { return _position; }
Vector   &GltLight::spotDirection() { return _spotDirection; }
GLfloat  &GltLight::spotExponent()  { return _spotExponent; }
GLfloat  &GltLight::spotCutoff()    { return _spotCutoff; }

GLfloat  &GltLight::attenutationConstant()  { return _attenuationConstant;  }
GLfloat  &GltLight::attenutationLinear()    { return _attenuationLinear;    }
GLfloat  &GltLight::attenutationQuadratic() { return _attenuationQuadratic; }

const GLenum   &GltLight::light()         const { return _light; }
const bool     &GltLight::enabled()       const { return _enabled; }
const GltColor &GltLight::ambient()       const { return _ambient; }
const GltColor &GltLight::diffuse()       const { return _diffuse; }
const GltColor &GltLight::specular()      const { return _specular; }
const Vector   &GltLight::position()      const { return _position; }
const Vector   &GltLight::spotDirection() const { return _spotDirection; }
const GLfloat  &GltLight::spotExponent()  const { return _spotExponent; }
const GLfloat  &GltLight::spotCutoff()    const { return _spotCutoff; }

const GLfloat  &GltLight::attenutationConstant()  const { return _attenuationConstant;  }
const GLfloat  &GltLight::attenutationLinear()    const { return _attenuationLinear;    }
const GLfloat  &GltLight::attenutationQuadratic() const { return _attenuationQuadratic; }

