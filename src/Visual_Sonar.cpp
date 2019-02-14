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
#include "opencv2/imgcodecs.hpp"

#include "light_reflection_elimination.h"
#include "Visual_Sonar.h"

#define pi 180
#define pii 3.1415

void visual_sonar(Mat Main_Image,Mat Gradian_Image, int Sonar_Number, int First_Sonar_Degree, int Last_Sonar_Degree, int First_pixel, int &X_Vector_Sum, int &Y_Vector_Sum) {

	namedWindow("Main Image", 1);
	namedWindow("Sonar_Vision", 1);

	double alfa, degree;
	int Image_Matrix[60][500];
	int x_vector_end, y_vector_end, x_vector_start, y_vector_start;
	int x_Length, y_Length;
	int x_rows = Main_Image.rows;
	int y_rows = Main_Image.cols;
	int Center_x = x_rows / 2, Center_y = y_rows / 2, x_vector, y_vector;

	for (int k = First_Sonar_Degree; k < Last_Sonar_Degree; k++) {

		degree = (2 * k*pi) / Sonar_Number;
		alfa = degree*pii / 180;

		for (int Pixel_Counter = First_pixel; Pixel_Counter <= (Center_x); Pixel_Counter++) {
			x_vector = Pixel_Counter*sin(alfa) + (Center_x);
			y_vector = Pixel_Counter*cos(alfa) + (Center_y);

            if (Pixel_Counter == First_pixel) {
				x_vector_start = x_vector;
				y_vector_start = y_vector;
            }else if (Pixel_Counter == Center_x) {
				x_vector_end = x_vector;
				y_vector_end = y_vector;
			}

			uchar* data = Gradian_Image.ptr<uchar>(x_vector, y_vector);
			Image_Matrix[k][Pixel_Counter] = *data;
			if (Image_Matrix[k][Pixel_Counter] + Image_Matrix[k][Pixel_Counter - 1] < 255)
				*data = 255;
			else if (Image_Matrix[k][Pixel_Counter] + Image_Matrix[k][Pixel_Counter - 1]  > 255) {
				int W = light_reflection_elimination(Main_Image, x_vector, y_vector);
				if (W >= 170)
					*data = 255;
				else if (W < 170) {
					Pixel_Counter = Center_x;
					x_vector_end = x_vector;
					y_vector_end = y_vector;

				}
			}
		}
		x_Length = x_vector_end - x_vector_start;
		y_Length = y_vector_end - y_vector_start;

		X_Vector_Sum += x_Length;
		Y_Vector_Sum += y_Length;
	}

	line(Gradian_Image, Point((Center_y), (Center_x)), Point(((Y_Vector_Sum) + Center_y), ((X_Vector_Sum) + Center_x)), 255, 2, 0);
	line(Main_Image, Point((Center_y), (Center_x)), Point(((Y_Vector_Sum) + Center_y), ((X_Vector_Sum) + Center_x)), 255, 1, 0);
	imshow("Main Image", Main_Image);
	imshow("Sonar_Vision", Gradian_Image);
	
}

