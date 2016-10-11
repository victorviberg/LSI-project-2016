#pragma once
/*
This is where the Button class is declared.
*/
#pragma once
#include <opencv/cv.h>
using namespace std;
using namespace cv;

class Button {
private:
	string Name;
	int Height;
	int Width;
	vector<int> Position;
	void Button_Function();

public:
	void Set_Name(string);
	void Set_Height(int);
	void Set_Width(int);
	void Set_Position(vector<int>);
	void Set_Button_Function();	 //void Set_Button_Function(Function);
};