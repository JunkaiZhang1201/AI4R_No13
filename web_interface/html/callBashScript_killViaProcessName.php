<?php
	// GET THE BASH SCRIPT NAME
	$processname = $_GET['name'];

	// ONLY EXECUTE IF "PROCESS NAME" HAS A LENGTH
	if (strlen($processname) == 0)
	{
		$output = "Argument must have a non-zero length";
	}
	else
	{
		// Call the bash script for killing processes
		$output = shell_exec("./bashscripts/killViaProcessName.sh $processname");
	}	
	
	echo "$output";
?>
