// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ai4r_interfaces:msg/TemplateMessage.idl
// generated code does not contain a copyright notice
#include "ai4r_interfaces/msg/detail/template_message__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ai4r_interfaces/msg/detail/template_message__struct.hpp"

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
  const ai4r_interfaces::msg::TemplateMessage & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: temp_bool
  cdr << (ros_message.temp_bool ? true : false);
  // Member: temp_uint32
  cdr << ros_message.temp_uint32;
  // Member: temp_int32
  cdr << ros_message.temp_int32;
  // Member: temp_float32
  cdr << ros_message.temp_float32;
  // Member: temp_float64
  cdr << ros_message.temp_float64;
  // Member: temp_string
  cdr << ros_message.temp_string;
  // Member: temp_float64_array
  {
    cdr << ros_message.temp_float64_array;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ai4r_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ai4r_interfaces::msg::TemplateMessage & ros_message)
{
  // Member: temp_bool
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.temp_bool = tmp ? true : false;
  }

  // Member: temp_uint32
  cdr >> ros_message.temp_uint32;

  // Member: temp_int32
  cdr >> ros_message.temp_int32;

  // Member: temp_float32
  cdr >> ros_message.temp_float32;

  // Member: temp_float64
  cdr >> ros_message.temp_float64;

  // Member: temp_string
  cdr >> ros_message.temp_string;

  // Member: temp_float64_array
  {
    cdr >> ros_message.temp_float64_array;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ai4r_interfaces
get_serialized_size(
  const ai4r_interfaces::msg::TemplateMessage & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: temp_bool
  {
    size_t item_size = sizeof(ros_message.temp_bool);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temp_uint32
  {
    size_t item_size = sizeof(ros_message.temp_uint32);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temp_int32
  {
    size_t item_size = sizeof(ros_message.temp_int32);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temp_float32
  {
    size_t item_size = sizeof(ros_message.temp_float32);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temp_float64
  {
    size_t item_size = sizeof(ros_message.temp_float64);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temp_string
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.temp_string.size() + 1);
  // Member: temp_float64_array
  {
    size_t array_size = ros_message.temp_float64_array.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.temp_float64_array[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ai4r_interfaces
max_serialized_size_TemplateMessage(
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


  // Member: temp_bool
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: temp_uint32
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: temp_int32
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: temp_float32
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: temp_float64
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: temp_string
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: temp_float64_array
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _TemplateMessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ai4r_interfaces::msg::TemplateMessage *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TemplateMessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ai4r_interfaces::msg::TemplateMessage *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TemplateMessage__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ai4r_interfaces::msg::TemplateMessage *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TemplateMessage__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_TemplateMessage(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _TemplateMessage__callbacks = {
  "ai4r_interfaces::msg",
  "TemplateMessage",
  _TemplateMessage__cdr_serialize,
  _TemplateMessage__cdr_deserialize,
  _TemplateMessage__get_serialized_size,
  _TemplateMessage__max_serialized_size
};

static rosidl_message_type_support_t _TemplateMessage__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TemplateMessage__callbacks,
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
get_message_type_support_handle<ai4r_interfaces::msg::TemplateMessage>()
{
  return &ai4r_interfaces::msg::typesupport_fastrtps_cpp::_TemplateMessage__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ai4r_interfaces, msg, TemplateMessage)() {
  return &ai4r_interfaces::msg::typesupport_fastrtps_cpp::_TemplateMessage__handle;
}

#ifdef __cplusplus
}
#endif
