#include <iostream>
#include "VideoEditor.h"
#include "PhotoEditor.h"
int main()
{
	VideoEditor myVideo;
	PhotoEditor myPhoto;
	//myVideo.track_different_colors_in_hsv();
	myVideo.record_video();
	return 0;
}