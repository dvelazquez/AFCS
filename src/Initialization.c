/* File open and write test */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../include/AFCS.h"

int Log; 
char FileName[70];
char ProjectName[70];
char SerialNumber[20];
char date[8];
time_t t;

// the TT XY structure
struct FileData {
   char  Name[50];
	float	X;
	float Y;
	char Color[6];
};
struct FileData TT[10];        /*Declare how many structures to save */ 

int Initialization( ){
   strcat(FileName,"../logs/");   
   printf("Enter Project Name\n");
   scanf("%s",ProjectName);
   strcat(FileName,ProjectName);   
   strcat(FileName,"_");
   printf("Enter Serial Number\n");
   scanf("%s",SerialNumber);
   strcat(FileName,SerialNumber);  // Serial Number
   strcat(FileName,"_");
   strcat(FileName, __DATE__);
   strcat(FileName,"_");
   strcat(FileName, __TIME__);
   printf("FileName=%s\n",FileName);
   Log = open(FileName, O_RDWR | O_CREAT, -1);  // This is the file name I want
	close(Log);

/*	FILE *fp1;
	fp1= fopen(FileName,"w");
	fprintf(fp1, "Writing test\n");
	printf("Ya paso el fprintf Writing Test");*/

  return FileName;
  // dont forge to    close(Log);
}

int ReadXY( ) {
   FILE *fp;
	char str1[20], str2[6], str3[6], str4[6];	// Name, X, Y, Color
	int i=1;
 
   fp = fopen("../TestXY.csv", "r");

	while(1)	{ 
	fscanf(fp, "%s %s %s %s", str1, str2, str3,str4);
		if (feof(fp))
			break;
   /* Data assignation */
   strcpy( TT[i].Name, str1);
   TT[i].X = atof(str2);
   TT[i].Y = atof(str3); 
  strcpy( TT[i].Color, str4);
   /* Data data*/
   printf( "TT[%i].Name : %s\n", i, TT[i].Name);
   printf( "TT[%i].X: %f\n", i, TT[i].X);
   printf( "TT[%i].Y: %f\n", i, TT[i].Y);
   printf( "TT[%i].Color : %s\n\n", i, TT[i].Color);
	i++;

}
	fclose(fp);
   return 0;	// Shall I return the struct instead of making it global??
}
