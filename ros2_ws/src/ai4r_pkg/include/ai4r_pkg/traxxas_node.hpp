#ifndef PWM_DRIVER_NODE_HPP
#define PWM_DRIVER_NODE_HPP

#include <chrono>
#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/bool.hpp"
#include "std_msgs/msg/u_int16.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/string.hpp"

// ai4r custom message types
#include "ai4r_interfaces/msg/servo_pulse_width.hpp"
#include "ai4r_interfaces/msg/esc_and_steering.hpp"

// Drivers
#include "i2c_driver/i2c_driver.h"
#include "pca9685/pca9685.h"

#include <math.h>
#include <bitset>

using namespace std::chrono_literals;

// Constants: 

// Do not touch:
constexpr uint16_t  ESC_SERVO_CHANNEL      = 12;
constexpr uint16_t  STEERING_SERVO_CHANNEL = 15;
constexpr uint16_t  ESTOP_DISABLE = 0;
constexpr uint16_t  ESTOP_ENABLE = 1;
constexpr uint16_t  ESTOP_ENABLE_WITHOUT_GUARDS = 2;
constexpr uint16_t  ESTOP_EMPTY = 999;

// Enum class declaration for states of Finite State Machine
enum class State {
    Disabled,
    Enabled,
    EnabledWithoutGuards,
    // Add more states as needed
};

// Can be changed:
constexpr float    SERVO_FREQUENCY = 100.0f;

// These define the min, max and neutral point for each of the servo channels. Any
// Values received outside of these will be restricted to the minimum or maximum
// value defined below. Percent values are mapped from the range [-100,100] to pulse
// width values in the range [MINIMUM_PULSE_WIDTH, MAXIMUM_PULSE_WIDTH]. When the node
// starts up, the neutral values are sent to each servo channel.

constexpr uint16_t MAXIMUM_PULSE_WIDTH =  1995;
constexpr uint16_t MINIMUM_PULSE_WIDTH =  1005;
constexpr uint16_t STEERING_NEUTRAL_PULSE_WIDTH =  1500;
constexpr uint16_t ESC_NEUTRAL_PULSE_WIDTH =  1500;

constexpr uint16_t STEERING_PULSE_WIDTH_STEP =  50;

constexpr uint16_t MIN_EMPTY_MSG_CYCLES_TO_TIMEOUT = 50;    // Minimum number of cycles (where no message is received) needed to get timeout (automatically switch from Enabled to Disabled state)

// VARIABLES FOR THE PWM DRIVER NODE:

// > I2C Driver Object:
// You will need to change the i2c number
// - List all i2c devices: `ls /dev/i2c*`
// - Allow permissions for the relevant device number e.g. for `/dev/i2c-1` which is i2c pin 1 on the RPi by doing: `sudo chmod 777 /dev/i2c-1`
const char * m_i2c_device_name = "/dev/i2c-1";
I2C_Driver m_i2c_driver (m_i2c_device_name);

// > PCA9685 PWM Servo Driver Object:
const uint8_t m_pca9685_address = 0x40;
PCA9685 m_pca9685_servo_driver (&m_i2c_driver, m_pca9685_address);

#endif