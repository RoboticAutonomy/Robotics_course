#!/usr/bin/env python3
# license removed for brevity
import rospy
from std_msgs.msg import Float32


def float_talker():
    pub = rospy.Publisher('float_chatter', Float32, queue_size=10)
    rospy.init_node('float_talker', anonymous=False) # anonymous=True means that when I created a nother node with the same name it will create a random number beside the node name just to change its name to work without any errors
    rate = rospy.Rate(10) # 10hz
    float_msg = Float32()
    count = 0
    while not rospy.is_shutdown():
        float_msg.data = count
        rospy.loginfo("%f",float_msg.data)
        count += 1
        pub.publish(float_msg.data)
        rate.sleep()

if __name__ == '__main__':
    try:
        float_talker()
        
    
    except rospy.ROSInterruptException:
        pass