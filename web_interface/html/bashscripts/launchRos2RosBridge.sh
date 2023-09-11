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
# > NOTE: these paths should NOT use ~
# > NOTE: sourcing the package here makes custom message types available to RosBridge
source /opt/ros/humble/setup.bash
source /home/asc-share/asclinic-system/ros2_ws/install/setup.bash
#
# Set the default agent ID parameter variable
export DEFAULT_AGENT_NAMESPACE=$(cat /home/asc-share/default_agent_namespace)
#
# Check whether the node already exists
# > Note: the -q options converts the
#   grep output to a true/false
if ros2 node list --no-daemon | grep -q /rosbridge; then
	echo "ROS-Bridge WebSocket node is already running"
else
	# Remove the outfile if it exists
	rm -f outfiles_for_nodes/outfile_for_rosbridge.txt
	# Launch the node
	nohup ros2 launch ai4r_pkg rosbridge_websocket_launch.xml agent_ns:=$DEFAULT_AGENT_NAMESPACE > outfiles_for_nodes/outfile_for_ros_bridge.txt 2>&1 &
	#nohup ros2 launch ai4r_pkg rosbridge_launch.xml > outfiles_for_nodes/outfile_for_rosbridge.txt 2>&1 &
	echo "ROS-Bridge WebSocket node successfully launched"
fi
