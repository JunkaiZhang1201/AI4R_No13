#!/bin/bash
#
# Specify the name to kill
nameToKill=ros
#
# Check how many processes will be sent the kill signal
numproc=$(pgrep -f -c $nameToKill)
#
# Run the process kill command
pkill -f --signal 9 ros
#
# Echo the status
echo "\"SIGKILL\" sent to $numproc matching \"$nameToKill\""