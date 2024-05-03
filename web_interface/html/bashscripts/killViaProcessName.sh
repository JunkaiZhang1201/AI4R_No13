#!/bin/bash
#
# Check that exactly one command is supplied
if [ "$#" -ne 1 ]; then
	echo "Exactly one argument must be supplied"
	exit 1
fi
#
# Check that the command supplied has a length
if [ "#1" == 0 ]; then
	echo "Argument must have a non-zero length."
	exit 1
fi
#
# Check that the command supplied does NOT contain spaces
if echo "$1" | egrep -q "[[:space:]]"; then
	echo "Argument must NOT have any spaces."
	exit 1
fi
#
# Put the commands into variables for make things more readable
nameToKill=$1
#
# Check whether there are any processes to kill with that name
numproc=$(pgrep -f -c $nameToKill)
if [ $numproc == "0" ]; then
        echo "No processes matching \"nameToKill\". Calling the kill command anyway"
else
        echo "\"SIGINT\" sent to $numproc matching \"$nameToKill\""
fi
#
# Run the process kill command
pkill -f --signal 2 $nameToKill