#pragma once

#include <opencv/cv.h>
using namespace std;
using namespace cv; // Alexandra: Mat is a data type in openCV, so we need to include cv here

/*
The Frame class and its public functions are declared here.
*/

// These two are just temporary because I don't know 
// what dimensions an image matrix will have. //Camilla
static const int Image_Height = 3;
static const int Image_Width = 3;



class Frame {
private:
	list<int> Exposure_Times;
	list<int[Image_Height][Image_Width]> Laser_Images;
	int Lasca_Area;
	list<int> Dot_Position;
	int Base_Image[Image_Height][Image_Width];
	int Time_Averaged_Image[Image_Height][Image_Width];
	int Contrast_Image[Image_Height][Image_Width];
	int Perfusion_Image[Image_Height][Image_Width];
public:
	void Set_Exposure_Times(list<int>);
	void Set_Laser_Images(list<int[Image_Height][Image_Width]>);

	void Set_Time_Averaged_Image(int[Image_Height][Image_Width]);
	Mat Set_Contrast_Image();
	Mat Set_Perfusion_Image();
	//Mat Set_Base_Image();
	void Set_Lasca_Area();
	void Set_Dot_Position();
	void Set_Base_Image();
	Mat Get_Time_Averaged_Image();
	Mat Get_Contrast_Image();
	Mat Get_Perfusion_Image();
	Mat Get_Base_Image();
	vector<int[Image_Height][Image_Width]> Get_Laser_Images();
	void Save_Frame();

};

