// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ai4r_interfaces:msg/LeftRightInt32.idl
// generated code does not contain a copyright notice
#include "ai4r_interfaces/msg/detail/left_right_int32__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ai4r_interfaces/msg/detail/left_right_int32__struct.hpp"

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
  const ai4r_interfaces::msg::LeftRightInt32 & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: left
  cdr << ros_message.left;
  // Member: right
  cdr << ros_message.right;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ai4r_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ai4r_interfaces::msg::LeftRightInt32 & ros_message)
{
  // Member: left
  cdr >> ros_message.left;

  // Member: right
  cdr >> ros_message.right;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ai4r_interfaces
get_serialized_size(
  const ai4r_interfaces::msg::LeftRightInt32 & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: left
  {
    size_t item_size = sizeof(ros_message.left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right
  {
    size_t item_size = sizeof(ros_message.right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ai4r_interfaces
max_serialized_size_LeftRightInt32(
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


  // Member: left
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: right
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _LeftRightInt32__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ai4r_interfaces::msg::LeftRightInt32 *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LeftRightInt32__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ai4r_interfaces::msg::LeftRightInt32 *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LeftRightInt32__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ai4r_interfaces::msg::LeftRightInt32 *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LeftRightInt32__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_LeftRightInt32(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _LeftRightInt32__callbacks = {
  "ai4r_interfaces::msg",
  "LeftRightInt32",
  _LeftRightInt32__cdr_serialize,
  _LeftRightInt32__cdr_deserialize,
  _LeftRightInt32__get_serialized_size,
  _LeftRightInt32__max_serialized_size
};

static rosidl_message_type_support_t _LeftRightInt32__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LeftRightInt32__callbacks,
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
get_message_type_support_handle<ai4r_interfaces::msg::LeftRightInt32>()
{
  return &ai4r_interfaces::msg::typesupport_fastrtps_cpp::_LeftRightInt32__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ai4r_interfaces, msg, LeftRightInt32)() {
  return &ai4r_interfaces::msg::typesupport_fastrtps_cpp::_LeftRightInt32__handle;
}

#ifdef __cplusplus
}
#endif
