#!/usr/bin/env python3
import rospy
from std_msgs.msg import Float32

def callback(float_data):
    rospy.loginfo(rospy.get_caller_id() + "I heard [%f]", float_data.data)
    
def float_listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('float_listener', anonymous=False)

    rospy.Subscriber("float_chatter", Float32, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    float_listener()