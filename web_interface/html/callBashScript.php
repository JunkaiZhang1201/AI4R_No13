<?php
	// Get the bash script name
	$scriptname = $_GET['scriptname']; 

	// ONLY EXECUTE NAMES WITH AN EXACT MATHC

	
	// For the GIT tab
	if ($scriptname == "gitStatus") {
		$temp = shell_exec("sudo ./bashscripts/gitStatus.sh");
		$output = "<pre>$temp</pre>";
	}
	elseif ($scriptname == "gitPull") {
		$temp = shell_exec("sudo ./bashscripts/gitPull.sh");
		$output = "<pre>$temp</pre>";
	}
	elseif ($scriptname == "gitDiff") {
		$temp = shell_exec("sudo ./bashscripts/gitDiff.sh");
		$output = "<pre>$temp</pre>";
	}
	elseif ($scriptname == "gitCheckoutAll") {
		$temp = shell_exec("sudo ./bashscripts/gitCheckoutAll.sh");
		$output = "<pre>$temp</pre>";
	}
	elseif ($scriptname == "gitCheckoutMaster") {
		$temp = shell_exec("sudo ./bashscripts/gitCheckoutMaster.sh");
		$output = "<pre>$temp</pre>";
	}
	elseif ($scriptname == "catkin_make") {
		$temp = shell_exec("sudo ./bashscripts/catkin_make.sh");
		$output = "<pre>$temp</pre>";
	}
	elseif ($scriptname == "catkin_make_clean") {
		$temp = shell_exec("sudo ./bashscripts/catkin_make_clean.sh");
		$output = "<pre>$temp</pre>";
	}
	elseif ($scriptname == "colcon_build") {
		$temp = shell_exec("sudo ./bashscripts/colcon_build.sh");
		$output = "<pre>$temp</pre>";
	}
	//
	// For the LAUNCH tab
	elseif ($scriptname == "checkForRosMaster") {
		$output = shell_exec("sudo ./bashscripts/checkForRosMaster.sh");
	}
	//
	// "launch Ros Master" is handled separately
	// because it requires an input argument
	//
	elseif ($scriptname == "killRosAll") {
		$output = shell_exec("sudo ./bashscripts/killRosAll.sh");
	}
	elseif ($scriptname == "killRos2All") {
		$output = shell_exec("sudo ./bashscripts/killRos2All.sh");
	}
	elseif ($scriptname == "checkForRosAgent") {
		$output = shell_exec("sudo ./bashscripts/checkForRosAgent.sh");
	}
	//
	// "launch Ros Agent" is handled separately
	// because it requires an input argument
	//
	elseif ($scriptname == "killRosAgent") {
		$output = shell_exec("sudo ./bashscripts/killRosAgent.sh");
	}
	elseif ($scriptname == "rosnodeList") {
		$temp = shell_exec("sudo ./bashscripts/rosnodeList.sh");
		$output = "<pre>$temp</pre>";
	}
	elseif ($scriptname == "rostopicList") {
		$temp = shell_exec("sudo ./bashscripts/rostopicList.sh");
		$output = "<pre>$temp</pre>";
	}
	elseif ($scriptname == "ros2nodeList") {
		$temp = shell_exec("sudo ./bashscripts/ros2nodeList.sh");
		$output = "<pre>$temp</pre>";
	}
	elseif ($scriptname == "ros2topicList") {
		$temp = shell_exec("sudo ./bashscripts/ros2topicList.sh");
		$output = "<pre>$temp</pre>";
	}
	elseif ($scriptname == "ros2serviceList") {
		$temp = shell_exec("sudo ./bashscripts/ros2serviceList.sh");
		$output = "<pre>$temp</pre>";
	}
	//
	// For the CONTROL tab:
	// { RADIO CONNECTION, TAKE-OFF, LAND, MOTORS-OFF, LOAD CONTROLLER }
	elseif ($scriptname == "rosConnect") {
		$output = shell_exec("sudo ./bashscripts/rosCrazyRadioCommand_forAgent.sh 0");
	}
	elseif ($scriptname == "rosDisconnect") {
		$output = shell_exec("sudo ./bashscripts/rosCrazyRadioCommand_forAgent.sh 1");
	}
	elseif ($scriptname == "rosTakeoff") {
		$output = shell_exec("sudo ./bashscripts/rosFlyingStateCommand_forAgent.sh 11");
	}
	elseif ($scriptname == "rosLand") {
		$output = shell_exec("sudo ./bashscripts/rosFlyingStateCommand_forAgent.sh 12");
	}
	elseif ($scriptname == "rosMotorsoff") {
		$output = shell_exec("sudo ./bashscripts/rosFlyingStateCommand_forAgent.sh 13");
	}
	elseif ($scriptname == "rosEnabledefault") {
		$output = shell_exec("sudo ./bashscripts/rosFlyingStateCommand_forAgent.sh 1");
	}
	elseif ($scriptname == "rosEnablestudent") {
		$output = shell_exec("sudo./bashscripts/rosFlyingStateCommand_forAgent.sh 3");
	}
	// For the CONTROL tab:
	// GET SETPOINT
	elseif ($scriptname == "rosGetSetpointDefault") {
		$output = shell_exec("sudo ./bashscripts/rosGetCurrentSetpoint_forAgent.sh default");
	}
	elseif ($scriptname == "rosGetSetpointStudent") {
		$output = shell_exec("sudo ./bashscripts/rosGetCurrentSetpoint_forAgent.sh student");
	}
	// For the CONTROL tab:
	// LOAD YAML PARAMETERS
	elseif ($scriptname == "rosLoadYamlDefault") {
		$output = shell_exec("sudo ./bashscripts/rosLoadYaml_forAgent.sh default");
	}
	elseif ($scriptname == "rosLoadYamlStudent") {
		$output = shell_exec("sudo ./bashscripts/rosLoadYaml_forAgent.sh student");
	}
	// For the MOTION VIDEO STREAMER:
	elseif ($scriptname == "motionStart") {
		$output = shell_exec("sudo ./bashscripts/motionStart.sh");
	}
	elseif ($scriptname == "motionStop") {
		$output = shell_exec("sudo ./bashscripts/motionStop.sh");
	}
	elseif ($scriptname == "motionStatus") {
		$output = shell_exec("sudo ./bashscripts/motionStatus.sh");
	}


	echo "$output";
?>
