#!/usr/bin/env python3
# license removed for brevity
import rospy
from std_msgs.msg import Int32


def int_talker():
    pub = rospy.Publisher('int_chatter', Int32, queue_size=10)
    rospy.init_node('int_talker', anonymous=False) # anonymous=True means that when I created a nother node with the same name it will create a random number beside the node name just to change its name to work without any errors
    rate = rospy.Rate(10) # 10hz
    int_msg = Int32()
    count = 0
    while not rospy.is_shutdown():
        int_msg.data = count
        rospy.loginfo("%d",int_msg.data)
        count += 1
        pub.publish(int_msg.data)
        rate.sleep()

if __name__ == '__main__':
    try:
        int_talker()
        
    
    except rospy.ROSInterruptException:
        pass