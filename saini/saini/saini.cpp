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
	
	// Open a new file for storing the processed image
	printf("Output TIFF File ? : ");
	scanf( "%s", out_filename);
	if((outfile_ptr = fopen((const char *)out_filename, "wb")) ==NULL)
	{
		printf("Error in opening file - %s - the filename may be wrong"
			, out_filename);
		exit(0);
	}
	/*---- Copy the existing file to the new file  */
	while( fread((void *)&item, (size_t)1, (size_t)1, infile_ptr) !=0)
	{
		fwrite((void *)&item, (size_t)1, (size_t)1, outfile_ptr);
	}
	//     bring the file pointer to the beginning of the input file
	rewind(infile_ptr);
	//     Close the output file and reopen it in read & write modes
	fclose(outfile_ptr);
	if((outfile_ptr = fopen((const char *)out_filename, "rb+")) ==NULL)
	{
		printf("Error in opening file - %s - the filename may be wrong"
			, out_filename);
		exit(0);
	}
	printf("Enter 1 for Image Negation:");
	scanf("%d", &reply);
	//reply=2;
	if(reply<0 || reply>2) display_error("Choice no. wrong. "
		"This choice is not included for students");
	/*---- Read byte_order, TIFF_identifier and offset to the first image file
	   directory(IFD).
	*/
	//   byte_order = getw(infile_ptr);
	fread((void *)&byte_order, (size_t)2, (size_t)1, infile_ptr);
	
	//   TIFF_identifier = getw(infile_ptr);
	fread((void *)&TIFF_identifier, (size_t)2, (size_t)1, infile_ptr);
	if(byte_order != 0x4949)  display_error("Byte Order not Intel Processor"
		" Compatible");
	if(TIFF_identifier != 0x002A)  display_error("File is not a valid TIFF file");
	fread((void *)&offset_address, (size_t)4, (size_t)1, infile_ptr);
	//   printf("offset address=%lu\n", offset_address);
	fseek(infile_ptr, offset_address, SEEK_SET);
	
	/*---- Read the total number of entries and the contents of the entries
	   themselves.
	*/
	//   no_of_entries = getw(infile_ptr);
	fread((void *)&no_of_entries, (size_t)2, (size_t)1, infile_ptr);
	//   printf("no_of_entries=%u\n", no_of_entries);
	/*---- Read Tag identifying the field, Field type, Number of values or count
	   of the type, Offset into the file where the value begins.
	*/
	for(i=0; i<no_of_entries; i++)
	{
		//      tag = getw(infile_ptr);
		fread((void *)&tag, (size_t)2, (size_t)1, infile_ptr);
		//      field_type = getw(infile_ptr);
		fread((void *)&field_type, (size_t)2, (size_t)1, infile_ptr);
		fread((void *)&count, (size_t)4, (size_t)1, infile_ptr);
		fread((void *)&value, (size_t)4, (size_t)1, infile_ptr);
		//      printf("tag =%u, field_type=%u, count=%lu, value=%lu\n",
		//		   tag, field_type, count, value);
		/*	  getch(); */
		/* Only a few tag information are required for a bilevel/gray scale scanned
		image. Other tags are skipped.  */
		switch(tag)
		{
		case 256 : /* Image Width. Number of columns in the image(pixels
				   per row. Only one bit per pixel is required for a
			bilevel system.  */
			ImageWidth = value;
			break;
		case 257 : /* Image Length. Number of rows of pixels in the image. */
			ImageLength = value;
			break;
		case 258 : /* BitsPerSample. The number of bits per component. */
			BitsPerSample = (short)value;
			//		     printf("Bits per sample=%d\n", BitsPerSample);
			//		     getch(); exit(0);
			break;
		case 259 : /* Co mpression. If the count =1, then there is no
			compression. */
			if(value !=1) display_error("Image is compressed. "
			"Can't process");
			break;
			case 262 : /* Photometric Interpretation. Determines the meaning
			of a bit.  */
			if(value<0 || value >3)
			display_error("The Image is not binary/8-bit gray"
				"/8-bit coloured/24-bit colour");
			BitWhite =0;
			if(value ==1) BitWhite =1;
			//printf("count=%lu, value=%lu,  BitWhite=%d\n", count, value, BitWhite); getch();
			break;
					
		case 273 : /* Strip Offsets. Byte offset for each strip. Specifies
				   the location of a strip with respect to the beginning
				of a tiff file. */
			NoOfStrips = count;
			StripOffsets= value;
			break;
		case 278 : /* Rows Per Strip. Number of rows per strip.  */
			RowsPerStrip = value;
			StripsPerImage =(ImageLength + RowsPerStrip -1)/RowsPerStrip;
			break;
		case 279 : /* Strip Byte Counts. For each strip, the number of bytes
					in it after compression. */
			StripByteCounts = value;
			break;
		case 282 : /* X-Resolution. Number of pixels per ResolutionUnit
					in the ImageWidth direction.  */
			XResolution = (short)value;
			break;
		case 283 : /* Y-Resolution. Number of pixels per ResolutionUnit
				in the ImageLength direction.  */
		    YResolution = (short)value;
			break;
		case 296 : /* Resolution Unit. Unit of measurement for X-Resolution
									   and Y-Resolution.
				   per row. Only one bit per pixel is required for a
				bilevel system.  */
			ResolutionUnit= (short)value;
			break;
		default :   break;
		}
	}
	/*   printf("ImageWidth, ImageLength, StripOffsets, RowsPerStrip,"
	" StripsPerImage, No. of Strips=%lu, %lu, %lu, %lu, %lu, %lu\n",
	   ImageWidth, ImageLength, StripOffsets, RowsPerStrip,
	   StripsPerImage, NoOfStrips);
	   printf("BitWhite, XResolution, YResolution, ResolutionUnit=%d, "
	   "%d, %d, %d\n", BitWhite, XResolution,
			 YResolution, ResolutionUnit);  */
	
	/*  Store the image in a buffer pointed to by ImageBuffer.  */
	
	if(BitsPerSample == 1) ImageWidthByte = (ImageWidth + 7)/8;
    else  if(BitsPerSample == 8) ImageWidthByte = ImageWidth;
    else  if(BitsPerSample == 24) ImageWidthByte = 3*ImageWidth;
	ImageSize = ImageWidthByte*ImageLength;
	n=ImageSize;
	//  printf("ImageSize=%lu\n", ImageSize);
	ImageBuffer =  malloc(ImageSize);
	if(ImageBuffer == NULL)
		display_error("Unable to allocate memory for storing the image"
		" in memory");
	
	/*  Zeroize the contents of the Image Buffer  */
	IB = (unsigned char *)ImageBuffer;
	for(i=0; i<ImageLength; i++)
		for(j=0; j<ImageWidthByte; j++)
		{
			(*IB) =0;
			IB++;
		}
		
		
		/*  Read the image data stored in strips in the TIFF format and build up
		a memory block where the whole data is stored.  */
		
		so = StripOffsets;  sbc = StripByteCounts;  ib = (unsigned char *)ImageBuffer;
		/*   printf("ImageSize=%lu\n", ImageSize);
		printf("NoOfStrips=%lu\n", NoOfStrips);
		printf("Strip offset=%lu\n", so);
		printf("Strip Byte Counts=%lu\n", StripByteCounts);
		getch();  */
		if(NoOfStrips ==1)
		{
			fseek(infile_ptr, so, SEEK_SET);
			/*  The location of the input file pointer is required to position the file
			pointer of the output file at the place from where the processed data in
			the output file is to be stored.
			*/
			file_position = (unsigned long)ftell(infile_ptr);
			//      printf("Position of input file pointer before storing the image=%d\n",
			//	       file_position);  getch();
			temp =fread(ImageBuffer, (size_t)1, (size_t)ImageSize, infile_ptr);
			//     printf("No of bytes read=%lu\n", temp);
			//     getch();
		}
		else
		{
			for(i=0; i<NoOfStrips; i++)
			{
				fseek(infile_ptr, so, SEEK_SET);
				fread(&StripAddress, 4, 1, infile_ptr);
				//       printf("StripAddress for %d strip = %lu\n", (i+1), StripAddress);
				so = so + 4;
				fseek(infile_ptr, sbc, SEEK_SET);
				sbc = sbc +4;
				fread(&StripSize, 4, 1, infile_ptr);
				//   printf("StripSize = %lu\n", StripSize);
				//     getch();
				fseek(infile_ptr, StripAddress, SEEK_SET);
				/*  The location of the input file pointer is required to position the file
				pointer of the output file at the place from where the processed data in
				the output file is to be stored.
				*/
				if(i==0)
				{
					file_position = (unsigned long) ftell(infile_ptr);
					//	 printf("Position of input file pointer before storing"
					//	   "a strip=%lu\n", file_position);  getch();
					
				}
				fread(ib, (size_t)StripSize, (size_t)1, infile_ptr);
				(unsigned char *)ib = (unsigned char *)ib + StripSize;
			}
		}
		IB = (unsigned char *)ImageBuffer;
        copy_to_array(ImageLength, ImageWidthByte, IB, fxy);
		if(reply ==1)
		{
			// Image Negation
			
			for(i=0; i<ImageLength; i++)
			{
				for(j=0; j<ImageWidthByte; j++)
				{
					fxyout[i][j]=255-fxy[i][j];
				}
			}
		} // if reply
		//log transform
		if(reply==2)
		{
			double f_[MAXSIZE][MAXSIXE]={0};
			DOUBLE
		}
		fseek(outfile_ptr, file_position, SEEK_SET);
        copy_array_to_file(ImageLength, ImageWidthByte, fxyout, outfile_ptr);
		fclose(infile_ptr);  fclose(outfile_ptr);
		// Writing the output image file to a text file.
		printf("Do you want to write the image file to a "
			"text output file(1 for yes 0 for no ? : ");
		scanf("%d", &reply2);
		if(reply2==1)copy_to_text_file(ImageLength, ImageWidthByte,  fxyout);
		
		getch();
		/*  Operation on the input image file is over  */
}
/* Copies the grayscale/color image to a 2D array  */
/*************************************************************************
*                                                                        *
*  Copies the grayscale/clor image to a 2D array                                   *
*                                                                        *
**************************************************************************
*/
void copy_to_array(unsigned long ImageLength, unsigned long ImageWidthByte, 
				   unsigned char *IB, unsigned char fxy[MAXSIZE][3*MAXSIZE])
{
	   int npixels=0; 
	   unsigned int i, j;
	   for(i=0; i<ImageLength; i++)
	   {
		   for(j=0; j<ImageWidthByte; j++)
		   {
			   npixels++;
			   fxy[i][j]=*IB;
			   IB++;
		   }  //  j-loop
	   }  // i-loop
	   printf("For Original Image : Total pixels=%d\n", npixels);  getch();   
}

/* Copies the array to image output file  */
/*************************************************************************
*                                                                        *
*  Copies the array to image output file                                 *
*                                                                        *
**************************************************************************
*/
void copy_array_to_file(unsigned long ImageLength, unsigned long ImageWidthByte, 
				   unsigned char fxyout[MAXSIZE][3*MAXSIZE], FILE *outfile_ptr)
{
	   int npixels=0; 
	   unsigned int i, j;
	   unsigned char pic_byte;
	   for(i=0; i<ImageLength; i++)
	   {
		   for(j=0; j<ImageWidthByte; j++)
		   {
			   npixels++; pic_byte=fxyout[i][j];  // R-component
			   fwrite((const void *) &pic_byte, (size_t)sizeof(pic_byte), (size_t)1, 
				   outfile_ptr);
		   }  //  j-loop
	   }  // i-loop
	   printf("For Output Image : Total pixels=%d\n", npixels);  getch();   
}
/*void copy_array_to_file(unsigned long ImageLength, unsigned long ImageWidthByte, 
				   unsigned char fxyout[MAXSIZE][3*MAXSIZE], FILE *outfile_ptr)
{
	   int npixels=0; 
	   unsigned int i, j;
	   unsigned char pic_byte;
	   Concurrency::parallel_invoke([=] (){onehalf(ImageLength , ImageWidthByte,fxyout,outfile_ptr);},
		   [=] (){secondhalf(ImageLength , ImageWidthByte,fxyout,outfile_ptr);});

	   //printf("For Output Image : Total pixels=%d\n", npixels);  getch();   
}

void onehalf(unsigned long ImageLength, unsigned long ImageWidthByte, 
				   unsigned char fxyout[MAXSIZE][3*MAXSIZE], FILE *outfile_ptr)
{
	int npixels=0; 
	unsigned int i, j;
	unsigned char pic_byte;
	for( i=0; i<ImageLength/2; i++)
	{
		for( j=0; j<ImageWidthByte/2; j++)
		{
			npixels++; pic_byte=fxyout[i][j]; 
			fwrite((const void *) &pic_byte, (size_t)sizeof(pic_byte), (size_t)1, 
			   outfile_ptr);
		}  
	}
	printf("\n onehalf%d",npixels);
	getch();
}
void secondhalf(unsigned long ImageLength, unsigned long ImageWidthByte, 
				   unsigned char fxyout[MAXSIZE][3*MAXSIZE], FILE *outfile_ptr)
{
	int npixels=0; 
	unsigned int i, j;
	unsigned char pic_byte;
	for( i=ImageLength/2; i<ImageLength; i++)
	{
		for( j=ImageWidthByte/2; j<ImageWidthByte; j++)
		{
			npixels++; pic_byte=fxyout[i][j]; 
			fwrite((const void *) &pic_byte, (size_t)sizeof(pic_byte), (size_t)1, 
			   outfile_ptr);
		}  
	}
	printf("\n secondhalf%d",npixels);
	getch();
}*/

/* Copies the array to image output file  */
/*************************************************************************
*                                                                        *
*  Write image function values to text file.                             *
*                                                                        *
**************************************************************************
*/
void copy_to_text_file(unsigned long ImageLength, unsigned long ImageWidthByte, 
				   unsigned char fxyout[MAXSIZE][3*MAXSIZE])
{
	int count=0;   
	unsigned int i, j;
	FILE *outfile; 
   // Open a text file for writing image data in text mode 
   if((outfile = fopen("image_text.out", "w")) ==NULL)
   {
	   printf("can't open file -image_text.out");  getch();
	   exit(0);
   }
   count=0;
   for(i=0; i<ImageLength; i++)
   {
	   for(j=0; j<ImageWidthByte; j++)
	   {
		   count++;
		   fprintf(outfile, "%4d", fxyout[i][j]);
		   if(count==10) { fprintf(outfile, "\n");  count++;  }
	   }  //  j-loop
       fprintf(outfile, "\n"); 
   }  // i-loop
}

/* Routine for displaying the error messages.  */
/*************************************************************************
*                                                                        *
*   Displays error.                                                      *
*                                                                        *
**************************************************************************
*/

void display_error( char *message)
{
	printf("%s\n", message);
	printf("Program stopped !!\n");  getch(); getch();
	exit(0);
}
