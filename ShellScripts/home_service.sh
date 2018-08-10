#!/bin/sh
xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/World/room.world" &
sleep 10
xterm  -e  " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/workspace/catkin_ws/src/World/map.yaml" & 
sleep 10
xterm  -e  " roslaunch add_markers add_markers_rviz.launch" &
sleep 10
xterm  -e  " rosrun add_markers add_markers"  &
sleep 10
xterm  -e  " rosrun pick_objects pick_objects" 
