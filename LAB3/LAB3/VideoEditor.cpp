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

	int LowH = 170;
	int HighH = 179;

	int LowS = 150;
	int HighS = 255;

	int LowV = 60;
	int HighV = 255;

	//Create trackbars in "Control" window
	createTrackbar("LowH", "Control", &LowH, 179); //Hue (0 - 179)
	createTrackbar("HighH", "Control", &HighH, 179);

	createTrackbar("LowS", "Control", &LowS, 255); //Saturation (0 - 255)
	createTrackbar("HighS", "Control", &HighS, 255);

	createTrackbar("LowV", "Control", &LowV, 255);//Value (0 - 255)
	createTrackbar("HighV", "Control", &HighV, 255);

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

		inRange(imgHSV, Scalar(LowH, LowS, LowV), Scalar(HighH, HighS, HighV), ThresholdedImg); //Threshold the image

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
	//some boolean variables for different functionality within this program
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
	namedWindow(windowName);
	//set mouse callback function to be active on "Webcam Feed" window
	//we pass the handle to our "frame" matrix so that we can draw a rectangle to it
	//as the user clicks and drags the mouse
	setMouseCallback(windowName, clickAndDrag_Rectangle, &cameraFeed);
	//initiate mouse move and drag to false 
	mouseIsDragging = false;
	mouseMove = false;
	rectangleSelected = false;

	//start an infinite loop where webcam feed is copied to cameraFeed matrix
	//all of our operations will be performed within this loop
	while (1)
	{
		//store image to matrix
		capture.read(cameraFeed);
		//convert frame from BGR to HSV colorspace
		cvtColor(cameraFeed, HSV, COLOR_BGR2HSV);
		//set HSV values from user selected region
		recordHSV_values(cameraFeed, HSV);
		//filter HSV image between values and store filtered image to
		//threshold matrix
		inRange(HSV, Scalar(H_MIN, S_MIN, V_MIN), Scalar(H_MAX, S_MAX, V_MAX), threshold);
		if (useMorphOps)
		{
			morph_ops(threshold);
		}
		//pass in thresholded frame to our object tracking function
		//this function will return the x and y coordinates of the
		//filtered object
		if (trackObjects)
		{
			track_filtered_object(x, y, threshold, cameraFeed);
		}
	}
}

void VideoEditor::recordHSV_values(Mat frame, Mat hsv_frame)
{
	//save HSV values for ROI that user selected to a vector
	if (mouseMove == false && rectangleSelected == true) 
	{
		//clear previous vector values
		if (H_ROI.size() > 0) H_ROI.clear();
		if (S_ROI.size() > 0) S_ROI.clear();
		if (V_ROI.size() > 0) V_ROI.clear();
		//if the rectangle has no width or height (user has only dragged a line) then we don't try to iterate over the width or height
		if (rectangleROI.width < 1 || rectangleROI.height < 1) cout << "Please drag a rectangle, not a line" << endl;
		else
		{
			for (int i = rectangleROI.x; i < rectangleROI.x + rectangleROI.width; i++)
			{
				//iterate through both x and y direction and save HSV values at each and every point
				for (int j = rectangleROI.y; j < rectangleROI.y + rectangleROI.height; j++)
				{
					//save HSV value at this point
					H_ROI.push_back((int)hsv_frame.at<Vec3b>(j, i)[0]);
					S_ROI.push_back((int)hsv_frame.at<Vec3b>(j, i)[1]);
					V_ROI.push_back((int)hsv_frame.at<Vec3b>(j, i)[2]);
				}
			}
		}
		//reset rectangleSelected so user can select another region if necessary
		rectangleSelected = false;
		//set min and max HSV values from min and max elements of each array
		if (H_ROI.size() > 0) 
		{
			H_MIN = *std::min_element(H_ROI.begin(), H_ROI.end());
			H_MAX = *std::max_element(H_ROI.begin(), H_ROI.end());
			cout << "MIN 'H' VALUE: " << H_MIN << endl;
			cout << "MAX 'H' VALUE: " << H_MAX << endl;
		}
		if (S_ROI.size() > 0) 
		{
			S_MIN = *std::min_element(S_ROI.begin(), S_ROI.end());
			S_MAX = *std::max_element(S_ROI.begin(), S_ROI.end());
			cout << "MIN 'S' VALUE: " << S_MIN << endl;
			cout << "MAX 'S' VALUE: " << S_MAX << endl;
		}
		if (V_ROI.size() > 0)
		{
			V_MIN = *std::min_element(V_ROI.begin(), V_ROI.end());
			V_MAX = *std::max_element(V_ROI.begin(), V_ROI.end());
			cout << "MIN 'V' VALUE: " << V_MIN << endl;
			cout << "MAX 'V' VALUE: " << V_MAX << endl;
		}
	}
	if (mouseMove == true)
	{
		//if the mouse is held down, we will draw the click and dragged rectangle to the screen
		rectangle(frame, initialClickPoint, Point(currentMousePoint.x, currentMousePoint.y), Scalar(0, 255, 0), 1, 8, 0);
	}
}

void VideoEditor::morph_ops(Mat & thresh)
{
	//morphological opening (removes small objects from the foreground)
	//morphological closing (removes small holes from the foreground)

	erode(thresh, thresh, getStructuringElement(MORPH_RECT, Size(3, 3)));
	erode(thresh, thresh, getStructuringElement(MORPH_RECT, Size(3, 3)));

	dilate(thresh, thresh, getStructuringElement(MORPH_RECT, Size(8, 8)));
	dilate(thresh, thresh, getStructuringElement(MORPH_RECT, Size(8, 8)));

}

void VideoEditor::draw_object(int x, int y, Mat & frame)
{
	//use some of the openCV drawing functions to draw crosshairs tracked on image

	//if and else statements to prevent memory errors from writing off the screen : for example(-25,-25) is not within the window

	circle(frame, Point(x, y), 20, Scalar(0, 255, 0), 2);//BRG!!!
	if (y - 25 > 0)
		line(frame, Point(x, y), Point(x, y - 25), Scalar(0, 255, 0), 2);
	else line(frame, Point(x, y), Point(x, 0), Scalar(0, 255, 0), 2);
	if (y + 25 < FRAME_HEIGHT)
		line(frame, Point(x, y), Point(x, y + 25), Scalar(0, 255, 0), 2);
	else line(frame, Point(x, y), Point(x, FRAME_HEIGHT), Scalar(0, 255, 0), 2);
	if (x - 25 > 0)
		line(frame, Point(x, y), Point(x - 25, y), Scalar(0, 255, 0), 2);
	else line(frame, Point(x, y), Point(0, y), Scalar(0, 255, 0), 2);
	if (x + 25 < FRAME_WIDTH)
		line(frame, Point(x, y), Point(x + 25, y), Scalar(0, 255, 0), 2);
	else line(frame, Point(x, y), Point(FRAME_WIDTH, y), Scalar(0, 255, 0), 2);

	putText(frame, std::to_string(x) + "," + std::to_string(y), Point(x, y + 30), 1, 1, Scalar(0, 255, 0), 2);
}

void VideoEditor::track_filtered_object(int & x, int & y, Mat threshold, Mat & cameraFeed)
{
	Mat temp;
	threshold.copyTo(temp);
	//these two vectors needed for output of findContours
	vector< vector<Point> > contours;
	vector<Vec4i> hierarchy;
	//find contours of filtered image using openCV findContours function
	findContours(temp, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	//use moments method to find our filtered object
	double refArea = 0;
	int largestIndex = 0;
	bool objectFound = false;
	if (hierarchy.size() > 0) {
		int numObjects = hierarchy.size();
		//if number of objects greater than MAX_NUM_OBJECTS we have a noisy filter
		if (numObjects < MAX_NUM_OBJECTS) 
		{
			for (int index = 0; index >= 0; index = hierarchy[index][0]) 
			{

				Moments moment = moments((cv::Mat)contours[index]);
				double area = moment.m00;

				//if the area is less than 20 px by 20px then it is probably just noise
				//if the area is the same as the 3/2 of the image size, probably just a bad filter
				//we only want the object with the largest area so we save a reference area each
				//iteration and compare it to the area in the next iteration.
				if (area > MIN_OBJECT_AREA && area<MAX_OBJECT_AREA && area>refArea) 
				{
					x = moment.m10 / area;
					y = moment.m01 / area;
					objectFound = true;
					refArea = area;
					//save index of largest contour to use with drawContours
					largestIndex = index;
				}
				else objectFound = false;
			}
			//let user know you found an object
			if (objectFound == true)
			{
				putText(cameraFeed, "Tracking Object", Point(0, 50), 2, 1, Scalar(0, 255, 0), 2);
				//draw object location on screen

				draw_object(x, y, cameraFeed); //this function draws green circle in the center of the object

				//draw largest contour
				//drawContours(cameraFeed, contours, largestIndex, Scalar(0, 255, 255), 2);
			}

		}
		else putText(cameraFeed, "TOO MUCH NOISE! ADJUST FILTER", Point(0, 50), 1, 2, Scalar(0, 0, 255), 2);
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
