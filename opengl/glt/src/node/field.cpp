#include "field.h"

/*! \file 
	\ingroup Node
*/

#include <iostream>
#include <iomanip>
using namespace std;

GltField::GltField()
{
}

GltField::GltField(const string &name)
: _name(name)
{
}

GltField::GltField(const GltField &field)
: _name(field._name) 
{
}

GltField::~GltField()
{
}

GltField &
GltField::operator=(const GltField &field)
{
	if (this!=&field)
	{
		_name        = field._name;
	//	_description = field._description;
	}

	return *this;
}

std::string GltField::get() const                   { return string(); }
bool        GltField::set(const std::string &value) { return false;    }
bool        GltField::reset()                       { return false;    }
bool        GltField::isDefault() const             { return false;    }

bool 
GltField::write(ostream &os,const string &prefix) const
{
	string fullName(prefix);
	if (prefix.size())
		fullName += ".";
	fullName += name() + ": ";

	os << setw(60) << setiosflags(ios::left) << fullName << get() << endl;

	return true;
}

      string &GltField::name()       { return _name; }
const string &GltField::name() const { return _name; }

//
// Windows specific
//

#ifdef GLT_WIN32

#include <windows.h>

bool 
GltField::writeRegistry(void *key) const
{
	if (!_name.size())
		return false;

	const string val = get();
	LONG res = RegSetValueEx((HKEY)key,_name.c_str(),0,REG_SZ,(CONST BYTE *) val.c_str(),val.size()+1);
	return res==ERROR_SUCCESS;
}

bool 
GltField::readRegistry(void *key)
{
	if (!_name.size())
		return false;

	const DWORD bufferMaxSize = 256;
	char buffer[bufferMaxSize];
	DWORD size = bufferMaxSize;
	DWORD type;

	LONG res = RegQueryValueEx((HKEY)key,_name.c_str(),0,&type,(BYTE *) buffer,&size);
	if (res==ERROR_SUCCESS && type==REG_SZ)
	{
		set(buffer);
		return true;
	}

	return false;
}

#endif
