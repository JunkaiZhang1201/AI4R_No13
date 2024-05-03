// First we import the rclcpp library. From rclcpp we’ll be able to retrieve many of the ROS2 core functionalities: nodes, topics, services, etc.
#include "rclcpp/rclcpp.hpp"

// Include any cpp header files here
#include "ai4r_pkg/cpp_header.hpp"

// Include any drivers here
#include "i2c_driver/i2c_driver.h"


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);   // The first thing we do is to initiate ROS2 communications before you create any node
    auto node = std::make_shared<rclcpp::Node>("my_node_name"); // Create an rclcpp::Node object. Because the node is stored in a smart pointer, you don’t need to worry about de-allocating its resources.
    rclcpp::spin(node); // Pause the program here and keep the node alive and allow all defined callback functions to be called.
    rclcpp::shutdown(); // After you’ve killed the node, this is what gets executed. 
    return 0;
}
