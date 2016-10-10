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


using namespace std;
using namespace FlyCapture2;
using namespace cv;


//Substracts each pixel value in one images from the corresponding pixel value in another
cv::Mat RemoveAmbientLight(cv::Mat baseimage, cv::Mat laserimage)
{
	cv::Mat result;

	result = laserimage - baseimage;

	return result;
}

cv::Mat CalculateContrast(cv::Mat input, int lascaSize) //There is some(read alot) problems with the iteration 
{

	int H = input.rows/lascaSize; //Needs a way to make sure size is divisible by lascaSize
	int W = input.cols/lascaSize; //As of now these are abit misleading

	int testW;
	int testH;

	cv::Mat perfusionimage = cv::Mat::ones(H, W, CV_8UC3);
	cv::Mat temp_width;
	cv::Mat temp_height;
	cv::Scalar mean;
	cv::Scalar std;
	double contrast; 
	
	for (int height_it = 0; height_it <= H - 1; height_it++)
	{
		for (int width_it = 0; width_it <= W - 1; width_it++)
		{

			
			cv::Mat tempLascaArea(input, cv::Range(lascaSize*height_it, lascaSize*(1 + height_it)), cv::Range(lascaSize*width_it,lascaSize*(1+ width_it)));
			//cv::Mat tempLascaArea(input, cv::Range(lascaSize*width_it, lascaSize*(1 + width_it)), cv::Range(lascaSize*height_it, lascaSize*(1 + height_it)));
			cv::meanStdDev(tempLascaArea, mean, std);
			contrast = std.val[0] / mean.val[0] *255;
			//cout << "Kontrast " << contrast << " X-led " << height_it << " Y-led " << width_it << endl;
			//perfusionimage.at<uchar>(width_it, height_it) = contrast;
			perfusionimage.at<uchar>(height_it, width_it) = 255;

		}

	}
	return perfusionimage;
}













