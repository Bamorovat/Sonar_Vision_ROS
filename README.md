# Sonar_Vision_ROS
## Mobile Robot Navigation Based on Sonar Vision Algorithm and Omnidirectional Vision
### Author: [Mohammad Hossein Bamorovat Abadi](https://bamorovat.wordpress.com/).

This code implemented with C++ programing Language under C programing Language Standard and **OpenCV Library**.
This package implemented in **ROS environment**.
Implementation of the **Sonar-Vision** algorithm described in:

1. Bamorovat Abadi,M.H, Asghari Oskoei,M. **“Effects of Mirrors in Mobile Robot Navigation Based on Omnidirectional Vision.”** 8th International Conference, ICIRA 2015, Portsmouth, UK, August 24-27, 2015.[[**PDF**]](https://bamorovatwo.files.wordpress.com/2016/12/intelligentroboticsandapplications.pdf)[[**BibTex**]](https://bamorovatwo.wordpress.com/bibtex1)
2. Bamorovat Abadi,M.H., Asghari Oskoei,M. , Fakharian,A. **“Mobile robot navigation using sonar vision algorithm applied to omnidirectional vision.”** AI & Robotics (IRANOPEN), 2015,IEEE, {1-6}, 2015.[[**PDF**]](https://bamorovatwo.files.wordpress.com/2016/12/the-7th-robocup-iranopen-international-symposium-and-the-5th-joint-conference-of-ai-robotics.pdf)[[**BibTex**]](https://bamorovatwo.wordpress.com/bibtex2)

##### If you use ***Sonar_Vision_ROS*** in an academic work, **please cite it via above bibtex links**.
Describing more about our project is in: https://www.bamorovat.wordpress.com

The program takes video and find static and dynamic obstacles, and free path, and send commands to robot node to Navigation. The parameters are (see the paper for details):

**Ns:** Number of Sonars. **KK1:** The number of first Sonar that we want to use. **KK2:** The number of last Sonar that we want to use. **ii:** Start point in each Sonar. Typical parameters are ***Ns=24, KK1=10, KK2=27, ii=60***.

# ROS
We use ROS to receive images from the camera or from a recorded sequence (rosbag). We have tested **Sonar_Vision in Ubuntu 12.04 with ROS Fuerte and Ubuntu 16.04 with ROS Kinetic**. If you do not have already installed ROS in your computer, we recommend you to install the Full-Desktop version of ROS Kinetic (http://wiki.ros.org/kinetic/Installation/Ubuntu).

# OpenCV
We use OpenCV to manipulate images and features. If you use a ROS version Kinetic, OpenCV 3 is already included in the ROS distribution.

# Installation
go to catkin workspace/src:

    cd catkin_ws/src
    
Creating sonar_vision Package:

    catkin_create_pkg sonar_vision roscpp std_msgs geometry_msgs sensor_msgs nav_msgs angles tf image_transport cv_bridge
    cd ..
    catkin_make

go to sonar_vision pakage and replace src,include,CMakeLists.txt,package.xml.

    cd catkin_ws/src/sonar_vision
    mkdir build
    cd build
    cmake ..
    make
 
# Usage
Befor run the package, we should Knowing the new package :

    . ~/catkin_ws/devel/setup.bash
    
Run the package (we assume that you call the camera via camera node before):

    rosrun sonar_vision sonar_vision
