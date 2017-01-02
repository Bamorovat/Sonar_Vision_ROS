
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

// Light Reflection Check On Floor ---------------------------------------------------------

#include "light_reflection_elimination.h"

int light_reflection_elimination (Mat src, int Ax, int Ay){

    Mat HSV;
    cvtColor(src,HSV, CV_BGR2HSV);
    Vec3b hsv=HSV.at<Vec3b>(Ax,Ay);
    //int H=hsv.val[0]; //hue
    int S=hsv.val[1]; //saturation
    int V=hsv.val[2]; //value
    int w;
    w = V-S;
    return (w);
}
