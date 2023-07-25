#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

# Import any python modules or libraries here
#from ai4r_pkg.module_to_import import 

def main(args=None):
    rclpy.init(args=args)
    node = Node('my_node_name')
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()