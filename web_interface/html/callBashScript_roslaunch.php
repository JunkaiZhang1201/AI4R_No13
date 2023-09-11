<?php
	// GET THE BASH SCRIPT NAME
	$scriptname = $_GET['scriptname'];

	// ONLY EXECUTE "SCRIPT NAMES" WITH AN EXACT MATCH
	//
	// > For the MASTER
	if ($scriptname == "sensor_systems")
	{
		// GET THE VALUES OF THE EMULATE FLAG
		// > This will be a string
		$flag_value = strtolower( $_GET['flag'] );
		// Check that the new setpoint values are numerical
		if (in_array($flag_value, array("true", "1", "yes"), true))
		{
			$flag_value = "true";
		}
		elseif (in_array($flag_value, array("false", "0", "no"), true))
		{
			$flag_value = "false";
		}
		else
		{
			echo "flag value = $flag_value, is not a boolean value.";
			exit();
		}
		// Call the bash script for launching this node
		$output = shell_exec("./bashscripts/launchRosSensorSystems.sh $flag_value");
	}
	elseif ($scriptname == "rosbridge")
	{
		// Call the bash script for launching this node
		$output = shell_exec("./bashscripts/launchRos2RosBridge.sh");
	}
	elseif ($scriptname == "traxxas")
	{
		// Call the bash script for launching this node
		$output = shell_exec("./bashscripts/launchRos2Traxxas.sh");
	}
	elseif ($scriptname == "policy")
	{
		// Call the bash script for launching this node
		$output = shell_exec("./bashscripts/launchRos2Policy.sh");
	}
	elseif ($scriptname == "linedetector")
	{
		// Call the bash script for launching this node
		$output = shell_exec("./bashscripts/launchRos2LineDetector.sh");
	}
	else
	{
		$output = "launch name = $scriptname is not a valid option";
	}

	echo "$output";
?>
