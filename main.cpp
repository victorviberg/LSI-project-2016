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

#include"Test-Function.h"
#include"Free-Functions.h"

using namespace std;
using namespace FlyCapture2; //This one will give errors unless camera thingy is fixed
using namespace cv;


int main(int, char**)
{
	//CameraLoopBW();
	//CameraLoopOther();
	//stilltest();
	//filtertest();
	//testFrame();
	testcapture();
	//stilltest2();
	//TestContrast();
	return(0);

}

