#ifndef NODE_FIELD_H
#define NODE_FIELD_H

/*

  GLT OpenGL C++ Toolkit (LGPL)
  Copyright (C) 2000-2002 Nigel Stewart  

  Email: nigels@nigels.com   
  WWW:   http://www.nigels.com/glt/

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

/*! \file 
	\brief   Base class for field serialisation/menu system
	\ingroup Node
*/

#include <string>
#include <iosfwd>
#include <misc/refcount.h>

class GltRegistry;
class GltFields;

class GltField;

/// Reference counted field pointer
typedef ReferenceCountPtr<GltField> GltFieldPtr;

/*! \clas    GltField 
	\brief   Base class for field serialisation/menu system
	\ingroup Node
*/

class GltField
{
	friend class GltFields;
	friend class GltRegistry;

protected:
	GltField();
	GltField(const std::string &name);
	GltField(const GltField &);

	GltField &operator=(const GltField &);

public:

	virtual ~GltField();

	        std::string &name();
	        bool        &locked();

	  const std::string &name() const;

	virtual std::string get() const;
	virtual bool        set(const std::string &value);
	virtual bool        reset();
	virtual bool        isDefault() const;

	virtual bool write(std::ostream &os,const std::string &prefix = std::string()) const;

protected:

	std::string _name;

	#ifdef GLT_WIN32
	virtual bool writeRegistry(void *key) const;
	virtual bool readRegistry (void *key);
	#endif
};

////////////

/*! \clas    GltFieldFunc 
	\brief   Callback function field
	\ingroup Node

	\note 
		We'd like to migrate this into GltFields, but
		the microsoft compiler can't deal with it.
*/

template<class T>
class GltFieldFunc : public GltField
{
public:
	GltFieldFunc(T &obj,void (T::*func)(void),const std::string &name,const bool output = false)
	: GltField(name), _obj(&obj), _func(func), _output(output)
	{
	}

	GltFieldFunc(const GltFieldFunc &f)
	: GltField(f), _obj(f._obj), _func(f._func), _output(f._output)
	{
	}

	virtual ~GltFieldFunc()
	{
	}

	GltFieldFunc &operator=(const GltFieldFunc &f)
	{
		if (this!=&f)
		{
			_obj    = f._obj;	
			_func   = f._func;
			_output = f._output;
		}

		return *this;
	}

	bool write(std::ostream &os,const std::string &prefix = std::string()) const 
	{ 
		if (_output)
			GltField::write(os,prefix);
		
		return true;
	}

	bool set(const std::string &value)
	{
		(_obj->*(_func))();
		return true;
	}

private:

								/// Object to receive events
	T *_obj;
								/// Void object callback function
	void (T::*_func)(void);
								/// Functions can be optionally written to output
	const bool _output;      
};

#endif
