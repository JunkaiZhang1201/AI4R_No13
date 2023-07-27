// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ai4r_interfaces:msg/ServoPulseWidth.idl
// generated code does not contain a copyright notice
#include "ai4r_interfaces/msg/detail/servo_pulse_width__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ai4r_interfaces__msg__ServoPulseWidth__init(ai4r_interfaces__msg__ServoPulseWidth * msg)
{
  if (!msg) {
    return false;
  }
  // channel
  // pulse_width_in_microseconds
  return true;
}

void
ai4r_interfaces__msg__ServoPulseWidth__fini(ai4r_interfaces__msg__ServoPulseWidth * msg)
{
  if (!msg) {
    return;
  }
  // channel
  // pulse_width_in_microseconds
}

bool
ai4r_interfaces__msg__ServoPulseWidth__are_equal(const ai4r_interfaces__msg__ServoPulseWidth * lhs, const ai4r_interfaces__msg__ServoPulseWidth * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // channel
  if (lhs->channel != rhs->channel) {
    return false;
  }
  // pulse_width_in_microseconds
  if (lhs->pulse_width_in_microseconds != rhs->pulse_width_in_microseconds) {
    return false;
  }
  return true;
}

bool
ai4r_interfaces__msg__ServoPulseWidth__copy(
  const ai4r_interfaces__msg__ServoPulseWidth * input,
  ai4r_interfaces__msg__ServoPulseWidth * output)
{
  if (!input || !output) {
    return false;
  }
  // channel
  output->channel = input->channel;
  // pulse_width_in_microseconds
  output->pulse_width_in_microseconds = input->pulse_width_in_microseconds;
  return true;
}

ai4r_interfaces__msg__ServoPulseWidth *
ai4r_interfaces__msg__ServoPulseWidth__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ai4r_interfaces__msg__ServoPulseWidth * msg = (ai4r_interfaces__msg__ServoPulseWidth *)allocator.allocate(sizeof(ai4r_interfaces__msg__ServoPulseWidth), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ai4r_interfaces__msg__ServoPulseWidth));
  bool success = ai4r_interfaces__msg__ServoPulseWidth__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ai4r_interfaces__msg__ServoPulseWidth__destroy(ai4r_interfaces__msg__ServoPulseWidth * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ai4r_interfaces__msg__ServoPulseWidth__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ai4r_interfaces__msg__ServoPulseWidth__Sequence__init(ai4r_interfaces__msg__ServoPulseWidth__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ai4r_interfaces__msg__ServoPulseWidth * data = NULL;

  if (size) {
    data = (ai4r_interfaces__msg__ServoPulseWidth *)allocator.zero_allocate(size, sizeof(ai4r_interfaces__msg__ServoPulseWidth), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ai4r_interfaces__msg__ServoPulseWidth__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ai4r_interfaces__msg__ServoPulseWidth__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ai4r_interfaces__msg__ServoPulseWidth__Sequence__fini(ai4r_interfaces__msg__ServoPulseWidth__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ai4r_interfaces__msg__ServoPulseWidth__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ai4r_interfaces__msg__ServoPulseWidth__Sequence *
ai4r_interfaces__msg__ServoPulseWidth__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ai4r_interfaces__msg__ServoPulseWidth__Sequence * array = (ai4r_interfaces__msg__ServoPulseWidth__Sequence *)allocator.allocate(sizeof(ai4r_interfaces__msg__ServoPulseWidth__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ai4r_interfaces__msg__ServoPulseWidth__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ai4r_interfaces__msg__ServoPulseWidth__Sequence__destroy(ai4r_interfaces__msg__ServoPulseWidth__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ai4r_interfaces__msg__ServoPulseWidth__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ai4r_interfaces__msg__ServoPulseWidth__Sequence__are_equal(const ai4r_interfaces__msg__ServoPulseWidth__Sequence * lhs, const ai4r_interfaces__msg__ServoPulseWidth__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ai4r_interfaces__msg__ServoPulseWidth__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ai4r_interfaces__msg__ServoPulseWidth__Sequence__copy(
  const ai4r_interfaces__msg__ServoPulseWidth__Sequence * input,
  ai4r_interfaces__msg__ServoPulseWidth__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ai4r_interfaces__msg__ServoPulseWidth);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ai4r_interfaces__msg__ServoPulseWidth * data =
      (ai4r_interfaces__msg__ServoPulseWidth *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ai4r_interfaces__msg__ServoPulseWidth__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ai4r_interfaces__msg__ServoPulseWidth__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ai4r_interfaces__msg__ServoPulseWidth__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
