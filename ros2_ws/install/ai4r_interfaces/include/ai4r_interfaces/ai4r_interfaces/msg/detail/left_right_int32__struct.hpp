// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ai4r_interfaces:msg/LeftRightInt32.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__LEFT_RIGHT_INT32__STRUCT_HPP_
#define AI4R_INTERFACES__MSG__DETAIL__LEFT_RIGHT_INT32__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ai4r_interfaces__msg__LeftRightInt32 __attribute__((deprecated))
#else
# define DEPRECATED__ai4r_interfaces__msg__LeftRightInt32 __declspec(deprecated)
#endif

namespace ai4r_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LeftRightInt32_
{
  using Type = LeftRightInt32_<ContainerAllocator>;

  explicit LeftRightInt32_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left = 0l;
      this->right = 0l;
    }
  }

  explicit LeftRightInt32_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left = 0l;
      this->right = 0l;
    }
  }

  // field types and members
  using _left_type =
    int32_t;
  _left_type left;
  using _right_type =
    int32_t;
  _right_type right;

  // setters for named parameter idiom
  Type & set__left(
    const int32_t & _arg)
  {
    this->left = _arg;
    return *this;
  }
  Type & set__right(
    const int32_t & _arg)
  {
    this->right = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ai4r_interfaces::msg::LeftRightInt32_<ContainerAllocator> *;
  using ConstRawPtr =
    const ai4r_interfaces::msg::LeftRightInt32_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ai4r_interfaces::msg::LeftRightInt32_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ai4r_interfaces::msg::LeftRightInt32_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ai4r_interfaces::msg::LeftRightInt32_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ai4r_interfaces::msg::LeftRightInt32_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ai4r_interfaces::msg::LeftRightInt32_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ai4r_interfaces::msg::LeftRightInt32_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ai4r_interfaces::msg::LeftRightInt32_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ai4r_interfaces::msg::LeftRightInt32_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ai4r_interfaces__msg__LeftRightInt32
    std::shared_ptr<ai4r_interfaces::msg::LeftRightInt32_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ai4r_interfaces__msg__LeftRightInt32
    std::shared_ptr<ai4r_interfaces::msg::LeftRightInt32_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LeftRightInt32_ & other) const
  {
    if (this->left != other.left) {
      return false;
    }
    if (this->right != other.right) {
      return false;
    }
    return true;
  }
  bool operator!=(const LeftRightInt32_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LeftRightInt32_

// alias to use template instance with default allocator
using LeftRightInt32 =
  ai4r_interfaces::msg::LeftRightInt32_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ai4r_interfaces

#endif  // AI4R_INTERFACES__MSG__DETAIL__LEFT_RIGHT_INT32__STRUCT_HPP_
