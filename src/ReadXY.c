/*	This file reads a TXT file with the format:
		Telltale Name		X			Y
		and stores the values in a TT structure 

		Daniel Velazquez - Feb 2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct FileData {
   char  Name[50];
	float	X;
	float Y;
};
 
int ReadXY( ) {
   FILE *fp;
	char str1[20], str2[5], str3[5];	// Name, X, Y
	int i=1;
   struct FileData TT[10];        /*Declare how many structures to save */
 
   fp = fopen("../TestXY.csv", "r");

	while(1)	{ 
	fscanf(fp, "%s %s %s", str1, str2, str3);
		if (feof(fp))
			break;
   /* Data assignation */
   strcpy( TT[i].Name, str1);
   TT[i].X = atof(str2);
   TT[i].Y = atof(str3); 
   /* Data data*/
   printf( "TT[%i].Name : %s\n", i, TT[i].Name);
   printf( "TT[%i].X: %f\n", i, TT[i].X);
   printf( "TT[%i].Y: %f\n\n", i, TT[i].Y);
	i++;
}
	fclose(fp);
   return 0;
}
