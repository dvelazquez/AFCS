/* Image Processing algorithms on the images goes in this section
    Daniel Velazquez
    Feb 2016
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
#include "AFCS.h"

   /* Initialize images 
    IplImage * Gray;
    IplImage * HSV;
    IplImage * HSV_Result;
    IplImage * Bin;
    IplImage * Result;
    CvFont font;*/

int improc(IplImage * Picture){
   CvMemStorage* storage = cvCreateMemStorage(0); //added 0 as default 64k
    CvCapture * capture;

		/* Now some processing to the image */
//		cvCvtColor(Picture,Gray,CV_BGR2GRAY); // Convert color image to gray		
//		cvDilate(Gray, Gray, NULL, 20);      //last arg is iterations
//		cvCanny(Gray, Gray, 1, 200, 3);		// this function finds edges
		cvCvtColor(Picture, HSV, CV_BGR2HSV); // Convert color image to HSV
		cvInRangeS(HSV, RedThresholdMin, RedThresholdMax, HSV_Result);
		cvDilate(HSV_Result, HSV_Result, NULL, 20);      //last arg is iterations
//		cvCanny(HSV_Result, HSV_Result,100,200,3);   //img,src,thres1,thres2,ap size   //EDGES
		// Lets try circles detection 
		cvFindContours(HSV_Result, storage, &contours, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_NONE, cvPoint(0,0));
		cvDrawContours(Picture, contours, RED, GREEN, MAX_CONTOUR_LEVELS, 1, CV_AA, cvPoint(0,0));
	
	return;

}


/*		int w;
		int h;
		CvSize dim =cvGetSize(Picture);
		printf("W= %i  H=%i\n",dim.width, dim.height);*/

//		point = (CvPoint *)CV_GET_SEQ_ELEM(CvPoint,contours,3);  // 1 is i
//		x=point->x;
//		y=point->y;
//	        if((x!=0)&&(y!=0)){
//		printf("Point X %i, Point Y %i\n", x, y);
	         //       cvPutText (Picture,"Here",cvPoint(x,y), &font, cvScalar(255,0,0,0));   //added last 0
//		}
