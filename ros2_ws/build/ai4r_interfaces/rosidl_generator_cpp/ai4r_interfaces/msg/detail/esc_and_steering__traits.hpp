// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ai4r_interfaces:msg/EscAndSteering.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__ESC_AND_STEERING__TRAITS_HPP_
#define AI4R_INTERFACES__MSG__DETAIL__ESC_AND_STEERING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ai4r_interfaces/msg/detail/esc_and_steering__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ai4r_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const EscAndSteering & msg,
  std::ostream & out)
{
  out << "{";
  // member: esc_percent
  {
    out << "esc_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.esc_percent, out);
    out << ", ";
  }

  // member: steering_percent
  {
    out << "steering_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_percent, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EscAndSteering & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: esc_percent
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "esc_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.esc_percent, out);
    out << "\n";
  }

  // member: steering_percent
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steering_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_percent, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EscAndSteering & msg, bool use_flow_style = false)
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
  const ai4r_interfaces::msg::EscAndSteering & msg,
  std::ostream & out, size_t indentation = 0)
{
  ai4r_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ai4r_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ai4r_interfaces::msg::EscAndSteering & msg)
{
  return ai4r_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ai4r_interfaces::msg::EscAndSteering>()
{
  return "ai4r_interfaces::msg::EscAndSteering";
}

template<>
inline const char * name<ai4r_interfaces::msg::EscAndSteering>()
{
  return "ai4r_interfaces/msg/EscAndSteering";
}

template<>
struct has_fixed_size<ai4r_interfaces::msg::EscAndSteering>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ai4r_interfaces::msg::EscAndSteering>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ai4r_interfaces::msg::EscAndSteering>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AI4R_INTERFACES__MSG__DETAIL__ESC_AND_STEERING__TRAITS_HPP_
