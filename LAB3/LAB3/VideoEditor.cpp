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
