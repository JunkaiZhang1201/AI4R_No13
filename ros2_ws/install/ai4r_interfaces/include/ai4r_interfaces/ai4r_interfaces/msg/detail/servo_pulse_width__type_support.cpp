// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ai4r_interfaces:msg/ServoPulseWidth.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ai4r_interfaces/msg/detail/servo_pulse_width__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ai4r_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ServoPulseWidth_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ai4r_interfaces::msg::ServoPulseWidth(_init);
}

void ServoPulseWidth_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ai4r_interfaces::msg::ServoPulseWidth *>(message_memory);
  typed_message->~ServoPulseWidth();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ServoPulseWidth_message_member_array[2] = {
  {
    "channel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ai4r_interfaces::msg::ServoPulseWidth, channel),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pulse_width_in_microseconds",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ai4r_interfaces::msg::ServoPulseWidth, pulse_width_in_microseconds),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ServoPulseWidth_message_members = {
  "ai4r_interfaces::msg",  // message namespace
  "ServoPulseWidth",  // message name
  2,  // number of fields
  sizeof(ai4r_interfaces::msg::ServoPulseWidth),
  ServoPulseWidth_message_member_array,  // message members
  ServoPulseWidth_init_function,  // function to initialize message memory (memory has to be allocated)
  ServoPulseWidth_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ServoPulseWidth_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ServoPulseWidth_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ai4r_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ai4r_interfaces::msg::ServoPulseWidth>()
{
  return &::ai4r_interfaces::msg::rosidl_typesupport_introspection_cpp::ServoPulseWidth_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ai4r_interfaces, msg, ServoPulseWidth)() {
  return &::ai4r_interfaces::msg::rosidl_typesupport_introspection_cpp::ServoPulseWidth_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
