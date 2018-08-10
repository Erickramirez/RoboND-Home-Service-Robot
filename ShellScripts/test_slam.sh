#!/bin/sh
xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/RoboND-Home-Service-Robot/World/room.world" &
sleep 10
xterm  -e  " roslaunch turtlebot_gazebo gmapping_demo.launch custom_gmapping_launch_file:=/home/nvidia/catkin_ws/src/RoboND-Home-Service-Robot/launch/gmapping.launch.xml" & 
sleep 10
xterm  -e  " roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 10
xterm  -e  " roslaunch turtlebot_teleop keyboard_teleop.launch"
