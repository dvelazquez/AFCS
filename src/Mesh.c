/*	This second file is to separate and clean up the code
	in ACFS, here we put a mesh with coordinates to easily find ROIs
	Daniel Velazquez
	January 2016
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

    CvFont font;

int Mesh(IplImage * Picture){

                // Let's draw a mesh to show coordinates for development
		int      x,y;
		for (x=0;x<=1276; x=x+50){
			for (y=0;y<=956; y=y+50){
				cvLine(Picture,cvPoint(x, 1),cvPoint(x,956),GREEN,1,0,1);   // 19 horizontal lines
				cvLine(Picture,cvPoint(1, y),cvPoint(1276,y),GREEN,1,0,1);  // 25 vertical lines	
			}
		}
		// Center Cross
/*                cvLine(Picture,cvPoint(630, 450),cvPoint(670,450),RED,2,0,1);
                cvLine(Picture,cvPoint(650, 430),cvPoint(650,465),RED,2,0,1);
                cvPutText (Picture,"(650,450)",cvPoint(330,250), &font, cvScalar(255,0,0,0));
		// Lower Right Corner
                cvLine(Picture,cvPoint(1230, 950),cvPoint(1250,950),RED,2,0,1);
                cvLine(Picture,cvPoint(1250, 930),cvPoint(1250,950),RED,2,0,1);
                cvPutText (Picture,"(1250,950)",cvPoint(530,460), &font, cvScalar(255,0,0,0));
		// Lower Right Corner
                cvLine(Picture,cvPoint(1230, 950),cvPoint(1250,950),RED,2,0,1);
                cvLine(Picture,cvPoint(1250, 930),cvPoint(1250,950),RED,2,0,1);
                cvPutText (Picture,"(1250,950)",cvPoint(530,460), &font, cvScalar(255,0,0,0));*/

		return ;
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

