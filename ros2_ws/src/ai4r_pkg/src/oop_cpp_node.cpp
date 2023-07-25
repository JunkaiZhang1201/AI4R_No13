#include "rclcpp/rclcpp.hpp"

// Include any cpp header files here
#include "ai4r_pkg/cpp_header.hpp"

// Include any drivers here
#include "i2c_driver/i2c_driver.h"

// Create a class which inherits from rclcpp::Node which contains almost all ROS2 basic functionalities. 
// Any addition/change you’ll make to your node will be inside the MyNode class. The main function will stay the same.
class MyNode : public rclcpp::Node
{
public:
    // Constructor is a good place to initiate your node with a name and options. You will also define your publishers/subscribers/services here. The node’s name is now set in the constructor, but nothing prevents you from passing the name from the main if you want, and then use it.
    MyNode() : Node("my_node_name") 
    {
        // Initialize the timer with another inherited method: create_wall_timer(). We need to give 2 arguments: the duration between 2 callbacks, and the function to call. Here to pass the class method we have to use std::bind(). The callback will start being triggered when the node starts spinning.
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(200),
            std::bind(&MyNode::timerCallback, this));
    } 

    TestParams() : Node("test_params_rclcpp") {
        this->declare_parameter("my_str", rclcpp::PARAMETER_STRING);
        this->declare_parameter("my_int", rclcpp::PARAMETER_INTEGER);
        this->declare_parameter("my_double_array", rclcpp::PARAMETER_DOUBLE_ARRAY);
    }

private:
    // Add a callback for this timer. We make this method private since it will only be called from within the node class.
    void timerCallback()
    {
        // Print something on the screen. Use the inherited method get_logger() to get the node’s logger and all the settings that go with it
        RCLCPP_INFO(this->get_logger(), "Hello from ROS2");
    }

    rclcpp::TimerBase::SharedPtr timer_;    // Declare a ROS2 Timer object as a private attribute of the class
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>(); // Create an object of the custom class we wrote
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}