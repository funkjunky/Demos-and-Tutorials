#include <misc/image.h>
#include <misc/string.h>

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;

int dx = 0;
int dy = 0;
int n = 0;

vector<string> input;
string         output;

int main(int argc,char *argv[])
{
	if (argc<4)
	{
	}
	else
	{
		dx = atoi(argv[1]);
		dy = atoi(argv[2]);

		n = dx*dy;
		input.resize(n);

		cout << dx << 'x' << dy << endl;

		if (3+n>argc)
				return EXIT_FAILURE;

		string data;
		data.reserve(1024*1024*5);		// Optimise for images <5 Meg

		int lineSize,w,h;

		for (int i=0; i<n; i++)
		{
			string type;
			uint32 width,height;

			cout << i << ' ' << argv[3+i] << ' ';
			cout.flush();

			data.erase();
			readStream(ifstream(argv[3+i],ios::binary),data);
			if (!decodePPM(type,width,height,input[i],data))
				return EXIT_FAILURE;

			cout << type << ' ' << width << ' ' << height << endl;
			cout.flush();

			lineSize = width*3;
			w = width*dx;
			h = height*dy;
		}

		cout << "Stitching " << w << 'x' << h << " ..." << endl;
		cout.flush();

		stitchImages(output,dx,dy,input,lineSize);
		data.erase();
		encodePPM(data,w,h,output);
		cout << "Writing..." << endl;
		writeStream(ofstream("out.ppm",ios::binary),data);
	}

	return EXIT_SUCCESS;
}