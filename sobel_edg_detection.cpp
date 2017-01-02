
/*	Sonar_Vision: An algorithm which can find a free path via the image.

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

#include"sobel_edg_detection.h"

void sobel(Mat src, Mat *grad2){

    Mat src_gray,grad;
    int scale = 1;
    int delta = 0.5;
    int ddepth = CV_16S;

    GaussianBlur(src, src, Size(5,5), 0, 0, BORDER_DEFAULT);/// Convert it to gray
    cvtColor(src, src_gray, CV_RGB2GRAY);/// Create window
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;/// Gradient X
    Sobel(src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
    convertScaleAbs(grad_x, abs_grad_x);/// Gradient Y
    Sobel(src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
    convertScaleAbs(grad_y, abs_grad_y);/// Total Gradient (approximate)
    addWeighted(abs_grad_x, 0.70, abs_grad_y, 0.70, 1, grad);

    threshold(grad, *grad2, 45, 255, 0);  //Threshold of Gradiant Edg Detector
   // return (grad2);

}
