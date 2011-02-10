#include "frame.h"

/*! \file 
    \ingroup GLT
    
    $Id: frame.cpp,v 1.10 2002/10/09 15:09:38 nigels Exp $
    
    $Log: frame.cpp,v $
    Revision 1.10  2002/10/09 15:09:38  nigels
    Added RCS Id and Log tags


*/

#include <cstdio>
using namespace std;

GltFrameRate::GltFrameRate(const int sampleSize)
: _frames(0), 
  _step(0.200),
  _lastFrameRate(0.0), 
  _lastFrameTime(0.0),
  _buffer(sampleSize)
{
	_lastCalc = _timer.elapsed();
}

GltFrameRate::~GltFrameRate()
{
}

GltFrameRate &
GltFrameRate::operator++()
{
	_frames++;
	_buffer.push_back(_timer.elapsed());
	
	// Recalculate frame rate and frame time
	// if we have sufficient samples and
	// enough time has elapsed.
	
	if (_buffer.size()>=2)
	{
		if ((_buffer.back()-_lastCalc)>=_step)
		{
			_lastCalc      = _buffer.back();
			_lastFrameTime = double(_buffer.back()-_buffer.front())/double(_buffer.size()-1);
			_lastFrameRate = 1.0/_lastFrameTime;
		}
	}
	
	return *this;
}

double GltFrameRate::elapsedTime() const { return _timer.elapsed(); }
int    GltFrameRate::totalFrames() const { return _frames;          }

double GltFrameRate::frameRate()   const { return _lastFrameRate; }
double GltFrameRate::frameTime()   const { return _lastFrameTime; }

std::string 
GltFrameRate::summary() const
{
	char buffer[1024];
	sprintf
	(
		buffer,
		"%3.0lf fps",
		frameRate()
	);
	return buffer;
}

std::string 
GltFrameRate::detailed() const
{
	char buffer[1024];
	sprintf
	(
		buffer,
		"%5.3lf sec %3.0lf fps",
		frameTime(),
		frameRate()
	);
	return buffer;
}

