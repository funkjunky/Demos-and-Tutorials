#include "image.h"

/*! \file 
	\brief   Image utility routines 
	\ingroup Misc
*/

#include <misc/endian.h>
#include <glt/color.h>

#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>

#include <set>
#include <map>
#include <list>
#include <iostream>
using namespace std;

bool isGreyscale(const string &rgb)
{
	assert(rgb.size()%3==0);

	if (rgb.size()%3)
		return false;

	for (size_t i=0; i<rgb.size(); i+=3)
		if (rgb[i]!=rgb[i+1] || rgb[i]!=rgb[i+2])
			return false;

	return true;
}

bool is256Colors(const string &rgb)
{
	assert(rgb.size()%3==0);

	if (rgb.size()%3)
		return false;

	set<uint32> colors;

	for (size_t i=0; i<rgb.size(); i+=3)
	{
		const uint32 col = (byte(rgb[i])<<16) | (byte(rgb[i+1])<<8) | byte(rgb[i+2]);

		colors.insert(col);

		if (colors.size()>256)
			return false;
	}

	return true;
}

void getChannel(string &dest,const string &rgb,const uint32 size,const uint32 channel)
{
	assert(rgb.size()%size==0);
	assert(channel<size);

	if (rgb.size()%size || channel>=size)
		return;

	dest.resize(rgb.size()/size);

	for (size_t i=channel,j=0; i<rgb.size(); i+=size,j++)
		dest[j] = rgb[i];
}

void rgb2Indexed(string &dest,const string &rgb)
{
	assert(rgb.size()%3==0);

	if (rgb.size()%3)
		return;

	// Output buffer will begin with lookup-table, 
	// followed by pixel indexes

	const int tableSize = 256*3;
	dest.resize(tableSize+rgb.size()/3);

	// First find the first 256 unique colors
	// we initialise lookup-table as we go

	map<uint32,byte> colors;

	for (size_t i=0,j=0; i<rgb.size();)
	{
		const uint32 col = (byte(rgb[i])<<16) | (byte(rgb[i+1])<<8) | byte(rgb[i+2]);
		
		// Is this a new colour?

		if (colors.find(col)==colors.end())
		{
			// Add it
			colors.insert(make_pair(col,j/3));

			// Copy it into lookup-table
			dest[j++] = rgb[i++];
			dest[j++] = rgb[i++];
			dest[j++] = rgb[i++];

			// Stop if we've found them all
			if (colors.size()==256)
				break;
		}
		else
			i += 3;
	}

	// Now use map to convert pixels to indexes

	{
		for (size_t i=0,j=tableSize; i<rgb.size(); i+=3,j++)
		{
			const uint32 col = (byte(rgb[i])<<16) | (byte(rgb[i+1])<<8) | byte(rgb[i+2]);
			assert(colors.find(col)!=colors.end());
			dest[j] = colors[col];
		}
	}
}

void indexed2rgb(string &dest,const string &indexed)
{
	const int tableSize = 256*3;
	const int pixels = indexed.size()-tableSize;

	assert(pixels>=0);
	if (pixels<0)
		return;

	dest.resize(pixels*3);

	for (size_t i=tableSize,j=0; i<indexed.size(); i++,j+=3)
	{
		const size_t p = 3*(byte)(indexed[i]);

		dest[j]   = indexed[p];
		dest[j+1] = indexed[p+1];
		dest[j+2] = indexed[p+2];
	}
}

void flipImage(string &dest,const string &src,const int width,const int height)
{
	const int lineSize = src.size()/height;

	assert(lineSize>0);
	assert(src.size()%lineSize==0);

	if (lineSize==0 || src.size()%lineSize!=0)
		return;

	dest.resize(src.size());

	const char *i = src.c_str();
	const char *j = dest.c_str()+dest.size()-lineSize;

	for (int k=0; k<height; i+=lineSize,j-=lineSize,k++)
		memcpy((void *)j,i,lineSize);
}

void 
mirrorImage(std::string &dest,const std::string &src,const int width,const int height)
{
	const int lineSize = static_cast<int>(src.size())/height;
	const int channels = lineSize/width;

	assert(channels>0);
	assert(src.size()%lineSize==0);
	assert(src.size()==width*height*channels);

	if (channels==0 || src.size()%lineSize!=0 || src.size()!=width*height*channels)
		return;

	dest.resize(src.size());

	const char *i = src.c_str();
	const char *j = dest.c_str()+lineSize-channels;

	for (int k=0; k<height; j+=lineSize*2,k++)
		for (int l=0; l<width; i+=channels,j-=channels,l++)
			memcpy((void *)j,i,channels);
}

void adjustGamma(std::string &image,const double gamma)
{
	byte table[256];
	for (int i=0; i<256; i++)
		table[i] = (byte) floor( pow(double(i)/255.0, 1.0/gamma)*255.0 + 0.5);

	      byte *j   =       (byte *) image.c_str();
	const byte *end = (const byte *) image.c_str() + image.size();

	for (;j<end;j++)
		*j = table[*j];
}

void 
adjustHSV
(
	std::string &image,
	const int width,
	const int height,
	const real hue,
	const real saturation,
	const real value
)
{
	const int channels = image.size()/(width*height);
	assert(channels*width*height==image.size());

	      byte *i   =       (byte *) image.data();
	const byte *end = (const byte *) image.data() + image.size();

	for (;i<end;i+=channels)
	{
		GltColor col(*i/255.0,*(i+1)/255.0,*(i+2)/255.0);
		
		real h,s,v;
		col.toHSV(h,s,v);

		h = fmod(h+hue+360.0,360.0);
		s = CLAMP(s+saturation,0.0,1.0);
		v = CLAMP(v+value,0.0,1.0);

		col.fromHSV(h,s,v);

		*i     = (byte) floor(col.red()  *255.0+0.5);
		*(i+1) = (byte) floor(col.green()*255.0+0.5);
		*(i+2) = (byte) floor(col.blue() *255.0+0.5);
	}
}

bool stitchImages(string &image,const int dx,const int dy,const vector<string> &src,const int lineSize)
{
	const int n=src.size();

	if (dx<1 || dy<1 || dx*dy!=n)
		return false;

	const int tileSize = src[0].size();

	// Allocate size of output image
	image.resize(n*tileSize);

	// Process each input in turn

	for (int y=0; y<dy; y++)
		for (int x=0; x<dx; x++)
		{
			const int k = x+y*dx;

			      byte *i    =       (byte *) image.data()+x*lineSize+y*dx*tileSize;
			const byte *iMax = (const byte *) image.data()+image.size();
			const byte *j    = (const byte *) src[k].data();
			const byte *jMax = (const byte *) src[k].data() + src[k].size(); 

			while (i<iMax && j<jMax)
			{
				memcpy(i,j,lineSize);
				i += lineSize*dx;
				j += lineSize;
			}
		}

	return true;
}

//
// Image decoding
//

bool decode(uint32 &width,uint32 &height,std::string &image,const std::string &data)
{
	string type;

	// PPM

	if (decodePPM(type,width,height,image,data))
		return true;
	
	// BMP

	if (decodeBMP(width,height,image,data))
		return true;

	// PNG

	#ifdef GLT_PNG
	if (decodePNG(width,height,image,data))
		return true;
	#endif

	// TGA

	return decodeTGA(width,height,image,data);
}

bool decodePPM(string &type,uint32 &width,uint32 &height,string &image,const string &data)
{
	if (data.size()<1 || data[0]!='P')
		return false;

	//

	size_t channels = 0;

	if (data[1]=='6')	// 24-bit binary RGB PPM file
	{
		channels = 3;
		type = "P6";
	}
	else
		if (data[1]=='5')	// 8-bit binary greyscale PGM file 
		{
			channels = 1;
			type = "P5";
		}
		else
			return false;

	//

	const string eol("\n");
	const string digits("0123456789");

	size_t i = 0;
	
	int depth = 0;

	for (;;)
	{
		// Find end-of-line

		i = data.find_first_of(eol,i);
		if (i==string::npos)
			break;
		else
			i++;

		// If this line is a comment, try next line

		if (data[i]=='#')
			continue;
		
		// Get width

		width = atoi(data.c_str()+i);
		i = data.find_first_not_of(digits,i); if (i==string::npos) break;
		i = data.find_first_of(digits,i);     if (i==string::npos) break;

		// Get height

		height = atoi(data.c_str()+i);
		i = data.find_first_not_of(digits,i); if (i==string::npos) break;
		i = data.find_first_of(digits,i);     if (i==string::npos) break;

		// Get depth

		depth = atoi(data.c_str()+i);
		i = data.find(eol,i); 
		if (i!=string::npos) 
			i++;

		break;
	}

	// Check that PPM seems to be valid

	const uint32 imageSize = width*height*channels;
	const uint32 rowSize   = width*channels;

	if (width!=0 && height!=0 && depth==255 && imageSize==data.size()-i)
	{
		// Extract image from input & flip
		flipImage(image,data.substr(i),width,height);
	}

	return true;
}

bool decodeBMP(uint32 &width,uint32 &height,string &image,const string &data)
{
	//
	// For information about the BMP File Format:
	//
	// http://www.daubnet.com/formats/BMP.html
	// http://www.dcs.ed.ac.uk/home/mxr/gfx/2d/BMP.txt
	//

	const uint32 fileHeaderSize = 14;
	if (data.size()<fileHeaderSize)
		return false;

	// Check for "BM" 

	if (data[0]!='B' || data[1]!='M') 
		return false;

	// Check the filesize matches string size

	const uint32 fileSize = littleEndian((uint32 *)(data.data()+2));
	if (data.size()!=fileSize)
		return false;

	// Get the size of the image header

	const uint32 imageHeaderSize = littleEndian((uint32 *)(data.data()+fileHeaderSize));
	if (fileHeaderSize+imageHeaderSize>data.size())
		return false;

	// Get some image info

	const uint32 imageWidth    = littleEndian((uint32 *)(data.data()+fileHeaderSize+4 ));
	const uint32 imageHeight   = littleEndian((uint32 *)(data.data()+fileHeaderSize+8 ));
	const uint16 imageBits     = littleEndian((uint16 *)(data.data()+fileHeaderSize+14));
	const uint32 imageCompress = littleEndian((uint32 *)(data.data()+fileHeaderSize+16));

	// Do some checking

	// We support only RGB images

	if (imageBits!=24)
		return false;		

	// We don't support compressed BMP.
	//
	// According to the specs, 4-bit and 8-bit RLE
	// compression is used only for indexed images.

	if (imageCompress!=0)
		return false;		

	const uint32 imagePos    = littleEndian((uint32 *)(data.data()+10));
	const uint32 imagePixels = imageWidth*imageHeight;
	const uint32 lineBytes   = (imageWidth*3+3)&~3;
	const uint32 imageBytes  = lineBytes*imageHeight;

	if (imagePos+imageBytes!=data.size())
		return false;

	// Extract the image

	width  = imageWidth;
	height = imageHeight;
	image.resize(imagePixels*3);
	
	// Destination iterator

	byte *i = (byte *) image.data();

	for (uint32 y=0; y<imageHeight; y++)
	{
		// Source iterator, beginning of y-th scanline

		const byte *j = (const byte *) data.data()+imagePos+lineBytes*y;

		// Copy the scanline, swapping red and blue channels
		// as we go...

		for (uint32 x=0; x<imageWidth; x++)
		{
			*(i++) = *(j++ + 2);		
			*(i++) = *(j++);
			*(i++) = *(j++ - 2);
		}
	}

 	return true;
}

bool 
decodeTGA(uint32 &width,uint32 &height,string &image,const string &data)
{
	// Check that header appears to be valid

	const uint32 tgaHeaderSize = 18;
	if (data.size()<tgaHeaderSize)
	{
		cerr << "TGA Header seems to be invalid." << endl;
		return false;
	}

	// We only handle type 1, 2 and 10, for the moment

	const uint32 tgaType = data[2];

	if (tgaType!=1 && tgaType!=2 && tgaType!=10)
	{
		cerr << "Found TGA type: " << tgaType << endl;
		return false;
	}

	// There should be a color map for type 1

	if (tgaType==1 && data[1]!=1)
	{
		cerr << "Expecting color map in type 1 TGA." << endl;
		return false;
	}
	
	// We only handle 24 bit or 32 bit images, for the moment

	uint32 bytesPerPixel=0;

	if (tgaType==1)
		bytesPerPixel = data[7]==24 ? 3 : 4;	// Color mapped
	else
		bytesPerPixel = data[16]==24 ? 3 : 4;	// Unmapped
	
	if (bytesPerPixel!=3 && bytesPerPixel!=4)
	{
		cerr << "Found TGA pixel depth: " << bytesPerPixel << endl;
		return false;
	}

	// Color map information

	const byte idSize = data[0];	// Upto 255 characters of text

	const uint16 origin   = littleEndian((uint16 *)(data.data()+3));
	const uint16 length   = littleEndian((uint16 *)(data.data()+5));
	const byte   size     = data[7]>>3;
	const uint32 mapSize  = length*size;
	const byte   *mapData = (const byte *) data.data()+tgaHeaderSize+idSize;

	//

	width  = littleEndian((uint16 *)(data.data()+12));
	height = littleEndian((uint16 *)(data.data()+14));

	// Check if TGA file seems to be the right size
	// (TGA allows for descriptive junk at the end of the
	//  file, we just ignore it)

	switch (tgaType)
	{
	case 1:		// Indexed
		{
			// TODO 
		}
		break;

	case 2:		// Unmapped RGB(A)
		{
			if (data.size()<tgaHeaderSize+idSize+width*height*bytesPerPixel)
				return false;
		}
		break;

	case 10:	// Compressed RGB(A)
		{
			// TODO
		}
		break;
	}


	image.resize(width*height*bytesPerPixel);

	// Destination iterator

	      byte *i = (byte *) image.data();				             // Destination
	const byte *j = (const byte *) data.data()+tgaHeaderSize+idSize+mapSize;     // Source

	switch (tgaType)
	{

		// Indexed

		case 1:
			{
				const uint32 pixels = width*height;

				for (uint32 p=0; p<pixels; p++)
				{
					const byte *entry = mapData+(*(j++))*bytesPerPixel;

					*(i++) = entry[2];
					*(i++) = entry[1];
					*(i++) = entry[0];

					if (bytesPerPixel==4)
						*(i++) = entry[3];
				}
			}
			break;

		// Unmapped RGB(A)

		case 2:	
			{
				for (uint32 y=0; y<height; y++)
				{
					// Copy the scanline, swapping red and blue channels
					// as we go...

					for (int x=0; x<width; x++)
					{
						*(i++) = *(j++ + 2);		
						*(i++) = *(j++);
						*(i++) = *(j++ - 2);

						if (bytesPerPixel==4)
							*(i++) = *(j++);	// Copy alpha
					}
				}
			}
			break;

		// Run Length Encoded, RGB(A) images 

		case 10:
			{
				const byte *iMax = (const byte *) image.data()+image.size();
				const byte *jMax = (const byte *) data.data()+data.size();

				while (i<iMax && j<jMax)
				{
					const bool rle   = ((*j)&128)==128;
					const int  count = ((*j)&127) + 1;

					j++;

					// Check if we're running out of output buffer
					if (i+count*bytesPerPixel>iMax)
						return false;

					if (rle)
					{
						// Check if we're running out of input data
						if (j+bytesPerPixel>jMax)
							return false;

						byte *pixel = i;

						// Get the next pixel, swapping red and blue

						*(i++) = *(j++ + 2);		
						*(i++) = *(j++);
						*(i++) = *(j++ - 2);

						if (bytesPerPixel==4)
							*(i++) = *(j++);	// Copy alpha

						// Now duplicate for rest of the run

						for (int k=0; k<count-1; k++,i+=bytesPerPixel)
							memcpy(i,pixel,bytesPerPixel);
					}
					else
					{
						// Check if we're running out of input data
						if (j+count*bytesPerPixel>jMax)
							return false;

						// Copy pixels, swapping red and blue as
						// we go...

						for (int k=0; k<count; k++)
						{
							*(i++) = *(j++ + 2);		
							*(i++) = *(j++);
							*(i++) = *(j++ - 2);

							if (bytesPerPixel==4)
								*(i++) = *(j++);	// Copy alpha
						}

					}
				}

				if (i!=iMax)
					return false;
			}	
			break;
	}

	// If the TGA origin is top-right
	// flip image

	if ((data[17]&32)==32)
	{
		// TODO - in-place flip
		string tmp = image;
		flipImage(image,tmp,width,height);
	}

	return true;
}

//

#ifdef GLT_PNG

#include <png.h>

class GltPngReader
{
public:

	GltPngReader(const std::string &data,png_structp png_ptr)
	: pos(data.c_str()), end(data.c_str()+data.size())
	{
		png_set_read_fn(png_ptr,this,(png_rw_ptr) &GltPngReader::read);
	}

	size_t remaining() const { return end-pos; }

private:

	static void read(png_structp png_ptr, png_bytep data, png_uint_32 length)
	{
		GltPngReader *reader = (GltPngReader *) png_get_io_ptr(png_ptr); 

		assert(reader);
		if (!reader)
			return;

		const char *&pos = reader->pos;
		const char *&end = reader->end;

		assert(pos);
		assert(end);
	
		if (pos && end)
		{
			if (pos+length<=end)
			{
				memcpy(data,pos,length);
				pos += length;
			}
			else
			{
				memcpy(data,pos,end-pos);
				pos = end = NULL;
			}
		}
	}

	const char *pos;
	const char *end;
};

class GltPngWriter
{
public:

	GltPngWriter(std::string &data,png_structp png_ptr)
	: _png(png_ptr), _data(data), _size(0)
	{
		png_set_write_fn(_png,this,(png_rw_ptr) &GltPngWriter::write,(png_flush_ptr) &GltPngWriter::flush);
	}

	~GltPngWriter()
	{
		GltPngWriter::flush(_png);
		png_set_write_fn(_png,NULL,NULL,NULL);
	}

private:

	static void write(png_structp png_ptr, png_bytep data, png_uint_32 length)
	{
		GltPngWriter *writer = (GltPngWriter *) png_get_io_ptr(png_ptr); 

		assert(writer);
		if (!writer)
			return;

		list<string> &blocks = writer->_blocks;
		size_t       &size   = writer->_size;
	
		if (length>0)
		{
			blocks.push_back(string());
			string &block = blocks.back();
			block.resize(length);
			memcpy((void *) block.data(),data,length);
			size += length;
		}
	}

	static void flush(png_structp png_ptr)
	{
		GltPngWriter *writer = (GltPngWriter *) png_get_io_ptr(png_ptr); 

		assert(writer);
		if (!writer)
			return;

		string       &data   = writer->_data;
		list<string> &blocks = writer->_blocks;
		size_t       &size   = writer->_size;

		if (size>0)
		{
			size_t begin = data.size();
			data.resize(begin+size);
			for (list<string>::iterator i=blocks.begin(); i!=blocks.end(); i++)
			{
				memcpy((void *)(data.data()+begin),(void *) i->data(),i->size());
				begin += i->size();
			}
			blocks.clear();
			size = 0;
		}
	}

	png_structp   _png;
	string       &_data;
	list<string>  _blocks;
	size_t        _size;
};

//

bool
decodePNG(uint32 &width,uint32 &height,std::string &image,const std::string &data)
{
	const char *pngSignature = "\211PNG\r\n\032\n";
   	if (data.size()<8 || strncmp(data.c_str(),pngSignature,8))
		return false;

	png_structp png_ptr = 
		png_create_read_struct(PNG_LIBPNG_VER_STRING,(png_voidp) NULL,NULL,NULL);

	if (!png_ptr)
		return false;

	png_infop info_ptr = png_create_info_struct(png_ptr);

	if (!info_ptr)
	{
		png_destroy_read_struct(&png_ptr,(png_infopp)NULL, (png_infopp)NULL);
        	return false;
	}

//  png_init_io(png_ptr, fp);

	GltPngReader read(data,png_ptr);

	png_read_info(png_ptr, info_ptr);

	int bit_depth, color_type, interlace_type,
        compression_type, filter_type;

	png_uint_32 w,h;

	png_get_IHDR(png_ptr, info_ptr, &w, &h,
                 &bit_depth, &color_type, &interlace_type,
                 &compression_type, &filter_type);

	width = w;
	height = h;

	// TODO - Handle other bit-depths

	if (bit_depth<8)
		png_set_packing(png_ptr);

	if (bit_depth==16)
		png_set_strip_16(png_ptr);

	int channels = png_get_channels(png_ptr,info_ptr);

	switch (color_type)
	{
		case PNG_COLOR_TYPE_GRAY:       image.resize(width*height);   break;
		case PNG_COLOR_TYPE_GRAY_ALPHA: image.resize(width*height*2); break;
		case PNG_COLOR_TYPE_RGB:        image.resize(width*height*3); break;
		case PNG_COLOR_TYPE_RGB_ALPHA:  image.resize(width*height*4); break;
		case PNG_COLOR_TYPE_PALETTE:    
			image.resize(width*height*3); 
			png_set_palette_to_rgb(png_ptr);
			break;
	}

	int rowbytes = image.size()/height;
	assert(image.size()==rowbytes*height);

	const char **row_pointers = (const char **) malloc(height*sizeof(char *));
	for(int i=0;i<height;i++)
		row_pointers[i] = image.c_str() + rowbytes*(height-1-i);

	png_read_image(png_ptr, (png_bytepp)row_pointers);

	free(row_pointers);
	free(info_ptr);
	free(png_ptr);

	return true;
}

bool 
encodePNG(std::string &data,const uint32 &width,const uint32 &height,const std::string &image)
{
	png_structp png_ptr =
		png_create_write_struct(PNG_LIBPNG_VER_STRING,(png_voidp) NULL,NULL,NULL);
	
	if (!png_ptr)
		return false;

	png_infop info_ptr = png_create_info_struct(png_ptr);

	if (!info_ptr)
	{
		png_destroy_write_struct(&png_ptr,(png_infopp)NULL);
        	return false;
	}

	{
		GltPngWriter write(data,png_ptr);
	
		const int channels   = image.size()/(width*height);
		const int bit_depth  = 8;
		      int color_type = 0; 

		switch (channels)
		{
			case 1:	color_type = PNG_COLOR_TYPE_GRAY;       break;
			case 2: color_type = PNG_COLOR_TYPE_GRAY_ALPHA; break;
			case 3: color_type = PNG_COLOR_TYPE_RGB;        break;
			case 4: color_type = PNG_COLOR_TYPE_RGB_ALPHA;  break;
		}

		assert(color_type);

		png_set_IHDR(
			png_ptr,info_ptr,width,height,bit_depth,color_type,
			PNG_INTERLACE_ADAM7,PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
	
		png_set_strip_16(png_ptr);
		png_set_packing(png_ptr);

		int rowbytes = image.size()/height;
		assert(image.size()==rowbytes*height);

		const char **row_pointers = (const char **) malloc(height*sizeof(char *));
		for(int i=0;i<height;i++)
			row_pointers[i] = image.c_str() + rowbytes*(height-1-i);

		png_write_info(png_ptr, info_ptr);
		png_write_image(png_ptr,(png_bytepp) row_pointers);
		png_write_end(png_ptr,info_ptr);

		free(row_pointers);
	}

	free(info_ptr);
	free(png_ptr);
	        	
	return true;
}

#endif

//
// Image encoding
//

bool 
encodePPM(string &data,const uint32 width,const uint32 height,const string &image)
{
	const bool ppm = width*height*3==image.size();
	const bool pgm = width*height  ==image.size();

	// Check that image data matches the dimensions

	if (!ppm && !pgm)
		return false;

	// PPM P6/P5 header 

	char header[100];
	sprintf(header,"%s\n%u %u\n255\n",ppm ? "P6" : "P5",width,height);

	// Assemble PPM file

	data.resize(strlen(header)+image.size());
	assert(data.size()==strlen(header)+image.size());
	strcpy((char *) data.data(),header);

	// Copy and flip

	const uint32 lineSize = ppm ? width*3 : width;

	// Destination pointer in data buffer
	byte *i = (byte *) data.data() + strlen(header);

	// Source pointer in image buffer
	const byte *j = (const byte *) image.data() + image.size() - lineSize;

	// Copy scan-lines until finished
	for (int k=0; k<height; i+=lineSize, j-=lineSize, k++)
		memcpy(i,j,lineSize);

	return true;
}

bool 
eencodeBMP(string &data,const uint32 width,const uint32 height,const string &image)
{
	// TODO
	return false;
}

bool 
encodeTGA(string &data,const uint32 width,const uint32 height,const string &image)
{
	// Check that image data matches the
	// dimensions

	if (width*height*3!=image.size())
		return false;

	// Allocate space for header and image
	data.resize(18+image.size());

	data[0] = 0;
	data[1] = 0;
	data[2] = 2;
	data[3] = 0;
	data[4] = 0;
	data[5] = 0;
	data[6] = 0;
	data[7] = 0;
	data[8] = 0;
	data[9] = 0;
	data[10] = 0;
	data[11] = 0;
	*(uint16 *) (data.data()+12) = littleEndian(uint16(width));
	*(uint16 *) (data.data()+14) = littleEndian(uint16(height));
	data[16] = 24;
	data[17] = 0;

	// Destination iterator

	      byte *i = (byte *) data.data()+18;				// Destination
	const byte *j = (const byte *) image.data();			// Source

	for (int y=0; y<height; y++)
	{
		// Copy the scanline, swapping red and blue channels
		// as we go...

		for (int x=0; x<width; x++)
		{
			*(i++) = *(j++ + 2);		
			*(i++) = *(j++);
			*(i++) = *(j++ - 2);
		}
	}

//-------------------------------------------------------------------------------
//DATA TYPE 2:  Unmapped RGB images.                                             |
//_______________________________________________________________________________|
//| Offset | Length |                     Description                            |
//|--------|--------|------------------------------------------------------------|
//|--------|--------|------------------------------------------------------------|
//|    0   |     1  |  Number of Characters in Identification Field.             |
//|        |        |                                                            |
//|        |        |  This field is a one-byte unsigned integer, specifying     |
//|        |        |  the length of the Image Identification Field.  Its value  |
//|        |        |  is 0 to 255.  A value of 0 means that no Image            |
//|        |        |  Identification Field is included.                         |
//|        |        |                                                            |
//|--------|--------|------------------------------------------------------------|
//|    1   |     1  |  Color Map Type.                                           |
//|        |        |                                                            |
//|        |        |  This field contains either 0 or 1.  0 means no color map  |
//|        |        |  is included.  1 means a color map is included, but since  |
//|        |        |  this is an unmapped image it is usually ignored.  TIPS    |
//|        |        |  ( a Targa paint system ) will set the border color        |
//|        |        |  the first map color if it is present.                     |
//|        |        |                                                            |
//|--------|--------|------------------------------------------------------------|
//|    2   |     1  |  Image Type Code.                                          |
//|        |        |                                                            |
//|        |        |  This field will always contain a binary 2.                |
//|        |        |  ( That's what makes it Data Type 2 ).                     |
//|        |        |                                                            |
//|--------|--------|------------------------------------------------------------|
//|    3   |     5  |  Color Map Specification.                                  |
//|        |        |                                                            |
//|        |        |  Ignored if Color Map Type is 0; otherwise, interpreted    |
//|        |        |  as follows:                                               |
//|        |        |                                                            |
//|    3   |     2  |  Color Map Origin.                                         |
//|        |        |  Integer ( lo-hi ) index of first color map entry.         |
//|        |        |                                                            |
//|    5   |     2  |  Color Map Length.                                         |
//|        |        |  Integer ( lo-hi ) count of color map entries.             |
//|        |        |                                                            |
//|    7   |     1  |  Color Map Entry Size.                                     |
//|        |        |  Number of bits in color map entry.  16 for the Targa 16,  |
//|        |        |  24 for the Targa 24, 32 for the Targa 32.                 |
//|        |        |                                                            |
//|--------|--------|------------------------------------------------------------|
//|    8   |    10  |  Image Specification.                                      |
//|        |        |                                                            |
//|    8   |     2  |  X Origin of Image.                                        |
//|        |        |  Integer ( lo-hi ) X coordinate of the lower left corner   |
//|        |        |  of the image.                                             |
//|        |        |                                                            |
//|   10   |     2  |  Y Origin of Image.                                        |
//|        |        |  Integer ( lo-hi ) Y coordinate of the lower left corner   |
//|        |        |  of the image.                                             |
//|        |        |                                                            |
//|   12   |     2  |  Width of Image.                                           |
//|        |        |  Integer ( lo-hi ) width of the image in pixels.           |
//|        |        |                                                            |
//|   14   |     2  |  Height of Image.                                          |
//|        |        |  Integer ( lo-hi ) height of the image in pixels.          |
//|        |        |                                                            |
//|   16   |     1  |  Image Pixel Size.                                         |
//|        |        |  Number of bits in a pixel.  This is 16 for Targa 16,      |
//|        |        |  24 for Targa 24, and .... well, you get the idea.         |
//|        |        |                                                            |
//|   17   |     1  |  Image Descriptor Byte.                                    |
//|        |        |  Bits 3-0 - number of attribute bits associated with each  |
//|        |        |             pixel.  For the Targa 16, this would be 0 or   |
//|        |        |             1.  For the Targa 24, it should be 0.  For     |
//|        |        |             Targa 32, it should be 8.                      |
//|        |        |  Bit 4    - reserved.  Must be set to 0.                   |
//|        |        |  Bit 5    - screen origin bit.                             |
//|        |        |             0 = Origin in lower left-hand corner.          |
//|        |        |             1 = Origin in upper left-hand corner.          |
//|        |        |             Must be 0 for Truevision images.               |
//|        |        |  Bits 7-6 - Data storage interleaving flag.                |
//|        |        |             00 = non-interleaved.                          |
//|        |        |             01 = two-way (even/odd) interleaving.          |
//|        |        |             10 = four way interleaving.                    |
//|        |        |             11 = reserved.                                 |
//|        |        |                                                            |
//|--------|--------|------------------------------------------------------------|
//|   18   | varies |  Image Identification Field.                               |
//|        |        |  Contains a free-form identification field of the length   |
//|        |        |  specified in byte 1 of the image record.  It's usually    |
//|        |        |  omitted ( length in byte 1 = 0 ), but can be up to 255    |
//|        |        |  characters.  If more identification information is        |
//|        |        |  required, it can be stored after the image data.          |
//|        |        |                                                            |
//|--------|--------|------------------------------------------------------------|
//| varies | varies |  Color map data.                                           |
//|        |        |                                                            |
//|        |        |  If the Color Map Type is 0, this field doesn't exist.     |
//|        |        |  Otherwise, just read past it to get to the image.         |
//|        |        |  The Color Map Specification describes the size of each    |
//|        |        |  entry, and the number of entries you'll have to skip.     |
//|        |        |  Each color map entry is 2, 3, or 4 bytes.                 |
//|        |        |                                                            |
//|--------|--------|------------------------------------------------------------|
//| varies | varies |  Image Data Field.                                         |
//|        |        |                                                            |
//|        |        |  This field specifies (width) x (height) pixels.  Each     |
//|        |        |  pixel specifies an RGB color value, which is stored as    |
//|        |        |  an integral number of bytes.                              |
//|        |        |                                                            |
//|        |        |  The 2 byte entry is broken down as follows:               |
//|        |        |  ARRRRRGG GGGBBBBB, where each letter represents a bit.    |
//|        |        |  But, because of the lo-hi storage order, the first byte   |
//|        |        |  coming from the file will actually be GGGBBBBB, and the   |
//|        |        |  second will be ARRRRRGG. "A" represents an attribute bit. |
//|        |        |                                                            |
//|        |        |  The 3 byte entry contains 1 byte each of blue, green,     |
//|        |        |  and red.                                                  |
//|        |        |                                                            |
//|        |        |  The 4 byte entry contains 1 byte each of blue, green,     |
//|        |        |  red, and attribute.  For faster speed (because of the     |
//|        |        |  hardware of the Targa board itself), Targa 24 images are  |
//|        |        |  sometimes stored as Targa 32 images.                      |
//|        |        |                                                            |
//--------------------------------------------------------------------------------

 	return true;
}
