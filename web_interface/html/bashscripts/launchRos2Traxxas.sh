#!/bin/bash
#
# Set the ROS2 Domain ID
export ROS_DOMAIN_ID=$(cat /home/asc-share/default_ros_domain_id)
# Set to discover ROS2 only on the localhost
export ROS_LOCALHOST_ONLY=0
# Set the ROS log location
export ROS_LOG_DIR=/var/www/html/.ros/log
#
# Make the ROS commands available
# NOTE: these paths should NOT use ~
source /opt/ros/humble/setup.bash
source /home/asc-share/asclinic-system/ros2_ws/install/setup.bash
#source /home/asc-share/asclinic-system/catkin_ws/src/asclinic_pkg/launch/Config.sh
#
# Set the default agent ID parameter variable
export DEFAULT_AGENT_NAMESPACE=$(cat /home/asc-share/default_agent_namespace)
#
# Check whether the node already exists
# > Note: the -q options converts the
#   grep output to a true/false
if ros2 node list --no-daemon | grep -q /traxxas; then
	echo "Traxxas node is already running"
else
	# Remove the outfile if it exists
	rm -f outfiles_for_nodes/outfile_for_traxxas.txt
	# Launch the node
	nohup ros2 launch ai4r_pkg traxxas_launch.py agent_ns:=$DEFAULT_AGENT_NAMESPACE > outfiles_for_nodes/outfile_for_traxxas.txt 2>&1 &
	#nohup ros2 run ai4r_pkg traxxas > outfiles_for_nodes/outfile_for_traxxas.txt 2>&1 &
	echo "Traxxas node successfully launched"
fi
