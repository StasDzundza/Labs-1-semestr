#pragma once
#include <string>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
using std::string;
class PhotoEditor
{
public:
	PhotoEditor();
	~PhotoEditor();
	void add_some_effects_on_photo(const char*path);
	void add_canny_effect(const char*path);
	void show_image_in_3_colors(const char*path);
	void what_is_color(const char*path);
private:
	int DELAY_CAPTION = 1500;
	int DELAY_BLUR = 100;
	int DELAY_COLOR = 1500;
	int MAX_KERNEL_LENGTH = 31;
	Mat src; 
	Mat dst;
	string path = "ChangedImages/";
	int count_changed_images = 0;
	const char *window_name = "Effects";
	int display_caption(const char* caption);
	int display_dst(int delay);
	void show_color_by_index(int index);
};
