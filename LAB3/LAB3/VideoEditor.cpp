#include "VideoEditor.h"
#include <iostream>
#include <exception>

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

		bool ReadIsSuccess = cap.read(OriginalImg); // read a new frame from video

		if (!ReadIsSuccess) //if not success, break loop
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
	namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"
	int Color = 0;
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

void VideoEditor::record_video(string save_path)
{
	cout << "Press \"R\" to REC video" << endl << endl;
	VideoCapture cap(0); // open the video camera no. 0

	VideoWriter writer;
	bool recording = false;
	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		throw std::exception("Cannot open the web cam");
	}

	const char* windowName = "Webcam Feed";
	namedWindow(windowName, CV_WINDOW_AUTOSIZE); //create a window to display our webcam feed

	string filename;
	if (save_path != "")
	{
		filename = save_path + "myVideo.avi";
	}
	else
	{
		filename = "myVideo.avi";
	}
	int fcc = CV_FOURCC('D', 'I', 'V', '3');
	int fps = 20;
	Size frame_size(cap.get(CV_CAP_PROP_FRAME_WIDTH), cap.get(CV_CAP_PROP_FRAME_HEIGHT));

	writer = VideoWriter(filename, fcc, fps, frame_size);
	if (!writer.isOpened()) //test if frame successfully read
	{
		cout << "ERROR TO OPEN CAMERA" << endl;
		throw std::exception("ERROR TO OPEN CAMERA");
	}
	while (true) 
	{
		Mat frame;

		bool ReadIsSuccess = cap.read(frame); // read a new frame from camera feed
		if (!ReadIsSuccess) //test if frame successfully read
		{
			cout << "ERROR READING FRAME FROM CAMERA FEED" << endl;
			break;
		}

		if (recording)
		{
			writer.write(frame);
			putText(frame, "REC", Point(0, 60), 2, 2, Scalar(0, 0, 255));
		}
		imshow(windowName, frame); //show the frame in "MyVideo" window
		
		//listen for 10ms for a key to be pressed
		switch (waitKey(10))
		{
		case 27://'esc' has been pressed (ASCII value for 'esc' is 27)				//exit program.
			return;
		case 114://pressed r (pause or rec)
			recording = !recording;
			break;
		}
	}
}

void VideoEditor::track_objects_by_web_cam()
{
	//some boolean variables for different functionality within this
	//program
	bool trackObjects = true;
	bool useMorphOps = true;
	calibrationMode = true;
	//Matrix to store each frame of the webcam feed
	Mat cameraFeed;
	//matrix storage for HSV image
	Mat HSV;
	//matrix storage for binary threshold image
	Mat threshold;
	//x and y values for the location of the object
	int x = 0, y = 0;
	//video capture object to acquire webcam feed
	VideoCapture capture;
	//open capture object at location zero (default location for webcam)
	capture.open(0);
	//set height and width of capture frame
	capture.set(CV_CAP_PROP_FRAME_WIDTH, FRAME_WIDTH);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, FRAME_HEIGHT);
	//must create a window before setting mouse callback
	cv::namedWindow(windowName);
	//set mouse callback function to be active on "Webcam Feed" window
	//we pass the handle to our "frame" matrix so that we can draw a rectangle to it
	//as the user clicks and drags the mouse
	cv::setMouseCallback(windowName, clickAndDrag_Rectangle, &cameraFeed);
	//initiate mouse move and drag to false 
	mouseIsDragging = false;
	mouseMove = false;
	rectangleSelected = false;

	//start an infinite loop where webcam feed is copied to cameraFeed matrix
	//all of our operations will be performed within this loop
	while (1)
	{

	}
}

void clickAndDrag_Rectangle(int event, int x, int y, int flags, void * param)
{
	//only if calibration mode is true will we use the mouse to change HSV values
	if (calibrationMode == true)
	{
		//get handle to video feed passed in as "param" and cast as Mat pointer
		Mat* videoFeed = (Mat*)param;

		if (event == CV_EVENT_LBUTTONDOWN && mouseIsDragging == false)
		{
			//keep track of initial point clicked
			initialClickPoint = Point(x, y);
			//user has begun dragging the mouse
			mouseIsDragging = true;
		}
		/* user is dragging the mouse */
		if (event == CV_EVENT_MOUSEMOVE && mouseIsDragging == true)
		{
			//keep track of current mouse point
			currentMousePoint = Point(x, y);
			//user has moved the mouse while clicking and dragging
			mouseMove = true;
		}
		/* user has released left button */
		if (event == CV_EVENT_LBUTTONUP && mouseIsDragging == true)
		{
			//set rectangle ROI to the rectangle that the user has selected
			rectangleROI = Rect(initialClickPoint, currentMousePoint);
			//reset boolean variables
			mouseIsDragging = false;
			mouseMove = false;
			rectangleSelected = true;
		}

		if (event == CV_EVENT_RBUTTONDOWN) 
		{
			//user has clicked right mouse button
			//Reset HSV Values
			H_MIN = 0;
			S_MIN = 0;
			V_MIN = 0;
			H_MAX = 255;
			S_MAX = 255;
			V_MAX = 255;

		}
	}
}
