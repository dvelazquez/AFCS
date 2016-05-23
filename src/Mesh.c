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
	// Why cvLine coordinates are (956,1276) but image is (480,620) (x2= 960,1240)
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

	// Tacho backlight LEDs, lines clockwise
	cvRectangle(Picture, cvPoint(100,505), cvPoint(140,545), BLUE, 2,1,1); 			
	cvRectangle(Picture, cvPoint(100,455), cvPoint(140,495), BLUE, 2,1,1); 		
	cvRectangle(Picture, cvPoint(100,395), cvPoint(140,435), BLUE, 2,1,1); 	
	cvRectangle(Picture, cvPoint(145,345), cvPoint(185,385), BLUE, 2,1,1); 
	cvRectangle(Picture, cvPoint(205,335), cvPoint(245,375), BLUE, 2,1,1); 
	cvRectangle(Picture, cvPoint(257,335), cvPoint(297,375), BLUE, 2,1,1); 
	cvRectangle(Picture, cvPoint(320,345), cvPoint(360,385), BLUE, 2,1,1); 
	cvRectangle(Picture, cvPoint(365,390), cvPoint(405,430), BLUE, 2,1,1); 
	cvRectangle(Picture, cvPoint(130,560), cvPoint(170,600), BLUE, 2,1,1);
	cvRectangle(Picture, cvPoint(175,590), cvPoint(215,630), BLUE, 2,1,1);  
	cvRectangle(Picture, cvPoint(230,590), cvPoint(270,630), BLUE, 2,1,1);  
	cvRectangle(Picture, cvPoint(285,590), cvPoint(325,630), BLUE, 2,1,1);  
	// Speed backlight LEDs, lines clockwise
	cvRectangle(Picture, cvPoint(850,490), cvPoint(890,530), BLUE, 2,1,1); 			
	cvRectangle(Picture, cvPoint(850,422), cvPoint(890,462), BLUE, 2,1,1); 		
	cvRectangle(Picture, cvPoint(875,370), cvPoint(915,410), BLUE, 2,1,1); 	
	cvRectangle(Picture, cvPoint(942,330), cvPoint(982,370), BLUE, 2,1,1); 
	cvRectangle(Picture, cvPoint(1010,330), cvPoint(1050,370), BLUE, 2,1,1); 
	cvRectangle(Picture, cvPoint(1080,342), cvPoint(1120,382), BLUE, 2,1,1); 
	cvRectangle(Picture, cvPoint(1125,400), cvPoint(1165,440), BLUE, 2,1,1); 
	cvRectangle(Picture, cvPoint(1125,470), cvPoint(1165,510), BLUE, 2,1,1); 
	cvRectangle(Picture, cvPoint(1110,530), cvPoint(1150,570), BLUE, 2,1,1); 
	cvRectangle(Picture, cvPoint(940,580), cvPoint(980,620), BLUE, 2,1,1);
	cvRectangle(Picture, cvPoint(1005,580), cvPoint(1045,620), BLUE, 2,1,1); 
	cvRectangle(Picture, cvPoint(1065,580), cvPoint(1105,620), BLUE, 2,1,1);  
	// Center backlight LEDs, lines clockwise
	cvRectangle(Picture, cvPoint(450,300), cvPoint(490,340), BLUE, 2,1,1);  
	cvRectangle(Picture, cvPoint(610,300), cvPoint(650,340), BLUE, 2,1,1);  
	cvRectangle(Picture, cvPoint(775,300), cvPoint(815,340), BLUE, 2,1,1);  
	
	// Tacho Telltales
	cvRectangle(Picture, cvPoint(200,535), cvPoint(230,565), RED, 2,1,1);  	  // Battery
	cvRectangle(Picture, cvPoint(300,415), cvPoint(330,445), RED, 2,1,1);  	  // Park Brake
	cvRectangle(Picture, cvPoint(310,450), cvPoint(340,480), AMBER, 2,1,1); // Track OFF
	cvRectangle(Picture, cvPoint(290,530), cvPoint(320,560), GREEN, 2,1,1); // Lights ON
	cvRectangle(Picture, cvPoint(345,495), cvPoint(375,525), AMBER, 2,1,1); // SES
	cvRectangle(Picture, cvPoint(195,420), cvPoint(225,450), AMBER, 2,1,1); // Security
	cvRectangle(Picture, cvPoint(225,400), cvPoint(255,430), AMBER, 2,1,1); // Tow
	cvRectangle(Picture, cvPoint(180,505), cvPoint(210,535), AMBER, 2,1,1); // ESC OFF

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

                // TT ROI Test
                cvRectangle(Picture, cvPoint(230,265), cvPoint(265,300), BLUE, 2,1,1);//added shift=1 ?
	             cvRectangle(Picture, cvPoint(1,1), cvPoint(1276,956), RED, 2,1,1);// size of full screen
*/

