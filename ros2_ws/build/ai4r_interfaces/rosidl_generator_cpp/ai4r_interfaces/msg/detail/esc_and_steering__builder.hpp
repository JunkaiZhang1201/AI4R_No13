// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ai4r_interfaces:msg/EscAndSteering.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__ESC_AND_STEERING__BUILDER_HPP_
#define AI4R_INTERFACES__MSG__DETAIL__ESC_AND_STEERING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ai4r_interfaces/msg/detail/esc_and_steering__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ai4r_interfaces
{

namespace msg
{

namespace builder
{

class Init_EscAndSteering_steering_percent
{
public:
  explicit Init_EscAndSteering_steering_percent(::ai4r_interfaces::msg::EscAndSteering & msg)
  : msg_(msg)
  {}
  ::ai4r_interfaces::msg::EscAndSteering steering_percent(::ai4r_interfaces::msg::EscAndSteering::_steering_percent_type arg)
  {
    msg_.steering_percent = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ai4r_interfaces::msg::EscAndSteering msg_;
};

class Init_EscAndSteering_esc_percent
{
public:
  Init_EscAndSteering_esc_percent()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EscAndSteering_steering_percent esc_percent(::ai4r_interfaces::msg::EscAndSteering::_esc_percent_type arg)
  {
    msg_.esc_percent = std::move(arg);
    return Init_EscAndSteering_steering_percent(msg_);
  }

private:
  ::ai4r_interfaces::msg::EscAndSteering msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ai4r_interfaces::msg::EscAndSteering>()
{
  return ai4r_interfaces::msg::builder::Init_EscAndSteering_esc_percent();
}

}  // namespace ai4r_interfaces

#endif  // AI4R_INTERFACES__MSG__DETAIL__ESC_AND_STEERING__BUILDER_HPP_
