
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

void visual_sonar(Mat Main_Image,Mat Gradian_Image, int Sonar_Number, int First_Sonar_Degree, int Last_Sonar_Degree, int First_pixel, int &X_Vector_Sum, int &Y_Vector_Sum);




