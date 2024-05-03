#!/bin/bash
#
# Make the ROS commands available
# NOTE: these paths should NOT use ~
source /opt/ros/humble/setup.bash
#
# Change directory to the colcon workspace of the repository
cd /home/asc-share/asclinic-system/ros2_ws
#
# Call catkin_make
colcon build --symlink-install 2>&1
