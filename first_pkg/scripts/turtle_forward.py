#!/usr/bin/env python3
# license removed for brevity
import rospy
from geometry_msgs.msg import Twist

def turtle_forward():
    pub = rospy.Publisher('turtle1/cmd_vel', Twist, queue_size=10)
    rospy.init_node('turtle_forward', anonymous=False) 
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        msg =  Twist()
        msg.linear.x = 0.5 
        rospy.loginfo(msg)
        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        turtle_forward()   # run for talker function
    except rospy.ROSInterruptException:
        pass