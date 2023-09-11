function getFileContents_outputLabelID(filePath, labelID)
{
	// Convert the "filePath" to a heading string
	var heading_string = "<p class=\"terminal-highligh-paragraph\">";
	heading_string = heading_string + "CONTENTS OF FILE";
	heading_string = heading_string + "<br>";
	heading_string = heading_string + filePath;
	heading_string = heading_string + "</p>";

	// Create a variable for sending an AJAX request
	var xmlhttp = new XMLHttpRequest();
	// Add the function to be run when the response is recieved
	xmlhttp.onreadystatechange = function()
	{
		if (this.readyState == 4 && this.status == 200)
		{
			// Construct and display the appropriate information
			var base_string = "";
			document.getElementById(labelID).innerHTML = base_string + heading_string + "<br>" + this.responseText;
		}
		else
		{
			// Construct and display the appropriate information
			var base_string = "";
			var display_message = getDisplayMessageForXMLHttpRequest(this);
			if (this.readyState == 4)
			{
				document.getElementById(labelID).innerHTML = base_string + heading_string + "<br>" + display_message;
			}
			else
			{
				document.getElementById(labelID).innerHTML = base_string + display_message;
			}
		}
	};
	xmlhttp.open("GET", "getFileContents.php?file_path_and_name=" + filePath, true);
	xmlhttp.send();
}