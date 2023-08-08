// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ai4r_interfaces:msg/ServoPulseWidth.idl
// generated code does not contain a copyright notice
#include "ai4r_interfaces/msg/detail/servo_pulse_width__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ai4r_interfaces/msg/detail/servo_pulse_width__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ai4r_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ai4r_interfaces
cdr_serialize(
  const ai4r_interfaces::msg::ServoPulseWidth & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: channel
  cdr << ros_message.channel;
  // Member: pulse_width_in_microseconds
  cdr << ros_message.pulse_width_in_microseconds;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ai4r_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ai4r_interfaces::msg::ServoPulseWidth & ros_message)
{
  // Member: channel
  cdr >> ros_message.channel;

  // Member: pulse_width_in_microseconds
  cdr >> ros_message.pulse_width_in_microseconds;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ai4r_interfaces
get_serialized_size(
  const ai4r_interfaces::msg::ServoPulseWidth & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: channel
  {
    size_t item_size = sizeof(ros_message.channel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pulse_width_in_microseconds
  {
    size_t item_size = sizeof(ros_message.pulse_width_in_microseconds);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ai4r_interfaces
max_serialized_size_ServoPulseWidth(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: channel
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: pulse_width_in_microseconds
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  return current_alignment - initial_alignment;
}

static bool _ServoPulseWidth__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ai4r_interfaces::msg::ServoPulseWidth *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ServoPulseWidth__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ai4r_interfaces::msg::ServoPulseWidth *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ServoPulseWidth__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ai4r_interfaces::msg::ServoPulseWidth *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ServoPulseWidth__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ServoPulseWidth(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ServoPulseWidth__callbacks = {
  "ai4r_interfaces::msg",
  "ServoPulseWidth",
  _ServoPulseWidth__cdr_serialize,
  _ServoPulseWidth__cdr_deserialize,
  _ServoPulseWidth__get_serialized_size,
  _ServoPulseWidth__max_serialized_size
};

static rosidl_message_type_support_t _ServoPulseWidth__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ServoPulseWidth__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ai4r_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ai4r_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<ai4r_interfaces::msg::ServoPulseWidth>()
{
  return &ai4r_interfaces::msg::typesupport_fastrtps_cpp::_ServoPulseWidth__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ai4r_interfaces, msg, ServoPulseWidth)() {
  return &ai4r_interfaces::msg::typesupport_fastrtps_cpp::_ServoPulseWidth__handle;
}

#ifdef __cplusplus
}
#endif
