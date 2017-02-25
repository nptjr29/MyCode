/*
	Thao Nguyen
	CPSC 481 - Assignment 2
	Description: This program makes the turtle autonomously navigate
				 on a rectangle loop. The turtle can start on any
				 location and follow a rectangular path. Once it 
				 comes back to the original location, it stops.
*/
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"

using namespace std;

ros::Publisher velocity_publisher;
ros::Subscriber pose_subscriber;
turtlesim::Pose turtlesim_pose;

const double PI = 3.14159265359;

// moves with a certain linear velocity for a certain distance
void move(double speed, double distance)
{
	geometry_msgs::Twist vel_msg;

	vel_msg.linear.x = speed;
	vel_msg.linear.y = 0;
	vel_msg.linear.z = 0;

	vel_msg.angular.x = 0;
	vel_msg.angular.y = 0;
	vel_msg.angular.z = 0;

	double t0 = ros::Time::now().toSec();
	double current_distance = 0.0;

	ros::Rate rate(100);

	do
    	{
		velocity_publisher.publish(vel_msg);
		double t1 = ros::Time::now().toSec();
		current_distance = speed * (t1-t0);
		ros::spinOnce();
		rate.sleep();
		
	} while(current_distance < distance);

	vel_msg.linear.x = 0;
	velocity_publisher.publish(vel_msg);
}

// makes the robot turn with a specified angular velocity
// and a specified a certain distance 
void rotate (double angular_speed, double relative_angle)
{
	geometry_msgs::Twist vel_msg;
	
	vel_msg.linear.x =0;
	vel_msg.linear.y =0;
	vel_msg.linear.z =0;

	vel_msg.angular.x = 0;
	vel_msg.angular.y = 0;
	vel_msg.angular.z = angular_speed;

	double t0 = ros::Time::now().toSec();
	double current_angle = 0.0;

	ros::Rate rate(100);

	do
	{
		velocity_publisher.publish(vel_msg);
		double t1 = ros::Time::now().toSec();
		current_angle = angular_speed * (t1-t0);
		ros::spinOnce();
		rate.sleep();
		
	} while (current_angle < relative_angle);

	vel_msg.angular.z = 0;
	velocity_publisher.publish(vel_msg);
}

// converts angles from degree to radians
double degreesToRadians(double angle_in_degrees)
{
	return (angle_in_degrees *PI /180.0);
}

// callback function to update the pose of the turtle  
void poseCallback(const turtlesim::Pose::ConstPtr & pose_message)
{
	turtlesim_pose.x=pose_message->x;
	turtlesim_pose.y=pose_message->y;
	turtlesim_pose.theta=pose_message->theta;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "turtlebox");
	ros::NodeHandle n;

	velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);      
	pose_subscriber = n.subscribe("/turtle1/pose", 10, poseCallback);	
	
	ros::Rate rate(2);
	turtlesim::Pose goal_pose;

	move(1,5);	// moves to the right
	rate.sleep();	

	rotate(degreesToRadians(10), degreesToRadians(90));	// rotate 90 degrees
	rate.sleep();
	
	move(1,2);	// moves upwards
	rate.sleep();

	rotate(degreesToRadians(10), degreesToRadians(90));	// rotates 90 degrees
	rate.sleep();

	move(1,5);	// moves to the left
	rate.sleep();

	rotate(degreesToRadians(10), degreesToRadians(90));	// rotates 90 degrees
	rate.sleep();

	move(1,2);	// moves downwards
	rate.sleep();

	return 0;
}



