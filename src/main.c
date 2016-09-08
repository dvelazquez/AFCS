/*	Daniel Velazquez
	Started December 2010
	Re-started January 2016
	Auto Functioncheck Sheet System
	https://github.com/dvelazquez/AFCS
*/

#include <opencv/cv.h>
#include "/usr/local/include/opencv2/imgproc/imgproc_c.h"
#include "opencv/highgui.h"

// May not need all these includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <fcntl.h>  // open file
#include "../include/AFCS.h"

	IplImage * Picture;
   IplImage * Gray;
   IplImage * HSV;
   IplImage * HSV_Result;
   IplImage * Bin;
   IplImage * Result;
   IplImage * ROI;
   IplImage * ROIGray;

//    CvSeq *contours = 0;
//    CvPoint *point = 0;

   int Log; 
    CvScalar s;

    CvFont font;
    double hScale=0.5;
    double vScale=0.5;
	char pause;

    int    lineWidth=1; 

int main( int argc, char *argv[ ] )
{
	Initialization();
	ReadXY();
   CvMemStorage* storage = cvCreateMemStorage(0); //added 0 as default 64k
   CvCapture * capture;
    /* Buffer */
   capture = cvCaptureFromCAM(0); // the parameter for a cam

    /* Parameters */
    float    threshold = 0.01;
    int      x,y,i,j;
    int key=0;
    i=0;

    cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, hScale,vScale,0,lineWidth,8); 

    Picture = cvQueryFrame( capture );

    Gray= cvCreateImage( cvGetSize(Picture), IPL_DEPTH_8U, 1 );  // Do not create the image everytime 

	while (key != 'q'){
		Picture = cvQueryFrame( capture );
//		Mesh(Picture );  // Routine to draw a mesh with coordinates

		ImageProcessing(Picture);// Image processing routine

		cvShowImage ("Camera", Picture);
//		cvMoveWindow("Camera", 100, 50);
//		cvShowImage ("Gray", Gray);
//		cvMoveWindow("Gray", 100, 50);

		cvShowImage ("ROI", ROIGray);
//		cvMoveWindow("ROI", 100, 50);

       key = cvWaitKey( 1 );    // Press Q to Quit
        }

    cvReleaseMemStorage(&storage);
    cvReleaseImage( &Picture );
    cvDestroyWindow( "Camera" );    // Destroy the window
    cvDestroyWindow( "ROI" );    // Destroy the window
    cvReleaseCapture( &capture );   // Release it or never close
   close(Log);
	//	fclose(fp);
}
