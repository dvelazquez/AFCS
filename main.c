// Daniel Velazquez
// Started December 2010
// Re-started January 2016
// Water meter monitoring by webcam

#include <opencv/cv.h>
#include "opencv/highgui.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>

#define RED CV_RGB(255,0,0)
#define GREEN CV_RGB(0,255,0)
#define BLUE CV_RGB(0,0,255)
#define BLACK CV_RGB(0,0,0)
#define WHITE CV_RGB(255,255,255)

int main( int argc, char *argv[ ] )
{
    /* Initialize images */
    IplImage * Picture;
    IplImage * Gray;
    IplImage * Bin;
    IplImage * Result;

/*   if( argc == 2){
      printf("Argument from command line was %s", argv[1]);
      return 0;         // Example how to read the input from the command line
   }*/


    /* Buffer */
    CvMemStorage* storage = cvCreateMemStorage(0); //added 0 as default 64k
   CvCapture * capture;
   capture = cvCaptureFromCAM(0); // the parameter for a cam

    /* Parameters */
    float    threshold = 0.01;
    int      x,y;
    CvScalar s;

    CvFont font;
    double hScale=0.7;
    double vScale=0.7;
    int    lineWidth=2; 
    int key=0;

    cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, hScale,vScale,0,lineWidth,8);   //added 8 (line type)

    Picture = cvQueryFrame( capture );
    Gray= cvCreateImage( cvGetSize(Picture), IPL_DEPTH_8U, 1 );  // Do not create the image everytime inside the main loop

    cvNamedWindow ("Camera",1); // added 1 WINDOW_AUTOSIZE = camera capture size (640x480)
    while (key != 'q'){
                Picture = cvQueryFrame( capture );

                cvPutText (Picture, argv[1],cvPoint(180,470), &font, cvScalar(255,0,0,0));
//                cvPutText (Picture,"Daniel Velazquez - Water Meter",cvPoint(180,470), &font, cvScalar(255,0,0,0));   //added last 0
                // Speedo cross
                cvLine(Picture,cvPoint(315, 130),cvPoint(315,150),RED,1,8,1); //added shift=1 ?
                cvLine(Picture,cvPoint(305, 140),cvPoint(325,140),RED,1,8,1);//added shift=1 ?
                //  Temp cross
                cvLine(Picture,cvPoint(95, 150),cvPoint(95,170),GREEN,1,8,1);//added shift=1 ?
                cvLine(Picture,cvPoint(85, 160),cvPoint(105,160),GREEN,1,8,1);//added shift=1 ?
                // Fuel cross
                cvLine(Picture,cvPoint(525, 165),cvPoint(525,185),BLUE,1,8,1);//added shift=1 ?
                cvLine(Picture,cvPoint(515, 175),cvPoint(535,175),BLUE,1,8,1);//added shift=1 ?
                // Pick two opposites points to center the cluster
                // Fuel Tank
                cvRectangle(Picture, cvPoint(490,60), cvPoint(520,90), RED, 2,1,1);//added shift=1 ?
                // Door
                cvRectangle(Picture, cvPoint(230,265), cvPoint(265,300), BLUE, 2,1,1);//added shift=1 ?

		/* Now some processing to the image */
		cvCvtColor(Picture,Gray,CV_BGR2GRAY); // Convert color image to gray
		cvCanny(Gray, Gray, 1, 200, 3);		// this function finds edges


//                cvShowImage ("Camera", Picture);
                cvShowImage ("Camera", Gray);
                cvMoveWindow("Camera", 100, 50);

       key = cvWaitKey( 1 );    // Press Q to Quit
        }

    cvReleaseMemStorage(&storage);
    cvReleaseImage( &Gray );
    cvDestroyWindow( "Camera" );    // Destroy the window
    cvReleaseCapture( &capture );   // Release it or never close
    }
