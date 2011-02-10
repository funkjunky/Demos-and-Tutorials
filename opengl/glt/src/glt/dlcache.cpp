#include "dlcache.h"

#include <glt/error.h>

/*! \file 
    \ingroup GLT
    
    $Id: dlcache.cpp,v 1.7 2002/10/09 15:09:38 nigels Exp $
    
    $Log: dlcache.cpp,v $
    Revision 1.7  2002/10/09 15:09:38  nigels
    Added RCS Id and Log tags


*/

using namespace std;

////////

GltDisplayListCache::GltDisplayListCache(const uint32 capacity)
: _capacity(capacity)
{
	_lists.reserve(capacity);
	assert(capacity>0);
}

GltDisplayListCache::~GltDisplayListCache()
{
	clear();
}

void
GltDisplayListCache::draw(const uint32 seed)
{
	GLuint *id = _lru.find(seed);

	GLERROR;

	if (id)
		glCallList(*id);
	else
	{
		GLuint list;

		if (_lru.size()>=_capacity)
			list = _lru.insert(seed);
		else
		{
			list = glGenLists(1);
			_lists.push_back(list);
			_lru.insert(seed,list);
		}

		// Compile and draw the display list

		glNewList(list,GL_COMPILE_AND_EXECUTE);
		OnDraw(seed);
		glEndList();
	}

	GLERROR;
}	

void 
GltDisplayListCache::clear()
{
	if (!_lists.size() && !_lru.size())
		return;

	GLERROR;

	// Free OpenGL display lists
	for (int i=0; i<_lists.size(); i++)
		glDeleteLists(_lists[i],1);
	
	GLERROR;

	// Clear OpenGL display list inventory
	_lists.clear();

	// Clear LRU Cache
	_lru.clear();
}
