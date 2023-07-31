
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class PwmDriverNode : public rclcpp::Node {
public:
    PwmDriverNode() : Node("ros2_node") {
        publisher_ = this->create_publisher<std_msgs::msg::String>("topic_name", 10);
        subscriber_ = this->create_subscription<std_msgs::msg::String>(
            "topic_name", 10, std::bind(&PwmDriverNode::callback, this, std::placeholders::_1));
    }

    void run() {
        rclcpp::Rate loop_rate(10);
        int count = 0;
        while (rclcpp::ok()) {
            auto msg = std_msgs::msg::String();
            msg.data = "Hello ROS 2: " + std::to_string(count);
            publisher_->publish(msg);
            loop_rate.sleep();
            count++;
        }
    }

    void callback(const std_msgs::msg::String::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "ROS 2 Received: %s", msg->data.c_str());
    }

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PwmDriverNode>();
    node->run();
    rclcpp::spin(node); // Use rclcpp::spin() to handle callbacks.
    rclcpp::shutdown();
    return 0;
}