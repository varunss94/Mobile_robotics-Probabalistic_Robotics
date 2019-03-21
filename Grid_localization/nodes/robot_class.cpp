//////////////////////////////////////////////////////////////
//
// Programmer: Victoria Albanese
// Date: October 12, 2017
// Filename: robot_class.cpp
//
// Description: This creates a class where properties of the 
// racecar can be set by the subscriber callback function
//
//////////////////////////////////////////////////////////////

#include "robot_class.hpp"

// CONSTRUCTOR (default)
// initializes the state to -1, an error state
Robot::Robot() 
{
	this->state = -1;
}

// SENSOR_CALLBACK (sets state of robot to door or wall)
// msg: the message read by the subscriber
// returns: n/a
void Robot::sensor_callback(const std_msgs::String::ConstPtr& msg)
{
	if (strcmp(msg->data.c_str(), "Wall") == 0)
	{
		this->state = WALL;
	}
		
	if (strcmp(msg->data.c_str(), "Door") == 0)
	{
		this->state = DOOR;
	}
}

//////////////////////////////////////////////////////////////
