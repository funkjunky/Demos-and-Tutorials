#include "read3dsb.h"

#ifdef WIN32
#pragma warning(disable : 4786)     // Lengthy STL symbols
#endif

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#include <math/point.h>

ostream *read3DSbinaryDebugStream = NULL;
int      read3DSbinaryDebugLevel  = 1;
int      tab = 0;

#define DOUT(level) \
	if (read3DSbinaryDebugStream && read3DSbinaryDebugLevel>=(level)) (*read3DSbinaryDebugStream)

#define TAB(level) \
	for (int t=0;t<tab;t++) DOUT(level) << ' ';
 
void (*callback)(vector<Point> &vertex,vector<TriangleIndex> &triangle,const string &name) = NULL;

typedef unsigned short chunkID;
typedef unsigned int   chunkSize;

chunkID readChunk ( istream &is, chunkSize &size );
void    eatChunk  ( istream &is, const chunkSize size );
char   *readString( istream &is);

void readMain    ( istream &is, chunkSize size );
void readEditor  ( istream &is, chunkSize size );
void readObject  ( istream &is, chunkSize size );
void readMesh    ( istream &is, chunkSize size,char *name );
void readMaterial( istream &is, chunkSize size);

void 
read3DSbinary
(
	istream &is,
	void (*outputCallback)(vector<Point> &vertex,vector<TriangleIndex> &triangle,const string &name)
)
{
	callback = outputCallback;
	tab = 0;

	chunkSize size;
	chunkID   id = readChunk(is,size);
	
	switch (id)
	{
	case 0x4d4d:
		readMain(is,size-6);
		break;
	case 0xc23d:
		readMain(is,size-6);
		break;
	}

	callback = NULL;
}


chunkID 
readChunk( istream &is, chunkSize &size )
{
	char chunkHeader[6];
	is.read(chunkHeader,6);

	if (is.gcount()!=6)
		return 0;

	chunkID id;

	id   = *((chunkID *) &chunkHeader[0]);
	size = *((chunkSize *) &chunkHeader[2]);

	TAB(1);
	DOUT(1) << "Chunk 0x" << hex << id << " (" << dec << size << " bytes.)" << endl; 

	return id;
}

void
eatChunk( istream &is, const chunkSize size )
{
	char *buffer = new char [size];
	is.read(buffer,size);
	delete [] buffer;
}

char *
readString( istream &is)
{
	vector<char> string;

	int size = 1;
	for (;;size++)
	{
		char buffer;
		is.read(&buffer,1);
		
		string.push_back(buffer);

		if (buffer=='\0')
			break;
	}

	char *buffer = new char [size];

	return 	strcpy(buffer,&(string[0]));
}


void 
readMain( istream &is, chunkSize size )
{
	tab++;

	while (1)
	{
		chunkSize subChunkSize = 0;
		chunkID   subChunkID = 0;

		if (!(subChunkID = readChunk(is,subChunkSize))) break;

		switch (subChunkID)
		{
		case 0x3d3d:						// Editor info, including Objects
			readEditor(is,subChunkSize-6);
			break;
		case 0x4130:						// Face Material
			readMaterial(is,subChunkSize-6);
			break;
		default:
			eatChunk(is,subChunkSize-6);
		}

		if (!subChunkID || size<subChunkSize)
			break;

		size -= subChunkSize;
	}

	tab--;
}

void 
readEditor( istream &is, chunkSize size )
{
	tab++;

	while (1)
	{
		chunkSize subChunkSize = 0;
		chunkID   subChunkID = 0;

		if (!(subChunkID = readChunk(is,subChunkSize))) break;

		switch (subChunkID)
		{
		case 0x4000:						// Object
			readObject(is,subChunkSize-6);
			break;
		case 0x4130:						// Face Material
			readMaterial(is,subChunkSize-6);
			break;
		default:
			eatChunk(is,subChunkSize-6);
		}

		if (size<subChunkSize)
			break;

		size -= subChunkSize;
	}

	tab--;
}

void 
readObject( istream &is, chunkSize size )
{
	tab++;

	char *name = readString(is);
	
	size -= strlen(name);

	TAB(1);
	DOUT(1) << "object : " << '\'' << name << '\'' << endl;

	while (1)
	{
		chunkSize subChunkSize = 0;
		chunkID   subChunkID = 0;

		if (!(subChunkID = readChunk(is,subChunkSize))) break;

		switch (subChunkID)
		{
		case 0x4100:						// Object
			readMesh(is,subChunkSize-6,name);
			break;
		case 0x4130:						// Face Material
			readMaterial(is,subChunkSize-6);
			break;
		default:
			eatChunk(is,subChunkSize-6);
		}

		if (!subChunkID || size<subChunkSize)
			break;

		size -= subChunkSize;
	}

	delete [] name;

	tab--;
}

void 
readMesh  ( istream &is, chunkSize size,char *name )
{
	tab++;

	vector<Point> vertex;
	vector<TriangleIndex> triangle;

	while (1)
	{
		chunkSize subChunkSize = 0;
		chunkID   subChunkID = 0;

		if (!(subChunkID = readChunk(is,subChunkSize))) break;

		switch (subChunkID)
		{
		case 0x4110:						// Vertex List
			{
				unsigned short number;
				is.read((char *) (void *) &number,2);

				TAB(1);
				DOUT(1) << "vertex list: " << number << " points." << endl;

				char buffer[12];

				for (int n=0;n<number;n++)
				{
					is.read(buffer,12);
					vertex.push_back
					( 
						Point
						(
							Vector
							(
								*((float *) &buffer[0]),
								*((float *) &buffer[4]),
								*((float *) &buffer[8])
							),
							Vector0
						)

					);

					TAB(2);
					DOUT(2) << vertex.back() << endl;
				}
			}
			break;
		case 0x4120:						// Face List
			{
				unsigned short number;
				is.read((char *) (void *) &number,2);

				TAB(1);
				DOUT(1) << "face list: " << number << " faces." << endl;

				char buffer[8];

				for (int n=0;n<number;n++)
				{
					is.read(buffer,8);

					TriangleIndex tri;

					tri.a = *((unsigned short *) &buffer[0]);
					tri.b = *((unsigned short *) &buffer[2]);
					tri.c = *((unsigned short *) &buffer[4]);

					if (tri.a>=vertex.size() || tri.b>=vertex.size() || tri.c>=vertex.size())
						cerr << "Error: Face data out of range." << endl;
					else
					{
						triangle.push_back(tri);

						TAB(2);
						DOUT(2) << tri.a << ',' << tri.b << ',' << tri.c << endl;
					}
				}
			}
			break;
		case 0x4130:						// Face Material
			readMaterial(is,subChunkSize-6);
			break;
		default:
			eatChunk(is,subChunkSize-6);
		}

		if (!subChunkID || size<subChunkSize)
			break;

		size -= subChunkSize;
	}

	if (callback)
		callback(vertex,triangle,name);

	tab--;
}

void 
readMaterial( istream &is, chunkSize size)
{
	TAB(1);
	DOUT(1) << "material : ";

	char *material = readString(is);

	DOUT(1) << '\'' << material << '\'';

	unsigned short number;
	is.read((char *) (void *) &number,2);

	DOUT(1) << ' ' << number << " faces." << endl;

	for (int n=0; n<number; n++)
	{
		unsigned short index;
		is.read((char *) (void *) &index,2);

		TAB(2);
		DOUT(2) << index << endl;
	}
}
