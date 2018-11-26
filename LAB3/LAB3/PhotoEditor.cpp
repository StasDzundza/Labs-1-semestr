#include "PhotoEditor.h"
#include <iostream>
#include <exception>

using std::cout;
using std::cin;
using std::endl;

PhotoEditor::PhotoEditor()
{
}

PhotoEditor::~PhotoEditor()
{
}

void PhotoEditor::add_some_effects_on_photo(const char * path)
{
	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	src = imread(path, IMREAD_COLOR);
	if (src.empty())
	{
		cout << " Error opening image" << endl;
		throw std::exception("Error opening image");
	}
	if (display_caption("Original Image") != 0)
	{
		return ;
	}
	dst = src.clone();//Creates a full copy of the src and the underlying data
	if (display_dst(DELAY_CAPTION) != 0)
	{
		return ;
	}
	if (display_caption("Homogeneous Blur") != 0)
	{
		return ;
	}
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		blur(src, dst, Size(i, i), Point(-1, -1));
		if (display_dst(DELAY_BLUR) != 0)
		{
			return ;
		}
	}
	if (display_caption("Gaussian Blur") != 0)
	{
		return ;
	}
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		GaussianBlur(src, dst, Size(i, i), 0, 0);
		if (display_dst(DELAY_BLUR) != 0)
		{
			return ;
		}
	}
	if (display_caption("Median Blur") != 0)
	{
		return ;
	}
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		medianBlur(src, dst, i);
		if (display_dst(DELAY_BLUR) != 0)
		{
			return ;
		}
	}
	if (display_caption("Bilateral Blur") != 0)
	{
		return ;
	}
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		bilateralFilter(src, dst, i, i * 2, i / 2);
		if (display_dst(DELAY_BLUR) != 0)
		{
			return ;
		}
	}
	display_caption("Done!");
}

void PhotoEditor::add_canny_effect(const char * path)
{
	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	src = imread(path, IMREAD_COLOR);
	if (src.empty())
	{
		cout << " Error opening image" << endl;
		throw std::exception("Error opening image");
	}
	if (display_caption("Original Image") != 0)
	{
		return;
	}
	dst = src.clone();//Creates a full copy of the src and the underlying data
	if (display_dst(DELAY_CAPTION) != 0)
	{
		return;
	}
	if (display_caption("Canny") != 0)
	{
		return;
	}
	Canny(src, dst, 10, 100, 3, true);
	imwrite(path + std::to_string(++count_changed_images) + ".jpg", dst);
	imshow(window_name, dst);
	waitKey(0);//wait when user press any key
	
}

void PhotoEditor::show_image_in_3_colors(const char * path)
{
	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	src = imread(path, IMREAD_COLOR);
	if (src.empty())
	{
		cout << " Error opening image" << endl;
		throw std::exception("Error opening image");
	}
	if (display_caption("Original Image") != 0)
	{
		return;
	}
	dst = src.clone();//Creates a full copy of the src and the underlying data
	if (display_dst(DELAY_CAPTION) != 0)
	{
		return;
	}
	if (display_caption("Red Shade") != 0)
	{
		return;
	}
	show_color_by_index(1);//red
	dst = src.clone();//Creates a full copy of the src and the underlying data
	if (display_caption("Green Shade") != 0)
	{
		return;
	}
	show_color_by_index(0);//
	dst = src.clone();//Creates a full copy of the src and the underlying data
	if (display_caption("Blue Shade") != 0)
	{
		return;
	}
	show_color_by_index(2);//blue
	dst = src.clone();//Creates a full copy of the src and the underlying data

}
//This method shows text before changed image
int PhotoEditor::display_caption(const char * caption)
{
	dst = Mat::zeros(src.size(), src.type());
	putText(dst, caption,Point(src.cols / 4, src.rows / 2),FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));//Write text
	return display_dst(DELAY_CAPTION);//Display
}
//This method displays text
int PhotoEditor::display_dst(int delay)
{
	imshow(window_name, dst);
	int c = waitKey(delay);
	if (c >= 0) { return -1; }//if anyone key has been pressed,program execution breaks;
	imwrite(path + std::to_string(++count_changed_images) + ".jpg", dst);
	return 0;
}

void PhotoEditor::show_color_by_index(int index)
{
	Mat splitChannels[3];
	split(src, splitChannels);
	splitChannels[index] = Mat::zeros(splitChannels[index].size(), CV_8UC1);
	merge(splitChannels, 3, dst);
	display_dst(DELAY_COLOR);
}
