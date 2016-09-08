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
	// Left Cross
	cvLine(Picture,cvPoint(380, 800),cvPoint(420,800),RED,2,0,1);
	cvLine(Picture,cvPoint(400, 780),cvPoint(400,820),RED,2,0,1);
	cvPutText (Picture,"(400,800)",cvPoint(210,410), &font, cvScalar(255,0,0,0));
	// Right Cross
	cvLine(Picture,cvPoint(830, 800),cvPoint(870,800),RED,2,0,1);
	cvLine(Picture,cvPoint(850, 780),cvPoint(850,820),RED,2,0,1);
	cvPutText (Picture,"(850,800)",cvPoint(440,410), &font, cvScalar(255,0,0,0));

	// Lower Right Corner
	cvLine(Picture,cvPoint(1230, 950),cvPoint(1250,950),RED,2,0,1);
	cvLine(Picture,cvPoint(1250, 930),cvPoint(1250,950),RED,2,0,1);
	cvPutText (Picture,"(1250,950)",cvPoint(530,460), &font, cvScalar(255,0,0,0));
	// Lower Right Corner
	cvLine(Picture,cvPoint(1230, 950),cvPoint(1250,950),RED,2,0,1);
	cvLine(Picture,cvPoint(1250, 930),cvPoint(1250,950),RED,2,0,1);
	cvPutText (Picture,"(1250,950)",cvPoint(530,460), &font, cvScalar(255,0,0,0));

	// Tacho backlight LEDs, lines clockwise 30p
	cvRectangle(Picture, cvPoint(105,480), cvPoint(135,510), WHITE, 2,1,1); // Off
	cvRectangle(Picture, cvPoint(110,455), cvPoint(140,485), WHITE, 2,1,1); // AutoStop
	cvRectangle(Picture, cvPoint(100,370), cvPoint(130,400), WHITE, 2,1,1); 	// 1
	cvRectangle(Picture, cvPoint(165,315), cvPoint(195,345), WHITE, 2,1,1);  // 2
	cvRectangle(Picture, cvPoint(250,315), cvPoint(280,345), WHITE, 2,1,1);  // 3
	cvRectangle(Picture, cvPoint(325,330), cvPoint(355,360), WHITE, 2,1,1);  // 4
	cvRectangle(Picture, cvPoint(370,400), cvPoint(400,430), WHITE, 2,1,1);  // 5
	cvRectangle(Picture, cvPoint(135,520), cvPoint(165,550), WHITE, 2,1,1); //RPMx1000
	cvRectangle(Picture, cvPoint(180,260), cvPoint(210,290), WHITE, 2,1,1);  //Ring up
	cvRectangle(Picture, cvPoint(180,600), cvPoint(210,630), WHITE, 2,1,1);  //Ring down
	cvRectangle(Picture, cvPoint(35,400), cvPoint(65,430), WHITE, 2,1,1);  //Ring left
	cvRectangle(Picture, cvPoint(385,565), cvPoint(415,595), WHITE, 2,1,1);   // GMC
	// Speed backlight LEDs, lines clockwise 30p
	cvRectangle(Picture, cvPoint(875,500), cvPoint(905,530), WHITE, 2,1,1); // 0
	cvRectangle(Picture, cvPoint(880,440), cvPoint(910,470), WHITE, 2,1,1); // 20
	cvRectangle(Picture, cvPoint(905,365), cvPoint(935,395), WHITE, 2,1,1); // 40
	cvRectangle(Picture, cvPoint(975,340), cvPoint(1005,370), WHITE, 2,1,1); // 60
	cvRectangle(Picture, cvPoint(1050,340), cvPoint(1080,370), WHITE, 2,1,1); // 80
	cvRectangle(Picture, cvPoint(1105,370), cvPoint(1135,400), WHITE, 2,1,1); // 100
	cvRectangle(Picture, cvPoint(1130,445), cvPoint(1160,475), WHITE, 2,1,1); // 120
	cvRectangle(Picture, cvPoint(1130,515), cvPoint(1160,545), WHITE, 2,1,1); // 140
	cvRectangle(Picture, cvPoint(1055,280), cvPoint(1085,310), WHITE, 2,1,1); // Ring Up
	cvRectangle(Picture, cvPoint(1210,445), cvPoint(1240,475), WHITE, 2,1,1); // Ring Right
	cvRectangle(Picture, cvPoint(1010,625), cvPoint(1040,655), WHITE, 2,1,1);  // Ring Down
	// Center backlight LEDs, lines clockwise 30p
	cvRectangle(Picture, cvPoint(415,300), cvPoint(445,330), WHITE, 2,1,1);  // Oil
	cvRectangle(Picture, cvPoint(570,305), cvPoint(600,335), WHITE, 2,1,1);  // Temp
	cvRectangle(Picture, cvPoint(680,305), cvPoint(710,335), WHITE, 2,1,1);  // Fuel
	cvRectangle(Picture, cvPoint(835,310), cvPoint(865,340), WHITE, 2,1,1);  // Batt
	
	// Tacho Telltales    30p
	cvRectangle(Picture, cvPoint(180,501), cvPoint(210,531), RED, 2,1,1);  	  // Battery
	cvRectangle(Picture, cvPoint(155,457), cvPoint(185,487), AMBER, 2,1,1); // ESC OFF
	cvRectangle(Picture, cvPoint(300,415), cvPoint(330,445), AMBER, 2,1,1);  	  // T/C
	cvRectangle(Picture, cvPoint(175,377), cvPoint(205,407), AMBER, 2,1,1); // Security
	cvRectangle(Picture, cvPoint(212,355), cvPoint(242,385), AMBER, 2,1,1); // Tow
	cvRectangle(Picture, cvPoint(300,460), cvPoint(330,490), AMBER, 2,1,1); // Track OFF
	cvRectangle(Picture, cvPoint(272,500), cvPoint(302,530), GREEN, 2,1,1); // Lights ON
	cvRectangle(Picture, cvPoint(337,430), cvPoint(367,460), GREEN, 2,1,1); // Auto Lights ON
	cvRectangle(Picture, cvPoint(340,470), cvPoint(370,500), AMBER, 2,1,1); // SES
	cvRectangle(Picture, cvPoint(310,500), cvPoint(340,530), RED, 2,1,1); // Airbag
	cvRectangle(Picture, cvPoint(285,537), cvPoint(315,567), RED, 2,1,1); // Brake
	cvRectangle(Picture, cvPoint(230,535), cvPoint(260,565), AMBER, 2,1,1); // ABS
	cvRectangle(Picture, cvPoint(178,535), cvPoint(208,565), AMBER, 2,1,1); // TPMS
	cvRectangle(Picture, cvPoint(258,357), cvPoint(288,387), BLUE, 2,1,1); // HighBeam
  // PRNDL Telltales 30p
	cvRectangle(Picture, cvPoint(945,550), cvPoint(975,580), RED, 2,1,1); // P
	cvRectangle(Picture, cvPoint(975,550), cvPoint(1005,580), RED, 2,1,1); // R
  // Center Telltales 30p
	cvRectangle(Picture, cvPoint(455,345), cvPoint(485,375), GREEN, 2,1,1); // Left
	cvRectangle(Picture, cvPoint(605,355), cvPoint(635,385), AMBER, 2,1,1); // Car
	cvRectangle(Picture, cvPoint(640,355), cvPoint(670,385), AMBER, 2,1,1); // Pedestrian
	cvRectangle(Picture, cvPoint(735,315), cvPoint(765,345), AMBER, 2,1,1); // Empty Gas
	cvRectangle(Picture, cvPoint(795,355), cvPoint(825,385), GREEN, 2,1,1); // Right
	// Speed Telltales 30p
	cvRectangle(Picture, cvPoint(935,460), cvPoint(965,490), AMBER, 2,1,1); // FrontFog
	cvRectangle(Picture, cvPoint(965,515), cvPoint(995,545), AMBER, 2,1,1); // GlowPlug
	cvRectangle(Picture, cvPoint(950,420), cvPoint(980,450), GREEN, 2,1,1); // Diff
	cvRectangle(Picture, cvPoint(965,380), cvPoint(995,410), GREEN, 2,1,1); // Fog
	cvRectangle(Picture, cvPoint(1005,375), cvPoint(1035,405), AMBER, 2,1,1); // H ?
	cvRectangle(Picture, cvPoint(1045,385), cvPoint(1075,415), GREEN, 2,1,1); // DownHill
	cvRectangle(Picture, cvPoint(1075,415), cvPoint(1105,445), AMBER, 2,1,1); // Lane
	cvRectangle(Picture, cvPoint(1085,453), cvPoint(1115,483), AMBER, 2,1,1); // Urea
	cvRectangle(Picture, cvPoint(1075,485), cvPoint(1105,515), RED, 2,1,1); // Seatbelt

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


