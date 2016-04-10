#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <array>
#include <iostream>
#include <string>

#include <stdlib.h>  // srand48()

using namespace std;

#define SIZE_X 100
#define SIZE_Y 100






// Write the pixels to a file of PPM image format
void writeToPPM(string filename, int myPixels[SIZE_X][SIZE_Y][3], int width, int height)
{

	// Save result to a PPM image (keep these flags if you compile under Windows)
	ofstream ofs(filename, ios::out | ios::binary);
	ofs << "P6\n" << width << " " << height << "\n255\n";

	for ( int x = 0; x < SIZE_X; x++)
	{
		for (int y = 0; y < SIZE_Y; y++)
		{
			for (int c = 0; c < 3; c++)
			{
			
				// Pixels have been placed into the array using the order of coordinates
				// myPixels[x][y][], but 
				ofs << (unsigned char)myPixels[y][x][c];
			}
		}
	}
	
	ofs.close();

} // end writeToPPM()


	
// Write the data to the stream as a swapped two-byte value
void write2ByteData(ofstream *myOFStream, int data)
{
    char *c = new char[1];
    *c = data & 0xff; myOFStream->write(c, 1); // LeastSigByte
    *c = (data & 0xff00) >> 8; myOFStream->write(c, 1); // This is the 2nd-leastSigByte
}

// Write the data to the stream as a swapped four-byte value
void write4ByteData(ofstream *myOFStream, int data)
{
    char *c = new char[1];
    *c = data & 0xff; myOFStream->write(c, 1); // LeastSigByte
    cout << "wrote 4-byte A   " << std::hex << (0xff & (int)*c) << std::dec << endl;
    *c = (data & 0xff00) >> 8; myOFStream->write(c, 1); // This is the 2nd-leastSigByte
    cout << "wrote 4-byte B   " << std::hex << (0xff & (int)*c) << std::dec << endl;
    *c = (data & 0xff0000) >> 16; myOFStream->write(c, 1); // This is the 2nd-leastSigByte
    cout << "wrote 4-byte C   " << std::hex << (0xff & (int)*c) << std::dec << endl;
    *c = (data & 0xff000000) >> 24; myOFStream->write(c, 1); // This is the 2nd-leastSigByte
    cout << "wrote 4-byte D   " << std::hex << (0xff & (int)*c) << std::dec << endl;
}


// Write the pixels to a file of BMP image format
void writeToBMP(string filename, int myPixels[SIZE_X][SIZE_Y][3], int width, int height)
{
    char *c = new char[1];
    char b1;
    char b2;
    int dummyIntR, dummyIntG, dummyIntB;
    ofstream myOFStream(filename, ofstream::out | ofstream::binary);
    
 
    // This data is the Bitmap file header. Some hardcoded information.
    // Write the 2-byte magic number. It should be "BM"
    b1 = 'B'; myOFStream.write(&b1, 1);  // dummy character
    b2 = 'M'; myOFStream.write(&b2, 1);  // dummy character

    int size = 	14 +  // size of Bitmap file header
		40 +  // size of BITMAPINFOHEADER header
		0 +   // TBD -- color table?
		(height *   // height
		((width * 3) + ((width * 3) % 4)));  // width including RGB and padding
    write4ByteData(&myOFStream, size);  // write size to Bitmap file header
    write2ByteData(&myOFStream, 0);  // write reserved to Bitmap file header
    write2ByteData(&myOFStream, 0);  // write reserved to Bitmap file header
    write4ByteData(&myOFStream, 54);  // write offset to Bitmap file header

    // This data is the BITMAPINFOHEADER file header. Some hardcoded information.
    write4ByteData(&myOFStream, 40);  // write header size to BITMAPINFOHEADER file header
    write4ByteData(&myOFStream, width);  // write width to BITMAPINFOHEADER file header
    write4ByteData(&myOFStream, height);  // write height to BITMAPINFOHEADER file header
    write2ByteData(&myOFStream, 1);  // write number color planes to BITMAPINFOHEADER file header
    write2ByteData(&myOFStream, 24);  // write bits per pixel to BITMAPINFOHEADER file header
    write4ByteData(&myOFStream, 0);  // write compression to BITMAPINFOHEADER file header
    write4ByteData(&myOFStream, width*height*3);  // write size of raw bitmap data to BITMAPINFOHEADER file header
    write4ByteData(&myOFStream, 0);  // write horiz. resolution to BITMAPINFOHEADER file header
    write4ByteData(&myOFStream, 0);  // write vert. resolution to BITMAPINFOHEADER file header
    write4ByteData(&myOFStream, 0);  // write number colors (0 => 2^n) to BITMAPINFOHEADER file header
    write4ByteData(&myOFStream, 0);  // write number important colors to BITMAPINFOHEADER file header

    
    
    // The rows of data in a BMP file are stored in REVERSE order (row at bottom
    // of image is stored first in file, etc.

    for (int i = height-1; i >= 0; i--)
    {

		for (int j = 0; j < width; j++)
		{
			// Pixel component data are stored in BMP file in B G R order
			//cout << ((this->thePixels.at(i)).at(j)).getR() << endl;
			
			*c = myPixels[j][i][2]; myOFStream.write(c, 1);
			*c = myPixels[j][i][1]; myOFStream.write(c, 1);
			*c = myPixels[j][i][0]; myOFStream.write(c, 1);
	    
		}  // end for c

		// Each row of pixels ends on a 32-bit boundary which is padded with zeroes if needed.
		// Read and discard any zeroes used for padding.
		// System.out.println("  going to have to discard " + (4 - ((width * 3) % 4)) + " padding bytes because of width " + width);
		*c = 0; // dummy data
		if (((width * 3) % 4) != 0)
		{
			for (int j = 0; j < (4 - (((width * 3) % 4))); j++)
			{
				myOFStream.write(c, 1);  // pad with dummy data
			}
		}
    }  // end for r

    myOFStream.close();
} // end writeToBMP()

	


