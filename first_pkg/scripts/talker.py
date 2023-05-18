#!/usr/bin/env python3
# license removed for brevity
import rospy
from std_msgs.msg import String

def talker():
    pub = rospy.Publisher('chatter', String, queue_size=10)
    rospy.init_node('talker', anonymous=False) # anonymous=True means that when I created a nother node with the same name it will create a random number beside the node name just to change its name to work without any errors
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        hello_str = "hello world %s" % rospy.get_time()   # rospy.get_time() to print the time now near to hello world
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()   # run for talker function
    except rospy.ROSInterruptException:
        pass