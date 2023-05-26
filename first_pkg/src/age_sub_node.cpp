/*Here I made the node by two ways the first portion or the upper part
used to subscribe contiously without stop and the lower part which is commented
uesd to just subscribe one message (rosrun first_pkg age_pub_node) and will not publish 
this message untill the subscriber working (rosrun first_pkg age_sub_node), then
(rostopic echo /age_calculation) to get the results 

First node which subscribe contiously
*/


#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "first_pkg/Age.h"   

int input_year;
int input_month;
int input_day;

ros::Subscriber age_sub_node;
ros::Publisher age_calculation;

first_pkg::Age age_cal;

void age_sub_Callback(const first_pkg::Age::ConstPtr& age_msg) 
{
  input_year = age_msg->years;
  input_month = age_msg->months;
  input_day = age_msg->days;
  ROS_INFO("You were born in Year [%.3f]; month [%.3f]; Day [%.3f]\n",age_msg->years, age_msg->months, age_msg->days);
  }

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "age_calculation");
  ros::NodeHandle n;
  age_sub_node = n.subscribe("age_publisher", 1000, age_sub_Callback);  
  age_calculation = n.advertise<first_pkg::Age>("age_calculation", 1000);
  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    age_cal.years = 2023 - input_year;
    age_cal.months = 5 - input_month;
    age_cal.days = 25 - input_day;
    
    ROS_INFO("Your age now is [%.3f] Years;[%.3f] Month;[%.3f] Day\n",age_cal.years, age_cal.months, age_cal.days);
    age_calculation.publish(age_cal);   
    ros::spinOnce();   
    loop_rate.sleep();  
  }

  return 0;
}



// Second version which subscribe only one message
// // This is the subscriber node for the age_subscriber topic but receive the age one time
// // here we can just sub one msg and it will not be sub untill we run (rostopic echo /age_calculation) to get the results


// #include "ros/ros.h"
// #include "std_msgs/Float32.h"
// #include "first_pkg/Age.h"   

// int input_year;
// int input_month;
// int input_day;

// ros::Subscriber age_sub_node;
// ros::Publisher age_calculation;

// first_pkg::Age age_cal;

// void age_sub_Callback(const first_pkg::Age::ConstPtr& age_msg) 
// {
//   input_year = age_msg->years;
//   input_month = age_msg->months;
//   input_day = age_msg->days;
//   ROS_INFO("You were born in Year [%.3f]; month [%.3f]; Day [%.3f]\n",age_msg->years, age_msg->months, age_msg->days);
//   age_cal.years = 2023 - input_year;
//   age_cal.months = 5 - input_month;
//   age_cal.days = 25 - input_day;
//   ROS_INFO("Your age now is [%.3f] Years;[%.3f] Month;[%.3f] Day\n",age_cal.years, age_cal.months, age_cal.days);
//   age_calculation.publish(age_cal);
//   }

// int main(int argc, char **argv)
// {
  
//   ros::init(argc, argv, "age_calculation");
//   ros::NodeHandle n;
//   age_calculation = n.advertise<first_pkg::Age>("age_calculation", 1000);
//   age_sub_node = n.subscribe("age_publisher", 1000, age_sub_Callback);  
  
//   while (age_calculation.getNumSubscribers() < 1) {
//     // wait for a connection to publisher
//     // you can do whatever you like here or simply do nothing
//   }


//   ros::spinOnce();   
//   ros::Duration(1.0).sleep(); 
//   return 0; 

// }

