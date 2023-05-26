/*Here I made the node by two ways the first portion or the upper part
used to published contiously without stop and the lower part which is commented
uesd to just published one message (rosrun first_pkg age_pub_node) and will not publish 
this message untill the subscriber working (rosrun first_pkg age_sub_node), then
(rostopic echo /age_calculation) to get the results 

First node which publish contiously
*/




#include "ros/ros.h"        
#include "first_pkg/Age.h"    

ros::Publisher age_pub;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "age_pub_node");  //initialize ros node , contain the node name talker

  ros::NodeHandle n;   //manage the communication, n can be changed to nd 

  age_pub = n.advertise<first_pkg::Age>("age_publisher", 1000); //create object publisher, topic name chatter, 1000 size of msgs

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
         
    
    first_pkg::Age age_msg;    

    age_msg.years = 1992;
    age_msg.months = 1;
    age_msg.days = 1;
    
    ROS_INFO("Years = : [%f]",age_msg.years);  
    ROS_INFO("Months = [%f]",age_msg.months);
    ROS_INFO("Days = [%f]",age_msg.days);
   
    age_pub.publish(age_msg);   

    ros::spinOnce();   

    loop_rate.sleep();  
   
  }


  return 0;
}





// Second version which publish only one message
// // This is the publisher node for the age_publisher topic but send the age one time
// // here we can just publish one msg and it will not be published untill we run the subscriber or the echo command
// // so we need to run the subscriber first then the publisher




// #include "ros/ros.h"        
// #include "first_pkg/Age.h"    

// ros::Publisher age_pub;

// int main(int argc, char **argv)
// {
//   ros::init(argc, argv, "age_pub_node");  //initialize ros node , contain the node name talker

//   ros::NodeHandle n;   //manage the communication, n can be changed to nd 

//   age_pub = n.advertise<first_pkg::Age>("age_publisher", 1000); //create object publisher, topic name chatter, 1000 size of msgs

//   while (age_pub.getNumSubscribers() < 1) {
//     // wait for a connection to publisher
//     // you can do whatever you like here or simply do nothing
//   }


//   first_pkg::Age age_msg;
//   age_msg.years = 1992;
//   age_msg.months = 1;
//   age_msg.days = 1;  
//   ROS_INFO("Years = : [%f]",age_msg.years);  
//   ROS_INFO("Months = [%f]",age_msg.months);
//   ROS_INFO("Days = [%f]",age_msg.days);
//   age_pub.publish(age_msg); 
//   ros::spinOnce();   
//   ros::Duration(1.0).sleep(); 
//   return 0;

// }