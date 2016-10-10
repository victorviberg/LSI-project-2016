/*
The Frame class and its functions are written here. 
*/
#pragma once
#include <iostream>
#include <list>
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


// Get functions
Mat Frame::Get_Base_Image() {
	return(Base_Image);
}

Mat Frame::Get_Laser_Image() {
	return(Laser_Image);
}

Mat Frame::Get_Contrast_Image() {
	return(Contrast_Image);
}

Mat Frame::Get_Time_Averaged_Image() {
	return(Time_Averaged_Image);
}

Mat Frame::Get_Perfusion_Image() {
	return(Perfusion_Image);
}

// TODO:
//void Save_Frame();