/* File to include all global definitions
    for ACFS
    Daniel Velazquez
    Feb 2016
*/

#define RED CV_RGB(255,0,0)
#define GREEN CV_RGB(0,255,0)
#define BLUE CV_RGB(0,0,255)
#define AMBER CV_RGB(255,191,0)
#define BLACK CV_RGB(0,0,0)
#define WHITE CV_RGB(255,255,255)
#define MAX_CONTOUR_LEVELS 10


// HSV Thresholds
/*			  H,    S,        V
		RED (0, 100%, 100%)
		LIME(120, 100%, 100%)
		BLUE(240, 100%, 100%)*/

#define RedThresholdMin cvScalar(0, 120, 120,0)		// <- Settings to be adjusted per LED Color
#define RedThresholdMax cvScalar(0, 255, 255,0)

// Global variables definition
    /* Initialize images */
extern    IplImage * Picture;
extern    IplImage * Gray;
extern    IplImage * HSV;
extern    IplImage * HSV_Result;
extern    IplImage * Bin;
extern    IplImage * Result;
extern    IplImage * ROI;
extern    IplImage * ROIGray;

extern    CvSeq *contours;
extern    CvPoint *point;

extern char FileName[70];

extern struct FileData {
   char  Name[50];
	float	X;
	float Y;
	char Color[6];  
};

extern  struct FileData TT[40];        /*Declare how many structures to save max */
