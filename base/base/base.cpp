// base.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Moments.cpp : Defines the entry point for the console application.
//


/*******************************************************************************
*       visualimage01.cpp - Program for Image Negation. Contrast Stretching and
*                           Histogram Equalization is performed for gray scale 
*                           and color images.
*
*       Note : Histogram Equalization in RGB color space does not provide satisfactory
*              results. Use HSI color space for Histogram Eqalization for color images. 
*_______________________________________________________________________________ 
*               The program reads the TIFF file,interprets,processes and writes
*               the processed image to an output file.
*_______________________________________________________________________________
*               Program tested for e32.tif, wom1.tif, beans.tif, color.tif,
*               family.tif and lilli.tif files.
*                
*_______________________________________________________________________________
*      Notes: 1) Program has been implemented in Microsoft's Visual C++6.0 under 
*                Windows environment and can be execetued under "Build" menu 
*                item of Visual C++6.0 or through "command line". It may not run 
*                purely under DOS environment because the memory requirement is
*                high.
*             2) This is not a product. This serves a demo for zooming operation 
*_______________________________________________________________________________
*	Developed By: Dr. Chandan Singh,
*		      Professor and Head,
*		      Department of Computer Science,
*		      Punjabi University, Patiala, India - 147 002
*             Phones : +91-175-3046316(O), 3046313(O), 2283209(R)
*             FAX :    +91-175-3046313.
*     	Date : January 15,2005.
*	Reference : 1) TIFF, Revision 6.0, (June 1992). Adobe Developers Association.
*	               www.adobe.com/Support/TechNotes.html 
*                  and ftp://ftp.adobe.com/pub/adobe/DeveloperSupport/TechNotes/PDFfiles
*               2) Digital Image Processing by Rafael C. Ganzalez and
*                  Richard E. Woods, Third Edition, Pearson Education, India, (for image
*                  processing operations)
**************************************************************************
*/
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <process.h>
#include <math.h>
#include <ppl.h>
#include <algorithm>
#define PI 3.14286
#define MAXSIZE 1024
#define NMAX 20
using namespace Concurrency;
using namespace std;

void  Read_Tiff_File(void);
void copy_array_to_file(unsigned long ImageLength, unsigned long ImageWidthByte, 
				   unsigned char fxyout[MAXSIZE][3*MAXSIZE], FILE *outfile_ptr);
void copy_to_array(unsigned long ImageLength, unsigned long ImageWidthByte, 
				   unsigned char *IB, unsigned char fxy[MAXSIZE][3*MAXSIZE]);
void copy_array_to_file_binary(unsigned long ImageLength, unsigned long ImageWidth, 
				   unsigned char fxyout[MAXSIZE][3*MAXSIZE], FILE *outfile_ptr);
void copy_to_text_file(unsigned long ImageLength, unsigned long ImageWidthByte, 
				   unsigned char fxyout[MAXSIZE][3*MAXSIZE]);
void display_error( char *message);
void onehalf(unsigned long ImageLength, unsigned long ImageWidthByte, 
				   unsigned char fxyout[MAXSIZE][3*MAXSIZE], FILE *outfile_ptr);
void secondhalf(unsigned long ImageLength, unsigned long ImageWidthByte, 
				   unsigned char fxyout[MAXSIZE][3*MAXSIZE], FILE *outfile_ptr);

unsigned long ImageWidth, ImageLength, StripOffsets, RowsPerStrip,
StripsPerImage, ImageWidthByte, ImageSize, StripByteCounts;
short int BitWhite;
short int ResolutionUnit, BitsPerSample;
unsigned long XResolution, YResolution, NoOfStrips;
void *ImageBuffer;
int ord=20;
int main()
{
	Read_Tiff_File();
	return(0);
}

void  Read_Tiff_File()
{
	long int n, sumR, sumG, sumB, nkR[256], sR[256], nkG[256], 
		sG[256], nkB[256], sB[256];
	short unsigned int i, j, reply, reply2=0;
	short unsigned int byte_order, TIFF_identifier;
	unsigned short int no_of_entries, tag, field_type, temp;
	unsigned long offset_address, count, value, so, sbc, StripAddress,
		StripSize;
	unsigned long file_position;
	unsigned char *IB, item;
	unsigned char *ib, fxy[MAXSIZE][3*MAXSIZE], fxyout[MAXSIZE][3*MAXSIZE];  // for RGB
	unsigned char in_filename[14], out_filename[14], pic_byteR, pic_byteG, pic_byteB; 
	FILE *infile_ptr, *outfile_ptr;
	
	// Open the input file for processing
	printf("Input TIFF File ? : ");
	scanf( "%s", in_filename);
	if((infile_ptr = fopen((const char *)in_filename, "rb+")) ==NULL)
	{
		printf("can't open file - %s - either the filename is wrong or the"
			" file does not exist\n", in_filename);
		exit(0);
	}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

