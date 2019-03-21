##############################################################
##
## Programmer: Victoria Albanese
## Date: October 12, 2017
## Filename: robot_class.hpp
##
## Description: This creates a class where the state of 
## the robot (wall/door) of the robot can be set by the 
## subscriber callback function
##
##############################################################

import rospy
from std_msgs.msg import String

WALL = 0
DOOR = 1

class Robot:
    def __init__(self):
        self.state = -1
        
    def initSubscriber(self):
        rospy.Subscriber("/robot/wall_door_sensor", String, self.sensor_callback, queue_size=1000)
        
    def get_state(self):
        return self.state
    
    def sensor_callback(self, msg):
        if msg == "Wall":
            self.state = WALL
        
        if msg == "Door":
            self.state = DOOR


