#!/usr/bin/env python3
import rospy
from std_msgs.msg import Int32

def callback(int_data):
    rospy.loginfo(rospy.get_caller_id() + "I heard [%d]", int_data.data)
    
def int_listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('int_listener', anonymous=False)

    rospy.Subscriber("int_chatter", Int32, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    int_listener()