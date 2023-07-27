#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "ai4r_interfaces/msg/servo_pulse_width.hpp"                                       // CHANGE

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("servo_pulse_width_subscriber")
  {
    subscription_ = this->create_subscription<ai4r_interfaces::msg::ServoPulseWidth>(    // CHANGE
      "servo_pulse_width_topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
  }

private:
  void topic_callback(const ai4r_interfaces::msg::ServoPulseWidth & msg) const  // CHANGE
  {
    RCLCPP_INFO_STREAM(this->get_logger(), "I heard: '" << msg.channel << "' and '" << msg.pulse_width_in_microseconds << "'");     // CHANGE
  }
  rclcpp::Subscription<ai4r_interfaces::msg::ServoPulseWidth>::SharedPtr subscription_;  // CHANGE
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}