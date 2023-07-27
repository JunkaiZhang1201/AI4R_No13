// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ai4r_interfaces:msg/TemplateMessage.idl
// generated code does not contain a copyright notice
#include "ai4r_interfaces/msg/detail/template_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `temp_string`
#include "rosidl_runtime_c/string_functions.h"
// Member `temp_float64_array`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
ai4r_interfaces__msg__TemplateMessage__init(ai4r_interfaces__msg__TemplateMessage * msg)
{
  if (!msg) {
    return false;
  }
  // temp_bool
  // temp_uint32
  // temp_int32
  // temp_float32
  // temp_float64
  // temp_string
  if (!rosidl_runtime_c__String__init(&msg->temp_string)) {
    ai4r_interfaces__msg__TemplateMessage__fini(msg);
    return false;
  }
  // temp_float64_array
  if (!rosidl_runtime_c__double__Sequence__init(&msg->temp_float64_array, 0)) {
    ai4r_interfaces__msg__TemplateMessage__fini(msg);
    return false;
  }
  return true;
}

void
ai4r_interfaces__msg__TemplateMessage__fini(ai4r_interfaces__msg__TemplateMessage * msg)
{
  if (!msg) {
    return;
  }
  // temp_bool
  // temp_uint32
  // temp_int32
  // temp_float32
  // temp_float64
  // temp_string
  rosidl_runtime_c__String__fini(&msg->temp_string);
  // temp_float64_array
  rosidl_runtime_c__double__Sequence__fini(&msg->temp_float64_array);
}

bool
ai4r_interfaces__msg__TemplateMessage__are_equal(const ai4r_interfaces__msg__TemplateMessage * lhs, const ai4r_interfaces__msg__TemplateMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // temp_bool
  if (lhs->temp_bool != rhs->temp_bool) {
    return false;
  }
  // temp_uint32
  if (lhs->temp_uint32 != rhs->temp_uint32) {
    return false;
  }
  // temp_int32
  if (lhs->temp_int32 != rhs->temp_int32) {
    return false;
  }
  // temp_float32
  if (lhs->temp_float32 != rhs->temp_float32) {
    return false;
  }
  // temp_float64
  if (lhs->temp_float64 != rhs->temp_float64) {
    return false;
  }
  // temp_string
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->temp_string), &(rhs->temp_string)))
  {
    return false;
  }
  // temp_float64_array
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->temp_float64_array), &(rhs->temp_float64_array)))
  {
    return false;
  }
  return true;
}

bool
ai4r_interfaces__msg__TemplateMessage__copy(
  const ai4r_interfaces__msg__TemplateMessage * input,
  ai4r_interfaces__msg__TemplateMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // temp_bool
  output->temp_bool = input->temp_bool;
  // temp_uint32
  output->temp_uint32 = input->temp_uint32;
  // temp_int32
  output->temp_int32 = input->temp_int32;
  // temp_float32
  output->temp_float32 = input->temp_float32;
  // temp_float64
  output->temp_float64 = input->temp_float64;
  // temp_string
  if (!rosidl_runtime_c__String__copy(
      &(input->temp_string), &(output->temp_string)))
  {
    return false;
  }
  // temp_float64_array
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->temp_float64_array), &(output->temp_float64_array)))
  {
    return false;
  }
  return true;
}

ai4r_interfaces__msg__TemplateMessage *
ai4r_interfaces__msg__TemplateMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ai4r_interfaces__msg__TemplateMessage * msg = (ai4r_interfaces__msg__TemplateMessage *)allocator.allocate(sizeof(ai4r_interfaces__msg__TemplateMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ai4r_interfaces__msg__TemplateMessage));
  bool success = ai4r_interfaces__msg__TemplateMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ai4r_interfaces__msg__TemplateMessage__destroy(ai4r_interfaces__msg__TemplateMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ai4r_interfaces__msg__TemplateMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ai4r_interfaces__msg__TemplateMessage__Sequence__init(ai4r_interfaces__msg__TemplateMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ai4r_interfaces__msg__TemplateMessage * data = NULL;

  if (size) {
    data = (ai4r_interfaces__msg__TemplateMessage *)allocator.zero_allocate(size, sizeof(ai4r_interfaces__msg__TemplateMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ai4r_interfaces__msg__TemplateMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ai4r_interfaces__msg__TemplateMessage__fini(&data[i - 1]);
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
ai4r_interfaces__msg__TemplateMessage__Sequence__fini(ai4r_interfaces__msg__TemplateMessage__Sequence * array)
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
      ai4r_interfaces__msg__TemplateMessage__fini(&array->data[i]);
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

ai4r_interfaces__msg__TemplateMessage__Sequence *
ai4r_interfaces__msg__TemplateMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ai4r_interfaces__msg__TemplateMessage__Sequence * array = (ai4r_interfaces__msg__TemplateMessage__Sequence *)allocator.allocate(sizeof(ai4r_interfaces__msg__TemplateMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ai4r_interfaces__msg__TemplateMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ai4r_interfaces__msg__TemplateMessage__Sequence__destroy(ai4r_interfaces__msg__TemplateMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ai4r_interfaces__msg__TemplateMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ai4r_interfaces__msg__TemplateMessage__Sequence__are_equal(const ai4r_interfaces__msg__TemplateMessage__Sequence * lhs, const ai4r_interfaces__msg__TemplateMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ai4r_interfaces__msg__TemplateMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ai4r_interfaces__msg__TemplateMessage__Sequence__copy(
  const ai4r_interfaces__msg__TemplateMessage__Sequence * input,
  ai4r_interfaces__msg__TemplateMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ai4r_interfaces__msg__TemplateMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ai4r_interfaces__msg__TemplateMessage * data =
      (ai4r_interfaces__msg__TemplateMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ai4r_interfaces__msg__TemplateMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ai4r_interfaces__msg__TemplateMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ai4r_interfaces__msg__TemplateMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
