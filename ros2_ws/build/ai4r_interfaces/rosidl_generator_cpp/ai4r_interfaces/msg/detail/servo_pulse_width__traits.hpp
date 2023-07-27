// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ai4r_interfaces:msg/ServoPulseWidth.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__SERVO_PULSE_WIDTH__TRAITS_HPP_
#define AI4R_INTERFACES__MSG__DETAIL__SERVO_PULSE_WIDTH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ai4r_interfaces/msg/detail/servo_pulse_width__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ai4r_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ServoPulseWidth & msg,
  std::ostream & out)
{
  out << "{";
  // member: channel
  {
    out << "channel: ";
    rosidl_generator_traits::value_to_yaml(msg.channel, out);
    out << ", ";
  }

  // member: pulse_width_in_microseconds
  {
    out << "pulse_width_in_microseconds: ";
    rosidl_generator_traits::value_to_yaml(msg.pulse_width_in_microseconds, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ServoPulseWidth & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: channel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "channel: ";
    rosidl_generator_traits::value_to_yaml(msg.channel, out);
    out << "\n";
  }

  // member: pulse_width_in_microseconds
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pulse_width_in_microseconds: ";
    rosidl_generator_traits::value_to_yaml(msg.pulse_width_in_microseconds, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ServoPulseWidth & msg, bool use_flow_style = false)
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
  const ai4r_interfaces::msg::ServoPulseWidth & msg,
  std::ostream & out, size_t indentation = 0)
{
  ai4r_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ai4r_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ai4r_interfaces::msg::ServoPulseWidth & msg)
{
  return ai4r_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ai4r_interfaces::msg::ServoPulseWidth>()
{
  return "ai4r_interfaces::msg::ServoPulseWidth";
}

template<>
inline const char * name<ai4r_interfaces::msg::ServoPulseWidth>()
{
  return "ai4r_interfaces/msg/ServoPulseWidth";
}

template<>
struct has_fixed_size<ai4r_interfaces::msg::ServoPulseWidth>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ai4r_interfaces::msg::ServoPulseWidth>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ai4r_interfaces::msg::ServoPulseWidth>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AI4R_INTERFACES__MSG__DETAIL__SERVO_PULSE_WIDTH__TRAITS_HPP_
