// ==============
// BASE NAMESPACE
// ==============
// DO NOT CHANGE OR DELETE THE FOLLOWING LINE
const base_namespace = "/UNKNOWN_agent";
console.log("[ROS BIDGE JS] base_namespace = (", + base_namespace + ")");



// ===============
// URL TO THE HOST
// ===============
// Construct the URL to the host
// i.e., to the computer that runs the robot
const url_to_host = new URL(window.location.href);
url_to_host.protocol = "ws";
url_to_host.port = 9090;
url_to_host.pathname = "/";
// Hard-code a URL for development purposes
//url_to_host.href = "ws://192.168.1.26:9090"
// Log the URL being used:
console.log("[ROS BIDGE JS] url.href = ",url_to_host.href);



// =================
// CONNECTING TO ROS
// =================
var ros = new ROSLIB.Ros(
{
	//url : "ws://localhost:9090"
	url : url_to_host.href
});

ros.on("connection", function()
{
	console.log("[ROS BIDGE JS] Connected to websocket server.");
	updateWebSocketStatusLabel("connected");
	// Start the heartbeat publishing
	//heartbeat_interval_id = setInterval(publishHeartbeat, heartbeart_interval_in_milliseconds);
});

ros.on("error", function(error)
{
	console.log("[ROS BIDGE JS] Error connecting to websocket server: ", error);
	updateWebSocketStatusLabel("experienced an error while connecting, error text: " + error);
});

ros.on("close", function()
{
	console.log("[ROS BIDGE JS] Connection to websocket server closed.");
	updateWebSocketStatusLabel("connection is closed");
	// Clear the fields to avoid displaying old information
	document.getElementById("traxxasNodeCurrentFSMState").innerHTML = "";
	document.getElementById("lineDetectorNumPoints").innerHTML = "";
	document.getElementById("lineDetectorFirstPoint").innerHTML = "";
	document.getElementById("policyNodeCurrentFSMState").innerHTML = "";
	// Clear the canvas
	clearCanvas("lineDetectorCanvas");
});

function updateWebSocketStatusLabel(status_as_string)
{
	document.getElementById("webSocketStatusLabel").innerHTML = "<b>" + status_as_string + "</b>";
	document.getElementById("urlOfHostLabel").innerHTML = url_to_host.href;
}

// =================================================
// FOR THE ROS BRIDGE CONNECT AND DISCONNECT BUTTONS
// =================================================
function rosbridgeConnect()
{
	ros.connect(url_to_host.href);
}

function rosbridgeClose()
{
	ros.close();
}



// ===================
// PUBLISHER VARIABLES
// ===================
var request_traxxas_fsm_state = new ROSLIB.Topic(
	{
		ros : ros,
		name : base_namespace + "/" + "estop",
		messageType : "std_msgs/UInt16"
	});

var request_policy_fsm_state = new ROSLIB.Topic(
	{
		ros : ros,
		name : base_namespace + "/" + "policy_fsm_transition_request",
		messageType : "std_msgs/UInt16"
	});

var request_policy_esc_setpoint = new ROSLIB.Topic(
	{
		ros : ros,
		name : base_namespace + "/" + "policy_esc_setpoint_request",
		messageType : "std_msgs/Float32"
	});



// =================
// PUBLISH FUNCTIONS
// =================
function sendTraxxasFSMStateRequest(state)
{
	var int_message = new ROSLIB.Message({ data : state });
	request_traxxas_fsm_state.publish(int_message);
	console.log("Requested the Traxxas Node state to transition to state = " + int_message.data );
}

function sendPolicyFSMStateRequest(state)
{
	var int_message = new ROSLIB.Message({ data : state });
	request_policy_fsm_state.publish(int_message);
	console.log("Requested the Policy Node to transition to state = " + int_message.data );
}

function sendPolicyEscSetpointRequest()
{
	// Get the value from the input
	var setpoint_selector = document.getElementById("inputPolicyEscSetpointRequest");
    var setpoint_value = parseFloat(setpoint_selector.value);
	// Build and send the message
	var float_message = new ROSLIB.Message({ data : setpoint_value });
	request_policy_esc_setpoint.publish(float_message);
	console.log("Requested the Policy Node to update its ESC setpoint to " + float_message.data + " %");
}



// ====================
// SUBSCRIBER VARIABLES
// ====================
var traxxas_fsm_state_subscriber = new ROSLIB.Topic({
	ros : ros,
	name : base_namespace + "/" + "traxxas_state",
	messageType : "std_msgs/String"
});

var line_detector_num_points_subscriber = new ROSLIB.Topic({
	ros : ros,
	name : base_namespace + "/" + "image_num_points",
	messageType : "std_msgs/UInt16"
});

var line_detector_points_subscriber = new ROSLIB.Topic({
	ros : ros,
	name : base_namespace + "/" + "image_points",
	messageType : "ai4r_interfaces/ImagePointsArray"
});
//from ai4r_interfaces.msg import IntArray, ElementInt
//from ai4r_interfaces.msg import ImagePointsArray, PixelCoordsFloat32

var policy_fsm_state_subscriber = new ROSLIB.Topic({
	ros : ros,
	name : base_namespace + "/" + "policy_fsm_state",
	messageType : "std_msgs/String"
});

var policy_actions_subscriber = new ROSLIB.Topic({
	ros : ros,
	name : base_namespace + "/" + "esc_and_steering_set_point_percent",
	messageType : "ai4r_interfaces/EscAndSteering"
});
//from ai4r_interfaces.msg import EscAndSteering

var traxxas_current_esc_subscriber = new ROSLIB.Topic({
	ros : ros,
	name : base_namespace + "/" + "traxxas_esc_current_pulse_width",
	messageType : "ai4r_interfaces/ServoPulseWidth"
});
//from ai4r_interfaces.msg import EscAndSteering

var traxxas_current_steering_subscriber = new ROSLIB.Topic({
	ros : ros,
	name : base_namespace + "/" + "traxxas_steering_current_pulse_width",
	messageType : "ai4r_interfaces/ServoPulseWidth"
});
//from ai4r_interfaces.msg import EscAndSteering



// =============================
// SUBSCRIBER CALLBACK FUNCTIONS
// =============================
traxxas_fsm_state_subscriber.subscribe(function(message)
{
	//console.log("Received message on " + traxxas_fsm_state_subscriber.name + ", with data = " + message.data );
	//traxxas_state_subscriber.unsubscribe();

	// Update the relevant label
	document.getElementById("traxxasNodeCurrentFSMState").innerHTML = "<pre>" + message.data + "</pre>";
});

line_detector_num_points_subscriber.subscribe(function(message)
{
	//console.log("Received message on " + line_detector_num_points_subscriber.name + ", with data = " + message.data );

	// Update the relevant label
	document.getElementById("lineDetectorNumPoints").innerHTML = "<pre>" + String(message.data).padStart(2,' ') + "</pre>";
});

line_detector_points_subscriber.subscribe(function(message)
{
	//console.log("Received message on " + line_detector_points_subscriber.name + ", with list = " + message.points );

	// Extract the list of points
	list_of_points = message.points

	// Extract the first point
	var num_points = list_of_points.length

	// Check whether there are any points
	if (num_points > 0)
	{
		// Extract the first point
		var first_point = list_of_points[0]
		// Update the relevant label for the first point
		//document.getElementById("lineDetectorNumPoints").innerHTML = num_points;
		document.getElementById("lineDetectorFirstPoint").innerHTML = "<pre>" + "( " + String(first_point.u).padStart(4,' ') + " , " + String(first_point.v).padStart(4,' ') + " )" + "</pre>";

		// Get the image resolution
		var image_width  = message.image_width;
		var image_height = message.image_height;
		document.getElementById("lineDetectorImageResolution").innerHTML = "<pre>" + "( " + String(image_height).padStart(4,' ') + " , " + String(image_width).padStart(4,' ') + " )" + "</pre>";

		// Clear the canvas and plot the points
		clearCanvas("lineDetectorCanvas");
		drawPoints("lineDetectorCanvas", list_of_points, image_width, image_height);
		drawLineThroughPoints("lineDetectorCanvas", list_of_points, 2);
	}
	else
	{
		document.getElementById("lineDetectorFirstPoint").innerHTML = "<pre>" + "( - , - )" + "</pre>";
		// Clear the canvas
		clearCanvas("lineDetectorCanvas");
	}
	
});

policy_fsm_state_subscriber.subscribe(function(message)
{
	//console.log("Received message on " + policy_fsm_state_subscriber.name + ", with data = " + message.data );

	document.getElementById("policyNodeCurrentFSMState").innerHTML = "<pre>" + message.data + "</pre>";
});

policy_actions_subscriber.subscribe(function(message)
{
	//console.log("Received message on " + policy_actions_subscriber.name + ", with (esc,steering) = ( " + message.esc_percent + " , " + message.steering_percent + " )" );

	document.getElementById("policyActionEscPercent").innerHTML = "<pre>" + String(message.esc_percent).padStart(4,' ') + "</pre>";
	var temp_steering_value = message.steering_percent;
	var temp_steering_string = temp_steering_value.toFixed(2);
	document.getElementById("policyActionSteeringPercent").innerHTML = "<pre>" + temp_steering_string.padStart(7,' ') + "</pre>";
});

traxxas_current_esc_subscriber.subscribe(function(message)
{
	//console.log("Received message on " + traxxas_current_esc_subscriber.name + ", with (channel,pulse width) = ( " + message.channel + " , " + message.pulse_width_in_microseconds + " )" );

	document.getElementById("traxxasNodeCurrentESCCommand").innerHTML = "<pre>for channel " + String(message.channel).padStart(3,' ') + "; pulse width set to " + String(message.pulse_width_in_microseconds).padStart(4,' ') + " us)</pre>";
});

traxxas_current_steering_subscriber.subscribe(function(message)
{
	//console.log("Received message on " + traxxas_current_steering_subscriber.name + ", with (channel,pulse width) = ( " + message.channel + " , " + message.pulse_width_in_microseconds + " )" );

	document.getElementById("traxxasNodeCurrentSteeringCommand").innerHTML = "<pre>for channel " + String(message.channel).padStart(3,' ') + "; pulse width set to " + String(message.pulse_width_in_microseconds).padStart(4,' ') + " us)</pre>";
});
