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

#include <math.h>
#include "Navigation.h"

#define pi 180
#define pii 3.1415

    /// ..................................Navigation Part ...................................///

void navigation (int X_Vector_Sum, int Y_Vector_Sum, float &Angular_Velocity , float &Linear_Velocity ){

    int Length_Vector = 0, X_Absolute = 0, Y_Absolute = 0;
    float Degree=0, Beta=0, Teta=0;

    Teta = atan2(X_Vector_Sum,Y_Vector_Sum);
    Beta = (Teta*pi)/pii;
    X_Absolute = fabs(X_Vector_Sum);
    Y_Absolute = fabs(Y_Vector_Sum);
    Length_Vector = sqrt((X_Absolute^2)+(Y_Absolute^2));

    Degree = 90+Beta;



//    Linear_Velocity = Length_Vector/25;
//    Angular_Velocity = Degree/50;



    if( Degree <= 2 && Degree >= -2){
        Linear_Velocity = 0.2;
        Angular_Velocity = (Degree/10);
                }
    else if((Degree >2 && Degree <= 10) || (Degree <-2 && Degree >= -10)){
        Linear_Velocity = 0.15;
        Angular_Velocity = (Degree/50);
    }
    else if((Degree >10 && Degree <= 25) || (Degree <-10 && Degree >= -25)){
        Linear_Velocity=0.1;
        Angular_Velocity = (Degree/50);
    }
    else if((Degree >25 && Degree <= 40) || (Degree <-25 && Degree >= -40)){
        Linear_Velocity=0.06;
        Angular_Velocity = (Degree/50);
    }
    else if (Degree > 40 || Degree < -40){
        Linear_Velocity=0;
        Angular_Velocity = (Degree/50);
    }


    Length_Vector = 0, X_Absolute = 0, Y_Absolute = 0;

}
