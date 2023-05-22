#include "ros/ros.h"        //including for the ros library
#include "std_msgs/Int32.h"    // include for the msg type that we used
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
   ros::init(argc, argv, "int_talker");  //initialize ros node , contain the node name talker

  ros::NodeHandle n;   //manage the communication, n can be changed to nd 

  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("int_chatter", 1000); //create object publisher, topic name chatter, 1000 size of msgs

  // while (chatter_pub.getNumSubscribers() < 1) {
  //   // wait for a connection to publisher
  //   // you can do whatever you like here or simply do nothing
  // }

  ros::Rate loop_rate(10);

  
  int count =0;   //create counter
  

  while (ros::ok())
  {
         
    
    std_msgs::Int32 int_msg;    //create new object called msg from std_msg

    int_msg.data = count;
    
    ROS_INFO("%i",int_msg.data);  // fn to show (print) what is inside the node on terminal after converting to str
    
    
   
    chatter_pub.publish(int_msg);   //chatter_pub that i created to pub my msg that i created

    ros::spinOnce();   //keep working inside a loop

    loop_rate.sleep();  //sleep with the previous rate 10 hz
    ++count;
  }


  return 0;
}