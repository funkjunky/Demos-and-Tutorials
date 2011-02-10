#include "text2src.h"

/*! \file 
	\brief   Routines for converting data to C/C++ source code
	\ingroup Misc
*/

#include <iostream>
#include <iomanip>
using namespace std;

//

void text2source(ostream &os,istream &is)
{
	bool firstLine = true;
	bool empty = true;

	while (1)
	{
		const int bufferSize = 1024;
		char buffer[bufferSize];

		if (!is.getline(buffer,bufferSize))
			break;
	
		empty = false;

		if (firstLine)
			firstLine = false;
		else
			os << "\\n\"" << '\\' << endl;

		char output[bufferSize*2];
		int p1 = 0,p2 = 0;

		while (buffer[p1]!='\0')
		{
			switch (buffer[p1])
			{
			case '\"':
			case '\\':
				output[p2++] = '\\';
				break;
			}

			output[p2++] = buffer[p1++];
		}

		output[p2] = '\0';

		os << '\"' << output;
	}

	if (!empty)
		os << "\\n\";" << endl;
}

//

void binary2source(ostream &os,istream &is)
{
	os.setf(ios::hex,ios::basefield);

	os << '{' << endl;
	
	bool begin = true;
	while (is.good() && !is.eof())
	{
		unsigned char buffer[16];
		is.read((char *) buffer,16);
		
		int size = is.gcount();
		if (size>0 && !begin)
		{
			os << ',';
			os << endl;
		}

		begin = false;

		for (int i=0; i<size;i++)
		{
			os << "0x" << setw(2) << setfill('0') << (unsigned int)buffer[i];
			if (i<size-1)
				os << ',';
		}

	}

	os << endl << "};" << endl;
}

