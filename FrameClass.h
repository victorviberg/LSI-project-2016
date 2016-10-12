/*
The Frame class and its public functions are declared here.
*/
#pragma once
#include <opencv/cv.h>
using namespace std;
using namespace cv; // Alexandra: Mat is a data type in openCV, so we need to include cv here


class Frame {
private:
	vector<int> Exposure_Times;
	Mat Laser_Image;
	int Lasca_Area;
	vector<int> Dot_Position;
	Mat Base_Image;
	Mat Time_Averaged_Image;
	Mat Contrast_Image;
	Mat Perfusion_Image;

public:
	void Set_Exposure_Times(vector<int>);
	void Set_Laser_Image(Mat);
	void Set_Time_Averaged_Image(Mat);
	void Set_Contrast_Image(Mat);
	void Set_Perfusion_Image(Mat);
	void Set_Lasca_Area(int);
	void Set_Dot_Position(vector<int>);
	void Set_Base_Image(Mat);
	Mat Get_Time_Averaged_Image();
	Mat Get_Contrast_Image();
	Mat Get_Perfusion_Image();
	Mat Get_Base_Image();
	Mat Get_Laser_Image();
	void Save_Frame();

};

