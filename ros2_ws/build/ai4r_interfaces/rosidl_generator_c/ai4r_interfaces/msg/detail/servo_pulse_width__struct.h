// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ai4r_interfaces:msg/ServoPulseWidth.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__SERVO_PULSE_WIDTH__STRUCT_H_
#define AI4R_INTERFACES__MSG__DETAIL__SERVO_PULSE_WIDTH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ServoPulseWidth in the package ai4r_interfaces.
typedef struct ai4r_interfaces__msg__ServoPulseWidth
{
  uint16_t channel;
  uint16_t pulse_width_in_microseconds;
} ai4r_interfaces__msg__ServoPulseWidth;

// Struct for a sequence of ai4r_interfaces__msg__ServoPulseWidth.
typedef struct ai4r_interfaces__msg__ServoPulseWidth__Sequence
{
  ai4r_interfaces__msg__ServoPulseWidth * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ai4r_interfaces__msg__ServoPulseWidth__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AI4R_INTERFACES__MSG__DETAIL__SERVO_PULSE_WIDTH__STRUCT_H_
