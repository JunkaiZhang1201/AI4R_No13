// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ai4r_interfaces:msg/LeftRightInt32.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__LEFT_RIGHT_INT32__BUILDER_HPP_
#define AI4R_INTERFACES__MSG__DETAIL__LEFT_RIGHT_INT32__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ai4r_interfaces/msg/detail/left_right_int32__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ai4r_interfaces
{

namespace msg
{

namespace builder
{

class Init_LeftRightInt32_right
{
public:
  explicit Init_LeftRightInt32_right(::ai4r_interfaces::msg::LeftRightInt32 & msg)
  : msg_(msg)
  {}
  ::ai4r_interfaces::msg::LeftRightInt32 right(::ai4r_interfaces::msg::LeftRightInt32::_right_type arg)
  {
    msg_.right = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ai4r_interfaces::msg::LeftRightInt32 msg_;
};

class Init_LeftRightInt32_left
{
public:
  Init_LeftRightInt32_left()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LeftRightInt32_right left(::ai4r_interfaces::msg::LeftRightInt32::_left_type arg)
  {
    msg_.left = std::move(arg);
    return Init_LeftRightInt32_right(msg_);
  }

private:
  ::ai4r_interfaces::msg::LeftRightInt32 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ai4r_interfaces::msg::LeftRightInt32>()
{
  return ai4r_interfaces::msg::builder::Init_LeftRightInt32_left();
}

}  // namespace ai4r_interfaces

#endif  // AI4R_INTERFACES__MSG__DETAIL__LEFT_RIGHT_INT32__BUILDER_HPP_
