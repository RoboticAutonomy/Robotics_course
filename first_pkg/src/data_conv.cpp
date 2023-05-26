#include "ros/ros.h"        //including for the ros library
#include "std_msgs/Int32.h"    // include for the msg type that we used
#include "std_msgs/Float32.h"    // include for the msg type that we used


int input_num;
float output_num;

ros::Subscriber int_sub;
ros::Publisher float_pub;

std_msgs::Float32 float_msg;

void int_Callback(const std_msgs::Int32::ConstPtr& int_msg)
{
  input_num = int_msg->data;
//   ROS_INFO("I heard: [%d]", input_num);
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "data_conv");  //initialize ros node , contain the node name talker

  
  ros::NodeHandle n;

  
  int_sub = n.subscribe("int_chatter", 1000, int_Callback);  // call back function
  float_pub = n.advertise<std_msgs::Float32>("float_chatter", 1000);

  ros::Rate loop_rate(10);

  
  while (ros::ok())
  {
   
    output_num = input_num/2.0;
    // output_num = float(input_num)/2;

    float_msg.data = output_num;
    
    ROS_INFO("%f",float_msg.data);  // fn to show (print) what is inside the node on terminal after converting to str
    
   
    float_pub.publish(float_msg);   //chatter_pub that i created to pub my msg that i created

    ros::spinOnce();   //keep working inside a loop

    loop_rate.sleep();  //sleep with the previous rate 10 hz
  }

  return 0;
}

