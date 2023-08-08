// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ai4r_interfaces:msg/TemplateMessage.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__TEMPLATE_MESSAGE__STRUCT_H_
#define AI4R_INTERFACES__MSG__DETAIL__TEMPLATE_MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'temp_string'
#include "rosidl_runtime_c/string.h"
// Member 'temp_float64_array'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/TemplateMessage in the package ai4r_interfaces.
typedef struct ai4r_interfaces__msg__TemplateMessage
{
  bool temp_bool;
  uint32_t temp_uint32;
  int32_t temp_int32;
  float temp_float32;
  double temp_float64;
  rosidl_runtime_c__String temp_string;
  rosidl_runtime_c__double__Sequence temp_float64_array;
} ai4r_interfaces__msg__TemplateMessage;

// Struct for a sequence of ai4r_interfaces__msg__TemplateMessage.
typedef struct ai4r_interfaces__msg__TemplateMessage__Sequence
{
  ai4r_interfaces__msg__TemplateMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ai4r_interfaces__msg__TemplateMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AI4R_INTERFACES__MSG__DETAIL__TEMPLATE_MESSAGE__STRUCT_H_
