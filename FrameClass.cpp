/*
The Frame class and its functions are written here. 
*/
#pragma once
#include <iostream>
#include "FrameClass.h"
#include <opencv/cv.h>


using namespace std;
using namespace cv; // Alexandra: Mat is a data type in openCV, so we need to include cv here


// Set functions
void Frame::Set_Exposure_Times(vector<int> New_Exposure_Times) {
	Exposure_Times = New_Exposure_Times;
}

void Frame::Set_Base_Image(Mat New_Base_Image) {
	Base_Image = New_Base_Image;
}

void Frame::Set_Laser_Image(Mat New_Laser_Image) {
	Laser_Image = New_Laser_Image;
}

void Frame::Set_Contrast_Image(Mat New_Contrast_Image) {
	Contrast_Image = New_Contrast_Image;
}

void Frame::Set_Time_Averaged_Image(Mat New_Time_Averaged_Image) {
	Time_Averaged_Image = New_Time_Averaged_Image;
}

void Frame::Set_Perfusion_Image(Mat New_Perfusion_Image) {
	Perfusion_Image = New_Perfusion_Image;
}

void Frame::Set_Lasca_Area(int New_Lasca_Area) {
	Lasca_Area = New_Lasca_Area;
}

void Frame::Set_Dot_Position(vector<int> New_Dot_Position) {
	Dot_Position = New_Dot_Position;
}

void Frame::Add_Contrast_Image(Mat Input)
{
	Contrast_Images.push_back(Input);

	if (Contrast_Images.size() > 5)
	{
		Contrast_Images.erase(Contrast_Images.begin()+0);
	}
	Contrast_Image = TemporalFiltering(Contrast_Images);

}

void Frame::Set_Filter_Window_Size(int value)
{
	Filter_Window_Size = value;
}
// Get functions
Mat Frame::Get_Base_Image() {
	return(Base_Image);
}

Mat Frame::Get_Laser_Image() {
	return(Laser_Image);
}

Mat Frame::Get_Contrast_Image() {
	return Contrast_Image;
}

Mat Frame::Get_Time_Averaged_Image() {
	return(Time_Averaged_Image);
}

Mat Frame::Get_Perfusion_Image() {
	return(Perfusion_Image);
}

void Frame::Set_Filename(string File_Name)
{
	"Averaged_Contrast_" + File_Name;
	"Base_Filename_" + File_Name;

	Video_Contrast.open("images\\" + Averaged_Contrast_Filename + ".avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, cv::Size(Width, Height), true);
	Video_Base.open("images\\" + Base_Filename + ".avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, cv::Size(Width, Height), true);
	
}

void Frame::Save_Frame()
{
	Video_Base.write(Base_Image);
	Video_Contrast.write(Contrast_Image);
}


//Constructos
Frame::Frame(string File_Name, int Width, int Height)
{

	Averaged_Contrast_Filename = "Averaged_Contrast_" + File_Name;
	Base_Filename = "Base_Filename_" + File_Name;

	
	Video_Contrast.open("images\\" + Averaged_Contrast_Filename +".avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, cv::Size(Width, Height), true);
	Video_Base.open("images\\" + Base_Filename +".avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, cv::Size(Width, Height), true);


}