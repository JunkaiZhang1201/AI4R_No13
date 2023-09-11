#!/bin/bash
source /opt/ros/noetic/setup.bash
#
# Set the ROS2 Domain ID
export ROS_DOMAIN_ID=$(cat /home/asc-share/default_ros_domain_id)
# Set to discover ROS2 only on the localhost
export ROS_LOCALHOST_ONLY=0
# Set the ROS log location
export ROS_LOG_DIR=/var/www/html/.ros/log
#
ros2 service list -t --no-daemon 2>&1
