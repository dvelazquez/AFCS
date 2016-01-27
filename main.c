/*	Daniel Velazquez
	Started December 2010
	Re-started January 2016
	Auto Functioncheck Sheet System
	https://github.com/dvelazquez/AFCS
*/


#include <opencv/cv.h>
#include "/usr/local/include/opencv2/imgproc/imgproc_c.h"
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
#define MAX_CONTOUR_LEVELS 10

// HSV Thresholds
/*			  H,    S,        V
		RED (0, 100%, 100%)
		LIME(120, 100%, 100%)
		BLUE(240, 100%, 100%)*/

#define RedThresholdMin cvScalar(0, 120, 120,0)		// <- Settings to be adjusted per LED Color
#define RedThresholdMax cvScalar(0, 255, 255,0)

int main( int argc, char *argv[ ] )
{
    /* Initialize images */
    IplImage * Picture;
    IplImage * Gray;
    IplImage * HSV;
    IplImage * HSV_Result;
    IplImage * Bin;
    IplImage * Result;

    CvSeq *contours = 0;
    CvPoint *point = 0;

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
    double hScale=0.5;
    double vScale=0.5;
    int    lineWidth=1; 
    int key=0;

    cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, hScale,vScale,0,lineWidth,8);   //added 8 (line type)

    Picture = cvQueryFrame( capture );
    Picture = cvQueryFrame( capture );

    Gray= cvCreateImage( cvGetSize(Picture), IPL_DEPTH_8U, 1 );  // Do not create the image everytime 
    HSV= cvCreateImage( cvGetSize(Picture), IPL_DEPTH_8U, 3 );  // Do not create the image everytime 
    HSV_Result= cvCreateImage( cvGetSize(Picture), IPL_DEPTH_8U, 1);  // Results is mono image

    cvNamedWindow ("Camera",1); // added 1 WINDOW_AUTOSIZE = camera capture size (640x480)
		int w;
		int h;

    while (key != 'q'){
                Picture = cvQueryFrame( capture );

		CvSize dim =cvGetSize(Picture);
		printf("W= %i  H=%i\n",dim.width, dim.height);

                // Let's draw a mesh to show coordinates for development
		for (x=0;x<=1276; x=x+50){
			for (y=0;y<=956; y=y+50){
				cvLine(Picture,cvPoint(x, 1),cvPoint(x,956),GREEN,1,0,1);   // 19 horizontal lines
				cvLine(Picture,cvPoint(1, y),cvPoint(1276,y),GREEN,1,0,1);  // 25 vertical lines	
			}
		}
		// Center Cross
                cvLine(Picture,cvPoint(630, 450),cvPoint(670,450),RED,2,0,1);
                cvLine(Picture,cvPoint(650, 430),cvPoint(650,465),RED,2,0,1);
                cvPutText (Picture,"(650,450)",cvPoint(330,250), &font, cvScalar(255,0,0,0));
		// Lower Right Corner
                cvLine(Picture,cvPoint(1230, 950),cvPoint(1250,950),RED,2,0,1);
                cvLine(Picture,cvPoint(1250, 930),cvPoint(1250,950),RED,2,0,1);
                cvPutText (Picture,"(1250,950)",cvPoint(530,460), &font, cvScalar(255,0,0,0));
		// Lower Right Corner
                cvLine(Picture,cvPoint(1230, 950),cvPoint(1250,950),RED,2,0,1);
                cvLine(Picture,cvPoint(1250, 930),cvPoint(1250,950),RED,2,0,1);
                cvPutText (Picture,"(1250,950)",cvPoint(530,460), &font, cvScalar(255,0,0,0));


		/* Now some processing to the image */
//		cvCvtColor(Picture,HSV,CV_BGR2GRAY); // Convert color image to gray		
//		cvCanny(Gray, Gray, 1, 200, 3);		// this function finds edges
		cvCvtColor(Picture, HSV, CV_BGR2HSV); // Convert color image to HSV
		cvInRangeS(HSV, RedThresholdMin, RedThresholdMax, HSV_Result);
		cvDilate(HSV_Result, HSV_Result, NULL, 5);      //last arg is iterations
//		cvCanny(HSV_Result, HSV_Result,100,200,3);   //img,src,thres1,thres2,ap size   //EDGES
		// Lets try circles detection 
		cvFindContours(HSV_Result, storage, &contours, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_NONE, cvPoint(0,0));
		cvDrawContours(Picture, contours, RED, GREEN, MAX_CONTOUR_LEVELS, 1, CV_AA, cvPoint(0,0));

//		point = (CvPoint *)CV_GET_SEQ_ELEM(CvPoint,contours,1);  // 1 is i
//		x=point->x;
//		y=point->y;
//		printf("Point X %i, Point Y %i\n", x, y);
//                cvPutText (Picture,"Here",cvPoint(x,y), &font, cvScalar(255,0,0,0));   //added last 0



                cvShowImage ("Camera", Picture);
//                cvMoveWindow("Camera", 100, 50);
//                cvShowImage ("HSV", HSV);
//                cvMoveWindow("HSV", 100, 50);

       key = cvWaitKey( 1 );    // Press Q to Quit
        }

    cvReleaseMemStorage(&storage);
    cvReleaseImage( &Gray );
    cvDestroyWindow( "Camera" );    // Destroy the window
    cvReleaseCapture( &capture );   // Release it or never close
    }



/*
Initial Squares, texts, etc...
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

             cvRectangle(Picture, cvPoint(1,1), cvPoint(1276,956), RED, 2,1,1);// size of full screen

*/
