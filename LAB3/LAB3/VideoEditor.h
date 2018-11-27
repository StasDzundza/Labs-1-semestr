#pragma once
#include <string>
using std::string;

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
private:

};