#include "ros/ros.h"        //including for the ros library
#include "geometry_msgs/Twist.h"    // include for the msg type that we used


int main(int argc, char **argv)
{
   ros::init(argc, argv, "turtle_forward");  //initialize ros node , contain the node name talker

  ros::NodeHandle n;   //manage the communication, n can be changed to nd 

  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000); //create object publisher, topic name chatter, 1000 size of msgs

//   while (chatter_pub.getNumSubscribers() < 1) {
//     // wait for a connection to publisher
//     // you can do whatever you like here or simply do nothing
//   }

  ros::Rate loop_rate(10);

  
  
 
  while (ros::ok())
  {
    
    geometry_msgs::Twist msg;    //create new object called msg from std_msg

    msg.linear.x = 0.5;
    // ROS_INFO("%i",msg.linear.x);  // fn to show (print) what is inside the node on terminal after converting to str
  
    chatter_pub.publish(msg);   //chatter_pub that i created to pub my msg that i created

    ros::spinOnce();   //keep working inside a loop
      
    loop_rate.sleep();  //sleep with the previous rate 10 hz

    
  }

  return 0;
}