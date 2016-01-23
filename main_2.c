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
//#include <iostream>


#define RED CV_RGB(255,0,0)
#define GREEN CV_RGB(0,255,0)
#define BLUE CV_RGB(0,0,255)
#define BLACK CV_RGB(0,0,0)
#define WHITE CV_RGB(255,255,255)


//using namespace std;



int main()
{
    /* Initialize images */
    IplImage * Picture;
    IplImage * All;
    IplImage * None;
    IplImage * AllGray;
    IplImage * NoneGray;
    IplImage * AllBin;
    IplImage * NoneBin;
    IplImage * Result;


    /* Buffer */
    CvMemStorage* storage = cvCreateMemStorage(0); //added 0 as default 64k
   CvCapture * capture;
   capture = cvCaptureFromCAM(0); // the parameter for a cam

    /* Load'em */
    All = cvLoadImage( "Pics/All.jpg", CV_LOAD_IMAGE_COLOR );
    None = cvLoadImage( "Pics/None.jpg", CV_LOAD_IMAGE_COLOR );
    AllGray = cvCreateImage( cvGetSize(All), IPL_DEPTH_8U, 1 );
    AllBin = cvCreateImage( cvGetSize(All), 8, 1 );
    /* Parameters */
    float    threshold = 0.01;
    int      x,y;
    CvScalar s;

    CvFont font;
    double hScale=0.7;
    double vScale=0.7;
    int    lineWidth=2;
    cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, hScale,vScale,0,lineWidth,8);   //added 8 (line type)

    cvNamedWindow ("Camera",1); // added 1 WINDOW_AUTOSIZE
    cvNamedWindow ("Original",1); // added 1 WINDOW_AUTOSIZE
    cvNamedWindow ("Gray",1);  // added 1 WINDOW_AUTOSIZE
    cvNamedWindow ("Bin",1);  // added 1 WINDOW_AUTOSIZE
    do {
                Picture = cvQueryFrame( capture );
                cvPutText (Picture,"Auto Checksheet",cvPoint(5,300), &font, cvScalar(255,0,0,0));   //added last 0
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

                cvShowImage ("Camera", Picture);
                cvMoveWindow("Camera", 1, 1);

                cvShowImage ("Original", None);
                cvMoveWindow("Original", 640, 1);

                /* Gray */
                cvCvtColor(All,AllGray,CV_BGR2GRAY);
                cvShowImage ("Gray", AllGray);
                cvMoveWindow("Gray", 1, 340);

                /* BW */

                cvThreshold(AllGray, AllBin, 80, 255, CV_THRESH_BINARY );
                //cvCanny(AllBin, AllBin, 150, 200, 3);
                cvShowImage ("Bin", AllBin);
                cvMoveWindow("Bin", 640, 340);


                cvCvtColor(Door,DoorGray,CV_BGR2GRAY);
                cvThreshold(DoorGray, DoorBin, 80, 255, CV_THRESH_BINARY );
                //Result = cvCreateImage( cvGetSize(All), 8, 1 );
                //cvMatchTemplate(Door,All,Result,CV_TM_CCORR);
                //cvNormalize( Result, Result, 1, 0, CV_MINMAX );
//                cvAbsDiff(DoorBin,AllBin,Result);
                //printf("%d\n",Result);

            /* Now some processing in the second window */


            /*gray = cvCreateImage( cvGetSize(All), IPL_DEPTH_8U, 1 );
            cvGrabFrame(capture);
            img=cvRetrieveFrame(capture);           // retrieve the captured frame
            cvCvtColor(img,gray,CV_BGR2GRAY);
        // CANNY
        //    cvCanny(gray, gray, 150, 200, 3);

        // Binaryzation with Threshold


        // Find COUNTOURS
        CvSeq* contours = 0;
        cvFindContours( Binary, storage, &contours );
        if( contours ){
            cvDrawContours(All,contours,cvScalarAll(255),cvScalarAll(255),100 );
        }


        cvShowImage (Window2, gray);*/
        //cvNamedWindow ("Binary");

        //cvShowImage ("Binary", Binary);


            int k = cvWaitKey( 50 );
            if (k == 27 || k == '\r') // Press ESC and Enter
                break; // for out
        } while( Picture );


    cvDestroyWindow( "Camera" );    // Destroy the window
    cvDestroyWindow( "Original" );  // Destroy the window
    cvDestroyWindow( "Gray" );      // Destroy the window
    cvDestroyWindow( "Bin" );       // Destroy the window
    cvReleaseCapture( &capture );   // Release it or never close
    }
