// First we import the rclcpp library. From rclcpp we’ll be able to retrieve many of the ROS2 core functionalities: nodes, topics, services, etc.
#include "rclcpp/rclcpp.hpp"

#include <gpiod.h>


// Specify the chip name of the GPIO interface
const char * gpio_chip_name = "/dev/gpiochip0";
// Initialise a GPIO chip
struct gpiod_chip *chip;
// GPIO line number to monitor
int line_number = 22;


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

private:
    // Add a callback for this timer. We make this method private since it will only be called from within the node class.
    void timerCallback()
    {
        // Get the current value of the line
        // > Note: the third argument to "gpiod_ctxless_get_value"
        //   is an "active_low" boolean input argument.
        //   If true, this indicate to the function that active state
        //   of this line is low.
        int val;
        val = gpiod_ctxless_get_value(gpio_chip_name, line_number, false, "foobar");
        RCLCPP_INFO(this->get_logger(), "GPIO line value: '%d'\n", val);
    }

    rclcpp::TimerBase::SharedPtr timer_;    // Declare a ROS2 Timer object as a private attribute of the class
};

int main(int argc, char **argv)
{

    // Open GPIO chip
    chip = gpiod_chip_open(gpio_chip_name);

    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>(); // Create an object of the custom class we wrote
    rclcpp::spin(node);

    // Release chip
    gpiod_chip_close(chip);

    rclcpp::shutdown();

    return 0;
}