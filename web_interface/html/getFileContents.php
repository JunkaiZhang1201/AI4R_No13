<?php
	
	$file_path_and_name = $_GET['file_path_and_name'];

	$temp = shell_exec("cat $file_path_and_name");
	
	$output = "<pre>$temp</pre>";

	echo "$output";
?>