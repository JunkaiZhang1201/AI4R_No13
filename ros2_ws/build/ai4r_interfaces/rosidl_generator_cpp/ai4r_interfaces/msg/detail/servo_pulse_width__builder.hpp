// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ai4r_interfaces:msg/ServoPulseWidth.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__SERVO_PULSE_WIDTH__BUILDER_HPP_
#define AI4R_INTERFACES__MSG__DETAIL__SERVO_PULSE_WIDTH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ai4r_interfaces/msg/detail/servo_pulse_width__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ai4r_interfaces
{

namespace msg
{

namespace builder
{

class Init_ServoPulseWidth_pulse_width_in_microseconds
{
public:
  explicit Init_ServoPulseWidth_pulse_width_in_microseconds(::ai4r_interfaces::msg::ServoPulseWidth & msg)
  : msg_(msg)
  {}
  ::ai4r_interfaces::msg::ServoPulseWidth pulse_width_in_microseconds(::ai4r_interfaces::msg::ServoPulseWidth::_pulse_width_in_microseconds_type arg)
  {
    msg_.pulse_width_in_microseconds = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ai4r_interfaces::msg::ServoPulseWidth msg_;
};

class Init_ServoPulseWidth_channel
{
public:
  Init_ServoPulseWidth_channel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ServoPulseWidth_pulse_width_in_microseconds channel(::ai4r_interfaces::msg::ServoPulseWidth::_channel_type arg)
  {
    msg_.channel = std::move(arg);
    return Init_ServoPulseWidth_pulse_width_in_microseconds(msg_);
  }

private:
  ::ai4r_interfaces::msg::ServoPulseWidth msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ai4r_interfaces::msg::ServoPulseWidth>()
{
  return ai4r_interfaces::msg::builder::Init_ServoPulseWidth_channel();
}

}  // namespace ai4r_interfaces

#endif  // AI4R_INTERFACES__MSG__DETAIL__SERVO_PULSE_WIDTH__BUILDER_HPP_
