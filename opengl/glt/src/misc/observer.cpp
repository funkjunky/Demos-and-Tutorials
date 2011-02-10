#include "observer.h"

/*! \file 
    \brief   Templated type-safe Observer-Subject pattern
	\ingroup Misc
*/

using namespace std;

/////////////////////////////////////////////////////////

GltObserverAbstract::GltObserverAbstract()
{
}

GltObserverAbstract::GltObserverAbstract(const GltObserverAbstract &other)
{
}

GltObserverAbstract::~GltObserverAbstract() 
{
	for (list<GltSubject *>::iterator i=_subjects.begin(); i!=_subjects.end(); i++)
		(*i)->_observers.remove(this);
	_subjects.clear();
}

GltObserverAbstract &
GltObserverAbstract::operator=(const GltObserverAbstract &other)
{
	return *this;
}

void 
GltObserverAbstract::observe(GltSubject &subject)
{
	subject._observers.push_back(this);
	_subjects.push_back(&subject);
}

void 
GltObserverAbstract::forget(GltSubject &subject)
{
	subject._observers.remove(this);
	_subjects.remove(&subject);
}

/////////////////////////////////////////////////////////

GltSubject::GltSubject()  
{
}

GltSubject::GltSubject(const GltSubject &other)
{
}

GltSubject::~GltSubject() 
{
	for (list<GltObserverAbstract *>::iterator i=_observers.begin(); i!=_observers.end(); i++)
		(*i)->_subjects.remove(this);
	_observers.clear();
}

GltSubject &
GltSubject::operator=(const GltSubject &other)
{
	return *this;
}

void 
GltSubject::notify(const void *object)
{
	for (list<GltObserverAbstract *>::iterator i=_observers.begin(); i!=_observers.end(); i++)
		(*i)->OnNotify(object);
}

