#ifndef REGISTRY_H
#define REGISTRY_H

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
	\brief   Field heirachy based registry
	\author  Nigel Stewart, RMIT (nigels@nigels.com)
	\ingroup Node
	\todo    Make Registry library?  Keybindings?  Scripting?  Undo/Redo?
*/

#include <string>
#include <iosfwd>
#include <list>

#include <node/field.h>
#include <node/fields.h>

class GltRegistryMenu;

/*! \clas    GltRegistry 
	\brief   Field Heirachy Container
	\ingroup Node
*/

class GltRegistry
{
	friend class GltRegistryMenu;

private:

	// Field registry can not be copied

	GltRegistry(const GltRegistry &);
	GltRegistry &operator=(const GltRegistry &);

public:

	/// Constructor
	GltRegistry();
	/// Destructor
	~GltRegistry();

	/// Set the root field for this registry
	void set(const GltFieldPtr &root);
	/// Reset this registry.
	void reset();
	/// Clear this registry.
	void clear();

	//
	// I/O
	//

	/// Write registry state to output stream
	bool write(std::ostream &os) const;
	/// Read registry state from input stream
	bool read(std::istream &os);

	/// Write registry state to output file
	bool write(const std::string &filename) const;
	/// Read registry state from input file
	bool read (const std::string &filename);

#ifdef GLT_WIN32
	/// Write registry state to Windows registry
	bool writeRegistry(const std::string &key) const;
	/// Read registry state from Windows registry
	bool readRegistry(const std::string &key);
#endif

	/// Set registry field by name
	bool set(const std::string &name,const std::string &value);
	/// Set registry fields from string buffer
	bool set(const std::string &settings);

private:
	GltFieldPtr               _root;
};

#endif
