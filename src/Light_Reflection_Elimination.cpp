/*	Visual_Sonar: An algorithm which can find a free path via the image.

Copyright (C) 2016 Mohammad Hossein Bamorovat Abadi

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

#include "light_reflection_elimination.h"

using namespace cv;

int light_reflection_elimination(Mat Main_Image, int x_vector_point, int y_vector_point) {

	Mat HSV_Image;
	cvtColor(Main_Image, HSV_Image, CV_BGR2HSV);
	Vec3b hsv = HSV_Image.at<Vec3b>(x_vector_point, y_vector_point);
	//int H=hsv.val[0]; //hue
	int Saturation = hsv.val[1]; //saturation
	int Value = hsv.val[2]; //value
	int Free_Point;
	Free_Point = Value - Saturation;
	return (Free_Point);
}

