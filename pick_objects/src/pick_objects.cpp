#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <iostream>
#include <chrono>
#include <thread>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = -5.0;
  goal.target_pose.pose.position.y = -4.0;
  goal.target_pose.pose.orientation.w = 2.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal - (-5.0,-4.0,2.0)");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  	ROS_INFO("Hooray, the base moved to (-5.0,-4.0,2.0)");
  else
  	ROS_INFO("The base failed to move forward 1 meter for some reason  - (-5.0,-4.0,2.0)");
  ROS_INFO("Waiting ...");
  std::chrono::seconds duration(5);
  std::this_thread::sleep_for(duration);
  ROS_INFO("Waited for 5 seconds.");
  
  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 2.0;
  goal.target_pose.pose.position.y = -8.0;
  goal.target_pose.pose.orientation.w = 1.0;
  
  // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending  goal - (2.0,-8.0,1.0)");
  ac.sendGoal(goal);
  
  // Wait an infinite time for the results
  ac.waitForResult();
  
  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  	ROS_INFO("Hooray, the base moved to (2.0,-8.0,1.0)");
  else
  	ROS_INFO("he base failed to move forward 1 meter for some reason  - (2.0,-8.0,1.0)");
  


  return 0;
}
