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
int Cycle=1;  // use a getsize function, for now use the known quantity
int i;
char pause;

int ImageProcessing(IplImage * Picture){
	// Left Cross
	cvLine(Picture,cvPoint(380, 800),cvPoint(420,800),RED,2,0,1);
	cvLine(Picture,cvPoint(400, 780),cvPoint(400,820),RED,2,0,1);
	// Right Cross
	cvLine(Picture,cvPoint(830, 800),cvPoint(870,800),RED,2,0,1);
	cvLine(Picture,cvPoint(850, 780),cvPoint(850,820),RED,2,0,1);

		// Extract ROI and put it in a different window
		// XY for ROI comes from TT[i].X and TT[i].Y
		// analyze (LEDs, Pointers, Displays, etc)
	for(i=0;i<31;i++){
		cvResetImageROI(Picture);		// always reset the Region of Interest
		cvSetImageROI(Picture, cvRect(TT[i].X/2, TT[i].Y/2, 15, 15));  
		ROI = cvCreateImage(cvSize(15, 15), IPL_DEPTH_8U, 3); // 3 for color
		ROIGray = cvCreateImage(cvSize(15, 15), IPL_DEPTH_8U, 1); // 1 for gray
		cvCopy(Picture, ROI, NULL); // copy sub image

		/* This routine is the size of a TT and can see it ON or OFF */
		cvCvtColor(ROI,ROIGray,CV_BGR2GRAY); // Convert color image to gray		
		cvThreshold(ROIGray,ROIGray,200,254,CV_THRESH_BINARY); 
		cvDilate(ROIGray, ROIGray, NULL, 1);      //last arg is iterations, lower is faster
		Average=cvAvg(ROIGray,NULL);
		AverageDouble = Average.val[0];
	   printf( "TT[%i].Name : %s\n", i, TT[i].Name);
		printf("Average=%f\t",AverageDouble);
		if(AverageDouble<=5)
			printf("OFF\n");
		if(AverageDouble>=6){
			printf("ON\n");
			cvShowImage ("ROI", ROI); 
			sleep(1);
		}
	   printf( "TT[%i].X: %f\n", i, TT[i].X);
	   printf( "TT[%i].Y: %f\n\n", i, TT[i].Y);
	   printf( "TT[%i].Color : %s\n", i, TT[i].Color);
		//printf("FileName=%s\n",FileName);
		printf("Termina 1 for\n\n");

	}
		/*if(i>30){
			i=1;
		}*/
		printf("Termina 30 TTs\n");
		//i++;

		cvResetImageROI(Picture);		// always reset the Region of Interest
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
//	i++;

/*		cvShowImage ("Camera", Picture);
		cvMoveWindow("Camera", 100, 50);
		cvShowImage ("ROI", ROI); 
		sleep(1);
	}	*/

