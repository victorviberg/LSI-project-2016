/*
The Frame class and its functions are written here. 
*/
#include <iostream>
#include <list>
#include "FrameClass.h"
using namespace std;

/*
I tryed just declaring the variables and functions, but 
got a problem with how to declare the vectors... So I
made everything a comment so it would be possible to 
build the program anyway. //Camilla
*/


// These two are just temporary because I don't know 
// what dimensions an image matrix will have. //Camilla
static const int Image_Height = 3;
static const int Image_Width = 3;
/*
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
	/*
	void Set_Time_Averaged_Image();
	Mat Set_Contrast_Image();
	Mat Set_Perfusion_Image();
	Mat Set_Base_Image();
	void Set_Lasca_Area();
	void Set_Dot_Position();
	void Set_Base_Image();
	Mat Get_Time_Averaged_Image();
	Mat Get_Contrast_Image();
	Mat Get_Perfusion_Image();
	Mat Get_Base_Image();
	vector<int[Image_Height][Image_Width]> Get_Laser_Images();
	void Save_Frame();*/
/*
};
*/
/*
void Frame::Set_Exposure_Times(list<int> Exp_Times) {
	Exposure_Times = Exp_Times;
}

void Frame::Set_Laser_Images(list<int[Image_Height][Image_Width]> Laser_Imag) {
	Laser_Images = Laser_Imag;
}
*/