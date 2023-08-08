// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ai4r_interfaces:msg/LeftRightInt32.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__LEFT_RIGHT_INT32__STRUCT_H_
#define AI4R_INTERFACES__MSG__DETAIL__LEFT_RIGHT_INT32__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/LeftRightInt32 in the package ai4r_interfaces.
typedef struct ai4r_interfaces__msg__LeftRightInt32
{
  int32_t left;
  int32_t right;
} ai4r_interfaces__msg__LeftRightInt32;

// Struct for a sequence of ai4r_interfaces__msg__LeftRightInt32.
typedef struct ai4r_interfaces__msg__LeftRightInt32__Sequence
{
  ai4r_interfaces__msg__LeftRightInt32 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ai4r_interfaces__msg__LeftRightInt32__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AI4R_INTERFACES__MSG__DETAIL__LEFT_RIGHT_INT32__STRUCT_H_
