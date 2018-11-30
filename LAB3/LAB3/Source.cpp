
#include <iostream>
#include <conio.h>
#include "VideoEditor.h"
#include "PhotoEditor.h"
using std::cout;
using std::endl;
int menu();
int main()
{
	VideoEditor myVideo;
	PhotoEditor myPhoto;
	while (true) {
		int answer = menu();
		switch (answer)
		{
		case 1: myVideo.track_objects_by_web_cam(); break;
		case 2: myVideo.record_video();  break;
		case 3: myVideo.track_different_colors_and_show_trajectory(color::red); break;
		case 4: myVideo.camera_with_different_effects(); break;
		case 5: myVideo.track_red_color_objects();  break;
		case 6: myPhoto.add_some_effects_on_photo(); break;
		case 7: myPhoto.add_canny_effect(); break;
		case 8: myPhoto.show_image_in_3_colors();  break;
		case 0:	return 0;
		}
		system("pause");
	}
	return 0;
}
int menu() {

	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 9) % 9;
		cout << "   Video OpenCV" << endl;
		if (key == 0) cout << "-> Exit." << endl;
		else  cout << "   Exit." << endl;
		if (key == 1) cout << "-> Track objects by webcam." << endl;
		else  cout << "   Track objects by webcam." << endl;
		if (key == 2) cout << "-> Record video." << endl;
		else  cout << "   Record video." << endl;
		if (key == 3) cout << "-> Track colors and show object trajectory." << endl;
		else  cout << "   Track colors and show object trajectory." << endl;
		if (key == 4) cout << "-> Show different effects on webcam." << endl;
		else  cout << "   Show different effects on webcam." << endl;
		if (key == 5) cout << "-> Track red color objects." << endl;
		else  cout << "   Track red color objects." << endl;
		cout << endl << "   Photo OpenCV" << endl << endl;
		if (key == 6) cout << "-> Add some effects on photo." << endl;
		else  cout << "   Add some effects on photo." << endl;
		if (key == 7) cout << "-> Add canny effect." << endl;
		else  cout << "   Add canny effect." << endl;
		if (key == 8) cout << "-> Show image in 3 colors." << endl;
		else  cout << "   Show image in 3 colors." << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}