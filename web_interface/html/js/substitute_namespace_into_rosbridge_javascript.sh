#!/bin/bash
#
# Check that the target JavaScript file exists
FILE=/var/www/html/js/rosbridge_for_ai4r.js
if [ -f "$FILE" ]; then
	LINE_TO_FIND="const base_namespace = \"/UNKNOWN_agent\";"
    # Check that the target file contains the line to be replaced
	CONTAINS_LINE=$(grep -c "${LINE_TO_FIND}" ${FILE})

	if [[ ${CONTAINS_LINE} -ge 1 ]]
	then
		# Get the default Agent Namespace parameter from the respective file
		export DEFAULT_AGENT_NAMESPACE=$(cat /home/asc-share/default_agent_namespace)
		# "sed" needs forward slashes to be escaped
		LINE_TO_FIND="const base_namespace = \"\/UNKNOWN_agent\";" 
		# Specify the new text for the line
		NEW_TEXT_FOR_LINE="const base_namespace = \"\/${DEFAULT_AGENT_NAMESPACE}\";"
		# Perform the necessary substitution for the line
		sed -i "s/${LINE_TO_FIND}/${NEW_TEXT_FOR_LINE}/g" ${FILE}

		echo "Line of ROS Bridge Javascript file successfully updated."
	else
		echo "Unable to find line \"$LINE_TO_FIND\" in file \"$FILE\""
	fi

else 
    echo "$FILE does not exist."
fi