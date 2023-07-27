// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ai4r_interfaces:msg/TemplateMessage.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__TEMPLATE_MESSAGE__TRAITS_HPP_
#define AI4R_INTERFACES__MSG__DETAIL__TEMPLATE_MESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ai4r_interfaces/msg/detail/template_message__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ai4r_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TemplateMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: temp_bool
  {
    out << "temp_bool: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_bool, out);
    out << ", ";
  }

  // member: temp_uint32
  {
    out << "temp_uint32: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_uint32, out);
    out << ", ";
  }

  // member: temp_int32
  {
    out << "temp_int32: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_int32, out);
    out << ", ";
  }

  // member: temp_float32
  {
    out << "temp_float32: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_float32, out);
    out << ", ";
  }

  // member: temp_float64
  {
    out << "temp_float64: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_float64, out);
    out << ", ";
  }

  // member: temp_string
  {
    out << "temp_string: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_string, out);
    out << ", ";
  }

  // member: temp_float64_array
  {
    if (msg.temp_float64_array.size() == 0) {
      out << "temp_float64_array: []";
    } else {
      out << "temp_float64_array: [";
      size_t pending_items = msg.temp_float64_array.size();
      for (auto item : msg.temp_float64_array) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TemplateMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: temp_bool
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temp_bool: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_bool, out);
    out << "\n";
  }

  // member: temp_uint32
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temp_uint32: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_uint32, out);
    out << "\n";
  }

  // member: temp_int32
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temp_int32: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_int32, out);
    out << "\n";
  }

  // member: temp_float32
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temp_float32: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_float32, out);
    out << "\n";
  }

  // member: temp_float64
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temp_float64: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_float64, out);
    out << "\n";
  }

  // member: temp_string
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temp_string: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_string, out);
    out << "\n";
  }

  // member: temp_float64_array
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.temp_float64_array.size() == 0) {
      out << "temp_float64_array: []\n";
    } else {
      out << "temp_float64_array:\n";
      for (auto item : msg.temp_float64_array) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TemplateMessage & msg, bool use_flow_style = false)
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
  const ai4r_interfaces::msg::TemplateMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  ai4r_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ai4r_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ai4r_interfaces::msg::TemplateMessage & msg)
{
  return ai4r_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ai4r_interfaces::msg::TemplateMessage>()
{
  return "ai4r_interfaces::msg::TemplateMessage";
}

template<>
inline const char * name<ai4r_interfaces::msg::TemplateMessage>()
{
  return "ai4r_interfaces/msg/TemplateMessage";
}

template<>
struct has_fixed_size<ai4r_interfaces::msg::TemplateMessage>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ai4r_interfaces::msg::TemplateMessage>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ai4r_interfaces::msg::TemplateMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AI4R_INTERFACES__MSG__DETAIL__TEMPLATE_MESSAGE__TRAITS_HPP_
