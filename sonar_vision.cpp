
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


#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Bool.h>
#include <nav_msgs/Odometry.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>


#include "Sonar_Vision.h"
#include "Navigation.h"
#include "sobel_edg_detection.h"

#define pi 180
#define pii 3.141592

using namespace cv;

ros::Publisher direction_pub;
geometry_msgs::Twist speedMsg;

void imageCallback(const sensor_msgs::ImageConstPtr& msg){

    try{

        Mat src;
        src = cv_bridge::toCvShare(msg, "bgr8")->image;

        Mat grad2;
        sobel(src,&grad2);     // Sobel Edge Detection & Threshold

        int SXX=0,SYY=0;
        sonar_vision(src,grad2,24,10,27,60,&SXX,&SYY);   //Sonar Vision Obstacle Avoidance function

        float Zavieh,Harkat;
        navigation (SXX,SYY,&Harkat,&Zavieh);      // Navigation function ---------------

        speedMsg.linear.x=Harkat;
        speedMsg.angular.z=Zavieh;
        direction_pub.publish(speedMsg);

        SXX = 0, SYY = 0;

        waitKey(30);

    }

  catch (cv_bridge::Exception& e){
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }

}

int main(int argc, char **argv){

    ros::init(argc, argv, "publisher");
    ros::NodeHandle nh;
    startWindowThread();
    image_transport::ImageTransport it(nh);
    direction_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
    image_transport::Subscriber sub = it.subscribe("camera/image", 1, imageCallback);
    ros::spin();
}

