/*

  Glt OpenGL C++ Toolkit (Glt)
  Copyright (C) 2000-2002 Nigel Stewart
  Email: nigels@nigels.com   WWW: http://www.nigels.com/glt/

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

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#include <glt/config.h>
#include <misc/text2src.h>

int main(int argc,char *argv[])
{
	if (argc==1)
	{
		cout << "text2src,bin2src" << endl;
		cout << "Part of the Glt Library: http://www.nigels.com/glt/" << endl;
		cout << endl;
		cout << "Usage: text2src [file]" << endl;

		return EXIT_FAILURE;
	}

	ifstream is(argv[1]);
	text2source(cout,is);

	return EXIT_SUCCESS;
}
