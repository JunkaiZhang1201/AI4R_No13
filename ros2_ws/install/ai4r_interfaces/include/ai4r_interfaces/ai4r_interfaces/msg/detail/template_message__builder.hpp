// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ai4r_interfaces:msg/TemplateMessage.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__TEMPLATE_MESSAGE__BUILDER_HPP_
#define AI4R_INTERFACES__MSG__DETAIL__TEMPLATE_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ai4r_interfaces/msg/detail/template_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ai4r_interfaces
{

namespace msg
{

namespace builder
{

class Init_TemplateMessage_temp_float64_array
{
public:
  explicit Init_TemplateMessage_temp_float64_array(::ai4r_interfaces::msg::TemplateMessage & msg)
  : msg_(msg)
  {}
  ::ai4r_interfaces::msg::TemplateMessage temp_float64_array(::ai4r_interfaces::msg::TemplateMessage::_temp_float64_array_type arg)
  {
    msg_.temp_float64_array = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ai4r_interfaces::msg::TemplateMessage msg_;
};

class Init_TemplateMessage_temp_string
{
public:
  explicit Init_TemplateMessage_temp_string(::ai4r_interfaces::msg::TemplateMessage & msg)
  : msg_(msg)
  {}
  Init_TemplateMessage_temp_float64_array temp_string(::ai4r_interfaces::msg::TemplateMessage::_temp_string_type arg)
  {
    msg_.temp_string = std::move(arg);
    return Init_TemplateMessage_temp_float64_array(msg_);
  }

private:
  ::ai4r_interfaces::msg::TemplateMessage msg_;
};

class Init_TemplateMessage_temp_float64
{
public:
  explicit Init_TemplateMessage_temp_float64(::ai4r_interfaces::msg::TemplateMessage & msg)
  : msg_(msg)
  {}
  Init_TemplateMessage_temp_string temp_float64(::ai4r_interfaces::msg::TemplateMessage::_temp_float64_type arg)
  {
    msg_.temp_float64 = std::move(arg);
    return Init_TemplateMessage_temp_string(msg_);
  }

private:
  ::ai4r_interfaces::msg::TemplateMessage msg_;
};

class Init_TemplateMessage_temp_float32
{
public:
  explicit Init_TemplateMessage_temp_float32(::ai4r_interfaces::msg::TemplateMessage & msg)
  : msg_(msg)
  {}
  Init_TemplateMessage_temp_float64 temp_float32(::ai4r_interfaces::msg::TemplateMessage::_temp_float32_type arg)
  {
    msg_.temp_float32 = std::move(arg);
    return Init_TemplateMessage_temp_float64(msg_);
  }

private:
  ::ai4r_interfaces::msg::TemplateMessage msg_;
};

class Init_TemplateMessage_temp_int32
{
public:
  explicit Init_TemplateMessage_temp_int32(::ai4r_interfaces::msg::TemplateMessage & msg)
  : msg_(msg)
  {}
  Init_TemplateMessage_temp_float32 temp_int32(::ai4r_interfaces::msg::TemplateMessage::_temp_int32_type arg)
  {
    msg_.temp_int32 = std::move(arg);
    return Init_TemplateMessage_temp_float32(msg_);
  }

private:
  ::ai4r_interfaces::msg::TemplateMessage msg_;
};

class Init_TemplateMessage_temp_uint32
{
public:
  explicit Init_TemplateMessage_temp_uint32(::ai4r_interfaces::msg::TemplateMessage & msg)
  : msg_(msg)
  {}
  Init_TemplateMessage_temp_int32 temp_uint32(::ai4r_interfaces::msg::TemplateMessage::_temp_uint32_type arg)
  {
    msg_.temp_uint32 = std::move(arg);
    return Init_TemplateMessage_temp_int32(msg_);
  }

private:
  ::ai4r_interfaces::msg::TemplateMessage msg_;
};

class Init_TemplateMessage_temp_bool
{
public:
  Init_TemplateMessage_temp_bool()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TemplateMessage_temp_uint32 temp_bool(::ai4r_interfaces::msg::TemplateMessage::_temp_bool_type arg)
  {
    msg_.temp_bool = std::move(arg);
    return Init_TemplateMessage_temp_uint32(msg_);
  }

private:
  ::ai4r_interfaces::msg::TemplateMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ai4r_interfaces::msg::TemplateMessage>()
{
  return ai4r_interfaces::msg::builder::Init_TemplateMessage_temp_bool();
}

}  // namespace ai4r_interfaces

#endif  // AI4R_INTERFACES__MSG__DETAIL__TEMPLATE_MESSAGE__BUILDER_HPP_
