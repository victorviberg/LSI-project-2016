/*
The Frame class and its functions are written here. 
*/
#include <iostream>
#include <list>
#include "FrameClass.h"
#include <opencv/cv.h>
using namespace std;
using namespace cv; // Alexandra: Mat is a data type in openCV, so we need to include cv here

/*
I tryed just declaring the variables and functions, but 
got a problem with how to declare the vectors... So I
made everything a comment so it would be possible to 
build the program anyway. //Camilla
*/


void Frame::Set_Exposure_Times(list<int> Exp_Times) {
	Exposure_Times = Exp_Times;
}

void Frame::Set_Time_Averaged_Image(int New_Time_Averaged_Image[Image_Height][Image_Width])
{
	// TODO: Check if this is fast enough
	for (int i = 0; i < Image_Height; i++)
	{
		for (int j = 0; j < Image_Width; j++)
		{
			Time_Averaged_Image[i][j] = New_Time_Averaged_Image[i][j];
		}
	}
}



// Alexandra: functions still to write

//Mat Set_Contrast_Image();
//Mat Set_Perfusion_Image();
////Mat Set_Base_Image();
//void Set_Lasca_Area();
//void Set_Dot_Position();
//void Set_Base_Image();
//Mat Get_Time_Averaged_Image();
//Mat Get_Contrast_Image();
//Mat Get_Perfusion_Image();
//Mat Get_Base_Image();
//vector<int[Image_Height][Image_Width]> Get_Laser_Images();
//void Save_Frame();