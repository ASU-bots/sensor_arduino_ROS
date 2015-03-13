#include <ros.h>
#include <std_msgs/Float32.h>

#include "ReadIMU.h"

ros::NodeHandle nh;

std_msgs::Float32 gyro_x;
std_msgs::Float32 gyro_y;
std_msgs::Float32 gyro_z;
std_msgs::Float32 accel_x;
std_msgs::Float32 accel_y;
std_msgs::Float32 accel_z;
std_msgs::Float32 mag_x;
std_msgs::Float32 mag_y;
std_msgs::Float32 mag_z;

ros::Publisher gyro_x_pub("gyro_x", &gyro_x);
ros::Publisher gyro_y_pub("gyro_y", &gyro_y);
ros::Publisher gyro_z_pub("gyro_z", &gyro_z);
ros::Publisher accel_x_pub("accel_x", &accel_x);
ros::Publisher accel_y_pub("accel_y", &accel_y);
ros::Publisher accel_z_pub("accel_z", &accel_z);
ros::Publisher mag_x_pub("mag_x", &mag_x);
ros::Publisher mag_y_pub("mag_y", &mag_y);
ros::Publisher mag_z_pub("mag_z", &mag_z);

void setup(){
  nh.initNode();
  
  nh.advertise(gyro_x_pub);
  nh.advertise(gyro_y_pub);
  nh.advertise(gyro_z_pub);
  nh.advertise(accel_x_pub);
  nh.advertise(accel_y_pub);
  nh.advertise(accel_z_pub);
  nh.advertise(mag_x_pub);
  nh.advertise(mag_y_pub);
  nh.advertise(mag_z_pub);
  
  gyro_x.data=0;
}

void loop(){
  getIMUData(gyro_x,  gyro_y,  gyro_z,
             accel_x, accel_y, accel_z,
             mag_x,   mag_y,   mag_z);
  
  gyro_x_pub.publish(&gyro_x);
  gyro_y_pub.publish(&gyro_y);
  gyro_z_pub.publish(&gyro_z);
  accel_x_pub.publish(&accel_x);
  accel_y_pub.publish(&accel_y);
  accel_z_pub.publish(&accel_z);
  mag_x_pub.publish(&mag_x);
  mag_y_pub.publish(&mag_y);
  mag_z_pub.publish(&mag_z);
  
  nh.spinOnce();
  delay(1);
}
