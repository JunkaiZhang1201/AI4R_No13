// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ai4r_interfaces:msg/LeftRightInt32.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__LEFT_RIGHT_INT32__TRAITS_HPP_
#define AI4R_INTERFACES__MSG__DETAIL__LEFT_RIGHT_INT32__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ai4r_interfaces/msg/detail/left_right_int32__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ai4r_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const LeftRightInt32 & msg,
  std::ostream & out)
{
  out << "{";
  // member: left
  {
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << ", ";
  }

  // member: right
  {
    out << "right: ";
    rosidl_generator_traits::value_to_yaml(msg.right, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LeftRightInt32 & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << "\n";
  }

  // member: right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right: ";
    rosidl_generator_traits::value_to_yaml(msg.right, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LeftRightInt32 & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ai4r_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ai4r_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ai4r_interfaces::msg::LeftRightInt32 & msg,
  std::ostream & out, size_t indentation = 0)
{
  ai4r_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ai4r_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ai4r_interfaces::msg::LeftRightInt32 & msg)
{
  return ai4r_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ai4r_interfaces::msg::LeftRightInt32>()
{
  return "ai4r_interfaces::msg::LeftRightInt32";
}

template<>
inline const char * name<ai4r_interfaces::msg::LeftRightInt32>()
{
  return "ai4r_interfaces/msg/LeftRightInt32";
}

template<>
struct has_fixed_size<ai4r_interfaces::msg::LeftRightInt32>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ai4r_interfaces::msg::LeftRightInt32>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ai4r_interfaces::msg::LeftRightInt32>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AI4R_INTERFACES__MSG__DETAIL__LEFT_RIGHT_INT32__TRAITS_HPP_
