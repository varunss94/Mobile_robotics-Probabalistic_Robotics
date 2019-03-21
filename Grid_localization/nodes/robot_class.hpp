//////////////////////////////////////////////////////////////
//
// Programmer: Victoria Albanese
// Date: October 12, 2017
// Filename: robot_class.hpp
//
// Description: This creates a class where the state of 
// the robot (wall/door) of the robot can be set by the 
// subscriber callback function
//
//////////////////////////////////////////////////////////////

#ifndef ROBOT_CLASS_HPP
#define ROBOT_CLASS_HPP
#define _USE_MATH_DEFINES

#include "ros/ros.h"
#include "std_msgs/String.h"

#include <cmath>
#include <string>

#define WALL 0
#define DOOR 1

class Robot 
{
	private: 
		int state;

	public:
		Robot();
		int get_state() { return this->state; }
		void sensor_callback(const std_msgs::String::ConstPtr& msg);
};

#endif // ROBOT_CLASS_HPP
