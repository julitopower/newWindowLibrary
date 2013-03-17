#include "../include/TextureLoader.hpp"
#include <string>
#include <iostream>
#include <jpeglib.h>
#include <cstdio>
using namespace std;

TextureLoader::TextureLoader() : rawData(0), isInitialized(false) {
};

TextureLoader::~TextureLoader() {
	if (rawData != 0 && isInitialized) {
		delete[] rawData;
	}
}

void TextureLoader::loadFile(string file) {
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;
	/* libjpeg data structure for storing one row, that is, scanline of an image */
	JSAMPROW row_pointer[1];

	FILE *infile = fopen( file.c_str(), "rb" );
	unsigned long location = 0;
	int i = 0;

	if ( !infile )
	{
	 	cout << "Error opening jpeg file " << file << endl;
	}
	/* here we set up the standard libjpeg error handler */
	cinfo.err = jpeg_std_error( &jerr );
	/* setup decompression process and source, then read JPEG header */
	jpeg_create_decompress( &cinfo );
	/* this makes the library read from infile */
	jpeg_stdio_src( &cinfo, infile );
	/* reading the image header which contains image information */
	jpeg_read_header( &cinfo, TRUE );
	/* Uncomment the following to output image information, if needed. */
	/*--
	printf( "JPEG File Information: \n" );
	printf( "Image width and height: %d pixels and %d pixels.\n", cinfo.image_width, cinfo.image_height );
	printf( "Color components per pixel: %d.\n", cinfo.num_components );
	printf( "Color space: %d.\n", cinfo.jpeg_color_space );
	--*/
	/* Start decompression jpeg here */
	jpeg_start_decompress( &cinfo );

	/* allocate memory to hold the uncompressed image */
	rawData = new unsigned char[cinfo.output_width*cinfo.output_height*cinfo.num_components];
	/* now actually read the jpeg into the raw buffer */
	row_pointer[0] = new unsigned char[cinfo.output_width*cinfo.num_components ];
	/* read one scan line at a time */
	while( cinfo.output_scanline < cinfo.image_height )
	{
		jpeg_read_scanlines( &cinfo, row_pointer, 1 );
		for( i=0; i<cinfo.image_width*cinfo.num_components;i++)
			rawData[location++] = row_pointer[0][i];
	}
	/* wrap up decompression, destroy objects, free pointers and close open files */
	jpeg_finish_decompress( &cinfo );
	jpeg_destroy_decompress( &cinfo );
	delete row_pointer[0];
	fclose( infile );
}

unsigned char * TextureLoader::getData() {
	return rawData;
}
