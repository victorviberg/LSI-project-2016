/*
This document contains functions not bound to a specific class.
*/
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>

#include "FlyCapture2.h" //This one will give errors unless camera thingy is fixed

#include<iostream>
#include <chrono>
#include <time.h>
#include <thread>
#include <windows.h>
#include<conio.h> 

#include "FrameClass.h"


using namespace std;
using namespace FlyCapture2;
using namespace cv;


//Substracts each pixel value in one images from the corresponding pixel value in another
cv::Mat RemoveAmbientLight(cv::Mat baseimage, cv::Mat laserimage,int gain)
{
	cv::Mat result;

	result = laserimage - baseimage;
	result = result*gain;

	return result;
}

cv::Mat CalculateContrast(cv::Mat input, int lascaSize) //There is some(read alot) problems with the iteration 
{

	int H = input.rows/lascaSize; //Needs a way to make sure size is divisible by lascaSize
	int W = input.cols/lascaSize; //As of now these are a bit misleading

	cv::Mat perfusionimage = cv::Mat::ones(H, W, CV_8U);

	cv::Scalar mean;
	cv::Scalar std;
	double contrast; 
	int k = 0;
	
	for (int width_it = 0; width_it <= W - 1; width_it++)
	{
		for (int height_it = 0; height_it <= H - 1; height_it++)
		{

			
			//cv::Mat tempLascaArea(input, cv::Range(lascaSize*width_it, lascaSize*(1 + height_itx)), cv::Range(lascaSize*height_it,lascaSize*(1+ height_it)));
			cv::Mat tempLascaArea(input, cv::Range(lascaSize*height_it, lascaSize*(1 + height_it)), cv::Range(lascaSize*width_it, lascaSize*(1 + width_it)));
			cv::meanStdDev(tempLascaArea, mean, std);
			contrast = std.val[0] / mean.val[0] *255;
			perfusionimage.at<uchar>(height_it, width_it) = contrast;
			k++;
		}

	}
	//cout << k;
	return perfusionimage;
}





//vector<double> Calc_ROI_Average(Frame Current_Working_Frame, vector<ROI> The_List_Of_ROIs) {
//	Mat Perfusion_Image = Current_Working_Frame.Get_Perfusion_Image();
//	vector<double> ROI_Averages;
//
//	for (int i = 0; i <= The_List_Of_ROIs.size(); i++)
//	{
//		// Calculate the average for ROI i in the vector.
//		vector<int> Location = The_List_Of_ROIs.at(i).Get_ROI_Location();
//		vector<int> Region = The_List_Of_ROIs.at(i).Get_ROI_Region();
//
//		double Average = 0;
//		// Calculate average of the rectangular ROIs.
//		for (int width = 0; width < Region.at(1); width++)
//		{
//			for (int height = 0; height < Region.at(2); height++)
//			{
//				Average = Average + Perfusion_Image.at<double>(Location.at(1) + width, Location.at(2) + height);
//			}
//		}
//		ROI_Averages.at(i) = Average / (Region.at(1)*Region.at(2));
//	}
//	return(ROI_Averages);
//}

