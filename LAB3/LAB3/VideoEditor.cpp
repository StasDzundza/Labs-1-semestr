#include "VideoEditor.h"
#include <iostream>
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

void VideoEditor::track_red_color_objects()
{
	VideoCapture cap(0); //capture the video from web cam

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		throw("Cannot open the web cam");
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
