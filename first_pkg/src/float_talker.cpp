#include "ros/ros.h"        //including for the ros library
#include "std_msgs/Float32.h"    // include for the msg type that we used

float count = 0; 

int main(int argc, char **argv)
{
   ros::init(argc, argv, "float_talker");  //initialize ros node , contain the node name talker

  ros::NodeHandle nd;   //manage the communication, n can be changed to nd 

  ros::Publisher chatter_pub = nd.advertise<std_msgs::Float32>("float_chatter", 1000); //create object publisher, topic name chatter, 1000 size of msgs

  ros::Rate loop_rate(10);

  
    //create counter
  while (ros::ok())
  {
   
    std_msgs::Float32 float_msg;    //create new object called msg from std_msg

    float_msg.data = count;
    
    ROS_INFO("%f",float_msg.data);  // fn to show (print) what is inside the node on terminal after converting to str
    
   
    chatter_pub.publish(float_msg);   //chatter_pub that i created to pub my msg that i created

    ros::spinOnce();   //keep working inside a loop

    loop_rate.sleep();  //sleep with the previous rate 10 hz
    ++count;
  }


  return 0;
}