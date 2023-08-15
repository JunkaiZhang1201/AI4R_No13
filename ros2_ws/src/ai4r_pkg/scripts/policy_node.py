#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from ai4r_interfaces.msg import IntArray, EscAndSteering
from std_msgs.msg import String, Int16
from rclpy.parameter import Parameter


# Import any python modules or libraries here
#from ai4r_pkg.module_to_import import function


FSM_STATE_NOT_PUBLISHING_ACTIONS   = 1
FSM_STATE_PUBLISHING_ZERO_ACTIONS  = 2
FSM_STATE_PUBLISHING_POLICY_ACTION = 3

LIST_OF_FSM_STATES = [FSM_STATE_NOT_PUBLISHING_ACTIONS, FSM_STATE_PUBLISHING_ZERO_ACTIONS, FSM_STATE_PUBLISHING_POLICY_ACTION]


# Create a class which inherits from the rclpy Node class (hence a superset of “rclpy.node.Node”).
class PolicyNode(Node):
    
    # CONSTRUCTOR FUNCTION
    def __init__(self):
        # Initialise the node object (passing the node name as an argument)
        super().__init__('policy_node')

        # Initialise the FSM state
        self.fsm_state = FSM_STATE_PUBLISHING_ZERO_ACTIONS

        # Initialise a counter for timing a lack of CV data
        self.counts_of_timer_without_cv_data_ = 0


        self.declare_parameters(
            namespace='',
            parameters=[
                ("timer_period", rclpy.Parameter.Type.DOUBLE),
                ("u_optical_centre", rclpy.Parameter.Type.DOUBLE),
                ("p_gain", rclpy.Parameter.Type.DOUBLE),
            ])
        self.timer_period = self.get_parameter_or("timer_period",Parameter("default_timer_period",Parameter.Type.DOUBLE,0.5))
        self.u_optical_centre = self.get_parameter_or("u_optical_centre",Parameter("default_u_optical_centre",Parameter.Type.DOUBLE,640))
        self.p_gain = self.get_parameter_or("p_gain",Parameter("default_p_gain",Parameter.Type.DOUBLE,0.1))



        # Create ROS2 publishers
        # > For publishing the FSM state
        self.fsm_state_publisher_ = self.create_publisher(String, '/policy_fsm_state', 10)
        # > For publishing the policy actions
        self.policy_action_publisher_ = self.create_publisher(EscAndSteering, '/esc_and_steering_set_point_percent', 10)

        # Create ROS2 subscribers
        # > For subscribing to the CV line detection data
        self.cv_subscription = self.create_subscription(IntArray, 'Image_Point', self.cv_line_dectection_callback, 10)
        # > For subscribing to requests to transition the state
        self.fsm_transition_request_subscription = self.create_subscription(Int16, 'policy_fsm_transition_request', self.fsm_transition_request_callback, 10)
        # > Prevent unused variable warning
        self.cv_subscription
        self.fsm_transition_request_subscription

        # Create a timer that is used for continually publishing the FSM state
        # > First argument is the duration between 2 callbacks (in seconds).
        # > Second argument is the callback function.
        self.create_timer(self.timer_period, self.timer_callback)



    # CALLBACK FUNCTION: for the CV line detection subscription 
    def cv_line_dectection_callback(self, msg):
        # Log the data received for debugging purposes:
        self.get_logger().info("[CONTROLLER NODE] Line detection points: \"%s\"" % msg.data)

        # List of image coordinates
        list_of_coords = msg.data

        # Set the counter to zero
        self.counts_of_timer_without_cv_data_ = 0

        # Run the control policy
        # > Set the ESC to a fixed value
        esc_action = 30
        # > Compute the average x of the line dection points
        steering_action = 0
        if (len(list_of_coords) > 0):
            # Extract the first elements 
            u_coords = [tup[0] for tup in list_of_coords]
            # Calculate the average 
            u_average = sum(u_coords) / len(u_coords)
            # Set the steering action. Possibly needs to be negative depending on steering convention.
            steering_action = self.p_gain*(u_average - self.u_optical_centre) 


        # Prepare the message to send
        msg = EscAndSteering()
        msg.esc_percent = esc_action
        msg.steering_percent = steering_action

        # Publish the message
        self.policy_action_publisher_.publish(msg)

        # Log the string published for debugging purposes:
        self.get_logger().info("[CONTROLLER NODE] Published esc action = " + str(esc_action) + ", steering action = " + str(steering_action))



    # CALLBACK FUNCTION: for the FSM state transition request
    def fsm_transition_request_callback(self, msg):
        # Extract the requests FSM state from the message
        requested_state = msg.data

        # Check that the requested state is valid
        if requested_state not in LIST_OF_FSM_STATES:
            # Log that this occurred
            self.get_logger().info("[CONTROLLER NODE] Received request to transition to an invalid state, requested_state = " + str(requested_state))

        # Transition the state
        self.fsm_state = requested_state

        # Log the data received for debugging purposes:
        self.get_logger().info("[CONTROLLER NODE] Received request to transtion to FSM state: " + str(msg.data))



    # CALLBACK FUNCTION: for the timer
    def timer_callback(self):
        # Convert the FSM state to a string
        state_as_string = "Unknown state"

        if (self.fsm_state == FSM_STATE_NOT_PUBLISHING_ACTIONS):
            state_as_string = "Not publishing action"
        elif (self.fsm_state == FSM_STATE_PUBLISHING_POLICY_ACTION):
            state_as_string = "Publishing policy action"
        elif (self.fsm_state == FSM_STATE_PUBLISHING_ZERO_ACTIONS):
            state_as_string = "Publishing zero actions"


        # Append to the string if "too" long since last CV data
        if (self.counts_of_timer_without_cv_data_ > 10):
            time_since_last = self.counts_of_timer_without_cv_data_ * self.timer_period
            state_as_string = state_as_string + " (" + str(time_since_last) + " seconds since last CV line detection data)"

        # Prepare the message to send
        msg = String()
        msg.data = state_as_string

        # Publish the message
        self.fsm_state_publisher_.publish(msg)

        # Log the string published for debugging purposes:
        self.get_logger().info("[CONTROLLER NODE] Published FSM state = " + state_as_string)

        # Increment the counter
        self.counts_of_timer_without_cv_data_ = self.counts_of_timer_without_cv_data_ + 1



def main(args=None):
    # Initialise ROS2 for this script
    rclpy.init(args=args)
    # Start as instance of the PolicyNode class
    node = PolicyNode()
    # Enter a ROS2 spin
    rclpy.spin(node)
    # Shutdown the nodes in this script
    rclpy.shutdown()

if __name__ == '__main__':
    main()
