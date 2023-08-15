// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ai4r_interfaces:msg/EscAndSteering.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ai4r_interfaces/msg/detail/esc_and_steering__struct.hpp"
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

void EscAndSteering_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ai4r_interfaces::msg::EscAndSteering(_init);
}

void EscAndSteering_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ai4r_interfaces::msg::EscAndSteering *>(message_memory);
  typed_message->~EscAndSteering();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember EscAndSteering_message_member_array[2] = {
  {
    "esc_percent",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ai4r_interfaces::msg::EscAndSteering, esc_percent),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "steering_percent",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ai4r_interfaces::msg::EscAndSteering, steering_percent),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers EscAndSteering_message_members = {
  "ai4r_interfaces::msg",  // message namespace
  "EscAndSteering",  // message name
  2,  // number of fields
  sizeof(ai4r_interfaces::msg::EscAndSteering),
  EscAndSteering_message_member_array,  // message members
  EscAndSteering_init_function,  // function to initialize message memory (memory has to be allocated)
  EscAndSteering_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t EscAndSteering_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &EscAndSteering_message_members,
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
get_message_type_support_handle<ai4r_interfaces::msg::EscAndSteering>()
{
  return &::ai4r_interfaces::msg::rosidl_typesupport_introspection_cpp::EscAndSteering_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ai4r_interfaces, msg, EscAndSteering)() {
  return &::ai4r_interfaces::msg::rosidl_typesupport_introspection_cpp::EscAndSteering_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
