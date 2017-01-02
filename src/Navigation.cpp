
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

// Navigation Calculation ...................................................................

#include"Navigation.h"

#define pii 3.14

void navigation (int SXX, int SYY, float *Harkat, float *Zavieh){

    *Harkat = 0;
    *Zavieh = 0;

    float Teta2;
    Teta2 = atan2(SXX,SYY);

    float Teta22=(Teta2*180)/pii;

    SXX=fabs(SXX);
    SYY=fabs(SYY);

    int L2=sqrt((SXX^2)+(SYY^2));

    int SF2 = L2;
    float SA2 = Teta22;

    int SF = SF2;
    float SA = SA2;
    SA=90+SA;

    if( SA <= 2 && SA >= -2){
       *Harkat = 0.2;
       *Zavieh = (SA/10);
    }else if((SA >2 && SA <= 10) || (SA <-2 && SA >= -10)){
       *Harkat = 0.15;
       *Zavieh = (SA/100);
    }else if((SA >10 && SA <= 25) || (SA <-10 && SA >= -25)){
       *Harkat=0.1;
       *Zavieh = (SA/100);
    }else if((SA >25 && SA <= 40) || (SA <-25 && SA >= -40)){
       *Harkat=0.06;
       *Zavieh = (SA/100);
    }else if (SA > 40 || SA < -40){
       *Harkat=0;
       *Zavieh = (SA/100);
    }
    SA2=0 , SF2 = 0;
    SA = 0, SF = 0;
    L2 = 0;
}

