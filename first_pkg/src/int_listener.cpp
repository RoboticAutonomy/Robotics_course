#include "ros/ros.h"
#include "std_msgs/Int32.h"

void chatterCallback(const std_msgs::Int32::ConstPtr& int_msg) // call back fn which I recevied the data from the topic in. 
// Named by the the name of the topic that I am subscribe from it.
// we can change the msg to any name not like the publisher
{
  ROS_INFO("I heard: [%d]", int_msg->data);  // using .c_str() to convert the msg to string, 
  // we can use msg.data but he used -> because he used pointer in std_msgs::String::ConstPtr
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "int_listener");

  
  ros::NodeHandle n;

  
  ros::Subscriber sub = n.subscribe("int_chatter", 1000, chatterCallback);  // call back function

  
  ros::spin();

  return 0;
}