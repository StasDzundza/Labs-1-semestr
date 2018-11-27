
#include <iostream>
#include "VideoEditor.h"
#include "PhotoEditor.h"
int main()
{
	VideoEditor myVideo;
	PhotoEditor myPhoto;
	
	myVideo.track_objects_by_web_cam();
	return 0;
}