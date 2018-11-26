#include <iostream>
#include "VideoEditor.h"
#include "PhotoEditor.h"
int main()
{
	VideoEditor myVideo;
	PhotoEditor myPhoto;
	//myVideo.track_different_colors_in_hsv();
	myPhoto.show_image_in_3_colors("bob.jpg");
	return 0;
}