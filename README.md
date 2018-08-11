# RoboND-Home-Service-Robot
This is the final project of Udacity Robotics Nanodegree. This is an implementation of a small home service robot  simulated in Gazebo environment.
# Summary of Tasks
1. Design a simple environment with the Building Editor in Gazebo.
2. Teleoperate your robot and manually test SLAM.
3. Create a wall_follower node that autonomously drives your robot to map your environment.
4. Use the ROS navigation stack and manually commands your robot using the 2D Nav Goal arrow in rviz to move to 2 different desired positions and orientations.
5. Write a pick_objects node that commands your robot to move to the desired pickup and drop off zones.
6. Write an add_markers node that subscribes to your robot odometry, keeps track of your robot pose, and publishes markers to rviz.

# How to run it
* wrking enviroment used: /home/workspace/catkin_ws
* if the catkin_location is different, please update the ShellScripts

Go to workspace directory
``` bash
$ cd ~/catkin_ws
```
Clone this repository.
``` bash
git clone https://github.com/Erickramirez/RoboND-Home-Service-Robot.git
```
Compile it:
``` bash
catkin_make
source devel/setup.bash
```
Testing SLAM
``` bash
$ ./RoboND-Home-Service-Robot/src/ShellScripts/test_slam.sh
```
Testing Navigation
``` bash
$ ./ShellScripts/RoboND-Home-Service-Robot/test_navigation.sh
```
Testing Pick_objects
``` bash
$ ./src/RoboND-Home-Service-Robot/ShellScripts/pick_objects.sh
```
Testing Add Markers
``` bash
$ ./src/RoboND-Home-Service-Robot/ShellScripts/add_marker.sh
```
Home Service
``` bash
$ ./src/RoboND-Home-Service-Robot/ShellScripts/home_service.sh
```

Note:
the initial location of the robot has been changed:
in order to recreate it, feel free to replace the file: 
```
/home/workspace/catkin_ws/src/RoboND-Home-Service-Robot/launch/kobuki.launch.xml
```
to the location:
```
/home/workspace/catkin_ws/src/utilities/turtlebot_simulator-indigo/turtlebot_gazebo/launch/includes/kobuki.launch.xml
```
