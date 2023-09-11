#!/bin/bash
#
# Change directory to the git repository
cd /home/asc-share/asclinic-system/
#
# Call git
sudo -u www-data git pull 2>&1
