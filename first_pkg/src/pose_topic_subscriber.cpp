#include "ros/ros.h"
// #include "std_msgs/Float32.h"
#include "turtlesim/Pose.h"

ros::Subscriber pose_topic_sub;

void pose_sub_Callback(const turtlesim::Pose::ConstPtr& pose_msg) // call back fn which I recevied the data from the topic in. 
// Named by the the name of the topic that I am subscribe from it.
// we can change the msg to any name not like the publisher
{
  ROS_INFO("x = [%f]", pose_msg->x);  // using .c_str() to convert the msg to string, 
  // we can use msg.data but he used -> because he used pointer in std_msgs::String::ConstPtr
  ROS_INFO("y = [%f]", pose_msg->y);
  ROS_INFO("Theta = [%f]", pose_msg->theta);
  ROS_INFO("Linear_velocity = [%f]", pose_msg->linear_velocity);
  ROS_INFO("Angular_velocity = [%f]", pose_msg->angular_velocity);
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "pose_topic_subscriber");

  
  ros::NodeHandle n;

  
  pose_topic_sub = n.subscribe("turtle1/pose", 1000, pose_sub_Callback);  // call back function

  
  ros::spin();

  return 0;
}