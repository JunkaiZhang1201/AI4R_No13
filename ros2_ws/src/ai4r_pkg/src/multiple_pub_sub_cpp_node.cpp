//             _____MultipleSubPubNode____
//            |                           |
// topic1 ----+--> ServoPulseWidth.msg ---+---> topic3
//            |                           |
// topic2 ----+-->        UInt16       ---+---> topic4
//            |___________________________|

#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "ai4r_interfaces/msg/servo_pulse_width.hpp"
#include "std_msgs/msg/u_int16.hpp"
#include "std_msgs/msg/float32.hpp"  

//using namespace std::chrono_literals;

class MultipleSubPubNode : public rclcpp::Node 
{
    public:
        MultipleSubPubNode() : Node("multiple_sub_pub_node") {
            // Subscribe to multiple topics
            topic1_sub_ = this->create_subscription<ai4r_interfaces::msg::ServoPulseWidth>(
                "topic1", rclcpp::QoS(10), std::bind(&MultipleSubPubNode::topic1Callback, this, std::placeholders::_1)
            );

            topic2_sub_ = this->create_subscription<std_msgs::msg::UInt16>(
                "topic2", rclcpp::QoS(10), std::bind(&MultipleSubPubNode::topic2Callback, this, std::placeholders::_1)
            );

            // Publish to multiple topics
            topic3_pub_ = this->create_publisher<ai4r_interfaces::msg::ServoPulseWidth>("topic3", rclcpp::QoS(10));
            topic4_pub_ = this->create_publisher<std_msgs::msg::UInt16>("topic4", rclcpp::QoS(10));

            // Perform any other initialization or setup here
        }

    private:
        // Callback functions for subscribed topics
        //void topic1Callback(const ai4r_interfaces::msg::ServoPulseWidth::SharedPtr msg) {
        void topic1Callback(const ai4r_interfaces::msg::ServoPulseWidth & msg) {
            // Process the received data from topic1 here
            // For example, you can publish some data to topic3
            //ai4r_interfaces::msg::ServoPulseWidth data_to_publish;
            // ... Populate the 'data_to_publish' message with your data ...
            topic3_pub_->publish(msg);
        }

        //void topic2Callback(const std_msgs::msg::UInt16::SharedPtr msg) {
        void topic2Callback(const std_msgs::msg::UInt16 & msg) {
            // Process the received data from topic2 here
            // For example, you can publish some data to topic4
            //std_msgs::msg::UInt16 data_to_publish;
            // ... Populate the 'data_to_publish' message with your data ...
            topic4_pub_->publish(msg);
        }

        // Subscriber and publisher objects
        rclcpp::Subscription<ai4r_interfaces::msg::ServoPulseWidth>::SharedPtr topic1_sub_;
        rclcpp::Subscription<std_msgs::msg::UInt16>::SharedPtr topic2_sub_;
        rclcpp::Publisher<ai4r_interfaces::msg::ServoPulseWidth>::SharedPtr topic3_pub_;
        rclcpp::Publisher<std_msgs::msg::UInt16>::SharedPtr topic4_pub_;
};

int main(int argc, char **argv) 
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MultipleSubPubNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
