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

using namespace std;
using namespace FlyCapture2; //This one will give errors unless camera thingy is fixed
//using namespace cv;



// This is what was in the "old" main while we were playing around. Parts are commented, remove them if you have the camera.
void oldMain()
{


	cv::Mat image2;
	cv::namedWindow("Fönster", 1);
	//cv::namedWindow("Kamera bild", 1);

	// Connect the camera
	Camera camera;

	Image rgbImage;
	Image rawImage;
	//camera.Connect(0);
	//camera.StartCapture();

	//camera.RetrieveBuffer(&rawImage);


	//rawImage.Convert(FlyCapture2::PIXEL_FORMAT_BGR, &rgbImage);

	//unsigned int rowBytes = (double)rgbImage.GetReceivedDataSize() / (double)rgbImage.GetRows();
	//cv::Mat image = cv::Mat(rgbImage.GetRows(), rgbImage.GetCols(), CV_8UC3, rgbImage.GetData(), rowBytes);

	//cv::Mat smallimage;
	//cv::resize(image, smallimage, cv::Size(800, 600), 0, 0, cv::INTER_CUBIC);




	cout << "First sentence." << endl;
	cout << "test";
	cout << "Hello!";
	cout << "A second sentence.";
	cout << "A third sentence.";


	image2 = cv::imread("image.jpg");
	cv::imshow("Fönster", image2);
	//cv::imshow("Kamera bild", image);

	cv::waitKey(0);




}




void CameraLoopOther()
{

	cv::Mat frame; //This is a single image
	cv::VideoCapture capture(0); //This is the "camera variable"
	char key; //This will be used to shut down the loop, keeps track of which button is pressed
	std::string filename;
	cvNamedWindow("Camera_Output", 1); //The window we show the images in
	bool record;
	int width;
	int height;

	width = capture.get(CV_CAP_PROP_FRAME_WIDTH);
	height = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
	cout << width << "    " << height;
	
	cv::VideoWriter video("images\\video.avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, cv::Size(width, height), true);
	video.open("images\\video.avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, cv::Size(width, height), true);

	record = false; 
	key = 'i'; //Something else then q
	while (key != 'q') //Loop until q is pressed
	{
		capture >> frame; //Takes a picture from the camera to the work memory
		//capture >> frame; //pause/delay/waiting causes some problems which are solved by doing this twice.
		imshow("Camera_Output", frame); //Displays the frame in our window

		key = cv::waitKey(10); //Checks for key presses and waits 10mS, if argument 0 is given it pauses until key is pressed.
		if (key == 's') //To save the image press s
		{
			cin >> filename; //Press the command window and type
			filename = "images\\" + filename + ".png";
			cv::imwrite(filename,frame);
		}
		if (key == 'v')
		{
			record = !record;
		}
		if (record)
		{
			video.write(frame);
		}
	}

	return;

}

//This one is untested
void CameraLoopBW()
{
	cv::Mat frame; //This is a single image
	cv::VideoCapture capture(0); //This is the "camera variable"
	char key; //This will be used to shut down the loop, keeps track of which button is pressed
	Camera camera;

	Image rgbImage;
	Image rawImage;

	bool record;
	std::string filename;

	cv::VideoWriter video("images\\video.avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, cv::Size(800, 600), true);
	video.open("images\\video.avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, cv::Size(800, 600), true);

	record = false;

	camera.Connect(0);
	camera.StartCapture();
	key = 'i';
	while (key != 'q')
	{
		camera.RetrieveBuffer(&rawImage);
		rawImage.Convert(FlyCapture2::PIXEL_FORMAT_BGR, &rgbImage);
		unsigned int rowBytes = (double)rgbImage.GetReceivedDataSize() / (double)rgbImage.GetRows(); //Converts the Image to Mat
		cv::Mat image = cv::Mat(rgbImage.GetRows(), rgbImage.GetCols(), CV_8UC3, rgbImage.GetData(), rowBytes);
		cv::Mat smallimage; //To resize the image, until we figure out how to take smaller pictures 
		cv::resize(image, smallimage, cv::Size(800, 600), 0, 0, cv::INTER_CUBIC);
		imshow("Camera_Output", smallimage);
		key = cv::waitKey(10);

		if (key == 's') //To save the image press s
		{
			cin >> filename; //Press the command window and type
			filename = "images\\" + filename + ".png";
			cv::imwrite(filename, smallimage);
		}
		if (key == 'v')
		{
			record = !record;
		}
		if (record)
		{
			cout << "sd";
			video.write(smallimage);
		}




	}



}








