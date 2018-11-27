#pragma once
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using std::string;
using std::vector;
using namespace cv;
class VideoEditor
{
public:
	VideoEditor();
	~VideoEditor();
	void track_different_colors_in_hsv();
	void track_different_colors_and_show_trajectory();
	void track_red_color_objects();
	void camera_with_different_effects();
	void record_video(string save_path = "");
	void track_objects_by_web_cam();

	
private:
	//initial min and max HSV filter values.
//these will be changed using trackbars
	int H_MIN = 0;
	int H_MAX = 256;
	int S_MIN = 0;
	int S_MAX = 256;
	int V_MIN = 0;
	int V_MAX = 256;
	//default capture width and height
	const int FRAME_WIDTH = 640;
	const int FRAME_HEIGHT = 480;
	//max number of objects to be detected in frame
	const int MAX_NUM_OBJECTS = 50;
	//minimum and maximum object area
	const int MIN_OBJECT_AREA = 20 * 20;
	const int MAX_OBJECT_AREA = FRAME_HEIGHT * FRAME_WIDTH / 1.5;
	//names that will appear at the top of each window
	const string windowName = "Original Image";
	const string windowName1 = "HSV Image";
	const string windowName2 = "Thresholded Image";
	const string windowName3 = "After Morphological Operations";
	const string trackbarWindowName = "Trackbars";

	bool calibrationMode;//used for showing debugging windows, trackbars etc.

	bool mouseIsDragging;//used for showing a rectangle on screen as user clicks and drags mouse
	bool mouseMove;
	bool rectangleSelected;
	Point initialClickPoint, currentMousePoint; //keep track of initial point clicked and current position of mouse
	Rect rectangleROI; //this is the ROI that the user has selected
	vector<int> H_ROI, S_ROI, V_ROI;// HSV values from the click/drag ROI region stored in separate vectors so that we can sort them easily
	

	//functions for void track_objects_by_web_cam();
	void recordHSV_values(Mat frame, Mat hsv_frame);
	void morph_ops(Mat &thresh);
};

//functions for void track_objects_by_web_cam();
void clickAndDrag_Rectangle(int event, int x, int y, int flags, void * param);