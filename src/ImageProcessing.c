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
#include "../include/AFCS.h"


int ImageProcessing(IplImage * Picture){
		/* Now some processing to the image */
//		cvCvtColor(Picture,Gray,CV_BGR2GRAY); // Convert color image to gray		
//		cvDilate(Gray, Gray, NULL, 20);      //last arg is iterations
//		cvCanny(Gray, Gray, 1, 200, 3);		// this function finds edges

		// Extract ROI and put it in a different window
		// ROI should come from an XY file of the feaures to
		// analyze (LEDs, Pointers, Displays, etc)
		// extract to a different function and *.c file  ??			FEB 10 2016
		cvSetImageROI(Picture, cvRect(285, 224, 25, 22));  // TT ROI Test
//		ROI = cvCreateImage(cvGetSize(Picture), Picture->depth, Picture->nChannels);
		ROI = cvCreateImage(cvSize(25, 22), IPL_DEPTH_8U, 3);
		/* copy subimage */
		cvCopy(Picture, ROI, NULL);
		/* always reset the Region of Interest */
		cvResetImageROI(Picture);

		// Shall we run the thresholding and all that to ROIs ??
		cvCvtColor(ROI, HSV, CV_BGR2HSV); // Convert color image to HSV
		cvInRangeS(HSV, RedThresholdMin, RedThresholdMax, HSV_Result);
		cvDilate(HSV_Result, HSV_Result, NULL, 20);      //last arg is iterations

		// NEED TO GET ROI SIZE TO CREATE HSV THE SAME SIZE
//		cvCvtColor(ROI, HSV, CV_BGR2HSV); // Convert color image to HSV
//		cvInRangeS(HSV, RedThresholdMin, RedThresholdMax, HSV_Result);
//		cvDilate(HSV_Result, HSV_Result, NULL, 20);      //last arg is iterations


//		cvCanny(HSV_Result, HSV_Result,100,200,3);   //img,src,thres1,thres2,ap size   //EDGES
		// Lets try circles detection 
//		cvFindContours(HSV_Result, storage, &contours, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_NONE, cvPoint(0,0));
//		cvDrawContours(Picture, &contours, RED, GREEN, MAX_CONTOUR_LEVELS, 1, CV_AA, cvPoint(0,0));
	
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


/*		CvPoint *r=NULL;
		i++;
		for(j=0; j<contours->total;j++){
			r=CV_GET_SEQ_ELEM(CvPoint,contours,j);  // 1 is i
			printf("Point X %i, Point Y %i\n",r->x, r->y);
			printf("J=%i,  I=%i,\n",j,i);
			printf("Contours Total=%i\n",contours->total);
		}
		printf("End of FOR Loop");*/

