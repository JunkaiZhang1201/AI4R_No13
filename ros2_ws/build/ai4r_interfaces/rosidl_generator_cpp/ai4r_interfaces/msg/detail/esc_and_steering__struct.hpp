// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ai4r_interfaces:msg/EscAndSteering.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__ESC_AND_STEERING__STRUCT_HPP_
#define AI4R_INTERFACES__MSG__DETAIL__ESC_AND_STEERING__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ai4r_interfaces__msg__EscAndSteering __attribute__((deprecated))
#else
# define DEPRECATED__ai4r_interfaces__msg__EscAndSteering __declspec(deprecated)
#endif

namespace ai4r_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EscAndSteering_
{
  using Type = EscAndSteering_<ContainerAllocator>;

  explicit EscAndSteering_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->esc_percent = 0.0f;
      this->steering_percent = 0.0f;
    }
  }

  explicit EscAndSteering_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->esc_percent = 0.0f;
      this->steering_percent = 0.0f;
    }
  }

  // field types and members
  using _esc_percent_type =
    float;
  _esc_percent_type esc_percent;
  using _steering_percent_type =
    float;
  _steering_percent_type steering_percent;

  // setters for named parameter idiom
  Type & set__esc_percent(
    const float & _arg)
  {
    this->esc_percent = _arg;
    return *this;
  }
  Type & set__steering_percent(
    const float & _arg)
  {
    this->steering_percent = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ai4r_interfaces::msg::EscAndSteering_<ContainerAllocator> *;
  using ConstRawPtr =
    const ai4r_interfaces::msg::EscAndSteering_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ai4r_interfaces::msg::EscAndSteering_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ai4r_interfaces::msg::EscAndSteering_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ai4r_interfaces::msg::EscAndSteering_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ai4r_interfaces::msg::EscAndSteering_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ai4r_interfaces::msg::EscAndSteering_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ai4r_interfaces::msg::EscAndSteering_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ai4r_interfaces::msg::EscAndSteering_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ai4r_interfaces::msg::EscAndSteering_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ai4r_interfaces__msg__EscAndSteering
    std::shared_ptr<ai4r_interfaces::msg::EscAndSteering_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ai4r_interfaces__msg__EscAndSteering
    std::shared_ptr<ai4r_interfaces::msg::EscAndSteering_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EscAndSteering_ & other) const
  {
    if (this->esc_percent != other.esc_percent) {
      return false;
    }
    if (this->steering_percent != other.steering_percent) {
      return false;
    }
    return true;
  }
  bool operator!=(const EscAndSteering_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EscAndSteering_

// alias to use template instance with default allocator
using EscAndSteering =
  ai4r_interfaces::msg::EscAndSteering_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ai4r_interfaces

#endif  // AI4R_INTERFACES__MSG__DETAIL__ESC_AND_STEERING__STRUCT_HPP_
