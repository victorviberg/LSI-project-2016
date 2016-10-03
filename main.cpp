#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>

//#include "FlyCapture2.h" //This one will give errors unless drivers and sdk for camera is installed.

#include<iostream>
#include <chrono>
#include <time.h>
#include <thread>
#include <windows.h>
#include<conio.h>           
using namespace std;
//using namespace cv;


int main(int, char**)
{
	cv::Mat image;
	cv::namedWindow("Fönster", 1);

	cout << "First sentence." << endl;
	cout << "test";
	cout << "Hello!";
	cout << "A second sentence.";
	cout << "A third sentence.";


	image = cv::imread("image.jpg");
	cv::imshow("Fönster",image);

	cv::waitKey(0);
	return(0);

}

