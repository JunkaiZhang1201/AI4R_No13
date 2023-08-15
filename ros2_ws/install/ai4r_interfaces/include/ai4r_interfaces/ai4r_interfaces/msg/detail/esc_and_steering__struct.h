// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ai4r_interfaces:msg/EscAndSteering.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__ESC_AND_STEERING__STRUCT_H_
#define AI4R_INTERFACES__MSG__DETAIL__ESC_AND_STEERING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/EscAndSteering in the package ai4r_interfaces.
typedef struct ai4r_interfaces__msg__EscAndSteering
{
  float esc_percent;
  float steering_percent;
} ai4r_interfaces__msg__EscAndSteering;

// Struct for a sequence of ai4r_interfaces__msg__EscAndSteering.
typedef struct ai4r_interfaces__msg__EscAndSteering__Sequence
{
  ai4r_interfaces__msg__EscAndSteering * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ai4r_interfaces__msg__EscAndSteering__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AI4R_INTERFACES__MSG__DETAIL__ESC_AND_STEERING__STRUCT_H_
