#!/bin/bash

# Start script execution
echo "Starting installation checks..."
total_checks=14
current_check=1

# Function to print the current check status
function print_check_status {
    echo "Check $current_check/$total_checks: $1"
    ((current_check++))
}

# Check if mosh is installed
print_check_status "Checking for Mosh installation..."
if command -v mosh &> /dev/null
then
    echo "Mosh is installed."
    mosh --version
else
    echo "Mosh is not installed."
fi

# Check if i2c-tools is installed
print_check_status "Checking for i2c-tools installation..."
if command -v i2cdetect &> /dev/null
then
    echo "i2c-tools is installed."
else
    echo "i2c-tools is not installed."
fi

# Check if libi2c-dev is installed
if dpkg -l | grep -q libi2c-dev; then
    echo "libi2c-dev is installed."
else
    echo "libi2c-dev is not installed."
fi

# Check if gpiod is installed
print_check_status "Checking for gpiod installation..."
if command -v gpioinfo &> /dev/null
then
    echo "gpiod is installed."
else
    echo "gpiod is not installed."
fi

# Check if libgpiod-dev is installed
if dpkg -l | grep -q libgpiod-dev; then
    echo "libgpiod-dev is installed."
else
    echo "libgpiod-dev is not installed."
fi

# Check if libgpiod-doc is installed
if dpkg -l | grep -q libgpiod-doc; then
    echo "libgpiod-doc is installed."
else
    echo "libgpiod-doc is not installed."
fi

# Check if git is installed
print_check_status "Checking for Git installation..."
if command -v git &> /dev/null
then
    echo "Git is installed."
    git --version
else
    echo "Git is not installed."
fi

# Check if ROS is installed
print_check_status "Checking for ROS installation..."
# Attempt to source the ROS 2 environment (replace 'humble' with your ROS distro if different)
source /opt/ros/humble/setup.bash 2>/dev/null

# Check if a ROS 2-specific command is available
if command -v ros2 &>/dev/null; then
    echo "ROS 2 is installed."
else
    echo "ROS 2 is not installed."
fi

# New checks for the additional libraries
# Check if v4l-utils is installed
print_check_status "Checking for v4l-utils installation..."
if command -v v4l2-ctl &> /dev/null
then
    echo "v4l-utils is installed."
else
    echo "v4l-utils is not installed."
fi

# Check if libv4l-dev is installed
if dpkg -l | grep -q libv4l-dev; then
    echo "libv4l-dev is installed."
else
    echo "libv4l-dev is not installed."
fi

# Check if qv4l2 is installed
if command -v qv4l2 &> /dev/null
then
    echo "qv4l2 is installed."
else
    echo "qv4l2 is not installed."
fi

# Check if uvcdynctrl is installed
if command -v uvcdynctrl &> /dev/null
then
    echo "uvcdynctrl is installed."
else
    echo "uvcdynctrl is not installed."
fi

# Check if NumPy is installed
print_check_status "Checking for NumPy installation..."
if python3 -c "import numpy; print(numpy.__version__)" &> /dev/null
then
    echo "NumPy is installed."
    python3 -c "import numpy; print('NumPy version:', numpy.__version__)"
else
    echo "NumPy is not installed."
fi

# Check if OpenCV is installed
print_check_status "Checking for OpenCV installation..."
if python3 -c "import cv2; print(cv2.__version__)" &> /dev/null
then
    echo "OpenCV is installed."
    python3 -c "import cv2; print('OpenCV version:', cv2.__version__)"
else
    echo "OpenCV is not installed."
fi

# Check if the asclinic-system directory exists and has been cloned
print_check_status "Checking for asclinic-system repository..."
if [ -d "${PATH_FOR_ASCLINIC_SYSTEM_LOCALLY}asclinic-system" ] && [ -n "$(ls -A ${PATH_FOR_ASCLINIC_SYSTEM_LOCALLY}asclinic-system)" ]; then
    echo "asclinic-system repository is cloned and directory exists."
else
    echo "asclinic-system repository is not cloned or directory does not exist."
fi

# Check if the RPLidar ROS package directory exists and has been cloned
print_check_status "Checking for RPLidar ROS package..."
if [ -d "${PATH_FOR_ASCLINIC_SYSTEM_LOCALLY}asclinic-system/catkin_ws/src/rplidar_ros" ] && [ -n "$(ls -A ${PATH_FOR_ASCLINIC_SYSTEM_LOCALLY}asclinic-system/catkin_ws/src/rplidar_ros)" ]; then
    echo "RPLidar ROS package is cloned and directory exists."
else
    echo "RPLidar ROS package is not cloned or directory does not exist."
fi

# Check if rosbridge_server is installed
print_check_status "Checking for rosbridge_server installation..."
if ros2 pkg list | grep -q rosbridge_server; then
    echo "rosbridge_server is installed."
else
    echo "rosbridge_server is not installed."
fi

# Check if Apache2 is installed
print_check_status "Checking for Apache2 installation..."
if command -v apache2ctl &> /dev/null; then
    echo "Apache2 is installed."
    apache2ctl -v
else
    echo "Apache2 is not installed."
fi

# Check if PHP is installed
print_check_status "Checking for PHP installation..."
if command -v php &> /dev/null; then
    echo "PHP is installed."
    php --version
else
    echo "PHP is not installed."
fi

# Check if ffmpeg is installed
print_check_status "Checking for FFmpeg installation..."
if command -v ffmpeg &> /dev/null; then
    echo "FFmpeg is installed."
    ffmpeg -version
else
    echo "FFmpeg is not installed."
fi

# Check if motion is installed
print_check_status "Checking for motion installation..."
if command -v motion &> /dev/null
then
    echo "Motion is installed."
else
    echo "Motion is not installed."
fi

# End of script execution
echo "Installation checks completed."