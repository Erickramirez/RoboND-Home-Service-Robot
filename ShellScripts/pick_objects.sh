#!/bin/sh
xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/World/room.world" &
sleep 10
xterm  -e  " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/workspace/catkin_ws/src/World/map.yaml" & 
sleep 10
xterm  -e  " roslaunch pick_objects pick_objects_rviz.launch" &
sleep 10
xterm  -e  " rosrun pick_objects pick_objects" 
