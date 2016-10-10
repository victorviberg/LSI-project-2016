/*
This document contains functions not bound to a specific class.
*/
#include "Frameclass.h"
#include "ROIclass.h"
#include <opencv/cv.h>
using namespace std;
using namespace cv;

vector<double> Calc_ROI_Average(Frame Current_Working_Frame, vector<ROI> The_List_Of_ROIs) {
	Mat Perfusion_Image = Current_Working_Frame.Get_Perfusion_Image();
	vector<double> ROI_Averages;

	for (int i = 0; i <= The_List_Of_ROIs.size(); i++)
	{
		// Calculate the average for ROI i in the vector.
		vector<int> Location = The_List_Of_ROIs.at(i).Get_ROI_Location();
		vector<int> Region = The_List_Of_ROIs.at(i).Get_ROI_Region();

		double Average = 0;
		// Calculate average of the rectangular ROIs.
		for (int width = 0; width < Region.at(1); width++)
		{
			for (int height = 0; height < Region.at(2); height++)
			{
				Average = Average + Perfusion_Image.at<double>(Location.at(1) + width, Location.at(2) + height);
			}
		}
		ROI_Averages.at(i) = Average / (Region.at(1)*Region.at(2));
	}
	return(ROI_Averages);
}

