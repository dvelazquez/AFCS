/* File open and write test */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Log; 
char FileName[70];
char ProjectName[70];
char SerialNumber[20];
char date[8];
time_t t;

int Initialization( ){
   strcat(FileName,"logs/");   
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

  return;
  // dont forge to    close(Log);
}

