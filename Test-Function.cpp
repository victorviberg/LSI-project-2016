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



// This is what was in the "old" main while we were playing around. Parts are commented, remove them if you have the camera.
void oldMain()
{


	cv::Mat image2;
	cv::namedWindow("F�nster", 1);
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
	cv::imshow("F�nster", image2);
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

	camera.Connect(-1);
	camera.StartCapture();
	key = 'i';
	while (key != 'q')
	{
		camera.RetrieveBuffer(&rawImage);
		rawImage.Convert(FlyCapture2::PIXEL_FORMAT_BGR, &rgbImage);
		unsigned int rowBytes = (double)rgbImage.GetReceivedDataSize() / (double)rgbImage.GetRows(); //Converts the Image to Mat
		cv::Mat image = cv::Mat(rgbImage.GetRows(), rgbImage.GetCols(), CV_8UC3, rgbImage.GetData(), rowBytes);

		cv::Mat smallimage; //To resize the image, until we figure out how to take smaller pictures 
		cv::resize(image, smallimage, cv::Size(640, 480), 0, 0, cv::INTER_CUBIC);

		
		image = smallimage;
		smallimage = CalculateContrast(smallimage, 15);
		cvtColor(smallimage, smallimage, cv::COLOR_GRAY2BGR);
		applyColorMap(smallimage, smallimage, 4);
		cv::resize(smallimage, smallimage, cv::Size(640, 480), 0, 0, cv::INTER_CUBIC);


		imshow("Camera_Output2", image);
		imshow("Camera_Output", smallimage);
		key = cv::waitKey(10);

		if (key == 's') //To save the image press s
		{
			cin >> filename; //Press the command window and type
			filename = "images\\" + filename + ".png";
			cv::imwrite(filename, image);
		}
		if (key == 'v')
		{
			record = !record;
		}
		if (record)
		{
			video.write(smallimage);
		}




	}



}



void TestContrast()
{
	cv::Mat frame; //This is a single image
	cv::Mat contrastmap; //This is the contrast image
	cv::VideoCapture capture(0); //This is the "camera variable"
	char key; //This will be used to shut down the loop, keeps track of which button is pressed
	std::string filename;
	cvNamedWindow("Camera_Output 1", 1); //The window we show the images in
	cvNamedWindow("Camera_Output 2", 1);
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
		contrastmap = CalculateContrast(frame, 5);
		cv::resize(contrastmap, contrastmap, cv::Size(width, height), 0, 0, cv::INTER_CUBIC);
		//frame = frame + contrastmap;
		imshow("Camera_Output 1", contrastmap); //Displays the frame in our window
		imshow("Camera_Output 2", frame);

		key = cv::waitKey(10); //Checks for key presses and waits 10mS, if argument 0 is given it pauses until key is pressed.
		if (key == 's') //To save the image press s
		{
			cin >> filename; //Press the command window and type
			filename = "images\\" + filename + ".png";
			cv::imwrite(filename, frame);
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

void stilltest()
{
	Mat image1 = imread("images//bil1.png");
	Mat image2 = imread("images//bil2.png");
	Mat image3;
	Mat image4;

	image3 = RemoveAmbientLight(image1, image2,10);
	image4 = CalculateContrast(image2, 15);
	resize(image4, image4, cv::Size(640, 480), 0, 0, cv::INTER_CUBIC);
	imshow("Speckle", image3);
	imshow("Kontrast", image4);

	cvWaitKey(0);

}



//void TestContrast()
//{
//	cv::Mat baseimage = cv::imread("images//finalimage.png");
//	cv::Mat image;
//	cv::Mat mapped;
//	//cv::Mat laserimage = cv::imread("images//laserimage.png");
//	//cv::Mat finalimage = RemoveAmbientLight(baseimage, laserimage);
//
//	//cv::waitKey(0);
//	//CameraLoopOther();
//	//oldMain();
//	cv::Mat test = CalculateContrast(baseimage, 5);
//	cv::resize(test, image, cv::Size(640, 480), 0, 0, cv::INTER_CUBIC);
//	cv::namedWindow("F�nster 1", 1);
//	cv::imshow("F�nster 1", baseimage);
//	cv::namedWindow("F�nster 2", 1);
//	cv::imshow("F�nster 2", image);
//	mapped = image + baseimage;
//	cv::namedWindow("F�nster 3", 1);
//	cv::imshow("F�nster 3", mapped);
//	cv::waitKey(0);
//
//
//
//}




