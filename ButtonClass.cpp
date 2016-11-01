/*
This is where the Button class is written. 
*/
#pragma once
#include <iostream>
#include "ButtonClass.h"
#include <opencv/cv.h>

using namespace std;
using namespace cv;


// Set functions
void Button::Set_Name(string New_Name) {
	Name = New_Name;
}

void Button::Set_Height(int New_Height) {
	Height = New_Height;
}

void Button::Set_Width(int New_Width) {
	Width = New_Width;
}

void Button::Set_Position(vector<int> New_Position) {
	Position = New_Position;
}

//void Set_Button_Function(Function);
void Button::Set_Button_Function(function<void ()> Button_Func) {
	Button_Function = Button_Func; 
}