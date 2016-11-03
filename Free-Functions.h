#pragma once
/*
This document contains declarations of all functions not bound to a specific class.
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
#include <vector>

#include"Test-Function.h"
using namespace std;
using namespace FlyCapture2;




cv::Mat RemoveAmbientLight(cv::Mat baseimage, cv::Mat laserimage,int threshhold);

cv::Mat CalculateContrast(cv::Mat input, int lascaSize);

cv::Mat CalculateContrast2(cv::Mat input, int lascaSize);

cv::Mat TemporalFiltering(vector<cv::Mat> input);







