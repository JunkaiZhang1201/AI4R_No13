// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ai4r_interfaces:msg/TemplateMessage.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ai4r_interfaces/msg/detail/template_message__rosidl_typesupport_introspection_c.h"
#include "ai4r_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ai4r_interfaces/msg/detail/template_message__functions.h"
#include "ai4r_interfaces/msg/detail/template_message__struct.h"


// Include directives for member types
// Member `temp_string`
#include "rosidl_runtime_c/string_functions.h"
// Member `temp_float64_array`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__TemplateMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ai4r_interfaces__msg__TemplateMessage__init(message_memory);
}

void ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__TemplateMessage_fini_function(void * message_memory)
{
  ai4r_interfaces__msg__TemplateMessage__fini(message_memory);
}

size_t ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__size_function__TemplateMessage__temp_float64_array(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__get_const_function__TemplateMessage__temp_float64_array(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__get_function__TemplateMessage__temp_float64_array(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__fetch_function__TemplateMessage__temp_float64_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__get_const_function__TemplateMessage__temp_float64_array(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__assign_function__TemplateMessage__temp_float64_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__get_function__TemplateMessage__temp_float64_array(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__resize_function__TemplateMessage__temp_float64_array(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__TemplateMessage_message_member_array[7] = {
  {
    "temp_bool",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ai4r_interfaces__msg__TemplateMessage, temp_bool),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temp_uint32",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ai4r_interfaces__msg__TemplateMessage, temp_uint32),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temp_int32",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ai4r_interfaces__msg__TemplateMessage, temp_int32),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temp_float32",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ai4r_interfaces__msg__TemplateMessage, temp_float32),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temp_float64",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ai4r_interfaces__msg__TemplateMessage, temp_float64),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temp_string",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ai4r_interfaces__msg__TemplateMessage, temp_string),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temp_float64_array",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ai4r_interfaces__msg__TemplateMessage, temp_float64_array),  // bytes offset in struct
    NULL,  // default value
    ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__size_function__TemplateMessage__temp_float64_array,  // size() function pointer
    ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__get_const_function__TemplateMessage__temp_float64_array,  // get_const(index) function pointer
    ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__get_function__TemplateMessage__temp_float64_array,  // get(index) function pointer
    ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__fetch_function__TemplateMessage__temp_float64_array,  // fetch(index, &value) function pointer
    ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__assign_function__TemplateMessage__temp_float64_array,  // assign(index, value) function pointer
    ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__resize_function__TemplateMessage__temp_float64_array  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__TemplateMessage_message_members = {
  "ai4r_interfaces__msg",  // message namespace
  "TemplateMessage",  // message name
  7,  // number of fields
  sizeof(ai4r_interfaces__msg__TemplateMessage),
  ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__TemplateMessage_message_member_array,  // message members
  ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__TemplateMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__TemplateMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__TemplateMessage_message_type_support_handle = {
  0,
  &ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__TemplateMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ai4r_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ai4r_interfaces, msg, TemplateMessage)() {
  if (!ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__TemplateMessage_message_type_support_handle.typesupport_identifier) {
    ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__TemplateMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ai4r_interfaces__msg__TemplateMessage__rosidl_typesupport_introspection_c__TemplateMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
