#include "ros/ros.h"        //including for the ros library
// #include "std_msgs/Int32.h"    // include for the msg type that we used
#include "std_msgs/Float32.h"    // include for the msg type that we used
#include "sensor_msgs/LaserScan.h" 
#include "geometry_msgs/Twist.h"  


float scan_forward_data;
float scan_right_data;
float scan_left_data;
// float control_data;

ros::Subscriber laser_detection;
ros::Publisher robot_controller;

// std_msgs::Float32 float_msg;
geometry_msgs::Twist control_data; 
sensor_msgs::LaserScan scan_msg;

void laser_detection_Callback(const sensor_msgs::LaserScan::ConstPtr& detection_msg)
{
  scan_forward_data = detection_msg->ranges[360];
  scan_right_data = detection_msg->ranges[0];
  scan_left_data = detection_msg->ranges[719];
  ROS_INFO("Front obstacle distance = [%f] m", detection_msg->ranges[360]);
  ROS_INFO("Right obstacle distance = [%f] m", detection_msg->ranges[0]);
  ROS_INFO("Left obstacle distance = [%f] m", detection_msg->ranges[719]);
//   ROS_INFO("Front obstacle distance= [%.3f] m; Right obstacle distance= [%.3f] m; Left obstacle distance= [%.3f] m\n",detection_msg->ranges[360], detection_msg->ranges[0], detection_msg->ranges[719]);
}

// int main(int argc, char **argv)
// {
  
//   ros::init(argc, argv, "robot_obstacle_avoidance");  //initialize ros node , contain the node name talker

  
//   ros::NodeHandle n;

  
//   laser_detection = n.subscribe("scan", 1000, laser_detection_Callback);  // call back function
//   robot_controller = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

//   ros::Rate loop_rate(10);

  
//   while (ros::ok())
//   {
//     // if (scan_forward_data < 1.0 && scan_right_data > 1.0 && scan_left_data > 1.0)  // turn left
//     // if (scan_forward_data < 1.0)
//     // {
//     //     control_data.linear.x = 0.5;
//     //     control_data.angular.z = 1.0;
//     // }
//     // // else if (scan_right_data < 1.0 && scan_left_data > 1.0)  // turn left
//     // else if (scan_right_data < 1.0)
//     // {
//     //     control_data.linear.x = 0.5;
//     //     control_data.angular.z = 1.0;
//     // }
//     // // else if (scan_left_data < 1.0 && scan_right_data > 1.0 )  // turn right
//     // else if (scan_left_data < 1.0) 
//     // {
//     //     control_data.linear.x = 0.5;
//     //     control_data.angular.z = -1.0;
//     // }
//     // else    // go straight
//     // {
//     //     control_data.linear.x = 0.5;
//     //     control_data.angular.z = 0.0;
//     // }

//     control_data.linear.x = 1;
//     control_data.angular.z = 0.0;
    
//     ROS_INFO("Robot linear velocity x is [%.5f] m/s; and angular z is [ %.5f] deg\n",control_data.linear.x, control_data.angular.z);
    
   
//     robot_controller.publish(control_data);   //chatter_pub that i created to pub my msg that i created

//     ros::spinOnce();   //keep working inside a loop

//     loop_rate.sleep();  //sleep with the previous rate 10 hz
//   }

//   return 0;
// }


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "robot_obstacle_avoidance");

  
  ros::NodeHandle n;

  
  ros::Subscriber laser_detection= n.subscribe("scan", 1000, laser_detection_Callback);  // call back function

  
  ros::spin();

  return 0;
}