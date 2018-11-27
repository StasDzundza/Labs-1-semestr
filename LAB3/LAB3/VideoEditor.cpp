#include "VideoEditor.h"
#include <iostream>
#include <exception>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv; 
using std::cout;
using std::cin;
using std::endl;

VideoEditor::VideoEditor()
{
}

VideoEditor::~VideoEditor()
{
}

void VideoEditor::track_different_colors_in_hsv()
{
	VideoCapture cap(0); //capture the video from web cam

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		throw std::exception("Cannot open the web cam");
	}

	namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

	int LowHue = 170;
	int HighHue = 179;

	int LowSaturation = 150;
	int HighSaturation = 255;

	int LowValue = 60;
	int HighValue = 255;

	//Create trackbars in "Control" window
	cvCreateTrackbar("LowHue", "Control", &LowHue, 179); //Hue (0 - 179)
	cvCreateTrackbar("HighHue", "Control", &HighHue, 179);

	cvCreateTrackbar("LowSat", "Control", &LowSaturation, 255); //Saturation (0 - 255)
	cvCreateTrackbar("HighSat", "Control", &HighSaturation, 255);

	cvCreateTrackbar("LowVal", "Control", &LowValue, 255); //Value (0 - 255)
	cvCreateTrackbar("HighVal", "Control", &HighValue, 255);

	while (true)
	{
		Mat OriginalImg;

		bool ReadIsSuccess = cap.read(OriginalImg); // read a new frame from video

		if (!ReadIsSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			throw std::exception("Cannot open the web cam");
		}

		Mat imgHSV;

		cvtColor(OriginalImg, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

		Mat ThresholdedImg;

		inRange(imgHSV, Scalar(LowHue, LowSaturation, LowValue), Scalar(HighHue, HighSaturation, HighValue), ThresholdedImg); //Threshold the image

	   //morphological opening (remove small objects from the foreground)
		erode(ThresholdedImg, ThresholdedImg, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(ThresholdedImg, ThresholdedImg, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//morphological closing (fill small holes in the foreground)
		dilate(ThresholdedImg, ThresholdedImg, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(ThresholdedImg, ThresholdedImg, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		imshow("Thresholded Image", ThresholdedImg); //show the thresholded image
		imshow("Original", OriginalImg); //show the original image

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
}

void VideoEditor::track_different_colors_and_show_trajectory()
{
	VideoCapture cap(0); //capture the video from webcam

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		throw std::exception("Cannot open the web cam");
	}

	namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

	int iLowH = 170;
	int iHighH = 179;

	int iLowS = 150;
	int iHighS = 255;

	int iLowV = 60;
	int iHighV = 255;

	//Create trackbars in "Control" window
	createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
	createTrackbar("HighH", "Control", &iHighH, 179);

	createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
	createTrackbar("HighS", "Control", &iHighS, 255);

	createTrackbar("LowV", "Control", &iLowV, 255);//Value (0 - 255)
	createTrackbar("HighV", "Control", &iHighV, 255);

	//last center coordinates of our traking object
	int LastX = -1;
	int LastY = -1;

	//Capture a temporary image from the camera
	Mat TmpImg;
	cap.read(TmpImg);

	//Create a black image with the size as the camera output
	Mat imgLines = Mat::zeros(TmpImg.size(), CV_8UC3);;


	while (true)
	{
		Mat OriginalImg;

		bool bSuccess = cap.read(OriginalImg); // read a new frame from video



		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		Mat imgHSV;

		cvtColor(OriginalImg, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

		Mat ThresholdedImg;

		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), ThresholdedImg); //Threshold the image

	   //morphological opening (removes small objects from the foreground)
		erode(ThresholdedImg, ThresholdedImg, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(ThresholdedImg, ThresholdedImg, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//morphological closing (removes small holes from the foreground)
		dilate(ThresholdedImg, ThresholdedImg, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(ThresholdedImg, ThresholdedImg, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//Calculate the moments of the thresholded image
		Moments oMoments = moments(ThresholdedImg);

		double dM01 = oMoments.m01;
		double dM10 = oMoments.m10;
		double dArea = oMoments.m00;

		// if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
		if (dArea > 10000)
		{
			//calculate the position of the ball
			int posX = dM10 / dArea;
			int posY = dM01 / dArea;

			if (LastX >= 0 && LastY >= 0 && posX >= 0 && posY >= 0)
			{
				//Draw a red line from the previous point to the current point
				line(imgLines, Point(posX, posY), Point(LastX, LastY), Scalar(0, 0, 255), 2);
			}

			LastX = posX;
			LastY = posY;
		}

		imshow("Thresholded Image", ThresholdedImg); //show the thresholded image

		OriginalImg = OriginalImg + imgLines;
		imshow("Original", OriginalImg); //show the original image

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
}

void VideoEditor::track_red_color_objects()
{
	VideoCapture cap(0); //capture the video from web cam

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		throw std::exception("Cannot open the web cam");
	}

	namedWindow("Original Window", CV_WINDOW_AUTOSIZE);
	namedWindow("Tracking Window", CV_WINDOW_AUTOSIZE);
	cout << "Press \"Esc\" to exit" << endl;
	while (true)
	{
		Mat OriginalImg;

		bool ReadIsSuccess = cap.read(OriginalImg); // read a new frame from video
		imshow("Original Window", OriginalImg);

		if (!ReadIsSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		Mat TrackingImg;
		inRange(OriginalImg, Scalar(10, 10, 150), Scalar(70, 70, 255), TrackingImg);
		imshow("Tracking Window", TrackingImg);
		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
}

void VideoEditor::camera_with_different_effects()
{
	namedWindow("Control", CV_WINDOW_KEEPRATIO); //create a window called "Control"
	int Color = 1;
	cvCreateTrackbar("Color", "Control", &Color, 3);
	VideoCapture cap(0); //capture the video from web cam

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		throw std::exception("Cannot open the web cam");
	}

	namedWindow("Original Window", CV_WINDOW_AUTOSIZE);
	namedWindow("Changed Window", CV_WINDOW_AUTOSIZE);
	cout << "Press \"Esc\" to exit" << endl;
	while (true)
	{
		Mat OriginalImg;

		bool ReadIsSuccess = cap.read(OriginalImg); // read a new frame from video
		imshow("Original Window", OriginalImg);

		if (!ReadIsSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		Mat ChangedImg;
		if (Color == 0)
		{
			Canny(OriginalImg, ChangedImg, 10, 100, 3, true);
		}
		else if (Color == 1)
		{
			Mat splitChannels[3];
			split(OriginalImg, splitChannels);
			splitChannels[0] = Mat::zeros(splitChannels[0].size(), CV_8UC1);
			merge(splitChannels, 3, ChangedImg);
		}
		else if (Color == 2)
		{
			Mat splitChannels[3];
			split(OriginalImg, splitChannels);
			splitChannels[1] = Mat::zeros(splitChannels[1].size(), CV_8UC1);
			merge(splitChannels, 3, ChangedImg);
		}
		else if (Color == 3)
		{
			Mat splitChannels[3];
			split(OriginalImg, splitChannels);
			splitChannels[1] = Mat::zeros(splitChannels[1].size(), CV_8UC1);
			merge(splitChannels, 3, ChangedImg);
		}
		imshow("Changed Window", ChangedImg);
		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
}
