#pragma once
/*
This is the declarations of the ROI class and its public functions.
*/
#include <iostream>
#include <vector>
#include <opencv/cv.h>
using namespace std;
using namespace cv;



class ROI {
private:
	vector<int> ROI_Location;
	vector<int> ROI_Region; // First element width, second height.
public:
	void Set_ROI_Location(vector<int>);
	void Set_ROI_Region(vector<int>);
	vector<int> Get_ROI_Location();
	vector<int> Get_ROI_Region();
};