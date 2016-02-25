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

CvScalar Average;
float AverageDouble;

int ImageProcessing(IplImage * Picture){
		// Extract ROI and put it in a different window
		// XY for ROI comes from TT[i].X and TT[i].Y
		// analyze (LEDs, Pointers, Displays, etc)
		cvSetImageROI(Picture, cvRect(285, 224, 25, 22));  // TT ROI Test
		ROI = cvCreateImage(cvSize(25, 22), IPL_DEPTH_8U, 3); // 3 for color
		ROIGray = cvCreateImage(cvSize(25, 22), IPL_DEPTH_8U, 1); // 1 for gray
		/* copy subimage */
		cvCopy(Picture, ROI, NULL);
		/* always reset the Region of Interest */
		cvResetImageROI(Picture);
		/* This routine is the size of a TT and can see it ON or OFF */
		cvCvtColor(ROI,ROIGray,CV_BGR2GRAY); // Convert color image to gray		
		cvThreshold(ROIGray,ROIGray,220,254,CV_THRESH_BINARY); 
		cvDilate(ROIGray, ROIGray, NULL, 1);      //last arg is iterations, lower is faster
		Average=cvAvg(ROIGray,NULL);
		AverageDouble = Average.val[0];
		printf("%f\n",AverageDouble);
		if(AverageDouble<=15)
			printf("OFF\t");
		if(AverageDouble>=60)
			printf("ON\t");

   printf( "TT[1].Name : %s\n", TT[1].Name);
   printf( "TT[1].X: %f\n", TT[1].X);
   printf( "TT[1].Y: %f\n\n", TT[1].Y);
   printf( "TT[1].Color : %s\n", TT[1].Color);

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
/*		cvCvtColor(Picture,Gray,CV_BGR2GRAY); // Convert color image to gray		
		cvThreshold(Gray,Gray,220,254,CV_THRESH_BINARY); 
		cvDilate(Gray, Gray, NULL, 1);      //last arg is iterations*/
		// Shall we run the thresholding and all that to ROIs ??
//		cvCvtColor(ROI, HSV, CV_BGR2HSV); // Convert color image to HSV
//		cvInRangeS(HSV, RedThresholdMin, RedThresholdMax, HSV_Result);
//		cvDilate(HSV_Result, HSV_Result, NULL, 20);      //last arg is iterations



//		cvCanny(HSV_Result, HSV_Result,100,200,3);   //img,src,thres1,thres2,ap size   //EDGES
		// Lets try circles detection 
//		cvFindContours(HSV_Result, storage, &contours, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_NONE, cvPoint(0,0));
//		cvDrawContours(Picture, &contours, RED, GREEN, MAX_CONTOUR_LEVELS, 1, CV_AA, cvPoint(0,0));

