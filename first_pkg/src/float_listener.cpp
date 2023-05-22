#include "ros/ros.h"
#include "std_msgs/Float32.h"

void chatterCallback(const std_msgs::Float32::ConstPtr& float_msg) // call back fn which I recevied the data from the topic in. 
// Named by the the name of the topic that I am subscribe from it.
// we can change the msg to any name not like the publisher
{
  ROS_INFO("I heard: [%f]", float_msg->data);  // using .c_str() to convert the msg to string, 
  // we can use msg.data but he used -> because he used pointer in std_msgs::String::ConstPtr
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "float_listener");

  
  ros::NodeHandle n;

  
  ros::Subscriber sub = n.subscribe("float_chatter", 1000, chatterCallback);  // call back function

  
  ros::spin();

  return 0;
}