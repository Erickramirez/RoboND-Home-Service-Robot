#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <visualization_msgs/Marker.h>

ros::Publisher marker_pub;
visualization_msgs::Marker marker;


const double pick_up_pose[3] = {-5.0,-4.0,0.0};

const double drop_off_pose[3] = {2.0,-8.0,0.0};

void publish_marker()
{
  while (marker_pub.getNumSubscribers() < 1)
  {
    if (!ros::ok())
    {
      return;
    }
	
    ROS_WARN_ONCE("Please create a subscriber to the marker.");
	
    sleep(1);
  }
  ROS_INFO_STREAM("Publishing marker at position x=" << marker.pose.position.x << ", y=" << marker.pose.position.y);
  marker_pub.publish(marker);
}

void odom_callback(const nav_msgs::Odometry::ConstPtr &msg)
{

  float robot_pose_x = msg->pose.pose.position.x;
  float robot_pose_y = msg->pose.pose.position.y;


    float pickup_distance = sqrt(pow((pick_up_pose[0] - robot_pose_x), 2) + pow((pick_up_pose[1] - robot_pose_y), 2));
    float drop_off_distance = sqrt(pow((drop_off_pose[0] - robot_pose_x), 2) + pow((drop_off_pose[1] - robot_pose_y), 2));
    ROS_INFO("Distance to pick up zone = %f", pickup_distance);
    if(pickup_distance <= 0.5)
	{
	    ROS_INFO("Waiting 5 seconds ...");
   	 	sleep(5);

    ROS_INFO("Publish hiding marker.");
    marker.action = visualization_msgs::Marker::DELETE;
    publish_marker();

  } 
  else
  
 	if (drop_off_distance <= 0.5)
	{
	marker.pose.position.x = drop_off_pose[0];
    marker.pose.position.y = drop_off_pose[1];
    marker.pose.position.z = drop_off_pose[2];
	
    marker.action = visualization_msgs::Marker::ADD;
    publish_marker();

  }
  }
int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;


  marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  ros::Subscriber subscriber_odom = n.subscribe("odom", 1000, &odom_callback);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;


    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "basic_shapes";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;
	

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = pick_up_pose[0];
    marker.pose.position.y = pick_up_pose[1];
    marker.pose.position.z = pick_up_pose[2];
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.45;
    marker.scale.y = 0.45;
    marker.scale.z = 0.45;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;
    marker.color.b = 1.0f;
    marker.color.a = 1.0;
	


    marker.lifetime = ros::Duration();
	marker.action = visualization_msgs::Marker::ADD;

    // Publish the marker
	publish_marker();
	// Listen to odom messages
	ROS_INFO_STREAM("Start listening for odom messages.");
	ros::Duration pause_duration(0.1);
	while (ros::ok())
	{
		ros::spinOnce();
    	pause_duration.sleep();
  	}
  // ros::spin();
}
