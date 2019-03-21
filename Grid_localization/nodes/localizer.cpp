////////////////////////////////////////////////////////////////////////////////
//
// Programmer: Victoria Albanese
// Date: September 28, 2017
// Filename: localizer.cpp
//
// Description: This file enables the robot to localize itself in a given 
// environment using a histogram filter.
//
////////////////////////////////////////////////////////////////////////////////

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

#include "helper_functions.hpp"
#include "robot_class.hpp"

#include <cstdlib>
#include <iostream>
#include <fstream>

#include <string>

#define FORWARD 4.0
#define BACKWARD -4.0

using namespace hmm;
using namespace std;

int main(int argc, char **argv)
{
	// verify that commandline arguments are all there
	if (argc != 2) 
	{
		cout << endl << "Usage: rosrun pset4_localization_victoria_albanese localize <+ or ->" << endl;
		cout << "\t +: start with positive velocity (travel right)" << endl;
		cout << "\t -: start with negative velocity (travel left)" << endl;
		return -1;
	}

	// set velocity from commandline argument
	float velocity;
	if (strcmp(argv[1], "+") == 0) velocity = FORWARD;
	else if (strcmp(argv[1], "-") == 0) velocity = BACKWARD;
	else 
	{
		cout << endl << "Usage: rosrun pset4_localization_victoria_albanese localize <+ or ->" << argv[1] << endl;
		cout << "\t +: start with positive velocity (travel right)" << endl;
		cout << "\t -: start with negative velocity (travel left)" << endl;
		return -1;

	}

  	// initialize node and create the node handle
  	ros::init(argc, argv, "controller");
  	ros::NodeHandle nh;

	// make a new robot
	Robot robot;

	// setup a publisher and its loop rate
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("robot/cmd_vel", 1000);
	ros::Rate loop_rate(10);  	
  	
	// get a sensor reading	
	ros::Subscriber sub = nh.subscribe<std_msgs::String>("robot/wall_door_sensor", 1000, &Robot::sensor_callback, &robot);
	ros::spinOnce();

	// make two histograms, one for measurement, one to hold intermediate movement step
    int size = 600;
	float histogram_measurement[size];
	float histogram_movement[size];
	float total_probability = 0.0;

	// initialize the two arrays
	for (int i = 0; i < size; i++) 
	{
		histogram_measurement[i] = 1.0 / (float)size;
		histogram_movement[i] = 0.0;
	}

	// do the stuff
	while(ros::ok()) 
	{
       
	geometry_msgs::Twist message;
		message.linear.x = velocity;
		pub.publish(message);
		if(velocity == FORWARD){
		for(int i = 0; i < size; i++){
				for(int j = 0; j < 8; j++){
					if(i+j >0 && i+j < size){
						histogram_movement[i+j] += histogram_measurement[i]*gauss((j/10), 1,1.0/3.0); 
					}
				}
			}
		}
		if(velocity == BACKWARD){
			for(int i = 599; i >= 0; i--){
				for(int j = 0; j < 8; j++){
					if(i-j >0 && i-j < size){
						histogram_movement[i-j] += histogram_measurement[i]*gauss((j/10), 1,1.0/3.0); 
					}
				}
			}
		}      	
		for(int i = 0; i < size; i++){
			if(robot.get_state() == WALL){
				histogram_measurement[i] = histogram_movement[i]* p_wall(i/10);
			}
			else if (robot.get_state()== DOOR){
				histogram_measurement[i] = histogram_movement[i]* p_door(i/10);
			}
		}
		
		for(int i = 0; i < size; i++){
			total_probability += histogram_measurement[i];
		}
		for(int i = 0; i < size ; i++){
			histogram_measurement[i] /= total_probability;
		}
		total_probability = 0.0;
		for(int i = 0; i<size; i++){		
			histogram_movement[i] = 0.0;
		}
		display_basic(histogram_measurement, size);
		// spin and sleep
		ros::spinOnce();
		loop_rate.sleep();
	}

  	return 0;
}
////////////////////////////////////////////////////////////////////////////////

