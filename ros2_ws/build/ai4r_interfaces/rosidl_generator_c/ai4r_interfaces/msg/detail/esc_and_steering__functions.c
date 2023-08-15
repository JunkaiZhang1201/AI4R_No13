// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ai4r_interfaces:msg/EscAndSteering.idl
// generated code does not contain a copyright notice
#include "ai4r_interfaces/msg/detail/esc_and_steering__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ai4r_interfaces__msg__EscAndSteering__init(ai4r_interfaces__msg__EscAndSteering * msg)
{
  if (!msg) {
    return false;
  }
  // esc_percent
  // steering_percent
  return true;
}

void
ai4r_interfaces__msg__EscAndSteering__fini(ai4r_interfaces__msg__EscAndSteering * msg)
{
  if (!msg) {
    return;
  }
  // esc_percent
  // steering_percent
}

bool
ai4r_interfaces__msg__EscAndSteering__are_equal(const ai4r_interfaces__msg__EscAndSteering * lhs, const ai4r_interfaces__msg__EscAndSteering * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // esc_percent
  if (lhs->esc_percent != rhs->esc_percent) {
    return false;
  }
  // steering_percent
  if (lhs->steering_percent != rhs->steering_percent) {
    return false;
  }
  return true;
}

bool
ai4r_interfaces__msg__EscAndSteering__copy(
  const ai4r_interfaces__msg__EscAndSteering * input,
  ai4r_interfaces__msg__EscAndSteering * output)
{
  if (!input || !output) {
    return false;
  }
  // esc_percent
  output->esc_percent = input->esc_percent;
  // steering_percent
  output->steering_percent = input->steering_percent;
  return true;
}

ai4r_interfaces__msg__EscAndSteering *
ai4r_interfaces__msg__EscAndSteering__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ai4r_interfaces__msg__EscAndSteering * msg = (ai4r_interfaces__msg__EscAndSteering *)allocator.allocate(sizeof(ai4r_interfaces__msg__EscAndSteering), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ai4r_interfaces__msg__EscAndSteering));
  bool success = ai4r_interfaces__msg__EscAndSteering__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ai4r_interfaces__msg__EscAndSteering__destroy(ai4r_interfaces__msg__EscAndSteering * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ai4r_interfaces__msg__EscAndSteering__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ai4r_interfaces__msg__EscAndSteering__Sequence__init(ai4r_interfaces__msg__EscAndSteering__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ai4r_interfaces__msg__EscAndSteering * data = NULL;

  if (size) {
    data = (ai4r_interfaces__msg__EscAndSteering *)allocator.zero_allocate(size, sizeof(ai4r_interfaces__msg__EscAndSteering), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ai4r_interfaces__msg__EscAndSteering__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ai4r_interfaces__msg__EscAndSteering__fini(&data[i - 1]);
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
ai4r_interfaces__msg__EscAndSteering__Sequence__fini(ai4r_interfaces__msg__EscAndSteering__Sequence * array)
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
      ai4r_interfaces__msg__EscAndSteering__fini(&array->data[i]);
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

ai4r_interfaces__msg__EscAndSteering__Sequence *
ai4r_interfaces__msg__EscAndSteering__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ai4r_interfaces__msg__EscAndSteering__Sequence * array = (ai4r_interfaces__msg__EscAndSteering__Sequence *)allocator.allocate(sizeof(ai4r_interfaces__msg__EscAndSteering__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ai4r_interfaces__msg__EscAndSteering__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ai4r_interfaces__msg__EscAndSteering__Sequence__destroy(ai4r_interfaces__msg__EscAndSteering__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ai4r_interfaces__msg__EscAndSteering__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ai4r_interfaces__msg__EscAndSteering__Sequence__are_equal(const ai4r_interfaces__msg__EscAndSteering__Sequence * lhs, const ai4r_interfaces__msg__EscAndSteering__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ai4r_interfaces__msg__EscAndSteering__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ai4r_interfaces__msg__EscAndSteering__Sequence__copy(
  const ai4r_interfaces__msg__EscAndSteering__Sequence * input,
  ai4r_interfaces__msg__EscAndSteering__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ai4r_interfaces__msg__EscAndSteering);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ai4r_interfaces__msg__EscAndSteering * data =
      (ai4r_interfaces__msg__EscAndSteering *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ai4r_interfaces__msg__EscAndSteering__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ai4r_interfaces__msg__EscAndSteering__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ai4r_interfaces__msg__EscAndSteering__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
