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
#include <string>
#include <cassert>
using namespace std;

#include <misc/string.h>
#include <misc/compress.h>
#include <misc/image.h>

#include <glt/fontasci.h>
#include <glt/fontunic.h>
#include <glt/texture.h>
#include <glt/info.h>

// Cygwin defines this
#undef unix

bool font2src (ostream &os,string &data);
bool ufont2src(ostream &os,string &data);
bool image2src(ostream &os,string &data);

bool lzf = false;
bool zlib = false;
bool image = false;
bool alpha = false;		// Turn greyscale into alpha image
bool mirror = false;
bool flip = false;
bool font = false;
bool ufont = false;
bool unix = false;
bool dos = false;

int main(int argc,char *argv[])
{
	if (argc==1)
	{
		cout << endl;
		cout << "bin2src" << endl;
		cout << endl;
		cout << "C/C++ source code generation tool." << endl;
		cout << "GLT C++ OpenGL Toolkit" << endl;
		cout << "http://www.nigels.com/glt/" << endl;
		cout << endl;
		cout << "Usage: bin2src [OPTION]... SOURCE" << endl;
		cout << endl;
		cout << "  -c       Compress." << endl;
		#ifdef GLT_ZLIB
		cout << "  -z       zLib compress." << endl;
		#endif
		cout << "  -font    Convert from VGA font."       << endl;
		cout << "  -ufont   Convert from Unicode font."   << endl;
		cout << "  -image   Convert from image."          << endl;
		cout << "  -mirror  Mirror image horizontally."   << endl;
		cout << "  -flip    Flip image vertically."       << endl;
		cout << "  -u       Convert to UNIX text."        << endl;
		cout << "  -d       Convert to DOS/Windows text." << endl;
		cout << endl;
		cout << GltVersionInformation();

		return EXIT_FAILURE;
	}

	// Parse command-line options

	string filename;

	for (int i=1; i<argc; i++)
	{
		string arg(argv[i]);

		if (arg=="-c") { lzf = true;  continue;  }
		if (arg=="-z") { zlib = true; continue;  }

		if (arg=="-image")  { image = true;  continue; }
		if (arg=="-mirror") { mirror = true; continue; }
		if (arg=="-flip")   { flip = true;   continue; }

		if (arg=="-alpha") { alpha = true; continue; }
		if (arg=="-font")  { font = true;  continue; }
		if (arg=="-ufont") { ufont = true; continue; }

		if (arg=="-u") { unix = true; continue; }
		if (arg=="-d") { dos = true;  continue; }

		filename = arg;
	}

	// Read the file into memory

	string input;
	ifstream is(filename.c_str(),ios::in|ios::binary);
	::readStream(is,input);

	// Convert from PPM image

	if (image)
	{
		bool ok = image2src(cout,input);
		return ok ? EXIT_SUCCESS : EXIT_FAILURE;
	}
	
	//

	if (font)
	{
		bool ok = font2src(cout,input);
		return ok ? EXIT_SUCCESS : EXIT_FAILURE;
	}

	if (ufont)
	{
		bool ok = ufont2src(cout,input);
		return ok ? EXIT_SUCCESS : EXIT_FAILURE;
	}

	// Convert to DOS or UNIX ascii

	if (unix)
	{
		string tmp;
		dos2unix(tmp,input);
		input = tmp;
	}

	if (dos)
	{
		string tmp;
		unix2dos(tmp,input);
		input = tmp;
	}

	if (lzf || zlib)
	{
		// Compress it into a temporary buffer

		string zip;

		#ifdef GLT_ZLIB
		if (zlib)
			::compressZLib(zip,input,9);
		else
		#endif
			::compress(zip,input);

		// Check that it decompresses OK

		#ifndef NDEBUG
		string unzip;
		if (!::decompress(unzip,zip) || input!=unzip)
			cout << "/* Compression FAILED! */" << endl;
		#endif

		// Compression info

		cout << "/* Compressed data: " << input.size() << " -> " << zip.size() << " */" << endl;

		// Output
		::bin2src(cout,zip);
	}
	else
		::bin2src(cout,input);

	return EXIT_SUCCESS;
}

//////////////////////////////////////////////

bool font2src(ostream &os,string &data)
{
	if (data.size()%256)
	{
		cerr << "This file doesn't seem to be a VGA font." << endl;
		return false;
	}

	const int width = 8;
	const int height = data.size()>>8;

	/* Flip */

	{
		GLubyte *ptr = (GLubyte *) data.c_str();

		for (int i=0; i<256; i++,ptr+=height)
			for (int j=0; j<height/2; j++)
				swap(ptr[j],ptr[height-1-j]);
	}

	string head;
	GltFontAscii::makeHeader(head,width,height);
	cout << "/* Font data " << width << 'x' << height << " */" << endl;

	::bin2src(cout,head+data);
	return true;
}

bool ufont2src(ostream &os,string &data)
{
	//
	// On the first pass, create the index
	//

	const unsigned int maxChars = 0x10000;
	byte index[maxChars];
	memset(index,0,sizeof(index));

	char *p = (char *) data.c_str();
	uint32 i = 0;
	uint32 size = 0;

	for (;;)
	{
		// Convert hex index to integer
		// (sscanf is much slower than this)

		uint32 j =
			fromHex4(*(p++))<<12 |
			fromHex4(*(p++))<< 8 |
			fromHex4(*(p++))<< 4 |
			fromHex4(*(p++));

		// Skip colon
		p++;	
		
		// Find end-of-line
		char *n = p;
		while (*n!='\n' && *n!='\0') n++;
		if (*n=='\0') break;

		// Update size, and point to next line

		size += index[j] = (n-p)>>1;
		p = n+1;
	}

	//
	// On the second pass, create the raw font data
	//

	// Store raw data in string

	string output;
	output.resize(sizeof(index)+size);
	memcpy((void *) output.data(),index,sizeof(index));

	// Input buffer pointer

	p = (char *) data.c_str();

	// Output buffer pointer

	unsigned char *q = (unsigned char *) output.data();
	q += sizeof(index);

	for (;;)
	{
		// Find colon

		while (*p!=':' && *p!='\0') p++;
		if (p=='\0') break; else p++;
		
		// Find end-of-line

		char *n = p;
		while (*n!='\n' && *n!='\0') n++;
		if (*n=='\0') break;

		switch (n-p)	// Copy and vertical flip
		{
			// These loops could be optimised/unrolled

			case 32:
				{
					for (int j=30; j>=0; j-=2)
						*(q++) = fromHex4(p[j  ])<<4 | fromHex4(p[j+1]);
					break;
				}
			case 64:
				{
					for (int j=60; j>=0; j-=4)
					{
						*(q++) = fromHex4(p[j  ])<<4 | fromHex4(p[j+1]);
						*(q++) = fromHex4(p[j+2])<<4 | fromHex4(p[j+3]);
					}
					break;
				}
			default:
				return false;
		}
	}

	if (lzf || zlib)
	{
		string zip;
		#ifdef GLT_ZLIB
		if (zlib)
			::compressZLib(zip,output,9);
		else
		#endif
			::compress(zip,output);
		data += zip;

		string head;
		GltFontUnicode::makeHeader(head,1);

		cout << "/* Compressed Unicode Font: " << zip.size() << " bytes */" << endl;
		::bin2src(cout,head+zip);
	}
	else
	{
		string head;
		GltFontUnicode::makeHeader(head,0);

		cout << "/* Unicode Font: " << output.size() << " bytes */" << endl;
		::bin2src(cout,head+output);
	}

	return true;
}

bool image2src(ostream &os,string &data)
{
	string type,image;
	uint32 width;
	uint32 height;

	bool ok = decode(width,height,image,data);

	if (!ok)
	{
		cerr << "Image file not recognized." << endl;
		return false;
	}

	const int compress = lzf || zlib;

	if (flip)
	{
		string tmp;
		flipImage(tmp,image,width,height);
		image = tmp;
	}

	if (mirror)
	{
		string tmp;
		mirrorImage(tmp,image,width,height);
		image = tmp;
	}

	//
	// RGB image
	//

	if (width*height*3==image.size())
	{
		if (isGreyscale(image))
		{
			// Extract grey from the red channel
			string grey;
			getChannel(grey,image,3,0);
			image = grey;

			// Create header & code comment
			GltTexture::makeHeader(data,GltTexture::TEXTURE_TYPE_GREY,width,height,1,compress);
			cout << "/* Image data " << width << 'x' << height << " Grey */" << endl;
		}
		else
			if (is256Colors(image))
			{
				// Convert from RGB to indexed
				string indexed;
				rgb2Indexed(indexed,image);
				image = indexed;

				// Create header & code comment
				GltTexture::makeHeader(data,GltTexture::TEXTURE_TYPE_INDEXED_RGB,width,height,1,compress);
				cout << "/* Image data " << width << 'x' << height << " Indexed */" << endl;
			}
			else
			{
				GltTexture::makeHeader(data,GltTexture::TEXTURE_TYPE_RGB,width,height,3,compress);
				cout << "/* Image data " << width << 'x' << height << " RGB */" << endl;
			}
	}
	else

		//
		// RGBA Image
		//

		if (width*height*4==image.size())
		{
			GltTexture::makeHeader(data,GltTexture::TEXTURE_TYPE_RGBA,width,height,4,compress);
			cout << "/* Image data " << width << 'x' << height << " RGBA */" << endl;
		}
		else

			//
			// Greyscale Image
			//

			if (width*height==image.size())
			{
				// Convert to white with alpha channel, if specified

				if (alpha)
				{
					GltTexture::makeHeader(data,GltTexture::TEXTURE_TYPE_GREYA,width,height,1,compress);
					cout << "/* Image data " << width << 'x' << height << " Grey+Alpha */" << endl;

					// Combine white image with alpha channel

					string tmp;
					tmp.resize(image.size()<<1);

					size_t i = 0;
					size_t j = 0;
					while (i<image.size())
					{
						tmp[j++] = char(255);
						tmp[j++] = image[i++];
					}

					image = tmp;
				}
				else
				{
					GltTexture::makeHeader(data,GltTexture::TEXTURE_TYPE_GREY,width,height,1,compress);
					cout << "/* Image data " << width << 'x' << height << " Grey */" << endl;
				}
			}
			else

				//
				// Greyscale with Alpha Image
				//
	
				if (width*height*2==image.size())
				{
					GltTexture::makeHeader(data,GltTexture::TEXTURE_TYPE_GREYA,width,height,2,compress);
					cout << "/* Image data " << width << 'x' << height << " Grey+Alpha */" << endl;
				}
				else
					return false;

	// Do compression, if necessary

	if (compress)
	{
		string zip;
		#ifdef GLT_ZLIB
		if (zlib)
			::compressZLib(zip,image,9);
		else
		#endif
			::compress(zip,image);
		data += zip;

		cout << "/* Compressed: " << image.size() << " -> " << zip.size() << " */" << endl;
		::bin2src(cout,data);
	}
	else
	{
		data += image;
		::bin2src(cout,data);
	}

	return true;
}
