
#include <iostream>
#include "VideoEditor.h"
#include "PhotoEditor.h"
int main()
{
	VideoEditor myVideo;
	PhotoEditor myPhoto;
	//myPhoto.what_is_color("green_ball.jpg");
	myVideo.track_objects_by_web_cam();
	return 0;
}