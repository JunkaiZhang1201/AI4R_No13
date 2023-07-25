#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

# Import any python modules or libraries here
#from ai4r_pkg.module_to_import import 


# Create a class which inherits from the rclpy Node class. Each ROS2 Python node that you’ll write will be a superset of “rclpy.node.Node”.
class MyNode(Node):
    # Create publishers, subscribers, and other ROS2 functionalities in the constructor
    def __init__(self):
        super().__init__('my_node_name')    # Initialize the Node object, and we pass the node name to it.
        self.create_timer(0.2, self.timer_callback) # Create a timer with the create_timer() method from the inherited Node class. You have to pass 2 arguments: the duration between 2 callbacks (in seconds), and the timer function.

    # The timer_callback() method is part of the MyNode class.
    def timer_callback(self):
        self.get_logger().info("Hello ROS2")    # Use another inherited Node method: get_logger().info(). This will print a ROS2 log on the terminal.

def main(args=None):
    rclpy.init(args=args)
    node = MyNode() # Instantiate the custom node we’ve written
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()