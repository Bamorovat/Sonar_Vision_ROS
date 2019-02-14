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

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <iostream>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Bool.h>
#include <nav_msgs/Odometry.h>
#include <rosbag/bag.h>
#include <tf/transform_broadcaster.h>
#include <tf/tf.h>

#include <opencv/cv.h>
#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui.hpp>

#include "Visual_Sonar.h"
#include "sobel_edg_detection.h"
#include "Navigation.h"

using namespace cv;
using namespace std;

ros::Publisher direction_pub;
geometry_msgs::Twist speedMsg;

float Angular_Velocity,Linear_Velocity;
int X_Vector_Sum = 0, Y_Vector_Sum = 0;

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
  try
  {
        Mat Main_Image, Gradian_Image;
        Main_Image = cv_bridge::toCvShare(msg, "bgr8")->image;

        sobel(Main_Image, Gradian_Image, 27);     // Sobel Edge Detection & Threshold
        visual_sonar(Main_Image, Gradian_Image, 24, 10, 27, 65, X_Vector_Sum, Y_Vector_Sum);   //Sonar Vision Obstacle Avoidance function

        // Navigation Part .......................................................
        navigation(X_Vector_Sum,Y_Vector_Sum,Angular_Velocity ,Linear_Velocity);    // Translate Sonar Vector To Navigate Commands

        // Navigation Send Message ...............................................
        speedMsg.linear.x=Linear_Velocity;
        speedMsg.angular.z=Angular_Velocity;
        direction_pub.publish(speedMsg);

        X_Vector_Sum = 0, Y_Vector_Sum = 0;  //, Angular_Velocity = 0, Linear_Velocity = 0;
        waitKey(30);
    }

    catch (cv_bridge::Exception& e)
    {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
    }
}


int main(int argc, char **argv)
{

    ros::init(argc, argv, "publisher");
    ros::NodeHandle nh;
    startWindowThread();
    image_transport::ImageTransport it(nh);
    direction_pub = nh.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity",1);
    image_transport::Subscriber sub = it.subscribe("camera/image", 1, imageCallback);
    ros::spin();

}

