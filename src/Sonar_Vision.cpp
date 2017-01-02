
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

// Sonar Vision Algorithm -----------------------------------------------------------------
#include"Sonar_Vision.h"
#include"light_reflection_elimination.h"


#define pi 180
#define pii 3.14

void sonar_vision (Mat src,Mat grad2,int Ns,int kk1, int kk2, int ii,int *SXX, int *SYY){

    namedWindow("Main Image", 1);
    namedWindow("Obstacle Avoidande", 1);


    float alfa,degree;
    int Vj[60][500];
    int xx2,yy2,xx1,yy1;
    int sxx, syy;
    int x = src.rows;
    int y = src.cols;
    int Cx = x / 2, Cy = y / 2, Ax, Ay;

    for (int k=kk1; k < kk2; k++){

        degree = (2 * k*pi) / Ns;
        alfa = degree*pii / 180;

        for (int i=ii; i <= (Cx); i++){
            Ax = i*sin(alfa) + (Cx);
            Ay = i*cos(alfa) + (Cy);
            if (i == 60){
                xx1 = Ax;
                yy1 = Ay;
            }
            if (i == Cx){
                xx2 = Ax;
                yy2 = Ay;
            }
            uchar* data = grad2.ptr<uchar>(Ax, Ay);
            Vj[k][i]=*data;
            if (Vj[k][i] + Vj[k][i-1] < 255)
                *data = 255;
            else if (Vj[k][i] + Vj[k][i-1]  > 255){
                int W =light_reflection_elimination (src,Ax,Ay);
                if (W >= 170)
                    *data = 255;
                else if(W < 170){
                    i = Cx ;
                    xx2 = Ax;
                    yy2 = Ay;

                    }
              }
        }
         sxx=xx2-xx1;
         syy=yy2-yy1;

         *SXX += sxx;
         *SYY += syy;
    }

    line(grad2, Point((Cy), (Cx)), Point(((*SYY)+Cy), ((*SXX)+Cx)), 255, 2, 0);
    line(src, Point((Cy), (Cx)), Point(((*SYY)+Cy), ((*SXX)+Cx)), 255, 1, 0);
    imshow("Main Image",src);
    imshow("Obstacle Avoidande",grad2);
}
