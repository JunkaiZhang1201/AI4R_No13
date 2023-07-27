// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ai4r_interfaces:msg/TemplateMessage.idl
// generated code does not contain a copyright notice
#include "ai4r_interfaces/msg/detail/template_message__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ai4r_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ai4r_interfaces/msg/detail/template_message__struct.h"
#include "ai4r_interfaces/msg/detail/template_message__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // temp_float64_array
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // temp_float64_array
#include "rosidl_runtime_c/string.h"  // temp_string
#include "rosidl_runtime_c/string_functions.h"  // temp_string

// forward declare type support functions


using _TemplateMessage__ros_msg_type = ai4r_interfaces__msg__TemplateMessage;

static bool _TemplateMessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TemplateMessage__ros_msg_type * ros_message = static_cast<const _TemplateMessage__ros_msg_type *>(untyped_ros_message);
  // Field name: temp_bool
  {
    cdr << (ros_message->temp_bool ? true : false);
  }

  // Field name: temp_uint32
  {
    cdr << ros_message->temp_uint32;
  }

  // Field name: temp_int32
  {
    cdr << ros_message->temp_int32;
  }

  // Field name: temp_float32
  {
    cdr << ros_message->temp_float32;
  }

  // Field name: temp_float64
  {
    cdr << ros_message->temp_float64;
  }

  // Field name: temp_string
  {
    const rosidl_runtime_c__String * str = &ros_message->temp_string;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: temp_float64_array
  {
    size_t size = ros_message->temp_float64_array.size;
    auto array_ptr = ros_message->temp_float64_array.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _TemplateMessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TemplateMessage__ros_msg_type * ros_message = static_cast<_TemplateMessage__ros_msg_type *>(untyped_ros_message);
  // Field name: temp_bool
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->temp_bool = tmp ? true : false;
  }

  // Field name: temp_uint32
  {
    cdr >> ros_message->temp_uint32;
  }

  // Field name: temp_int32
  {
    cdr >> ros_message->temp_int32;
  }

  // Field name: temp_float32
  {
    cdr >> ros_message->temp_float32;
  }

  // Field name: temp_float64
  {
    cdr >> ros_message->temp_float64;
  }

  // Field name: temp_string
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->temp_string.data) {
      rosidl_runtime_c__String__init(&ros_message->temp_string);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->temp_string,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'temp_string'\n");
      return false;
    }
  }

  // Field name: temp_float64_array
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->temp_float64_array.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->temp_float64_array);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->temp_float64_array, size)) {
      fprintf(stderr, "failed to create array for field 'temp_float64_array'");
      return false;
    }
    auto array_ptr = ros_message->temp_float64_array.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ai4r_interfaces
size_t get_serialized_size_ai4r_interfaces__msg__TemplateMessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TemplateMessage__ros_msg_type * ros_message = static_cast<const _TemplateMessage__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name temp_bool
  {
    size_t item_size = sizeof(ros_message->temp_bool);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name temp_uint32
  {
    size_t item_size = sizeof(ros_message->temp_uint32);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name temp_int32
  {
    size_t item_size = sizeof(ros_message->temp_int32);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name temp_float32
  {
    size_t item_size = sizeof(ros_message->temp_float32);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name temp_float64
  {
    size_t item_size = sizeof(ros_message->temp_float64);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name temp_string
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->temp_string.size + 1);
  // field.name temp_float64_array
  {
    size_t array_size = ros_message->temp_float64_array.size;
    auto array_ptr = ros_message->temp_float64_array.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _TemplateMessage__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ai4r_interfaces__msg__TemplateMessage(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ai4r_interfaces
size_t max_serialized_size_ai4r_interfaces__msg__TemplateMessage(
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

  // member: temp_bool
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: temp_uint32
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: temp_int32
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: temp_float32
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: temp_float64
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: temp_string
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
  // member: temp_float64_array
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

static size_t _TemplateMessage__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ai4r_interfaces__msg__TemplateMessage(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TemplateMessage = {
  "ai4r_interfaces::msg",
  "TemplateMessage",
  _TemplateMessage__cdr_serialize,
  _TemplateMessage__cdr_deserialize,
  _TemplateMessage__get_serialized_size,
  _TemplateMessage__max_serialized_size
};

static rosidl_message_type_support_t _TemplateMessage__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TemplateMessage,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ai4r_interfaces, msg, TemplateMessage)() {
  return &_TemplateMessage__type_support;
}

#if defined(__cplusplus)
}
#endif
