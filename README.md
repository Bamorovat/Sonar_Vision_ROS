# Visual_Sonar_ROS
## Mobile Robot Navigation Based on Visual Sonar Algorithm and Omnidirectional Vision
### Author: [Mohammad Hossein Bamorovat Abadi](https://bamorovat.wordpress.com/).

This code implemented with C++ programing Language under C programing Language Standard and **OpenCV Library**.
This package implemented in **ROS environment**.
Implementation of the **Visual Sonar** algorithm described in:

1. Bamorovat Abadi,M.H, Asghari Oskoei,M. **“Effects of Mirrors in Mobile Robot Navigation Based on Omnidirectional Vision.”** 8th International Conference, ICIRA 2015, Portsmouth, UK, August 24-27, 2015.[[**PDF**]](https://bamorovat.files.wordpress.com/2017/01/intelligentroboticsandapplications.pdf)[[**BibTex**]](https://bamorovat.wordpress.com/bibtex1/)
2. Bamorovat Abadi,M.H., Asghari Oskoei,M. , Fakharian,A. **“Mobile robot navigation using sonar vision algorithm applied to omnidirectional vision.”** AI & Robotics (IRANOPEN), 2015,IEEE, {1-6}, 2015.[[**PDF**]](https://bamorovat.files.wordpress.com/2017/01/the-7th-robocup-iranopen-international-symposium-and-the-5th-joint-conference-of-ai-robotics.pdf)[[**BibTex**]](https://bamorovat.wordpress.com/bibtex2/)
3.  Bamorovat Abadi,M.H., Asghari Oskoei,M. , Fakharian,A. **“Side Sonar Vision Applied to Omni-directional Images to Navigate Mobile Robots.”** 16th conference on Fuzzy Systems and 14th conference on Intelligent Systems, IEEE, 2017.[[**PDF**]](https://bamorovat.files.wordpress.com/2017/08/side-sonar-vision-applied-to-omni-directional-images-to-navigate.pdf)[[**BibTex**]](https://bamorovat.wordpress.com/bibtext3/)

The program takes video and find static and dynamic obstacles, and free path, and send commands to robot node to Navigation. The parameters are (see the paper for details):

**Ns:** Number of Sonars. **KK1:** The number of first Sonar that we want to use. **KK2:** The number of last Sonar that we want to use. **ii:** Start point in each Sonar. Typical parameters are ***Ns=24, KK1=10, KK2=27, ii=60***.


##### If you use ***Visual_Sonar_ROS*** in an academic work, **please cite it via above bibtex links**.
Describing more about our project is in: https://www.bamorovat.wordpress.com

You can see a short movie of our robot Movement in: https://youtu.be/JKRwDcHyVbo

# ROS
We use ROS to receive images from the camera or from a recorded sequence (rosbag). We have tested **Visual_Sonar in Ubuntu 12.04 with ROS Fuerte, Ubuntu 16.04 with ROS Kinetic and Ubuntu 18.04 with ROS Melodic**. If you do not have already installed ROS in your computer, we recommend you to install the Full-Desktop version of ROS Kinetic (http://wiki.ros.org/kinetic/Installation/Ubuntu).

# OpenCV
We use OpenCV to manipulate images and features. If you use a ROS version Kinetic, OpenCV 3 is already included in the ROS distribution.

# Installation
Download and copy the visual_sonar_ros file at to catkin workspace/src (**Note: Remove "-master" from the end of the file name**):

    cd catkin_ws/src

go to visual_sonar_ros pakage and run codes below at ubuntu terminal:

    cd catkin_ws/src/visual_sonar_ros
    mkdir build
    cd build
    cmake ..
    make
 
# Usage
Befor run the package, we should Knowing the new package :

    . ~/catkin_ws/devel/setup.bash
    
Run the package:

    rosrun visual_sonar_ros visual_sonar_ros

# Note
A camera data should be run in to ROS and after that this Node should be run.
