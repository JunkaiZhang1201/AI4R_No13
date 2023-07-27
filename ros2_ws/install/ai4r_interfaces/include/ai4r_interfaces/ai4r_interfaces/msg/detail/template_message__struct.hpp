// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ai4r_interfaces:msg/TemplateMessage.idl
// generated code does not contain a copyright notice

#ifndef AI4R_INTERFACES__MSG__DETAIL__TEMPLATE_MESSAGE__STRUCT_HPP_
#define AI4R_INTERFACES__MSG__DETAIL__TEMPLATE_MESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ai4r_interfaces__msg__TemplateMessage __attribute__((deprecated))
#else
# define DEPRECATED__ai4r_interfaces__msg__TemplateMessage __declspec(deprecated)
#endif

namespace ai4r_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TemplateMessage_
{
  using Type = TemplateMessage_<ContainerAllocator>;

  explicit TemplateMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temp_bool = false;
      this->temp_uint32 = 0ul;
      this->temp_int32 = 0l;
      this->temp_float32 = 0.0f;
      this->temp_float64 = 0.0;
      this->temp_string = "";
    }
  }

  explicit TemplateMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : temp_string(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temp_bool = false;
      this->temp_uint32 = 0ul;
      this->temp_int32 = 0l;
      this->temp_float32 = 0.0f;
      this->temp_float64 = 0.0;
      this->temp_string = "";
    }
  }

  // field types and members
  using _temp_bool_type =
    bool;
  _temp_bool_type temp_bool;
  using _temp_uint32_type =
    uint32_t;
  _temp_uint32_type temp_uint32;
  using _temp_int32_type =
    int32_t;
  _temp_int32_type temp_int32;
  using _temp_float32_type =
    float;
  _temp_float32_type temp_float32;
  using _temp_float64_type =
    double;
  _temp_float64_type temp_float64;
  using _temp_string_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _temp_string_type temp_string;
  using _temp_float64_array_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _temp_float64_array_type temp_float64_array;

  // setters for named parameter idiom
  Type & set__temp_bool(
    const bool & _arg)
  {
    this->temp_bool = _arg;
    return *this;
  }
  Type & set__temp_uint32(
    const uint32_t & _arg)
  {
    this->temp_uint32 = _arg;
    return *this;
  }
  Type & set__temp_int32(
    const int32_t & _arg)
  {
    this->temp_int32 = _arg;
    return *this;
  }
  Type & set__temp_float32(
    const float & _arg)
  {
    this->temp_float32 = _arg;
    return *this;
  }
  Type & set__temp_float64(
    const double & _arg)
  {
    this->temp_float64 = _arg;
    return *this;
  }
  Type & set__temp_string(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->temp_string = _arg;
    return *this;
  }
  Type & set__temp_float64_array(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->temp_float64_array = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ai4r_interfaces::msg::TemplateMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const ai4r_interfaces::msg::TemplateMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ai4r_interfaces::msg::TemplateMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ai4r_interfaces::msg::TemplateMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ai4r_interfaces::msg::TemplateMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ai4r_interfaces::msg::TemplateMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ai4r_interfaces::msg::TemplateMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ai4r_interfaces::msg::TemplateMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ai4r_interfaces::msg::TemplateMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ai4r_interfaces::msg::TemplateMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ai4r_interfaces__msg__TemplateMessage
    std::shared_ptr<ai4r_interfaces::msg::TemplateMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ai4r_interfaces__msg__TemplateMessage
    std::shared_ptr<ai4r_interfaces::msg::TemplateMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TemplateMessage_ & other) const
  {
    if (this->temp_bool != other.temp_bool) {
      return false;
    }
    if (this->temp_uint32 != other.temp_uint32) {
      return false;
    }
    if (this->temp_int32 != other.temp_int32) {
      return false;
    }
    if (this->temp_float32 != other.temp_float32) {
      return false;
    }
    if (this->temp_float64 != other.temp_float64) {
      return false;
    }
    if (this->temp_string != other.temp_string) {
      return false;
    }
    if (this->temp_float64_array != other.temp_float64_array) {
      return false;
    }
    return true;
  }
  bool operator!=(const TemplateMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TemplateMessage_

// alias to use template instance with default allocator
using TemplateMessage =
  ai4r_interfaces::msg::TemplateMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ai4r_interfaces

#endif  // AI4R_INTERFACES__MSG__DETAIL__TEMPLATE_MESSAGE__STRUCT_HPP_
