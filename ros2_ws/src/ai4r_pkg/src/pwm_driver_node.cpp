#include "rclcpp/rclcpp.hpp"
#include "your_package_name/msg/topic1_msg.hpp"
#include "your_package_name/msg/topic2_msg.hpp"

using namespace std::chrono_literals;

class MultipleSubPubNode : public rclcpp::Node {
public:
    MultipleSubPubNode() : Node("multiple_sub_pub_node") {
        // Subscribe to multiple topics
        topic1_sub_ = this->create_subscription<your_package_name::msg::Topic1Msg>(
            "topic1", rclcpp::QoS(10), std::bind(&MultipleSubPubNode::topic1Callback, this, std::placeholders::_1)
        );

        topic2_sub_ = this->create_subscription<your_package_name::msg::Topic2Msg>(
            "topic2", rclcpp::QoS(10), std::bind(&MultipleSubPubNode::topic2Callback, this, std::placeholders::_1)
        );

        // Publish to multiple topics
        topic3_pub_ = this->create_publisher<your_package_name::msg::Topic1Msg>("topic3", rclcpp::QoS(10));
        topic4_pub_ = this->create_publisher<your_package_name::msg::Topic2Msg>("topic4", rclcpp::QoS(10));

        // Perform any other initialization or setup here
    }

private:
    // Callback functions for subscribed topics
    void topic1Callback(const your_package_name::msg::Topic1Msg::SharedPtr msg) {
        // Process the received data from topic1 here
        // For example, you can publish some data to topic3
        your_package_name::msg::Topic1Msg data_to_publish;
        // ... Populate the 'data_to_publish' message with your data ...
        topic3_pub_->publish(data_to_publish);
    }

    void topic2Callback(const your_package_name::msg::Topic2Msg::SharedPtr msg) {
        // Process the received data from topic2 here
        // For example, you can publish some data to topic4
        your_package_name::msg::Topic2Msg data_to_publish;
        // ... Populate the 'data_to_publish' message with your data ...
        topic4_pub_->publish(data_to_publish);
    }

    // Subscriber and publisher objects
    rclcpp::Subscription<your_package_name::msg::Topic1Msg>::SharedPtr topic1_sub_;
    rclcpp::Subscription<your_package_name::msg::Topic2Msg>::SharedPtr topic2_sub_;
    rclcpp::Publisher<your_package_name::msg::Topic1Msg>::SharedPtr topic3_pub_;
    rclcpp::Publisher<your_package_name::msg::Topic2Msg>::SharedPtr topic4_pub_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MultipleSubPubNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
