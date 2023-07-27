// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ai4r_interfaces:msg/ServoPulseWidth.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__SERVO_PULSE_WIDTH__STRUCT_HPP_
#define AI4R_INTERFACES__MSG__DETAIL__SERVO_PULSE_WIDTH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ai4r_interfaces__msg__ServoPulseWidth __attribute__((deprecated))
#else
# define DEPRECATED__ai4r_interfaces__msg__ServoPulseWidth __declspec(deprecated)
#endif

namespace ai4r_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ServoPulseWidth_
{
  using Type = ServoPulseWidth_<ContainerAllocator>;

  explicit ServoPulseWidth_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->channel = 0;
      this->pulse_width_in_microseconds = 0;
    }
  }

  explicit ServoPulseWidth_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->channel = 0;
      this->pulse_width_in_microseconds = 0;
    }
  }

  // field types and members
  using _channel_type =
    uint16_t;
  _channel_type channel;
  using _pulse_width_in_microseconds_type =
    uint16_t;
  _pulse_width_in_microseconds_type pulse_width_in_microseconds;

  // setters for named parameter idiom
  Type & set__channel(
    const uint16_t & _arg)
  {
    this->channel = _arg;
    return *this;
  }
  Type & set__pulse_width_in_microseconds(
    const uint16_t & _arg)
  {
    this->pulse_width_in_microseconds = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ai4r_interfaces::msg::ServoPulseWidth_<ContainerAllocator> *;
  using ConstRawPtr =
    const ai4r_interfaces::msg::ServoPulseWidth_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ai4r_interfaces::msg::ServoPulseWidth_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ai4r_interfaces::msg::ServoPulseWidth_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ai4r_interfaces::msg::ServoPulseWidth_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ai4r_interfaces::msg::ServoPulseWidth_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ai4r_interfaces::msg::ServoPulseWidth_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ai4r_interfaces::msg::ServoPulseWidth_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ai4r_interfaces::msg::ServoPulseWidth_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ai4r_interfaces::msg::ServoPulseWidth_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ai4r_interfaces__msg__ServoPulseWidth
    std::shared_ptr<ai4r_interfaces::msg::ServoPulseWidth_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ai4r_interfaces__msg__ServoPulseWidth
    std::shared_ptr<ai4r_interfaces::msg::ServoPulseWidth_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ServoPulseWidth_ & other) const
  {
    if (this->channel != other.channel) {
      return false;
    }
    if (this->pulse_width_in_microseconds != other.pulse_width_in_microseconds) {
      return false;
    }
    return true;
  }
  bool operator!=(const ServoPulseWidth_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ServoPulseWidth_

// alias to use template instance with default allocator
using ServoPulseWidth =
  ai4r_interfaces::msg::ServoPulseWidth_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ai4r_interfaces

#endif  // AI4R_INTERFACES__MSG__DETAIL__SERVO_PULSE_WIDTH__STRUCT_HPP_
