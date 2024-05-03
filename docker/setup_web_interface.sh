ASCLINIC_BRANCH_FOR_WEB_INTERFACE="main"
#AI4R_BRANCH_FOR_WEB_INTERFACE="ai4rweb"
DEFAULT_AGENT_NAMESPACE="agent01"
DEFAULT_ROS_DOMAIN_ID=1

# Make the shared directory under "/home"
mkdir -p /home/asc-share

# Clone "ai4r-system" git repository
# NOTE: first remove the repository if it exists

cd /home/asc-share
rm -rf asclinic-system/

mkdir -p /home/asc-share/asclinic-system
cd /home/asc-share/asclinic-system

#git clone https://gitlab.unimelb.edu.au/asclinic/asclinic-system.git
git clone https://gitlab.unimelb.edu.au/ai4r/ai4r-system.git .                  # Updated path for ai4r-system

# Check out the requested branch of the repository
#cd asclinic-system/
git checkout ${ASCLINIC_BRANCH_FOR_WEB_INTERFACE}

#cd ai4r-system/
#git checkout ${AI4R_BRANCH_FOR_WEB_INTERFACE}

# Add this git repository as safe for non-owners to work with
# NOTE: This makes it easier to work with when
#       logged-in to the computer
#     > If this is not done, then any git command
#       is met with the message:
#       fatal: unsafe repository ('/home/asc-share/asclinic-system' is owned by someone else)
git config --system --add safe.directory /home/asc-share/asclinic-system        # Add safe directory to system instead of global to allow the www-data user to run git commands

# Give the www-data user owndership and permission to the asc-share directory 
# and asclinic-system git repository:
#sudo chown -R www-data:www-data /home/asc-share
sudo chown -R www-data:www-data /home/asc-share/asclinic-system
#sudo chmod -R u+rwX /home/asc-share
#sudo chmod -R u+rwX /home/asc-share/asclinic-system.git

# First, remove any contents already there
rm -rf /var/www/html/*
# Now copy across from the repository
cp -R /home/asc-share/asclinic-system/web_interface/html/* /var/www/html/

# Give ownership and write permissions to the `www-data` user to the `/var/www/` directory
sudo chown -R www-data:www-data /var/www/
sudo chmod -R u+w /var/www/

# # Clone the RPLidar package for ROS
# cd /home/asc-share/
# cd asclinic-system/catkin_ws/src/
# git clone https://github.com/Slamtec/rplidar_ros.git

# Remove the ".git" folder to avoid having a nested git repository
# rm -rf rplidar_ros/.git/

cd /home/asc-share/
# Add a new file with the default Agent ID
sudo rm -f /home/asc-share/default_agent_namespace
echo $DEFAULT_AGENT_NAMESPACE | tee /home/asc-share/default_agent_namespace
sudo rm -f /home/asc-share/default_ros_domain_id
echo $DEFAULT_ROS_DOMAIN_ID | tee /home/asc-share/default_ros_domain_id

# sudo usermod -aG sudo www-data
#echo "www-data ALL=(ALL) NOPASSWD: /usr/bin/git, /opt/ros/humble/bin/ros2" >> /etc/sudoers
echo "www-data ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers                         # Add www-data user sudo access to run git and ros commands

# Reset/update the web interface, name space variables, resolving the issue with
# Unreliable behavior of the Launch Policy Node
/home/asc-share/asclinic-system/web_interface/html/bashscripts/updatewebinterface.sh