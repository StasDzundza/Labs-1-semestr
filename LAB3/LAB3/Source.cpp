#include <iostream>
#include "VideoEditor.h"
#include "PhotoEditor.h"
int main()
{
	VideoEditor myVideo;
	PhotoEditor myPhoto;
	//myVideo.track_different_colors_in_hsv();
	myPhoto.add_some_effects_on_photo("bob.jpg");
	return 0;
}